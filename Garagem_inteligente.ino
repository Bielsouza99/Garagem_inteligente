#include <Ultrasonic.h>
#include <Servo.h>
#define pino_trigger 6
#define pino_echo 7
#define servo 5

#define fechado 0
#define aberto 90

Ultrasonic ultrasonic(pino_trigger, pino_echo); 
Servo s;
int pos;




void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");

  s.attach(servo);
  Serial.begin(9600);
  s.write(0);
}

void loop() {
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);

  Serial.print("Distância em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distância em polegadas:  ");
  Serial.println(inMsec);
  delay(200);

  if (cmMsec<=25){ 
    s.write(aberto);
  }
  else {
    s.write(fechado);
    }
  }


