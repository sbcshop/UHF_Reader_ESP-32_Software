#ifndef UHF_H
#define UHF_H
#include <Arduino.h>
static byte container[1024]; //A buff container to contain received bytes

// Add here UHF commands in byte array format to configure, 
// refer Manual: https://github.com/sbcshop/UHF_Reader_ESP-32_Software/blob/main/documents/UHF%20Commands%20Manual.pdf
static byte HARDWARE_VERSION[]    = {0XBB,0X00,0X03,0X00,0X01,0X00,0X04,0X7E};
static byte MULTIPLE_READ[]   = {0XBB, 0X00, 0X27, 0X00, 0X03, 0X22, 0X27, 0X10, 0X83, 0X7E};
static byte SINGLE_READ[]     = {0XBB,0X00,0X22,0X00,0X00,0X22,0X7E};
static byte STOP_READ[]       = {0XBB,0X00,0X28,0X00,0X00,0X28,0X7E};

static String asciiVal;

void extractEPC(byte frm[], int le);
void frameParse(byte dataCom[], int lent);
#endif
