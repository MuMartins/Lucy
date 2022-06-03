/*
PARA GIRAR O MOTOR NO SENTIDO HORARIO A ENTRADA 1 DEVE ESTAR HIGH ENQUANTO A ENTRADA 2 DEVE ESTAR LOW
PARA GIRAR O MOTOR NO SENTIDO ANTI-HORARIO A ENTRADA 1 DEVE ESTAR LOW ENQUANTO A ENTRADA 2 DEVE ESTAR HIGH
PARA TRAVAR O MOTOR AS DUAS ENTRADAS DEVEM ESTAR LOW
PARA FREIAR O MOTOR AS DUAS ENRTADAS DEVEM ESTAR HIGH
*/
// Adicionando a biblioteca do sensor ultrassônico
#include <Ultrasonic.h>

// Definindo os sensores ultrassônicos
Ultrasonic ultrasonic01(13, 12);
Ultrasonic ultrasonic02(11, 10);
Ultrasonic ultrasonic03(9, 8);

// Definindo portas dos motores A e B 
int IN_A1 = 4;
int IN_A2 = 5;
int IN_B1 = 6;
int IN_B2 = 7;

void setup() {
  // Inicia a porta serial
  Serial.begin(9600);

  // Define pinos dos motores
  pinMode(IN_A1, OUTPUT);
  pinMode(IN_A2, OUTPUT);
  pinMode(IN_B1, OUTPUT);
  pinMode(IN_B2, OUTPUT);
}

void loop() {
  // https://www.arduino.cc/reference/pt/language/structure/control-structure/dowhile/
  do {
    digitalWrite(IN_A1, HIGH);
    digitalWrite(IN_A2, LOW);
    digitalWrite(IN_B1, LOW);
    digitalWrite(IN_B2, LOW);
  } while (ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM) <= 10);
}
