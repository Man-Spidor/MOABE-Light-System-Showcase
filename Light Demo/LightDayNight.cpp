#include "LightDayNight.h"

#include <MOABEDirectionalLight.h>

#include <TimeManager.h>

LightDayNight::LightDayNight(MOABEDirectionalLight* _pLight, float DayNightTime) :
	pLight(_pLight),
	DayNightAngle(0.0f)
{
	this->DayNightAngle = MATH_PI / DayNightTime;
}

void LightDayNight::UpdateLight()
{
	this->pLight->TiltUpDown(this->DayNightAngle * TimeManager::GetFrameTime());
}
