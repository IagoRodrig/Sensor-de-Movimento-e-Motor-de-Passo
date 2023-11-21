#include <Stepper.h>

#define e1 2
#define e2 3
#define e3 4
#define e4 5

const int passosPorGiro = 64;

Stepper stepper(passosPorGiro, e1, e3, e2, e4);

int pinPIR = 9;

void setup() {
  stepper.setSpeed(500);
  pinMode(pinPIR, INPUT);
  Serial.begin(9600);
}

void loop() {

  if(digitalRead(pinPIR)==HIGH) {

    Serial.println("Movimento");
    for(int i = 0; i < 32; i++) {
      stepper.step(-passosPorGiro);
    }
    
  }else{

    Serial.println("---------");
    
  } 
  delay(200);

}
