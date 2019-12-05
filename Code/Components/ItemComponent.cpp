#include "StdAfx.h"
#include "ItemComponent.h"

static void RegisterItem(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(SItemComponent));
		{
		}
	}
}
CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterItem)

void SItemComponent::Initialize()
{
	LoadGeometry();
	Physicalize();
}

uint64 SItemComponent::GetEventMask() const
{
	return BIT64(ENTITY_EVENT_COMPONENT_PROPERTY_CHANGED);
}

void SItemComponent::ProcessEvent(SEntityEvent & event)
{
	switch (event.event)
	{
	case ENTITY_EVENT_COMPONENT_PROPERTY_CHANGED:
	{
		if (sItemProperties != sPrevItemProperties)
		{
			sPrevItemProperties = sItemProperties;

			LoadGeometry();
			Physicalize();
		}
	}
	break;
	}
}

void SItemComponent::ReflectType(Schematyc::CTypeDesc<SItemComponent>& desc)
{
	desc.SetGUID("{18C094CC-645E-41B7-A4AB-58AAED8683DF}"_cry_guid);
	desc.SetLabel("Item Component");
	desc.SetDescription("Base item component");
	desc.AddMember(&SItemComponent::sItemProperties, 'itep', "ItemProperties", "Item settings", "all properties of this item", SItemProperties());
}

void SItemComponent::LoadGeometry()
{
	string sGeomPath = GetProperties()->sRenderProperties.sGeomPath.value.c_str();
	if (sGeomPath.empty())
	{
		m_pEntity->LoadGeometry(GEOMETRY_SLOT, "");
		return;
	}

	m_pEntity->LoadGeometry(GEOMETRY_SLOT, sGeomPath);
}

void SItemComponent::Physicalize()
{
	SEntityPhysicalizeParams PhysParams;
	PhysParams.mass = GetProperties()->sPhysicsProperties.fMass;
	PhysParams.type = PE_RIGID;
	m_pEntity->Physicalize(PhysParams);
}
