# Biblioteca para sensor ultrassônico e Arduino Due
[![platform badge](https://img.shields.io/badge/platform-Arduino-orange.svg)](https://github.com/arduino)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/SciCoBot/led_debug/blob/main/LICENSE)

## Contents

- [Sobre](#sobre)
- [Comandos Básicos](#comandos-básicos)
- [Modo de Usar](#modo-de-usar)
- [Como Utilizar](#como-utilizar)
- [Implementaçõs Futuras](#implementaçõs-futuras)

## Sobre

Esta biblioteca foi criada para controlar o HC-SR4, um sensor que consegue medir obstáculos entre 2 to 400cm.

<p align="center">
  <img src="https://github.com/SciCoBot/ultrasonic/blob/main/images/hcsr04.png"/ height="200" width="350">
</p>

Nota: inspirado em [arduino-lib-hc-sr04](https://github.com/Martinsos/arduino-lib-hc-sr04).

## Comandos Básicos
### Definições

- **ULTRASONIC_DEBUG:** utilizado para habilitar ou desabilitar mensagens debug padrão. Utilize 1 para habilitar. Por default é igual a 0.

### Funções:

- **Ultrasonic::init():** um objeto deve primeiro ser iniciado para o correto funcionamento da biblioteca. Esta função seta os valores iniciais das variáveis de classe.
- **Ultrasonic::measureDistanceCm():** mede e retorna a distância em centimetros, usando, por default, temperatura igual a 25 graus celsius

## Modo de Usar

Instancie um objeto da classe Ultrasonic e inicie-o:

```c
Ultrasonic ultrasonic;
ultrasonic.init(triggerPin, echoPin);
```
Onde triggerPin e echoPin são os pinos do ultrassônico, conectados no Due. Por defalt, a distância máxima é definida como 400 cm, se você precisa definir outro valor, ao iniciar faça como:

```c
UltraSonicDistanceSensor sensor(triggerPin, echoPin, maxDistanceCm);
```

Além disso, é possível definir o tempo maximo de medição (em micro secondos), por default esse valor é 0, mas ele pode ser defindo durante a inicialização:

```c
UltraSonicDistanceSensor sensor(triggerPin, echoPin, maxDistanceCm, absoluteTimeout);
```

Então, para medir a distância, basta chamar:
```c
ultrasonic.measureDistanceCm()
```
Se a distância retornada for maior que 400 cm, retornará -1.

## Como Utilizar

- Baixe.
- Adicione a partir da IDE arduino: Sketch -> Include Library -> Add .ZIP Library... -> selecione o arquivo baixado na etapa anterior.
- Teste o exemplo.

## Implementaçõs Futuras
