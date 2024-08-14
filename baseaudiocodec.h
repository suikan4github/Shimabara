/**
* \ file baseaudiocodec.h
* \brief header file for an abstract audio codec class
* \arthur SeiichiHorie
* \date 6/Apr/2016
*/

#ifndef _BaseAudioCodec_h_
#define _BaseAudioCodec_h_

#include "mbed.h"
/**
 \brief audio framework name space. 
*/
namespace shimabara 
{


        /**
         * \brief Sampling Frequency of the umb_adau1361
         */
    enum Fs_Type 
    {
        Fs_32,  ///< 32kHz
        Fs_441, ///< 44.1kHz
        Fs_48,  ///< 48kHz
        Fs_96   ///< 96kHz
    } ;


/**
* \brief abstract audio codec controller.
* \details
*   This class is template for all codec classes
*/
    class BaseAudioCodec
    {
    public:
            /**
            * \brief constructor.
            * \param Fs Sampling frequency.
            * \param Addr I2C device address. value range is from 0 to 127
            * \details
            *   initialize the internal variables.
            */
        BaseAudioCodec( Fs_Type Fs );
        
            /**
            * \brief Actual initializer. 
            * \details
            *   Initialize the codec itself and start the conversion process.
            *   and configure for given parameter. 
            *
            *   Finally, set the input gain to 0dB.
            */
        virtual void start(void)=0;
        
            /**
            * \brief Set the line input gain and enable the relevant mixer.
            * \param left_gain Gain by dB. The gain value outside of the acceptable range will be saturated.
            * \param right_gain Gain by dB. The gain value outside of the acceptable range will be saturated.
            * \param mute set true to mute
            */
        virtual void set_line_input_gain(float left_gain, float right_gain, bool mute=false);
            /**
            * \brief Set the aux input gain and enable the relevant mixer.
            * \param left_gain Gain by dB. The gain value outside of the acceptable range will be saturated.
            * \param right_gain Gain by dB. The gain value outside of the acceptable range will be saturated.
            * \param mute set true to mute
            */
        virtual void set_aux_input_gain(float left_gain, float right_gain, bool mute=false);
            /**
            * \brief Set the mic input gain and enable the relevant mixer.
            * \param left_gain Gain by dB. The gain value outside of the acceptable range will be saturated.
            * \param right_gain Gain by dB. The gain value outside of the acceptable range will be saturated.
            * \param mute set true to mute
            */
        virtual void set_mic_input_gain(float left_gain, float right_gain, bool mute=false);
            /**
            * \brief Set the line output gain and enable the relevant mixer.
            * \param left_gain Gain by dB. The gain value outside of the acceptable range will be saturated.
            * \param right_gain Gain by dB. The gain value outside of the acceptable range will be saturated.
            * \param mute set true to mute
            */
        virtual void set_line_output_gain(float left_gain, float right_gain, bool mute=false);
            /**
            * \brief Set the headphone output gain and enable the relevant mixer.
            * \param left_gain Gain by dB. The gain value outside of the acceptable range will be saturated.
            * \param right_gain Gain by dB. The gain value outside of the acceptable range will be saturated.
            * \param mute set true to mute
            */
        virtual void set_hp_output_gain(float left_gain, float right_gain, bool mute=false);
    protected:
        unsigned int addr;
        Fs_Type fs;
    };


}

#endif