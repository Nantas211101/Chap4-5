#pragma once

namespace NodesState{
    enum ID{
        nothing,
        isSearching,
        isAccesing,
        isUpdating,
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