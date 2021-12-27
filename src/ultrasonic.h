/***********************************************************************************
 *  @file       ultrasonic.h
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

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#define ULTRASONIC_DEBUG 0

#include "Arduino.h"

class Ultrasonic{
 public:
    /**
     * @param triggerPin  Digital pin that is used for controlling sensor (output).
     * @param echoPin  Digital pin that is used to get information from sensor (input).
     * @param maxDistanceCm  Maximum distance sensor can measure, defaults to 4m for HC-SR04.
     *                       You might want to set this value if you are using different sensor than HC-SR04
     *                       or if you don't care about distances larger than whatever you will set it to
     *                       (therefore reducing time it takes for a single measurement).
     * @param maxTimeoutMicroSec  Single measurement will never take longer than whatever value you provide here.
     *   You might want to do this in order to ensure your program is never blocked for longer than some specific time,
     *   since measurements are blocking.
     *   By default, there is no limit on time (only on distance). By defining timeout, you are again limiting the distance. 
     */
   void init(uint8_t triggerPin, uint8_t echoPin, unsigned short maxDistanceCm = 400, unsigned long maxTimeoutMicroSec = 0);

    /**
     * Measures distance by sending ultrasonic waves and measuring time it takes them
     * to return.
     * @returns Distance in centimeters, or negative value if distance is greater than 400cm.
     */
    float measureDistanceCm(float temperature = 25);
    
 private:
 
    uint8_t _triggerPin, _echoPin;
    unsigned short _maxDistanceCm;
    unsigned long _maxTimeoutMicroSec;
};

#endif // ULTRASONIC_H
