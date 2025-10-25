#pragma once
#include "AudioNode.h"
#include "Note.h"
class CInstrument :
    public CAudioNode
{
public:
    CInstrument();
    virtual ~CInstrument(void);
    virtual void SetNote(CNote* note) = 0;
};

