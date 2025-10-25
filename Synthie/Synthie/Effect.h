#pragma once
class CEffect
{
public:
	CEffect(void);
	~CEffect(void);

	void Process(double* frameIn, double* frameOut);
};

