#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QTextEdit>
#include <QProgressBar>
#include <QMessageBox>
#include <QProcess>
#include <QTextStream>
#include <QFile>

class InstallerWindow : public QWidget {
    Q_OBJECT

public:
    InstallerWindow(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("UNI-OS Installer");

        QVBoxLayout* layout = new QVBoxLayout(this);
        QLabel* titleLabel = new QLabel("Welcome to UNI-OS Installer", this);
        layout->addWidget(titleLabel);

        QPushButton* selectIsoButton = new QPushButton("Select ISO File", this);
        layout->addWidget(selectIsoButton);

        QLabel* isoPathLabel = new QLabel("No ISO selected", this);
        layout->addWidget(isoPathLabel);

        QPushButton* selectTargetButton = new QPushButton("Select Installation Target Disk", this);
        layout->addWidget(selectTargetButton);

        QLabel* targetPathLabel = new QLabel("No target disk selected", this);
        layout->addWidget(targetPathLabel);

        QPushButton* installButton = new QPushButton("Install UNI-OS", this);
        layout->addWidget(installButton);

        QProgressBar* progressBar = new QProgressBar(this);
        layout->addWidget(progressBar);
        progressBar->setRange(0, 100);
        progressBar->setValue(0);

        // Log text area
        logTextArea = new QTextEdit(this);
        logTextArea->setReadOnly(true);
        layout->addWidget(logTextArea);

        // Connect buttons
        connect(selectIsoButton, &QPushButton::clicked, this, [this, isoPathLabel] {
            QString isoPath = QFileDialog::getOpenFileName(this, "Select UNI-OS ISO", "", "ISO Files (*.iso)");
            if (!isoPath.isEmpty()) {
                isoPathLabel->setText(isoPath);
            }
        });

        connect(selectTargetButton, &QPushButton::clicked, this, [this, targetPathLabel] {
            QString targetDisk = QFileDialog::getExistingDirectory(this, "Select Target Disk");
            if (!targetDisk.isEmpty()) {
                targetPathLabel->setText(targetDisk);
            }
        });

        connect(installButton, &QPushButton::clicked, this, [this, progressBar, isoPathLabel, targetPathLabel] {
            QString isoPath = isoPathLabel->text();
            QString targetPath = targetPathLabel->text();

            if (isoPath == "No ISO selected" || targetPath == "No target disk selected") {
                QMessageBox::warning(this, "Error", "Please select both an ISO file and a target disk.");
                return;
            }

            // Check filesystem type
            if (!checkFilesystem(targetPath)) {
                return;
            }

            // Start installation process
            installOS(isoPath, targetPath, progressBar);
        });

        setLayout(layout);
    }

private:
    QTextEdit* logTextArea;

    void logToUI(const QString &message) {
        logTextArea->append(message);  // Append log messages to the UI
    }

    bool checkFilesystem(const QString &targetPath) {
        QProcess process;
        process.start(QString("lsblk -f %1").arg(targetPath));
        process.waitForFinished();

        QByteArray output = process.readAllStandardOutput();
        QString outputStr(output);
        if (!outputStr.contains("ext4")) {
            QMessageBox::warning(this, "Filesystem Error", "The target disk is not formatted with ext4. Please format it to ext4.");
            return false;
        }
        return true;
    }

    void logError(const QString &message) {
        QFile logFile("installer.log");
        if (logFile.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&logFile);
            out << message << "\n";
        }
    }

    bool executeCommandWithLogging(const QString &command, QProgressBar *progressBar, const QString &stepDescription) {
        logToUI(stepDescription + " started...");

        QProcess process;
        process.start(command);
        process.waitForFinished();

        int exitCode = process.exitCode();
        QByteArray errorOutput = process.readAllStandardError();

        if (exitCode != 0) {
            logError(stepDescription + " failed: " + errorOutput);
            QMessageBox::critical(this, "Error", "An error occurred during the installation: " + errorOutput);
            return false;
        }

        logToUI(stepDescription + " completed successfully.");
        return true;
    }

    void installOS(const QString &isoPath, const QString &targetPath, QProgressBar *progressBar) {
        logToUI("Starting installation...");

        // Mount ISO
        QString mountCommand = QString("mount -o loop %1 /mnt/iso").arg(isoPath);
        if (!executeCommandWithLogging(mountCommand, progressBar, "Mounting ISO")) {
            return;  // If mount fails, stop installation
        }

        // Copy files
        QString copyCommand = QString("cp -r /mnt/iso/* %1/").arg(targetPath);
        if (!executeCommandWithLogging(copyCommand, progressBar, "Copying files")) {
            return;
        }

        // Install Bootloader
        QString bootloaderCommand = QString("grub-install --target=i386-pc --boot-directory=%1/boot /dev/sda").arg(targetPath);
        if (!executeCommandWithLogging(bootloaderCommand, progressBar, "Installing bootloader")) {
            return;
        }

        logToUI("Installation complete. Reboot to finish setup.");
        QMessageBox::information(this, "Installation Complete", "UNI-OS has been successfully installed. Please reboot your system.");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    InstallerWindow window;
    window.show();

    return app.exec();
}
