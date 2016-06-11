//
//  AudioObject.hpp
//  AudioProject
//
//  Created by Antriksh Bali on 31/05/16.
//
//
#include "IAudioData.hpp"
#include "SampleInfo.hpp"

#ifndef AudioObject_hpp
#define AudioObject_hpp
class AudioObject
{
public:
    AudioObject(const SampleInfo& info, IAudioData* data);
    bool GenerateSamples(float* stream, size_t streamLength);
    void setPos(double pos);
    
private:
    size_t m_audioPos;
    size_t m_audioLength;
    SampleInfo m_sampleInfo;
    IAudioData* m_audioData;
    size_t PosToAbsolutePos(double pos);
    
};

#endif /* AudioObject_hpp */
