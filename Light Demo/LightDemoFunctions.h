#ifndef LIGHTDEMOFUNCTIONS_H
#define LIGHTDEMOFUNCTIONS_H

#include <MOABEUser.h>

class LightDemoFunctions : public MOABEUser
{
public:
	LightDemoFunctions() = default;
	LightDemoFunctions(const LightDemoFunctions& other) = default;
	LightDemoFunctions& operator=(const LightDemoFunctions& other) = default;
	LightDemoFunctions(LightDemoFunctions&& other) = default;
	LightDemoFunctions& operator=(LightDemoFunctions&& other) = default;
	~LightDemoFunctions() = default;

	virtual void GameStart() override;
	virtual void GameEnd() override;
	virtual void LoadAllContent() override;
};

#endif // LIGHTDEMOFUNCTIONS_H
