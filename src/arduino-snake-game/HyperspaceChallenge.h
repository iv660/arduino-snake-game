#if !defined(HYPERSPACE_CHALLENGE_H)
#define HYPERSPACE_CHALLENGE_H

#include "BaseChallenge.h"

class HyperspaceChallenge: public BaseChallenge<HyperspaceChallenge>
{
    private:
    public:
        void startRound() override;
};


#endif // HYPERSPACE_CHALLENGE_H
