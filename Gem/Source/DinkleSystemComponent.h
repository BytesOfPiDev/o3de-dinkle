
#pragma once

#include <AzCore/Component/Component.h>

#include <Dinkle/DinkleBus.h>

namespace Dinkle
{
    class DinkleSystemComponent
        : public AZ::Component
        , protected DinkleRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(DinkleSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        DinkleSystemComponent();
        ~DinkleSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // DinkleRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
