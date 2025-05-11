#include <windows.h>
#include <winternl.h>

NTSTATUS NTAPI NtQuerySystemInformation(
    SYSTEM_INFORMATION_CLASS SystemInformationClass,
    PVOID SystemInformation,
    ULONG SystemInformationLength,
    PULONG ReturnLength)
{
    typedef NTSTATUS (NTAPI *pOrigFn)(SYSTEM_INFORMATION_CLASS, PVOID, ULONG, PULONG);
    static pOrigFn Original = NULL;
    if (!Original)
        Original = (pOrigFn)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "NtQuerySystemInformation");

    NTSTATUS status = Original(SystemInformationClass, SystemInformation, SystemInformationLength, ReturnLength);

    // Spoof OS version info
    if (SystemInformationClass == SystemVersionInformation && NT_SUCCESS(status)) {
        OSVERSIONINFOEXW* ver = (OSVERSIONINFOEXW*)SystemInformation;
        ver->dwMajorVersion = 10;
        ver->dwMinorVersion = 0;
        ver->dwBuildNumber = 19041;
        wcscpy(ver->szCSDVersion, L"UNI_OS Custom Build");
    }

    return status;
}
