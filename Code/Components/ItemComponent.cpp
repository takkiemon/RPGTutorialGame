#include "StdAfx.h"
#include "ItemComponent.h"

void SItemComponent::Initialize()
{
	LoadGeometry();
	Physicalize();
	CreateItemName();
	InitializeClass();
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
			InitializeClass();
		}
	}
	break;
	}
	ProcessEventClass(event);
}

void SItemComponent::ReflectType(Schematyc::CTypeDesc<SItemComponent>& desc)
{
	desc.SetGUID("{18C094CC-645E-41B7-A4AB-58AAED8683DF}"_cry_guid);
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

void SItemComponent::CreateItemName()
{
	string sLongName = m_pEntity->GetClass()->GetName();
	sLongName.erase(0, sLongName.find_last_of(':') + 1);
	string sFirst;
	sFirst.SetAt(0, sLongName[0]);
	sFirst.MakeUpper();
	sLongName.erase(0, 1);
	GetProperties()->sItemName = sFirst + sLongName;
}

void SItemComponent::PickUp(CPlayerComponent *pNewOwner)
{
	if (!pNewOwner)
		return;

	pOwner = pNewOwner;
	pOwner->GetEntity()->AttachChild(m_pEntity);
}

bool SItemComponent::IsPickable()
{
	return !pOwner;
}
