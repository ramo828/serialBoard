#ifndef serialboard_h
#define serialboard_h
#include "Arduino.h"


class Board {

  #define ON 1
  #define OFF 0

  private: 
    int _pin;

  public:
    Board(int pin, int baudrate);
    void yaz(String msg);
    void led(int status);
    String oxu();
    bool okay();
    void version();
    void author();
    void help();
    bool execute(String command);
};


#endif
