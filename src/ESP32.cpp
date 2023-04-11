#include <Arduino.h>

int read_value;
int repetition = 10;
float u;
float u_in = 3.278 ;
String incomingString;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available() > 0){
    incomingString = Serial.readString();

    if (incomingString.equals("m")){
      read_value = 0;
      for(int j = 0; j < repetition; j++){
        read_value+=analogRead(35);}

      read_value=read_value/repetition;
      Serial.print("A0: ");
      Serial.print(read_value);
      u=(u_in/4095.000)*read_value;
      Serial.print(" - U: ");
      Serial.println(u);
}}}