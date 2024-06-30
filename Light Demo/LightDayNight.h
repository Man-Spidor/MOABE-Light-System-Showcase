#ifndef LIGHTDAYNIGHT_H
#define LIGHTDAYNIGHT_H

#include "LightBehaviourCommand.h"

class MOABEDirectionalLight;

class LightDayNight : public LightBehaviourCommand
{
public:
	LightDayNight() = delete;
	LightDayNight(const LightDayNight& other) = default;
	LightDayNight& operator=(const LightDayNight& other) = default;
	LightDayNight(LightDayNight&& other) = default;
	LightDayNight& operator=(LightDayNight&& other) = default;
	~LightDayNight() = default;

	LightDayNight(MOABEDirectionalLight* _pLight, float DayNightTime);

	virtual void UpdateLight() override;

private:
	MOABEDirectionalLight* pLight;
	float DayNightAngle;
};

#endif // LIGHTDAYNIGHT_H
