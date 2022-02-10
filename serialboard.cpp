#include "serialboard.h"
#include "Arduino.h"
#include <Keyboard.h>

int count = 0;

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

void Board::execute(String command){

    String command1, command2;
    command.trim();
    if(command.equals("on"))
      Board::led(ON);
    else if(command.equals("off"))
      Board::led(OFF);
    else if(command.equals("bon")){
      Board::yaz("Blink calisdirilir...");
      Board::blink();
    }
    else if(command.equals("go")){
      Board::yaz("Calisdilir...");
      Board::setBeginTime(15);
      Board::attack();
    }
    else if(command.equals("help"))
      Board::help();
    else if(command.equals("run"))
      Board::run();
    else if(command.equals("exit"))
      exit(0);
    else if(command.startsWith("set")){
      command1 = command.substring(3,command.length());
      command1.trim();
      Board::yaz("SET");
      if(command1.startsWith("name")){
        command2 = command1.substring(4,command1.length());
        command2.trim();
        Board::setName(command2);
        Board::yaz("name: "+command2);
      }
    else if(command1.startsWith("step")){
        command2 = command1.substring(4,command1.length());
        command2.trim();
        Board::setStep(command2.toInt());
        Board::yaz("step: "+command2);
      }
      else if(command1.startsWith("time")){
        command2 = command1.substring(4,command1.length());
        command2.trim();
        Board::setStpTime(command2.toInt());
        Board::yaz("Step Time: "+command2);
      }
      else if(command1.startsWith("stime")){
        command2 = command1.substring(5,command1.length());
        command2.trim();
//        bo/ard.settime(command2.toInt());
        Board::yaz("start time: "+command2);
      }
      else if(command1.startsWith("limit")){
        command2 = command1.substring(5,command1.length());
        command2.trim();
        Board::setLimit(command2.toInt());
        Board::yaz("limit: "+command2);
      }
      else if(command1.startsWith("reset")){
       Board::yaz("siralam resetlendi!");
       Board::reset();
      }
  }
}



void Board::blink(){
  while(count < _limit && !BOOTSEL){
    count++;
    Board::yaz(String(count));
    Board::led(ON);
    delay(_stpTime);
    Board::led(OFF);
    delay(_stpTime);
  }
}

void Board::run(){
  Board::yaz(_name);
  Board::yaz(String(_step));
  Board::yaz(String(_limit));
  Board::yaz(String(_stpTime));
}

void Board::reset(){
  count = 0;
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
//Keyboard

void Board::kYaz(String msg){
  delay(50);
  Keyboard.println(msg);
}

void Board::enter() {
  Keyboard.press(KEY_KEYPAD_ENTER);
  delay(100);
  Keyboard.releaseAll();
}

void Board::down(int step){
    for(int i = 0; i< step; i++){
    Board::led(ON);
    delay(_stpTime/2);
    Keyboard.press(KEY_DOWN_ARROW);
    delay(100);
    Keyboard.releaseAll();
    Board::led(OFF);
    delay(_stpTime/2);
    }
    Board::enter();
  }



  void Board::attack() {
  delay(_beginStart*1000);
   while(count < _limit && !BOOTSEL){
    count++;
    kYaz("Metros");
    down(_step+count);
  }
}
