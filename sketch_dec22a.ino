//CODE BY AJITH V ANIL
const int flexpin1 = A0; 
const int flexpin2 = A1; 
const int flexpin3 = A2; 
const int flexpin4 = A3; 
const int flexpin5 = A4; 
const int ot1 = 3; 
const int ot2 = 4; 
const int ot3 = 5; 
const int ot4 = 6; 
const int ot5 = 7; 
void setup () 
{ 
 Serial.begin(9600); 
 pinMode(ot1,OUTPUT);
 pinMode(ot2,OUTPUT);
 pinMode(ot3,OUTPUT);
 pinMode(ot4,OUTPUT);
 pinMode(ot5,OUTPUT);
} 
void loop () 
{ 
 int flexposition1;  
 int flexposition2;
 int flexposition3;
 int flexposition4;
 int flexposition5;
 
 flexposition1 = analogRead(flexpin1);
 flexposition2 = analogRead(flexpin2);
 flexposition3 = analogRead(flexpin3);
 flexposition4 = analogRead(flexpin4);
 flexposition5 = analogRead(flexpin5);
 Serial.print("sensor 1: "); 
 Serial.print(" sensor 2: "); 
 Serial.print(" sensor 3: "); 
 Serial.print(" sensor 4: "); 
 Serial.print(" sensor 5: "); 
 
 Serial.println(flexposition1); 
 Serial.print(flexposition2); 
 Serial.print(flexposition3);
 Serial.print(flexposition4);
 Serial.print(flexposition5);   
 if (flexposition1 > 8)// you can change this value according to your sensor reading
 {
  digitalWrite(ot1,HIGH);
  digitalWrite(ot2,LOW);
  digitalWrite(ot3,LOW);
  digitalWrite(ot4,LOW);
  digitalWrite(ot5,LOW);
  }
  else if (flexposition2 > 8)
  {
  digitalWrite(ot2,HIGH);
  digitalWrite(ot1,LOW);
  digitalWrite(ot3,LOW);
  digitalWrite(ot4,LOW);
  digitalWrite(ot5,LOW);
  }
 else if (flexposition3 > 8)
  {
  digitalWrite(ot3,HIGH);
  digitalWrite(ot2,LOW);
  digitalWrite(ot1,LOW);
  digitalWrite(ot4,LOW);
  digitalWrite(ot5,LOW);
  }
  else if (flexposition4 > 8)
  {
  digitalWrite(ot4,HIGH);
  digitalWrite(ot2,LOW);
  digitalWrite(ot3,LOW);
  digitalWrite(ot1,LOW);
  digitalWrite(ot5,LOW);
  }
  else if (flexposition5 > 8)
  {
  digitalWrite(ot5,HIGH);
  digitalWrite(ot2,LOW);
  digitalWrite(ot3,LOW);
  digitalWrite(ot4,LOW);
  digitalWrite(ot1,LOW);
  }
}
