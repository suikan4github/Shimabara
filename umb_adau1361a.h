/*
* \brief header file for the UMB-ADAU1361A codec board controler
* \arthur SeiichiHorie
* \date 8/May/2016
*/

#ifndef _UMB_ADAU1361A_H_
#define _UMB_ADAU1361A_H_

#include "adau1361.h"
#include "mbed.h"
/**
 \brief audio framework name space. 
*/
namespace shimabara 
{


/**
* \brief UMB-ADAU1361-A audio codec board controller.
* \details
*   This class send a set of command to control an UMB-ADAU1361-A codec board.
*
*   The hardware desription is here. http://dsps.shop-pro.jp/?pid=82798273

      
      example :
      \code
#include "unzen.h"          // audio framework include file
#include "umb_adau1361a.h"     // audio codec contoler include file
#include "mbed.h"

#define CODEC_I2C_ADDR 0x38

DigitalOut myled1(LED1);


    // customer signal processing initialization call back.
void init_callback(
            unsigned int block_size     // block size [sample]
            )
{
        // place initialization code here
}


    // customer signal processing call back.
void process_callback(
            float rx_left_buffer[],     // array of the left input samples
            float rx_right_buffer[],    // array of the right input samples
            float tx_left_buffer[],     // place to write the left output samples
            float tx_right_buffer[],    // place to write the left output samples
            unsigned int block_size     // block size [sample]
            )
{
        // Sample processing
    for ( int i=0; i<block_size; i++)   // for all sample
    {
        tx_left_buffer[i] = rx_left_buffer[i];      // copy from input to output
        tx_right_buffer[i] = rx_right_buffer[i];
        
    }
}



int main() 
{    
        // I2C is essential to talk with ADAU1361
    I2C i2c(SDA, SCL);

        // create an audio codec contoler
    shimabara::UMB_ADAU1361A codec(shimabara::Fs_32, i2c, CODEC_I2C_ADDR ); 
//    shimabara::UMB_ADAU1361A codec(shimabara::Fs_441, i2c, CODEC_I2C_ADDR ); 
//    shimabara::UMB_ADAU1361A codec(shimabara::Fs_48, i2c, CODEC_I2C_ADDR ); 
//    shimabara::UMB_ADAU1361A codec(shimabara::Fs_96, i2c, CODEC_I2C_ADDR ); 

       // create an audio framework by singlton pattern
    unzen::Framework audio;
 
         // Set I3C clock to 10kHz
    i2c.frequency( 10000 );


        // Configure the optional block size of signal processing. By default, it is 1[Sample] 
//    audio.set_block_size(16);

    
        // Start the ADAU1361. Audio codec starts to generate the I2C signals 
    codec.start();

        // Start the audio framework on ARM processor.  
    audio.start( init_callback, process_callback);     // path the initializaiton and process call back to framework 


        // periodically changing gain for test
    while(1)     
    {
        for ( int i=-15; i<4; i++ )
        {
            codec.set_hp_output_gain( i, i );
            codec.set_line_output_gain( i, i );
            myled1 = 1;
            wait(0.2);
            myled1 = 0;
            wait(0.2);
        }
    }
}


      \endcode
*/
    class UMB_ADAU1361A:public Adau1361
    {
    public:
            /**
            * \brief constructor.
            * \param controler Pass the I2C controler object.
            * \param Fs Sampling frequency.
            * \param Addr I2C device address. value range is from 0 to 127
            * \details
            *   initialize the internal variables.
            */
        UMB_ADAU1361A( Fs_Type Fs, I2C &controler, unsigned int Addr ):
            Adau1361( Fs, controler, Addr  ){};
    protected:
            /**
            * \brief configuration of the PLL for the desired Fs.
            * \details
            *   Configure the PLL based on the given Fs and hardware clock configuration. 
            *   Fs is stored in fs member variable already. Hadrware clock have to be given
            *   from the circuit designer. For the UMB-ADAU1361-A, the clock is external 
            *   12MHz oscillator from the clock input. 
            */
        virtual void configure_pll(void);
            /**
            * \brief configuration of the the codec for UMB-ADAU1361-A
            * \details
            *   Configure Internal signal pass and parameters for UMB-ADAU1361.  
            *   The all pass-through signals are shut off. All cross channel signals are shut off. 
            *   Monoral output is disabled. 
            */
        virtual void configure_board(void);
    };

}

#endif