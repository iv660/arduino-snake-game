#if !defined(DIRECTION_SWITCH_INTREFACE_H)
#define DIRECTION_SWITCH_INTREFACE_H

namespace XC
{
    namespace Hardware
    {
        class DirectionSwitchInterface
        {
            public:
                enum Direction {
                    NONE,
                    LEFT,
                    RIGHT,
                    UP,
                    DOWN,
                };

                virtual Direction getDirection() = 0;
        };
    }; // namespace Hardware
}; // namespace XC


#endif // DIRECTION_SWITCH_INTREFACE_H
