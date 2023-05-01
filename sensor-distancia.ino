// Sensor de distancia
//definindo as entradas
const int trigger = 8;
const int echo = 7;
const int ledG = 13;
const int ledY = 12;
const int ledR = 11;
const int buz = 9;

float dist = 0;

void setup(){
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(ledG,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(buz,OUTPUT);
  digitalWrite(buz,LOW);
}

void loop(){
  digitalWrite(trigger,LOW);
  delayMicroseconds(5);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  
  dist=pulseIn(echo,HIGH);
  dist = dist/58;
  Serial.print("Distancia = ");
  Serial.print(dist);
  Serial.print(" cm");
  Serial.write(10);
  delay(200);
        
  //definindo os valores de distância
  if(dist < 40)
  {
    digitalWrite(ledR,HIGH);
    digitalWrite(ledY,LOW);
    digitalWrite(ledG,LOW);
    digitalWrite(buz,HIGH);
  }
  else if(dist < 50)
  {
    digitalWrite(ledR,LOW);
    digitalWrite(ledY,HIGH);
    digitalWrite(ledG,LOW);
    digitalWrite(buz,LOW);
  }
  else
  {
    digitalWrite(ledY,LOW);
    digitalWrite(ledR,LOW);
    digitalWrite(ledG,HIGH);
    digitalWrite(buz,LOW);
  } 
}
