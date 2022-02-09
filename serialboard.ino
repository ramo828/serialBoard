#include "serialboard.h"
#include "skeyboard.h"
#define LED 25

Board board(LED,9600);
String command,command1,command2;


void setup() {
  delay(2000);
  board.yaz("\tProgrammer Ramiz Memmedli");
}

void loop() {
    command = board.oxu();
    board.execute(command);
}














  
