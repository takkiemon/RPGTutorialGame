#pragma once

#include <CrySchematyc/ResourceTypes.h>
#include <CrySchematyc/Reflection/TypeDesc.h>

enum ItemGeometrySlot
{
	GEOMETRY_SLOT = 0
};
//
struct SRenderProperties
{
	inline bool operator==(const SRenderProperties& rhs) const { return 0 == memcmp(this, &rhs, sizeof(rhs)); }
	inline bool operator!=(const SRenderProperties& rhs) const { return 0 != memcmp(this, &rhs, sizeof(rhs)); }

	Schematyc::GeomFileName sGeomPath;
	Schematyc::MaterialFileName sMaterial;
};
static void ReflectType(Schematyc::CTypeDesc<SRenderProperties>& desc)
{
	desc.SetGUID("{4702195E-4B7D-464D-B489-A367DD086E9D}"_cry_guid);
	desc.SetLabel("Render properties");
	desc.SetDescription("Render Properties");
	desc.AddMember(&SRenderProperties::sGeomPath, 'geom', "GeometryPath", "Geometry path", "Geometry path of this item", "");
	desc.AddMember(&SRenderProperties::sMaterial, 'smat', "MaterialPath", "Material path", "Material path of this item", "");
}
//
struct SPhysicsProperties
{
	inline bool operator==(const SPhysicsProperties& rhs) const { return 0 == memcmp(this, &rhs, sizeof(rhs)); }
	inline bool operator!=(const SPhysicsProperties& rhs) const { return 0 != memcmp(this, &rhs, sizeof(rhs)); }

	float fMass;
};
static void ReflectType(Schematyc::CTypeDesc<SPhysicsProperties>& desc)
{
	desc.SetGUID("{E1EE4388-CE7C-46F4-A922-518CB652D482}"_cry_guid);
	desc.SetLabel("Physics properties");
	desc.SetDescription("Render Properties");
	desc.AddMember(&SPhysicsProperties::fMass, 'fmas', "Mass", "Mass", "Mass property of this item", 0.f);
}
//MAIN PROPERTY STRUCTURE
struct SItemProperties
{
	inline bool operator==(const SItemProperties& rhs) const { return 0 == memcmp(this, &rhs, sizeof(rhs)); }
	inline bool operator!=(const SItemProperties& rhs) const { return 0 != memcmp(this, &rhs, sizeof(rhs)); }

	SRenderProperties sRenderProperties;
	SPhysicsProperties sPhysicsProperties;
	//item specific
	//non-editor variables:
	string sItemName;
};
static void ReflectType(Schematyc::CTypeDesc<SItemProperties>& desc)
{
	desc.SetGUID("{46045A6E-5B52-4200-85C1-845FCD81360A}"_cry_guid);
	desc.SetLabel("Item properties");
	desc.SetDescription("Item Properties");
	desc.AddMember(&SItemProperties::sRenderProperties, 'renp', "RenderProperties", "Render Settings", "All render settings of this item", SRenderProperties());
	desc.AddMember(&SItemProperties::sPhysicsProperties, 'phyp', "PhysicsProperties", "Physics Settings", "All physics settings of this item", SPhysicsProperties());
}