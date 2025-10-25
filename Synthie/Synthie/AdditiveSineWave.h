#pragma once
#include "AudioNode.h"
#include <cmath>

class CAdditiveSineWave :
    public CAudioNode
{
public:
    CAdditiveSineWave(void);
    ~CAdditiveSineWave(void);

    virtual void Start();

    virtual bool Generate();

    void SetFreq(double f) { m_freq = f; }

    void SetAmplitude(double& a) { memcpy(&m_amp, &a, sizeof(double) * 8); }

    void SetVibratoRate(double d) { m_vibratoRate = d; }

    void SetVibratoFreq(double d) { m_vibratoFreq = d; }

    void SetDuration(double d) { m_duration = d; }

private:
    double m_freq;
    double m_duration;
    double m_amp[8];
    double m_amplitude;

    double m_time;

    double m_vibratoRate;
    double m_vibratoFreq;

    double m_sineRadians;
    double m_vibratoRadians;
};

