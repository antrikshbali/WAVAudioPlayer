//
//  SDLAudioDevice.hpp
//  AudioProject
//
//  Created by Antriksh Bali on 31/05/16.
//
//

#ifndef SDLAudioDevice_hpp
#define SDLAudioDevice_hpp
#include "../IAudioDevice.hpp"

class SDLAudioDevice : public IAudioDevice
{
public:
    virtual IAudioData* CreateAudioFromFile(const std::string& filePath);
    virtual void ReleaseAudio(IAudioData* audiodata);
private:
    
};

#endif /* SDLAudioDevice_hpp */
