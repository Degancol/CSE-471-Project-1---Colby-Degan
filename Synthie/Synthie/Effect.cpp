#include "pch.h"
#include "Effect.h"

CEffect::CEffect(void) {}

CEffect::~CEffect(void) {}

void CEffect::Process(double* frameIn, double* frameOut)
{
	frameOut[0] = frameIn[0];
	frameOut[1] = frameIn[1];
}