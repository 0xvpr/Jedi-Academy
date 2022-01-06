#include "Hacks.hpp"

#include "Offsets.hpp"
#include "Entity.hpp"
#include "Memory.hpp"
#include "Assembly.hpp"
#include <psapi.h>

extern uintptr_t module_base_addr;

void hacks::ToggleInfiniteHealth(bool bEnabled) {

    uint8_t health_original[6] = {
        0x8B, 0xB7, 0x44, 0x02, 0x00, 0x00  // mov esi, [edi + 0x244]
    };

    void* health_addr = [](){
        auto base = (uintptr_t)GetModuleHandleA("jagamex86.dll");
        return reinterpret_cast<void *>(base + offsets::health_op);
    }();

    if (bEnabled) {
        memory::Detour(health_addr, health_detour, sizeof(health_original));
    } else {
        memory::Patch(health_addr, health_original, sizeof(health_original));
    }

}

void hacks::ToggleInfiniteShields(bool bEnabled) {

    (void)bEnabled;

}

void hacks::ToggleInfiniteForce(bool bEnabled) {

    uint8_t force_original[6] = {
        0x29, 0x88, 0x50, 0x12, 0x00, 0x00  // sub [eax + 0x1250], ecx
    };
    uint8_t force_patch[6] = {
        0x90,          // nop
        0x90,          // nop
        0x90,          // nop
        0x90,          // nop
        0x90,          // nop
        0x90           // nop
    };

    MODULEINFO modInfo = []() {
        MODULEINFO _modInfo;
        auto base = GetModuleHandleA("jagamex86.dll");
        GetModuleInformation(GetCurrentProcess(), base, &_modInfo, sizeof(_modInfo));
        return _modInfo;
    }();

    if (bEnabled) {
        uint8_t pattern[18] = {
            0x29, 0x88, 0x50, 0x12, 0x00, 0x00,     // sub [eax + 0x1250], ecx
            0x8B, 0x82, 0x10, 0x01, 0x00, 0x00,     // mov eax, [edx + 0x110]
            0x8B, 0x88, 0x50, 0x12, 0x00, 0x00      // mov ecx, [eax + 0x1250]
        };

        void* force_addr = memory::FindPattern((modInfo.lpBaseOfDll), modInfo.SizeOfImage, pattern, sizeof(pattern));
        if (force_addr) {
            memory::Patch(force_addr, force_patch, sizeof(force_patch));
        }
    } else {
        uint8_t pattern[18] = {
            0x90,                                   // nop
            0x90,                                   // nop
            0x90,                                   // nop
            0x90,                                   // nop
            0x90,                                   // nop
            0x90,                                   // nop
            0x8B, 0x82, 0x10, 0x01, 0x00, 0x00,     // mov eax, [edx + 0x110]
            0x8B, 0x88, 0x50, 0x12, 0x00, 0x00      // mov ecx, [eax + 0x1250]
        };

        void* force_addr = memory::FindPattern(modInfo.lpBaseOfDll, modInfo.SizeOfImage, pattern, sizeof(pattern));
        if (force_addr) {
            memory::Patch(force_addr, force_original, sizeof(force_original));
        }
    }

}