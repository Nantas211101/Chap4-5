#pragma once

namespace NodesState{
    enum ID{
        nothing,
        isSearching,
        isAccesing,
        isUpdating,
        isPushing,
        isPoping,
    };

    enum ActionType{
        StepByStep,
        RunAtOnce,
    };
}

namespace ActionState{
    enum ID{
        isDoing,
        DoneTrue,
        DoneFalse,
    };
}