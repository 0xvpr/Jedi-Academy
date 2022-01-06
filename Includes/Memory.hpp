#ifndef MEMORY_HPP
#define MEMORY_HPP

#ifndef WIN32_LEAN_AND_MEAN
#   define WIN32_LEAN_AND_MEAN
#endif // WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdint>
#include <vector>

namespace memory {

/**
 * Finds the Dynamic Memory Access address of an embedded process.
 *
 * @param:  ptr
 * @param:  offsets
 * @param:  size
 *
 * @return: addr
**/
template <typename T> [[nodiscard]]
T FindDynamicAddress(uintptr_t ptr, const std::vector<unsigned>& offsets) {

    uintptr_t addr = ptr;

    for (const auto& offset : offsets) {
        addr  = *(uintptr_t *)addr;
        addr += offset;

        if (*(uintptr_t *)addr == 0) { 
            return 0;
        }
    }

    return reinterpret_cast<T>(addr);
}

/**
 * Byte replacement from source to destination.
 *
 * @param:  destination
 * @param:  source
 * @param:  size
 *
 * @return: bSuccess
**/
bool Patch(void* dst, void* src, size_t size);

/**
 * Hooks into a function and detours the target function to another function.
 *
 * @param:  fTargetFunc
 * @param:  fMyFunc
 * @param:  size
 *
 * @return: bSuccess
**/
bool Detour(void* fTargetFunc, void* fMyFunc, size_t size);

/**
 * Hooks into a function and detours the target function to another function.
 *
 * @param:  fTargetFunc
 * @param:  fMyFunc
 * @param:  size
 *
 * @return: bSuccess
**/
bool Detour(void* fTargetFunc, void (* fMyFunc)(), size_t size);

/**
 * Hooks into a function and detours the target function to another function, then jumps back.
 *
 * @param:  src
 * @param:  dst
 * @param:  size
 *
 * @return: addr
**/
char* TrampHook(void* targetFunc, void* myFunc, size_t size);

/**
 * Scans a given chunk of data for the given pattern and mask.
 *
 * @param:  base_addr       The base address of where the scan data is from.
 * @param:  img_size        The size of the module.
 * @param:  pattern         The pattern to scan for.
 * @param:  pattern_size    The size of the pattern to scan for.
 *
 * @return: Pointer of the pattern found, 0 otherwise.
**/
unsigned char* FindPattern(void* base_addr, size_t img_size, void* pattern, size_t s);

}

#endif // MEMORY_HPP