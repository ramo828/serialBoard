#include "serialboard.h"
#include "skeyboard.h"
#define LED 25

Board board(LED,9600);
String command,command1,command2;
bool activ = false;

String name;
int step,stime,limit,stpTime;
int count = 0;
int bcount = 0;

void setup() {
  delay(2000);
  board.yaz("\tProgrammer Ramiz Memmedli");
}

void loop() {
    command = board.oxu();
    command.trim();
      
    if(command.equals("on"))
      board.led(ON);
    else if(command.equals("off"))
      board.led(OFF);
    else if(command.equals("bon")){
      board.yaz("Blink calisdirilir...");
      blink();
    }
    else if(command.equals("help"))
      board.help();
    else if(command.equals("run"))
      run();
    else if(command.equals("exit"))
      exit(0);
    else if(command.startsWith("set")){
      command1 = command.substring(3,command.length());
      command1.trim();
      board.yaz("SET");
      if(command1.startsWith("name")){
        command2 = command1.substring(4,command1.length());
        command2.trim();
        setName(command2);
        board.yaz("name: "+command2);
      }
      else if(command1.startsWith("step")){
        command2 = command1.substring(4,command1.length());
        command2.trim();
        setStep(command2.toInt());
        board.yaz("step: "+command2);
      }
      else if(command1.startsWith("time")){
        command2 = command1.substring(4,command1.length());
        command2.trim();
        setStpTime(command2.toInt());
        board.yaz("Step Time: "+command2);
      }
      else if(command1.startsWith("stime")){
        command2 = command1.substring(5,command1.length());
        command2.trim();
        //settime(command2.toInt());
        board.yaz("start time: "+command2);
      }
      else if(command1.startsWith("limit")){
        command2 = command1.substring(5,command1.length());
        command2.trim();
        setLimit(command2.toInt());
        board.yaz("limit: "+command2);
      }
  }
}

void setName(String _name){
  name = _name;
}
void setStep(int _step){
  step = _step;
}
void setLimit(int _limit){
  limit = _limit;
}
void setStpTime(int _stpTime){
  stpTime = _stpTime;
}



void blink(){
//  count = 0;
  while(count < limit && !BOOTSEL){
    count++;
    board.yaz(String(count));
    board.led(ON);
    delay(stpTime);
    board.led(OFF);
    delay(stpTime);
  }
}

void run(){
  board.yaz(name);
  board.yaz(String(step));
  board.yaz(String(limit));
  board.yaz(String(stpTime));
  board.yaz(String(bcount));
}










  
