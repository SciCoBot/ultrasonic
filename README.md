# Arduino library for HC-SR04 ultrasonic distance sensor.

Esta biblioteca foi criada para controlar o HC-SR0, um sensor que consegue medir obstáculos entre 2 to 400cm.

![HC-SR04](https://github.com/SciCoBot/ultrasonic/blob/main/images/hcsr04.jpg)

## Modo de usar

Instancie um objeto da classe Ultrasonic e inicie-o:

```c
Ultrasonic ultrasonic;
ultrasonic.init(triggerPin, echoPin);
```
Onde triggerPin e echoPin são os pinos do ultrassônico. Por defalt a distância máxima é definida como 400 cm, se você precisa definir outro valor, ao iniciar faça como:

```c
UltraSonicDistanceSensor sensor(triggerPin, echoPin, maxDistanceCm);
```

Além disso, é possível definir o tempo maximo de medição (em micro secondos), por default esse valor é 0, mas ele pode ser defindo durante a inicialização:

```c
UltraSonicDistanceSensor sensor(triggerPin, echoPin, maxDistanceCm, absoluteTimeout);
```

Then, to measure the distance, you just call `measureDistanceCm()`, which will return distance in centimeters (double). If distance is larger than 400cm, it will return negative value.

The calculation assumes a temperature of around 20°C. For improved accuracy you may also provide a temperature yourself, either an average for your location or directly measured from another sensor. The call for a temperature of 3.5°C would as such look like this: `measureDistanceCm(3.5)`.

## Example

In this simple example, we need to connect sensors pins like this:

- vcc to 5V
- trig to digital pin 13
- echo to digital pin 12
- gnd to gnd

```c
#include <HCSR04.h>

// Initialize sensor that uses digital pins 13 and 12.
const byte triggerPin = 13;
const byte echoPin = 12;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    float distance = distanceSensor.measureDistanceCm();
    Serial.println(distance);
    delay(500);
}
```
