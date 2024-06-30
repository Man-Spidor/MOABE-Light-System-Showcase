#ifndef LIGHTFIRE_H
#define LIGHTFIRE_H

#include <LightBehaviourCommand.h>
#include <MOABELight.h>
#include <LightAlarm.h>

// Changes the light's color back and forth based on a specified time frame
class LightFire : public LightBehaviourCommand
{
public:
	LightFire() = delete;
	LightFire(const LightFire& other) = default;
	LightFire& operator=(const LightFire& other) = default;
	LightFire(LightFire&& other) = default;
	LightFire& operator=(LightFire&& other) = default;
	~LightFire() = default;

	LightFire(MOABELight* _pLight, Vect _Color1, Vect _Color2, float FlickerTime);

	virtual void StartBehaviour() override;

	virtual void UpdateLight() override;

	virtual void Callback0() override;
	virtual void Callback1() override;

private:
	LightAlarm Alarm;

	const Vect BlendColor1;
	const Vect BlendColor2;
	const Vect* CurrBlendColor1;
	const Vect* CurrBlendColor2;

	MOABELight* pLight;
	float BlendFactor;
	float CurrBlendFactor;
	float SwitchTime;
};

#endif // LIGHTFIRE_H
