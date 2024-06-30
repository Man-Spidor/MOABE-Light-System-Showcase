#ifndef FOGDATA_H
#define FOGDATA_H

#include <Vect.h>

struct FogData 
{
	FogData() : FogStart(0.0f), FogRange((float)UINT_MAX), FogColor()
	{};

	float FogStart ;
	float FogRange;
	Vect FogColor;
};

#endif // FOGDATA_H