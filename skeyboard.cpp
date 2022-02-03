#include "serialboard.h"
#include "Arduino.h"
#include "skeyboard.h"
#include <Keyboard.h>

sBoard::sBoard() {
  Keyboard.begin();
}
