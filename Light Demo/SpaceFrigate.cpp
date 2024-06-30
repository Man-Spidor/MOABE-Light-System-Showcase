#include "SpaceFrigate.h"

#include <TimeManager.h>
#include <ModelManager.h>
#include <TextureManager.h>
#include <SceneManager.h>		// NEED TO INCLUDE SCENEMANAGER IN EVERY COLLIDABLE CLASS

#include <Colors.h>
#include <Visualizer.h>

// Constant Global Variables to define some consts
const Vect CamLookOffset = Vect(0.0f, 75.0f, -225.0f);
const Vect CamPosOffset = Vect(0.0f, 50.0f, -100.0f);
const Vect UpVect = Vect(0.0f, 1.0f, 0.0f);

SpaceFrigate::SpaceFrigate() :
	FrigateCam(),
	RotTrans(TRANS, 0.0f, 20.0f, 0.0f),
	pGO(new GraphicsObject_TextureLight(ModelManager::Get("Frigate")))
{
	FrigateCam.setPerspective(MATH_PI8, 16.0f / 9.0f, 1.0f, 5000.0f);
	FrigateCam.setOrientAndPosition(UpVect, CamLookOffset * this->RotTrans, CamPosOffset * this->RotTrans);

	this->pGO->SetTexture(TextureManager::Get("Frigate"));
	this->pGO->SetMaterial(0.3f * Colors::Gray, 0.3f * Colors::Gray, 0.3f * Vect(1.0f, 1.0f, 1.0f));

	Collidable::SetCollidableGroup<SpaceFrigate>();

	// Three Different Collidable Models To Choose From
	
	// Collidable::SetBSphereModel(this->pGO->GetModel());
	// Collidable::SetAABBModel(this->pGO->GetModel());
	Collidable::SetOBBModel(this->pGO->GetModel());
}

SpaceFrigate::~SpaceFrigate()
{
	delete this->pGO;
}

void SpaceFrigate::Initialize()
{
	// Used to Mark the Camera's Position
	// Comment out if not doing so
	Visualizer::Activate(VisualizeMode::DRAW_MARKERS);

	Inputable::RegisterKeyToScene(JAZUL_KEY::KEY_Q, EventType::KEY_PRESS);
	Inputable::RegisterKeyToScene(JAZUL_KEY::KEY_E, EventType::KEY_PRESS);
	
	// Keys To Control Light Culling
	Inputable::RegisterKeyToScene(JAZUL_KEY::KEY_1, EventType::KEY_PRESS);
	Inputable::RegisterKeyToScene(JAZUL_KEY::KEY_2, EventType::KEY_PRESS);
	Inputable::RegisterKeyToScene(JAZUL_KEY::KEY_3, EventType::KEY_PRESS);

	Updatable::RegisterToScene();
	Drawable::RegisterToScene3D();

	Collidable::RegisterToScene();
}

void SpaceFrigate::Update()
{
	//* Draw A Point To Visualize The Cameras Position
	
	Vect CamPos;
	this->FrigateCam.getPos(CamPos);
	Visualizer::ShowMarkerLineSegment(this->RotTrans.get(ROW_3), CamPos, Colors::Purple);

	//*/

	const float speed = MOVE_SPEED * TimeManager::GetFrameTime();
	const float rot_angle = ROT_ANGLE * TimeManager::GetFrameTime();

	if (Keyboard::GetKeyState(JAZUL_KEY::KEY_W)) {
		this->RotTrans = Matrix(TRANS, 0.0f, 0.0f, speed) * this->RotTrans;
	}
	else if (Keyboard::GetKeyState(JAZUL_KEY::KEY_S)) {
		this->RotTrans = Matrix(TRANS, 0.0f, 0.0f, -speed) * this->RotTrans;
	}

	if (Keyboard::GetKeyState(JAZUL_KEY::KEY_D)) {
		this->RotTrans = Matrix(ROT_Y, -rot_angle) * this->RotTrans;
	}
	else if (Keyboard::GetKeyState(JAZUL_KEY::KEY_A)) {
		this->RotTrans = Matrix(ROT_Y, rot_angle) * this->RotTrans;
	}

	Matrix world = this->RotTrans;
	this->pGO->SetWorld(world);

	SceneManager::SetCurrCamera3D(&this->FrigateCam);
	SceneManager::GetCurrScene().SetCurrCameraPos(Vect(0, 1, 0), CamLookOffset * this->RotTrans, CamPosOffset * this->RotTrans);
	SceneManager::GetCurrScene().UpdateCurrCamera();
	
	Collidable::UpdateCollisionData(world);		// Need to update collision data every frame if the game object is not static
}

void SpaceFrigate::Draw3D()
{
	this->pGO->Render();
}

void SpaceFrigate::KeyPressed(JAZUL_KEY key)
{
	static const float MinRenderDist = 750.0f;

	switch (key) {
	case JAZUL_KEY::KEY_Q:
		SceneManager::SwitchDebugMode();
		break;
	case JAZUL_KEY::KEY_E:
		SceneManager::SwitchPlayMode();
		break;
	case JAZUL_KEY::KEY_1:
		SceneManager::GetCurrScene().SetLightModeNormal();
		break;
	case JAZUL_KEY::KEY_2:
		SceneManager::GetCurrScene().SetLightModeCullByDist(MinRenderDist);
		break;
	case JAZUL_KEY::KEY_3:
		SceneManager::GetCurrScene().SetLightModeCullByView(MinRenderDist * 2.0f);
		break;

	default:
		break;
	}
}

void SpaceFrigate::Collision(Tree* pTree)
{
	UNREFERENCED_PARAMETER(pTree);

	Trace::out("I am a frigate and I am colliding with a tree!!\n");
}
