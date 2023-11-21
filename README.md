# Sensor de Movimento e Motor de Passo

Este é meu primeiro projeto mexendo com [Sensor de detecção de moviento](https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-pir-detector-de-movimento) e [Motor de Passo](https://blog.moduloeletronica.com.br/controlando-um-motor-de-passo-com-o-arduino/).

Nesse projeto eu fiz com que, ao passar a mão ou qualquer coisa na frente do Sensor, o motor começava a girar.

## Desafios
  
Nesse projeto acredito que os desafios foram:
- Receber dadso do Sensor de Movimento
- ligar o motor e fazelo funcionar

## Aprendizados

Aprendi algumas coisas que poderam me ajudar em projetos mais a frente, como: Amaçador de latinhas, Abridor de porta e entre outros...


## Recebendo Valor do Sensor

```c++
...
int pinPIR = 9;

void setup() {
  ...
  pinMode(pinPIR, INPUT); // Iniciando o sensor.
  Serial.begin(9600); // para printar os valores recebidos.
}

void loop() {

  if(digitalRead(pinPIR)==HIGH) {

    Serial.println("Movimento");
    ...
  }else{
    Serial.println("---------");
  } 
  delay(200);

}
```
## ligando o motor comforme o Sensor indentifica.
```c++
#include <Stepper.h>
#define e1 2 // Definindo as entradas do motor
#define e2 3
#define e3 4
#define e4 5
const int passosPorGiro = 64; // Definindo os passos por giro (Pode variar de motor para motor)

Stepper stepper(passosPorGiro, e1, e3, e2, e4); // Criando meu Objeto do motor

int pinPIR = 9;

void setup() {
  stepper.setSpeed(500); // Definindo a Velocidade dele
  pinMode(pinPIR, INPUT);
  Serial.begin(9600);
}

void loop() {

  if(digitalRead(pinPIR)==HIGH) {

    Serial.println("Movimento");
    for(int i = 0; i < 32; i++) {
      stepper.step(-passosPorGiro); // Girando ele até completar um volta
    }
    
  }else{

    Serial.println("---------");
    
  } 
  delay(200);

}
```

# Resultado

[Veja o resultado!](https://youtu.be/WoGq_Idl4V4?si=cQout-rZncpziTMg).

## Autores

- [@Victor-Lis](https://github.com/Victor-Lis).
- [@iagoRRocha](https://github.com/iagoRRocha).
