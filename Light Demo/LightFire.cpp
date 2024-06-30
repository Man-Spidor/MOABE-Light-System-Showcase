#include "LightFire.h"
#include <TimeManager.h>

LightFire::LightFire(MOABELight* _pLight, Vect _Color1, Vect _Color2, float FlickerTime) :
	Alarm(*this),
	BlendColor1(_Color1),
	BlendColor2(_Color2),
	CurrBlendColor1(&BlendColor1),
	CurrBlendColor2(&BlendColor2),
	pLight(_pLight),
	BlendFactor(1.0f / FlickerTime),
	CurrBlendFactor(0.0f),
	SwitchTime(FlickerTime)
{
}

void LightFire::StartBehaviour()
{
	this->Alarm.StartAlarm(0, this->SwitchTime);
}

void LightFire::UpdateLight()
{
	this->CurrBlendFactor += BlendFactor * TimeManager::GetFrameTime();

	Vect color = this->CurrBlendFactor * *this->CurrBlendColor1 + (1.0f - this->CurrBlendFactor) * *this->CurrBlendColor2;
	
	this->pLight->SetAmbDifSpec(color, color, 0.5f * color);	// Adjust Specular automatically for simplicity
}

void LightFire::Callback0()
{
	this->CurrBlendFactor = 0.0f;
	this->CurrBlendColor1 = &this->BlendColor2;
	this->CurrBlendColor2 = &this->BlendColor1;

	this->pLight->SetAmbDifSpec(this->BlendColor2, this->BlendColor2, 0.5f * this->BlendColor2);	// Adjust Specular automatically for simplicity
	this->Alarm.StartAlarm(1, this->SwitchTime);
}

void LightFire::Callback1()
{
	this->CurrBlendFactor = 0.0f;
	this->CurrBlendColor1 = &this->BlendColor1;
	this->CurrBlendColor2 = &this->BlendColor2;

	this->pLight->SetAmbDifSpec(this->BlendColor1, this->BlendColor1, 0.5f * this->BlendColor1);	// Adjust Specular automatically for simplicity
	this->Alarm.StartAlarm(0, this->SwitchTime);
}
