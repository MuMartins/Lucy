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
  
  if (ult01 > 10) {
    // Robô anda para frente se não houver nenhum obstáculo na frente do robô
    int ult01 = ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM);
    int ult02 = ultrasonic02.convert(ultrasonic02.timing(), Ultrasonic::CM);
    int ult03 = ultrasonic03.convert(ultrasonic03.timing(), Ultrasonic::CM);
    digitalWrite(IN_A1, HIGH);
    digitalWrite(IN_A2, LOW);
    digitalWrite(IN_B1, HIGH);
    digitalWrite(IN_B2, LOW);
    Serial.println("frente");
  }
  
  if (ult01 < 10) {
    // Se houver um obstáculo a menos de 10 cm do sensor da frente, irá verificar os outros sensores
    if (ult02 < 10) {
      // Se houver um obstáculo a menos de 10 cm do sensor da esquerda, o motor gira no sentido horário 
      int ult01 = ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM);
      int ult02 = ultrasonic02.convert(ultrasonic02.timing(), Ultrasonic::CM);
      int ult03 = ultrasonic03.convert(ultrasonic03.timing(), Ultrasonic::CM);
      digitalWrite(IN_A1, HIGH);
      digitalWrite(IN_A2, LOW);
      digitalWrite(IN_B1, LOW);
      digitalWrite(IN_B2, LOW);
    }
    if (ult03 < 10) {
      // Se houver um obstáculo a menos de 10 cm do sensor da direita, o motor gira no sentido anti-horário 
      int ult01 = ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM);
      int ult02 = ultrasonic02.convert(ultrasonic02.timing(), Ultrasonic::CM);
      int ult03 = ultrasonic03.convert(ultrasonic03.timing(), Ultrasonic::CM);
      digitalWrite(IN_A1, LOW);
      digitalWrite(IN_A2, LOW);
      digitalWrite(IN_B1, LOW);
      digitalWrite(IN_B2, HIGH);
    }

    if (ult02 < 10 && ult03 < 10) {
      // Se houver um obstáculo a menos de 10 cm do sensor da esquerda e da direita, todos os motores travam
      int ult01 = ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM);
      int ult02 = ultrasonic02.convert(ultrasonic02.timing(), Ultrasonic::CM);
      int ult03 = ultrasonic03.convert(ultrasonic03.timing(), Ultrasonic::CM);
      digitalWrite(IN_A1, LOW);
      digitalWrite(IN_A2, LOW);
      digitalWrite(IN_B1, LOW);
      digitalWrite(IN_B2, LOW);
    }

    else {
      // Se houver um obstáculo a menos de 10 cm apenas do sensor da frente, o motor gira no sentido horário 
      int ult01 = ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM);
      int ult02 = ultrasonic02.convert(ultrasonic02.timing(), Ultrasonic::CM);
      int ult03 = ultrasonic03.convert(ultrasonic03.timing(), Ultrasonic::CM);
      digitalWrite(IN_A1, HIGH);
      digitalWrite(IN_A2, LOW);
      digitalWrite(IN_B1, LOW);
      digitalWrite(IN_B2, LOW);
    }
  }

  if (ult02 < 5) {
    // Se houver um obstáculo a menos de 10 cm do sensor da esquerda, o motor gira no sentido horário 
    int ult01 = ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM);
    int ult02 = ultrasonic02.convert(ultrasonic02.timing(), Ultrasonic::CM);
    int ult03 = ultrasonic03.convert(ultrasonic03.timing(), Ultrasonic::CM);
    digitalWrite(IN_A1, HIGH);
    digitalWrite(IN_A2, LOW);
    digitalWrite(IN_B1, LOW);
    digitalWrite(IN_B2, LOW);
  }

  if (ult03 < 5) {
    // Se houver um obstáculo a menos de 10 cm do sensor da direita, o motor gira no sentido anti-horário 
    int ult01 = ultrasonic01.convert(ultrasonic01.timing(), Ultrasonic::CM);
    int ult02 = ultrasonic02.convert(ultrasonic02.timing(), Ultrasonic::CM);
    int ult03 = ultrasonic03.convert(ultrasonic03.timing(), Ultrasonic::CM);
    digitalWrite(IN_A1, LOW);
    digitalWrite(IN_A2, LOW);
    digitalWrite(IN_B1, LOW);
    digitalWrite(IN_B2, HIGH);
  }
}
