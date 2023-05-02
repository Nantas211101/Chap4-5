#pragma once

namespace NodesState{
    enum ID{
        nothing,
        isSearching,
        isAccesing,
        isUpdating,
    };
}

namespace ActionState{
    enum ID{
        isDoing,
        DoneTrue,
        DoneFalse,
    };
}
