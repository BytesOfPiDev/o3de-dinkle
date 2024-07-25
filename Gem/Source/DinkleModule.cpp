
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "DinkleSystemComponent.h"

#include <Dinkle/DinkleTypeIds.h>

namespace Dinkle
{
    class DinkleModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(DinkleModule, DinkleModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(DinkleModule, AZ::SystemAllocator);

        DinkleModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                DinkleSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<DinkleSystemComponent>(),
            };
        }
    };
}// namespace Dinkle

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), Dinkle::DinkleModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_Dinkle, Dinkle::DinkleModule)
#endif
