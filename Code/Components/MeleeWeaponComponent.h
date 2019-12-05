/*
Author : Tak Man Wong
Project : RPGTutorialGame
Purpose : Defines all melee weapons
*/

#pragma once

#include <CryEntitySystem/IEntityComponent.h>
#include "MeleeWeaponProperties.h"

class CMeleeWeaponComponent : public IEntityComponent {
public:
	CMeleeWeaponComponent() = default;
	CMeleeWeaponComponent::~CMeleeWeaponComponent() {}

	virtual void Initialize() override;
	virtual uint64 GetEventMask() const override;
	virtual void ProcessEvent(SEntityEvent& event) override;
	static void ReflectType(Schematyc::CTypeDesc<CMeleeWeaponComponent>& desc); // CryLog("ik ben bij 1:37:37 in de tutorial https://youtu.be/h4wEQUwO5PY?t=5857"); dafuq is er met de 'gEnv' ?
	//MELEE WEAPON COMPONENT
};