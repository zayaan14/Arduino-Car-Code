
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 8


RF24 radio(CE_PIN, CSN_PIN);


const byte address[6] = "00001";



int powerP = 2;

int xPin = A5;
int yPin = A4;

int xVal;
int yVal;

int number;






void setup() {

  Serial.begin(9600);

  radio.begin();


  radio.openWritingPipe(address);

  radio.stopListening();

  pinMode(powerP, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);






}
void loop() {

    digitalWrite(powerP, HIGH);

  xVal = analogRead(xPin);
  yVal = analogRead(yPin);

  if(xVal<=30 && yVal<=600 && yVal>=300) {
    number = 1;
  }

  else if(xVal>=800 && yVal<=600 && yVal>=300){
    number = 2;
  }
  

  else if(yVal>=800 && xVal<=600 && xVal>=300) {
    number = 3;
  }

  else if(yVal<=300 && xVal<=600 && xVal>=300){
    number = 4;
  }

  else{
    number = 5;
  }
  Serial.println(number);
  radio.write(&number, sizeof(number));

}
