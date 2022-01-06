#ifndef HACKS_HPP
#define HACKS_HPP

#ifndef WIN32_LEAN_AND_MEAN
#   define WIN32_LEAN_AND_MEAN
#endif // WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tlhelp32.h>

namespace hacks {
    void ToggleInfiniteHealth(bool);
    void ToggleInfiniteShields(bool);
    void ToggleInfiniteForce(bool);
}

#endif /* _HACKS_H */
