/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _UART_CLASS_
#define _UART_CLASS_

#include "HardwareSerial.h"



#define SERIAL_8N1 0
#define SERIAL_8E1 1
#define SERIAL_8O1 2
#define SERIAL_8M1 3
#define SERIAL_8S1 4



#define SERIAL_BUFFER_SIZE 128

class UARTClass : public HardwareSerial
{
  public:
    UARTClass(void);
    UARTClass( uint8_t uart_ch );
    void begin(const uint32_t baud_rate);
    void begin(const uint32_t buad_rate, uint8_t config);
    void end(void);
    int available(void);
    int availableForWrite(void);
    int peek(void);
    int read(void);
    void flush(void);
    virtual size_t write(uint8_t);
    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write; // pull in write(str) and write(buf, size) from Print

    operator bool() { return true; }; // UART always active

  protected:
    
    uint8_t uart_number;

};

#endif // _UART_CLASS_
