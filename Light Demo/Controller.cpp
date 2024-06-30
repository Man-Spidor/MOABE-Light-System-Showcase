#include "Controller.h"

#include "CampfireScene.h"
#include "LightForestScene.h"

#include <SceneManager.h>

void Controller::Initialize()
{
	Inputable::RegisterKeyToScene(JAZUL_KEY::KEY_ARROW_LEFT, EventType::KEY_PRESS);
	Inputable::RegisterKeyToScene(JAZUL_KEY::KEY_ARROW_RIGHT, EventType::KEY_PRESS);
}

void Controller::KeyPressed(JAZUL_KEY key)
{
	// need to be pressing left control for debug keys to work
	switch (key) {
	case JAZUL_KEY::KEY_ARROW_LEFT:
		if(Keyboard::GetKeyState(JAZUL_KEY::KEY_LEFT_CONTROL))
			SceneManager::SwitchCurrScene(new CampfireScene);
		break;

	case JAZUL_KEY::KEY_ARROW_RIGHT:
		if(Keyboard::GetKeyState(JAZUL_KEY::KEY_LEFT_CONTROL))
			SceneManager::SwitchCurrScene(new LightForestScene);
		break;

	default:
		break;
	}
}
