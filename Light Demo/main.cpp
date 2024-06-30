#include <MOABEAttorney.h>
#include "LightDemoFunctions.h"

int CALLBACK WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nShowCmd);

	LightDemoFunctions demoFuncs;

	MOABE::SetUserFunctions(&demoFuncs);

	MOABEAttorney::Run(hInstance);

	return 0;
}
