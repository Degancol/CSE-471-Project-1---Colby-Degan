#pragma once
#include "AudioNode.h"
class CAR :
    public CAudioNode
{
public:
    CAR();
    ~CAR();
    void Start();
    bool Generate();
    void SetSource(CAudioNode* source) { m_source = source; }
    void SetDuration(double duration) { m_duration = duration; }
private:
    double m_attack;
    double m_release;
    double m_duration;
    double m_time;
    CAudioNode* m_source;
};

