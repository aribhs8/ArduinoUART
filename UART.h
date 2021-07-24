/*
  UART.h - Library for processing serial comm.
  Created by Arib Hussain, July 24, 2021.
*/

#ifndef UART_h
#define UART_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class UART
{
    String _readBuffer;
    boolean _endFlag;
    SoftwareSerial *_serial;

public:
    UART(const byte &rxPin, const byte &txPin);
    void init(const uint32_t &speed, boolean listen = false);
    void setToListen() const;
    void getData();
    void sendData(const String &msg) const;
    String getBuffer();
};

#endif