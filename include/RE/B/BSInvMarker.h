#pragma once

#include "RE/N/NiPoint3.h"
#include "RE/N/NiExtraData.h"

namespace RE
{
    class BSInvMarker : public NiExtraData 
    {
    public:
        inline static constexpr auto RTTI = RTTI_BSInvMarker; 
        inline static constexpr auto Ni_RTTI = NiRTTI_BSInvMarker; 
        inline static constexpr auto VTABLE = VTABLE_BSInvMarker;

        RE::NiPoint3 GetRotationEulerAnglesXYZ() const;

        // members
        float         zoom;       // 18
        std::uint16_t rotationX;  // 1C
        std::uint16_t rotationY;  // 1E
        std::uint16_t rotationZ;  // 20
        std::uint8_t  pad22[6];   // 22
    };
    static_assert(sizeof(BSInvMarker) == 0x28);
}