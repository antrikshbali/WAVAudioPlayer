//
//  IAudioDevice.hpp
//  AudioProject
//
//  Created by Antriksh Bali on 31/05/16.
//
//

#ifndef IAudioDevice_hpp
#define IAudioDevice_hpp
#include <string>
#include "IAudioData.hpp"

class IAudioDevice
{
public:
    virtual ~IAudioDevice() {}
    virtual IAudioData* CreateAudioFromFile(const std::string& filePath) = 0;
    virtual void ReleaseAudio(IAudioData* audiodata) = 0;
private:
    
};

#endif /* IAudioDevice_hpp */
