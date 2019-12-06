#include "StdAfx.h"
#include "MeleeWeaponComponent.h"

static void RegisterMeleeWeapon(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CMeleeWeaponComponent));
		{
		}
	}
}
CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterMeleeWeapon)

void CMeleeWeaponComponent::InitializeClass()
{

}

void CMeleeWeaponComponent::ProcessEventClass(SEntityEvent & event)
{

}

void CMeleeWeaponComponent::ReflectType(Schematyc::CTypeDesc<CMeleeWeaponComponent>& desc)
{
	desc.SetGUID("{8B81D8F2-19CC-406D-B0D8-94C071845E75}"_cry_guid);
	desc.AddBase<SItemComponent>();
	desc.SetEditorCategory("Items");
	desc.SetLabel("Melee Weapon Component");
	desc.SetDescription("Melee weapon component");
	desc.AddMember(&CMeleeWeaponComponent::sItemProperties, 'itep', "ItemProperties", "Item settings", "all properties of this item", SItemProperties());
}
