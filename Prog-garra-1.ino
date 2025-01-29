#include <Servo.h> 
#include <VarSpeedServo.h> 

Servo servo1; //cria um novo objeto servo

void setup (){

  pinMode(8, INPUT);// conecta o botão de abertura
  pinMode(10, INPUT); // conecta o botão de fechamento
  pinMode(2, INPUT);// conecta o botão de stop
  servo1.attach(9); //conecta o objeto servo1 ao pino 9
  
}//fim setup

void loop(){

  if (digitalRead(8) == HIGH){
  	servo1.write(180,20); // envia sinal para o servo fechar  com tempo 20
  }
  if (digitalRead(10) == HIGH){
 	  servo1.write(0,20); // envia sinal para o servo abrir com tempo 20
  }
  if (digitalRead (2) == HIGH) {
    servo1.stop();  // Para o servo na posição 
  }    
  delay(15); //aguarda movimento do servo
  
}