#include "serialboard.h"
#include "Arduino.h"


Board::Board(int pin, int baudrate){
  pinMode(pin, OUTPUT);
  _pin = pin;
  Serial.begin(baudrate);
}

void Board::yaz(String msg){
  Serial.println(msg);
}

String Board::oxu() {
  String command;
  command = Serial.readStringUntil('\n');
  command.trim();
  return command;
}

void Board::led(int status){
  digitalWrite(_pin,status);
}

bool Board::okay(){
   if(Serial.available()){
    return true;
   }
   else {
    return false;
   }
}
void Board::version(){
  Serial.println("Versiya: 0.0.1 Beta");
}
void Board::author(){
  Serial.println("Created by Mammadli Ramiz");
}  

bool Board::execute(String command){
  if(command.equals("ok")){
    Serial.println("OK");
    return true;
  }
  return false;
}


void Board::help() {
  Serial.println("\t Version - version");
  Serial.println("\t Author - author");
  Serial.println("\t Help - help");
  Serial.println("\t Led on - set led on");
  Serial.println("\t Led off - set led off");
  Serial.println("\t Sleep (seconds} - sleep (seconds)");
  Serial.println("\t Show options - show opions");
  Serial.println("\t Run - run");
}
