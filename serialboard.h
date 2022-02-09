#ifndef serialboard_h
#define serialboard_h
#include "Arduino.h"


class Board {

  #define ON 1
  #define OFF 0

  private: 
    int _pin;
    String _name;
    int _step;
    int _limit;
    int _stpTime;
    
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
    void blink();
    void run();
    
    void setName(String name){
    _name = name;
    }
    void setStep(int step){
    _step = step;
    }
    void setLimit(int limit){
    _limit = limit;
    }
    void setStpTime(int stpTime){
    _stpTime = stpTime;
    }
 };


#endif
