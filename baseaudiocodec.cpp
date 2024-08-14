
#include "baseaudiocodec.h"

namespace shimabara 
{
    
    BaseAudioCodec::BaseAudioCodec( Fs_Type Fs )
    {
        fs = Fs;
    } 

    void BaseAudioCodec::set_line_input_gain(float left_gain, float right_gain, bool mute)
    {
    }
    
    void BaseAudioCodec::set_aux_input_gain(float left_gain, float right_gain, bool mute)
    {
    }
    
    void BaseAudioCodec::set_mic_input_gain(float left_gain, float right_gain, bool mute)
    {
    }
    
    void BaseAudioCodec::set_line_output_gain(float left_gain, float right_gain, bool mute)
    {
    }
    
    void BaseAudioCodec::set_hp_output_gain(float left_gain, float right_gain, bool mute)
    {
    }
    
 

}