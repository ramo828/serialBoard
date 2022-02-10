#include "serialboard.h"

Board board(LED,9600);
String command;

void setup() {
  delay(2000);
  board.yaz("\tProgrammer Ramiz Memmedli");
}

void loop() {
    command = board.oxu();
    board.execute(command);
}














  
