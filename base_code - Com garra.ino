
#include <VarSpeedServo.h> 
#include <Servo.h> 

VarSpeedServo servo1; //cria um novo objeto servo

void setup() {
  // Inicializa a transferência de dados com o computador, 9600 Bytes/s
  Serial.begin(9600);
  servo1.attach(9); //conecta o objeto servo1 ao pino 9

}

void loop() {
  // "Serial" são as portas Rx Tx do Arduino
  if (Serial.available() > 0) {
    char value = Serial.read();
    Serial.println(value);

    if (value == 'U') {
      Forward();
    } else if (value == 'D') {
      Backward();
    } else if (value == 'S') {
      Stop();
    } else if (value == 'L') {
      Left();
    } else if (value == 'R') {
      Right();
    } else if (value == 'P') {
      Open();
    } else if (value == 'O') {
      Close();
    }
  }
}

// COMANDOS GARRA

void Open() {
  delay(15); // aguarda para executar o comando para evitar duplo click
  servo1.write(180,20,false); // envia sinal para o servo abrir  com tempo 20, false para sobrepor caso seja enviado outro comando
  if (value == 'X') {
    servo1.stop();  // Para o servo na posição 
  }
}
void Close(value) {
  delay(15); // aguarda para executar o comando para evitar duplo click
  servo1.write(0,20,false); // envia sinal para o servo fechar com tempo 20, false para sobrepor caso seja enviado outro comando
  if (value == 'X') {
    servo1.stop();  // Para o servo na posição 
  }
}

// COMANDOS RODAS

void Forward() {
  // Roda direita
  analogWrite(5, 150);
  digitalWrite(6, LOW);
  // Roda esquerda
  analogWrite(9, 150);
  digitalWrite(10, LOW);
}
void Backward() {
  analogWrite(6, 150);
  digitalWrite(5, LOW);
  analogWrite(10, 150);
  digitalWrite(9, LOW);
}
void Stop() {
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}
void Left() {
  analogWrite(5, 120);
  digitalWrite(6, LOW);
  analogWrite(10, 120);
  digitalWrite(9, LOW);
}
void Right() {
  analogWrite(6, 120);
  digitalWrite(5, LOW);
  analogWrite(9, 120);
  digitalWrite(10, LOW);
}
