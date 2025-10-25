#include "pch.h"
#include "AdditiveSineWave.h"

CAdditiveSineWave::CAdditiveSineWave(void)
{
    m_freq = 440.0;
    m_amplitude = 0.5;

    for (int i = 0; i < 8; i++)
    {
        m_amp[i] = 0.1;
    }

    m_vibratoRate = 0.0;
    m_vibratoFreq = 0.0;

    m_time = 0.0;
    m_sineRadians = 0.0;
    m_vibratoRadians = 0.0;
}

CAdditiveSineWave::~CAdditiveSineWave(void)
{
}

void CAdditiveSineWave::Start()
{
    m_time = 0.0;
    m_sineRadians = 0.0;
    m_vibratoRadians = 0.0;
}

bool CAdditiveSineWave::Generate()
{
    double tailTime = 0.005;

    if (m_time >= m_duration + tailTime)
    {
        return false;
    }

    double sample = 0.0;

    for (int n = 1; n <= 8; n++)
    {
        if (n * m_freq > 22050.0)
        {
            break;
        }

        sample += m_amplitude * m_amp[n - 1] * sin(m_sineRadians * n);
    }

    m_vibratoRadians += (2 * PI * m_vibratoRate) / GetSampleRate();
    m_sineRadians += (2 * PI * (m_freq + (m_vibratoFreq * sin(m_vibratoRadians)))) / GetSampleRate();

    if (m_time < 0.005)
    {
        sample *= m_time / 0.005;
    }

    if (m_time > m_duration)
    {
        double fade = 1.0 - ((m_time - m_duration) / tailTime);

        if (fade < 0.0)
        {
            fade = 0.0;
        }

        sample *= fade;
    }

    m_frame[0] = sample;
    m_frame[1] = sample;

    m_time += GetSamplePeriod();

    if (m_time >= m_duration + tailTime)
    {
        m_frame[0] = 0.0;
        m_frame[1] = 0.0;

        return false;
    }

    return true;
}