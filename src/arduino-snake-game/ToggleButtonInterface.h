#if !defined(TOGGLE_BUTTON_INTERFACE_H)
#define TOGGLE_BUTTON_INTERFACE_H)

namespace XC
{
    namespace Hardware
    {
        class ToggleButtonInterface
        {
            public:
                virtual void tick() = 0;
                virtual void reset() = 0;
                virtual bool isOn() = 0;
        };
    }
}

#endif // TOGGLE_BUTTON_INTERFACE_H)
