/*
PARA GIRAR O MOTOR NO SENTIDO HORARIO A ENTRADA 1 DEVE ESTAR HIGH ENQUANTO A ENTRADA 2 DEVE ESTAR LOW
PARA GIRAR O MOTOR NO SENTIDO ANTI-HORARIO A ENTRADA 1 DEVE ESTAR LOW ENQUANTO A ENTRADA 2 DEVE ESTAR HIGH
PARA TRAVAR O MOTOR AS DUAS ENTRADAS DEVEM ESTAR LOW
PARA FREIAR O MOTOR AS DUAS ENRTADAS DEVEM ESTAR HIGH
*/

// Adicionando a biblioteca do sensor ultrassônico
#include <Ultrasonic.h>

// Definindo os sensores ultrassônicos
Ultrasonic ultrasonic01(10, 9);
Ultrasonic ultrasonic02(8, 7);
Ultrasonic ultrasonic03(6, 5);

// Definindo portas dos motores A e B 
int IN_A1 = 11;
int IN_A2 = 12;
int IN_B1 = 3;
int IN_B2 = 4;

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
  int ult01 = ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM);
  int ult02 = ultrasonic02.convert(ultrasonic02.timing(), Ultrasonic::CM);
  int ult03 = ultrasonic03.convert(ultrasonic03.timing(), Ultrasonic::CM);

  /*
  Serial.print("ULT 01: ");
  Serial.println(ult01);
  Serial.print("ULT 02: ");
  Serial.println(ult02);
  Serial.print("ULT 03: ");
  Serial.println(ult03);
  */
  
  if (ult01 > 10) {
    // Robô anda para frente se não houver nenhum obstáculo na frente do robô
    int ult01 = ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM);
    digitalWrite(IN_A1, HIGH);
    digitalWrite(IN_A2, LOW);
    digitalWrite(IN_B1, HIGH);
    digitalWrite(IN_B2, LOW);
    Serial.println("frente");
  }
  if (ult01 < 10) {
    if (ult02 < 10) {
      int ult01 = ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM);
      int ult02 = ultrasonic02.convert(ultrasonic02.timing(), Ultrasonic::CM);
      digitalWrite(IN_A1, HIGH);
      digitalWrite(IN_A2, LOW);
      digitalWrite(IN_B1, LOW);
      digitalWrite(IN_B2, LOW);
      Serial.println("entrei no 1");
    }
    if (ult03 < 10) {
      int ult01 = ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM);
      int ult03 = ultrasonic03.convert(ultrasonic03.timing(), Ultrasonic::CM);
      digitalWrite(IN_A1, LOW);
      digitalWrite(IN_A2, LOW);
      digitalWrite(IN_B1, LOW);
      digitalWrite(IN_B2, HIGH);
      Serial.println("entrei no 2");
    }
  }
}
