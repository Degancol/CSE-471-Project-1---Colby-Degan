#pragma once
#include "Instrument.h"
#include "AdditiveSineWave.h"

class CAdditiveSynthesizer :
    public CInstrument
{
public:
	CAdditiveSynthesizer(void);
	virtual ~CAdditiveSynthesizer(void);
public:
	virtual void Start();
	virtual bool Generate();

	void SetFreq(double f) { m_sinewave.SetFreq(f); }
	void SetAmplitude(double& a) { m_sinewave.SetAmplitude(a); }
	void SetDuration(double d) { m_duration = d * (60 / GetBPM()); }

	void SetCrossFadeIn(double d) { m_attack = d * (60 / GetBPM()); }
	void SetCrossFadeOut(double d) { m_release = d * (60 / GetBPM()); }

	virtual void SetNote(CNote* note);

private:
	CAdditiveSineWave   m_sinewave;

	double m_duration;
	double m_time;

	double m_attack;
	double m_decay;
	double m_sustain;
	double m_release;

	double m_crossFadeIn;
	double m_crossFadeOut;
};

