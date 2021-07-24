/*
  UART.cpp - Library for processing serial comm.
  Created by Arib Hussain, July 24, 2021.
*/

#include "Arduino.h"
#include "UART.h"

UART::UART(const byte &rxPin, const byte &txPin)
{
    _readBuffer = "";
    _endFlag = false;
    _serial = new SoftwareSerial(rxPin, txPin);
}

void UART::init(const uint32_t &speed, boolean listen)
{
    _readBuffer.reserve(82);
    _serial->begin(speed);
    if (listen)
    {
        _serial->listen();
    }
}

void UART::setToListen() const
{
    _serial->listen();
}

void UART::getData()
{
    while (_serial->available())
    {
        byte byteIn = _serial->read();
        _readBuffer += char(byteIn);
        if (byteIn == '\n')
        {
            _endFlag = true;
        }
    }
}

void UART::sendData(const String &msg) const
{
    _serial->println(msg);
}

String UART::getBuffer()
{
    if (_endFlag)
    {
        String dupl = _readBuffer;
        _readBuffer = "";
        _endFlag = false;

        return dupl;
    }

    return "";
}
