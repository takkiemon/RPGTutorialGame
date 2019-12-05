/*
Author : Tak Man Wong
Project : CryEngine RPG Tutorial stuffs
Purpose : Base structure for items. All types of items will derive from it
*/



#pragma once

#include <CryEntitySystem/IEntityComponent.h>
#include "ItemProperties.h"

struct SItemComponent : public IEntityComponent
{
public:
	SItemComponent() = default;
	SItemComponent::~SItemComponent() {}

	virtual void Initialize() override;
	virtual void InitializeClass() = 0;
	virtual uint64 GetEventMask() const override;
	virtual void ProcessEvent(SEntityEvent& event) override;
	static void ReflectType(Schematyc::CTypeDesc<SItemComponent>& desc);
	//geometry and physics
	virtual void LoadGeometry();
	virtual void Physicalize();
	//
	SItemProperties *GetProperties() { return &sItemProperties; }
protected:
	SItemProperties sItemProperties, sPrevItemProperties;
};