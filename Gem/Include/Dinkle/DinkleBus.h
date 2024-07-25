
#pragma once

#include <Dinkle/DinkleTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Dinkle
{
    class DinkleRequests
    {
    public:
        AZ_RTTI(DinkleRequests, DinkleRequestsTypeId);
        virtual ~DinkleRequests() = default;
        // Put your public methods here
    };

    class DinkleBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using DinkleRequestBus = AZ::EBus<DinkleRequests, DinkleBusTraits>;
    using DinkleInterface = AZ::Interface<DinkleRequests>;

} // namespace Dinkle
