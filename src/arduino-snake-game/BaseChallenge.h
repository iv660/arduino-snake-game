#pragma once

#include "Scene.h"
#include "GridAllocator.h"

template <typename Derived>
class BaseChallenge
{
    private:
    protected:
        Scene* scene;
        GridAllocator gridAllocator;
    public:
        virtual Derived* setScene(Scene* scene)
        {
            this->scene = scene;

            return this;
        }

        virtual Derived* setGridAllocator(GridAllocator gridAllocator)
        {
            this->gridAllocator = gridAllocator;

            return this;
        }

        virtual void startRound() {}
        virtual void beforeRoundStart() {}
};

