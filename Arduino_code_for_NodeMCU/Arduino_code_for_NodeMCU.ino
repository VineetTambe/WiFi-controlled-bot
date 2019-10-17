/* 
 *  Project by :
 *  Vineet Tambe 32265
 *  Siddhart Kalgoankar 32261
 *  Tanya Thakur 32266
 *  
 *  This code sets the arduino to serially recieve data from the nodemcu 
 *  and accordingly give commmands to the motordriver IC.
 *  
 * 

*/
/*
Pin Configuration = 

D0 }to Motor on the left
D1 
D2 }to Motor on the right
D3
*/


#define D0 2
#define D1 3
#define D2 4
#define D3 5

void setup() {
  // put your setup code here, to run once:
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D0, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0)
  {
    char data = Serial.read();
    if (data == 'F')
    {
      Serial.println("Forward");
      digitalWrite(D0, HIGH);
      digitalWrite(D1, LOW);
      digitalWrite(D2, HIGH);
      digitalWrite(D3, LOW);
    }
    else if (data == 'B')
    {
      Serial.println("Backward");
      digitalWrite(D0, LOW);
      digitalWrite(D1, HIGH);
      digitalWrite(D2, LOW);
      digitalWrite(D3, HIGH);
    }
    else if (data == 'L')
    {
      Serial.println("Left");
      digitalWrite(D0, LOW);
      digitalWrite(D1, HIGH);
      digitalWrite(D2, HIGH);
      digitalWrite(D3, LOW);
    }
    else if (data == 'R')
    {
      Serial.println("Right");
      digitalWrite(D0, HIGH);
      digitalWrite(D1, LOW);
      digitalWrite(D2, LOW);
      digitalWrite(D3, HIGH);
    }
    else
    {
      Serial.println("Stop");
      digitalWrite(D0, LOW);
      digitalWrite(D1, LOW);
      digitalWrite(D2, LOW);
      digitalWrite(D3, LOW);
    }
  }
}
