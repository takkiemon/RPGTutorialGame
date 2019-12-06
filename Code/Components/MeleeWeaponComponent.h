/*

Author : Tak Man Wong
Project : RPGTutorialGame
Purpose : Defines all melee weapons

*/

#pragma once

#include <CryEntitySystem/IEntityComponent.h>
#include "MeleeWeaponProperties.h"
#include "ItemComponent.h"

class CMeleeWeaponComponent : public SItemComponent
{
public:
	CMeleeWeaponComponent() = default;
	CMeleeWeaponComponent::~CMeleeWeaponComponent() {}

	virtual void InitializeClass() override;
	virtual void ProcessEventClass(SEntityEvent& event) override;
	static void ReflectType(Schematyc::CTypeDesc<CMeleeWeaponComponent>& desc); // CryLog("ik ben bij 1:37:37 in de tutorial https://youtu.be/h4wEQUwO5PY?t=5857"); dafuq is er met de 'gEnv' ?
	//MELEE WEAPON COMPONENT

};
