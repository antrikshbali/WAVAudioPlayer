//
//  SDLAudioDevice.cpp
//  AudioProject
//
//  Created by Antriksh Bali on 31/05/16.
//
//

#include "SDLAudioDevice.hpp"
#include "SDLWAVAudioData.hpp"

IAudioData* SDLAudioDevice::CreateAudioFromFile(const std::string& filePath)
{
    return new SDLWAVAudioData(filePath, false);
}

void SDLAudioDevice::ReleaseAudio(IAudioData* audioData)
{
    if(audioData)
    {
        delete audioData;
    }
}

