#include <windows.h>
#include <setupapi.h>
#include <vector>
#include <string>
#include <devguid.h> 

#pragma comment(lib, "setupapi.lib")

std::vector<std::wstring> ListPhysicalDrives() {
    std::vector<std::wstring> devices;

    HDEVINFO hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_DISK, NULL, NULL, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
    if (hDevInfo == INVALID_HANDLE_VALUE)
        return devices;

    SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
    deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

    for (DWORD i = 0; SetupDiEnumDeviceInterfaces(hDevInfo, NULL, &GUID_DEVINTERFACE_DISK, i, &deviceInterfaceData); ++i) {
        DWORD requiredSize = 0;
        SetupDiGetDeviceInterfaceDetail(hDevInfo, &deviceInterfaceData, NULL, 0, &requiredSize, NULL);

        PSP_DEVICE_INTERFACE_DETAIL_DATA pDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA)malloc(requiredSize);
        if (!pDetailData)
            break;
        pDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

        if (SetupDiGetDeviceInterfaceDetail(hDevInfo, &deviceInterfaceData, pDetailData, requiredSize, NULL, NULL)) {
            devices.emplace_back(pDetailData->DevicePath);
        }
        free(pDetailData);
    }

    SetupDiDestroyDeviceInfoList(hDevInfo);
    return devices;
}

int main() {
    auto drives = ListPhysicalDrives();

    return 0;
}
