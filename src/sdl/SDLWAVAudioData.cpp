//
//  SDLWAVAudioData.cpp
//  AudioProject
//
//  Created by Antriksh Bali on 31/05/16.
//
//

#include "SDLWAVAudioData.hpp"

SDLWAVAudioData::SDLWAVAudioData(const std::string& fileName, bool streamFromFile)
{
    //To Do - Handle streamFromFile
    SDL_AudioSpec wavSpec;
    Uint8* wavStart;
    Uint32 wavLength;
    
    if (SDL_LoadWAV(fileName.c_str(), &wavSpec, &wavStart, &wavLength)==NULL)
    {
        //To Do - Proper Error Handling
        throw fileName;
    }
    m_start = wavStart;
    m_pos = wavStart;
    m_end = (m_start + wavLength);
}

SDLWAVAudioData::~SDLWAVAudioData()
{
    SDL_FreeWAV(m_start);
}

size_t SDLWAVAudioData::GenerateSamples(float* stream, size_t streamLength, size_t pos, const SampleInfo& info)
{
    float pitch = (float)info.pitch; //pitch is pitch factor
    m_pos=(m_start + pos);

    if(m_pos >= m_end || m_pos < m_start)
    {
        return 0;
    }
    
    Uint32 lengthLeft = (Uint32)((m_end - m_pos)/pitch);
    Uint32 length = (Uint32)streamLength;
    length = (length > lengthLeft ? lengthLeft : length);
    
    //To Do - Make this more general
    Sint16* samples = (Sint16*)m_pos;
    float sampleIndex = 0;
    float factor = (float)info.volume*1.0f/32678.0f;
    for (Uint32 i = 0;i < length;i++)
    {
        stream[i]= (samples[size_t(sampleIndex)])*factor; //float* stream contains sample data
        sampleIndex += pitch;
    }
    
    // LP Filter to smooth out pitch shifts
    if(pitch != 1.0)
    {
     
        for(int j = 1;j < (length + 1); j++)
        {
            stream[j]= 0.5*stream[j] + 0.5*stream[j-1];
        }
    }
    
    m_pos = (Uint8*)(samples+(size_t)sampleIndex);
    return (size_t)(m_pos - m_start);
}

size_t SDLWAVAudioData::GetAudioLength()
{
    return (size_t)(m_end - m_start);
    
}

