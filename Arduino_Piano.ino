//Arduino Piano

#define T_P 220
#define T_C 262
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 493
#define T_BB 520
#define T_CC 550

const int P = 12;
const int C = 10;
const int D = 9;
const int E = 8;
const int F = 7;
const int G = 6;
const int A = 5;
const int B = 4;
const int BB = 3;
const int CC = 2;

const int Buzz = 11;
const int LED = 13;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(P, INPUT); digitalWrite(P,HIGH);
  pinMode(C, INPUT); digitalWrite(C,HIGH);
  pinMode(D, INPUT); digitalWrite(D,HIGH);
  pinMode(E, INPUT); digitalWrite(E,HIGH);
  pinMode(F, INPUT); digitalWrite(F,HIGH);
  pinMode(G, INPUT); digitalWrite(G,HIGH);
  pinMode(A, INPUT); digitalWrite(A,HIGH);
  pinMode(B, INPUT); digitalWrite(B,HIGH);
  pinMode(BB, INPUT); digitalWrite(BB,HIGH);
  pinMode(CC, INPUT); digitalWrite(CC,HIGH);
  digitalWrite(LED,LOW);
  Serial.begin(9600);
}

void loop()
{
    while(digitalRead(P) == LOW)
  {
    tone(Buzz,T_P); digitalWrite(LED,HIGH);
  }
  while(digitalRead(C) == LOW)
  {
    tone(Buzz,T_C); digitalWrite(LED,HIGH);
  }

  while(digitalRead(D) == LOW)
  {
    tone(Buzz,T_D); digitalWrite(LED,HIGH);
  }

  while(digitalRead(E) == LOW)
  {
    tone(Buzz,T_E); digitalWrite(LED,HIGH);
  }

  while(digitalRead(F) == LOW)
  {
    tone(Buzz,T_F); digitalWrite(LED,HIGH);
  }

  while(digitalRead(G) == LOW)
  {
    tone(Buzz,T_G); digitalWrite(LED,HIGH);
  }

  while(digitalRead(A) == LOW)
  {
    tone(Buzz,T_A); digitalWrite(LED,HIGH);
  }

  while(digitalRead(B) == LOW)
  {
    tone(Buzz,T_B); digitalWrite(LED,HIGH);
  }

  while(digitalRead(BB) == LOW)
  {
    tone(Buzz,T_BB); digitalWrite(LED,HIGH);
  }

  while(digitalRead(CC) == LOW)
  {
    tone(Buzz,T_CC); digitalWrite(LED,HIGH);
  }

  noTone(Buzz);
  digitalWrite(LED,LOW);

}

