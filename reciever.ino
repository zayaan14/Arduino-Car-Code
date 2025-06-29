
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


#define CE_PIN 9
#define CSN_PIN 8


RF24 radio(CE_PIN, CSN_PIN);





const byte address[6] = "00001";




int speed1 = 3;
int D1 = 2;
int D2 = 4;

int speed2 = 5;
int D3 = 6;
int D4 = 7;



int speedA = 200;
int speedB = 0;

void setup()
{

  Serial.begin(9600);
  radio.begin();
  

  radio.openReadingPipe(0, address);
  

  radio.startListening();

pinMode(speed1, OUTPUT);
pinMode(D1, OUTPUT);
pinMode(D2, OUTPUT);

pinMode(speed2, OUTPUT);
pinMode(D3, OUTPUT);
pinMode(D4, OUTPUT);

}

void loop(){

  if (radio.available())
  {

    int val=1;
    radio.read(&val, sizeof(val));
    Serial.println(val);
    if(val==1) {
      analogWrite(speed1, speedA);
      digitalWrite(D1, HIGH);
      digitalWrite(D2, LOW);

      analogWrite(speed2, speedA);
      digitalWrite(D3, HIGH);
      digitalWrite(D4, LOW);
    }

    else if(val==2) {
      analogWrite(speed1, speedA);
      digitalWrite(D1, LOW);
      digitalWrite(D2, HIGH);

      analogWrite(speed2, speedA);
      digitalWrite(D3, LOW);
      digitalWrite(D4, HIGH);
    }

    else if(val==3){
      analogWrite(speed1, 255);
      digitalWrite(D1, LOW);
      digitalWrite(D2, HIGH);

      analogWrite(speed2, 255);
      digitalWrite(D3, HIGH);
      digitalWrite(D4, LOW);

    }

    else if(val==4){
      analogWrite(speed1, 255);
      digitalWrite(D1, HIGH);
      digitalWrite(D2, LOW);

      analogWrite(speed2, 255);
      digitalWrite(D3, LOW);
      digitalWrite(D4, HIGH);

    }





    else if(val==5){
      analogWrite(speed1, 0);
      digitalWrite(D1, LOW);
      digitalWrite(D2, LOW);

      analogWrite(speed2, 0);
      digitalWrite(D3, LOW);
      digitalWrite(D4, LOW);
      
    }

  }
}