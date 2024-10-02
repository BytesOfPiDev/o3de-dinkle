#include "DinkleSystemComponent.h"

#include "AzCore/Serialization/SerializeContext.h"

#include "Dinkle/DinkleTypeIds.h"

namespace Dinkle
{
    AZ_COMPONENT_IMPL(DinkleSystemComponent, "DinkleSystemComponent", DinkleSystemComponentTypeId);

    void DinkleSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<DinkleSystemComponent, AZ::Component>()->Version(0);
        }
    }

    void DinkleSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("DinkleService"));
    }

    void DinkleSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("DinkleService"));
    }

    void DinkleSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void DinkleSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    DinkleSystemComponent::DinkleSystemComponent()
    {
        if (DinkleInterface::Get() == nullptr)
        {
            DinkleInterface::Register(this);
        }
    }

    DinkleSystemComponent::~DinkleSystemComponent()
    {
        if (DinkleInterface::Get() == this)
        {
            DinkleInterface::Unregister(this);
        }
    }

    void DinkleSystemComponent::Init()
    {
    }

    void DinkleSystemComponent::Activate()
    {
        DinkleRequestBus::Handler::BusConnect();
    }

    void DinkleSystemComponent::Deactivate()
    {
        DinkleRequestBus::Handler::BusDisconnect();
    }
} // namespace Dinkle
