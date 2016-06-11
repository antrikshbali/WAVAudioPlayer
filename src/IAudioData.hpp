//
//  IAudioData.hpp
//  AudioProject
//
//  Created by Antriksh Bali on 31/05/16.
//
//

#ifndef IAudioData_hpp
#define IAudioData_hpp
#include "SampleInfo.hpp"
#include <cstddef>

class IAudioData
{
public: virtual ~IAudioData() {}
    virtual size_t GenerateSamples(float* stream, size_t streamLength, size_t pos, const SampleInfo& info) = 0;
    virtual size_t GetAudioLength() = 0;
private:
};

#endif /* IAudioData_hpp */
