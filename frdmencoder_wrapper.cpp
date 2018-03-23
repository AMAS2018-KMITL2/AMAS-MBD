#include "mbed.h"
#include "frdmencoder_wrapper.h"

uint32_t Pps = 0;
uint32_t Pulse = 0;
uint32_t *temp;


extern "C" void kl25z_Encoder_Init(uint8_T channel)
{
    InterruptIn encoder(PTD5);
    encoder.rise(&Interrupt); 
}


extern "C" void kl25z_Encoder_Read(void *pps, void *pulses)
{
    temp = (uint32*)pps;
    Pps = temp;
    pps = 0;
    
    temp = (uint32*)pulse;
    Pulse = temp;
}


extern "C" void kl25z_Encoder_Terminate(void)
{
    
}