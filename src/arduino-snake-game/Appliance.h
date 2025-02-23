#if !defined(APPLIANCE_H)
#define APPLIANCE_H

#include "ScreenInterface.h"
#include "DirectionSwitchInterface.h"
#include "ToggleButtonInterface.h"

namespace XC 
{
    namespace Hardware
    {
        struct Appliance
        {
            public:
                ScreenInterface* screen;
                DirectionSwitchInterface* directionSwitch;
                ToggleButtonInterface* pauseButton;
        };
    }; // namespace Hardware
}; // namespace XC


#endif // APPLIANCE_H
