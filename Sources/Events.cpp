#include "Events.hpp"
#include "Hacks.hpp"

bool bCheatsEnabled = false;
bool bInfiniteHealth = false;
bool bInfiniteShields = false;
bool bInfiniteForce = false;

bool events::HandleKeyboard(void) {
    
    if (GetAsyncKeyState(VK_TAB) & 1) {
        bCheatsEnabled = !bCheatsEnabled;

        if (bCheatsEnabled) {
            hacks::ToggleInfiniteHealth(bInfiniteHealth);
            hacks::ToggleInfiniteShields(bInfiniteShields);
            hacks::ToggleInfiniteForce(bInfiniteForce);
        } else {
            hacks::ToggleInfiniteHealth(false);
            hacks::ToggleInfiniteShields(false);
            hacks::ToggleInfiniteForce(false);
        }
    }

    if ((GetAsyncKeyState(VK_F1) & 1) && bCheatsEnabled) {
        bInfiniteHealth = !bInfiniteHealth;

        hacks::ToggleInfiniteHealth(bInfiniteHealth);
    }

    if ((GetAsyncKeyState(VK_F2) & 1) && bCheatsEnabled) {
        bInfiniteShields = !bInfiniteShields;

        hacks::ToggleInfiniteShields(bInfiniteShields);
    }

    if ((GetAsyncKeyState(VK_F3) & 1) && bCheatsEnabled) {
        bInfiniteForce = !bInfiniteForce;

        hacks::ToggleInfiniteForce(bInfiniteForce);
    }

    if (GetAsyncKeyState(VK_END)) {
        hacks::ToggleInfiniteHealth(false);
        hacks::ToggleInfiniteShields(false);
        hacks::ToggleInfiniteForce(false);

        return true;
    }

    return false;
}
