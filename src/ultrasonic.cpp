/***********************************************************************************
 *  @file       ultrasonic.cpp
 *  Project     ultrassonic
 *  @brief      Arduino Due library for SR04 ultrasonic.
 *
 * It is inspired by arduino-lib-hc-sr04 (https://github.com/SciCoBot/arduino-lib-hc-sr04).
 *
 *  @author     Otávio Augusto Rocha da Cruz
 *  @bug 		 No known bugs.
 *  License     MIT
 *
 *  @section License
 *
 * Copyright (c) 2021 SciCoBot
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**********************************************************************************/

#include "ultrasonic.h"
#include "serial_debug/src/serial_debug.h"

void Ultrasonic::init(uint8_t triggerPin, uint8_t echoPin, unsigned short maxDistanceCm, unsigned long maxTimeoutMicroSec) 
{
    _triggerPin = triggerPin;
    _echoPin = echoPin;
    _maxDistanceCm = maxDistanceCm;
    _maxTimeoutMicroSec = maxTimeoutMicroSec;
    
    pinMode(_triggerPin, OUTPUT);
    pinMode(_echoPin, INPUT);
    
    #if ULTRASONIC_DEBUG == 1
    	DEBUGLN("Init ultrasonic sucess");
    #endif
}

float Ultrasonic::measureDistanceCm(float temperature) 
{
    unsigned long maxDistanceDurationMicroSec;
    
	 // The approximate speed of sound in dry (0% humidity) air at temperatures near 0 °C
	 float speedOfSoundInCmPerMicroSec = 0.03313 + 0.0000606 * temperature; 
	 
	 // Compute max delay based on max distance with 10% margin in microseconds
    maxDistanceDurationMicroSec =  1.10 * (_maxDistanceCm / speedOfSoundInCmPerMicroSec);
    if (_maxTimeoutMicroSec > 0) {
    	maxDistanceDurationMicroSec = min(maxDistanceDurationMicroSec, _maxTimeoutMicroSec);
    }
    digitalWrite(_triggerPin, LOW);
    delayMicroseconds(2);
    // Hold trigger for 10 microseconds, which is signal for sensor to measure distance.
    digitalWrite(_triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_triggerPin, LOW);

    // Measure the length of echo signal, which is equal to the time needed for sound to go there and back.
    unsigned long durationMicroSec = pulseIn(_echoPin, HIGH, maxDistanceDurationMicroSec); 

    float distanceCm = durationMicroSec / 2.0 * speedOfSoundInCmPerMicroSec;
    
    #if ULTRASONIC_DEBUG == 1
    	DEBUG("distanceCm = ");
    	DEBUGLN(distanceCm);
    #endif
    
    if (distanceCm == 0 || distanceCm > _maxDistanceCm || distanceCm < 0) {
        return -1.0 ;
    } else {
        return distanceCm;
    }
}
