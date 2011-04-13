// Written by JH

// *************************************************************************
// ************************** LED Flash Class ******************************
// *************************************************************************
class LEDs {
public: 
  bool on;
protected:
  unsigned long previousTime;
  unsigned long flashTime;
public:
  LEDs(void) { 
    on = false;
  }

  virtual void initialize(int);
  virtual void run(unsigned long currentTime);
  
  bool canRun(unsigned long currentTime)
  {
    if(on)
    {
      if (currentTime > previousTime + flashTime){
        previousTime = currentTime;
        return true;
      }
    }
    return false;
  }
};

// *************************************************************************
// ************************** Flash All LEDs  ******************************
// *************************************************************************
class LEDs_FlashAll : LEDs{
private:
  int pin;
  bool state;
  bool flash;

public:
  LEDs_FlashAll() : LEDs(){}

  void initialize(int ledPin)
  {
    pin = ledPin;
    state = false;
    flash = false;
    
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH); //turn on the LEDs
  }
  
  void run(unsigned long currentTime)
  {
    if(canRun(currentTime))
    {
      //Serial.println("Running");
      if(flash)
      {
        state = !state;
        digitalWrite(pin, state);
      }else if(!state)
      {
        //Serial.println("Turning ON");
        digitalWrite(pin, HIGH);
        state = true;
      }
    }
  }
  
  void off()
  {
     on = false;
     state = false;
     digitalWrite(pin, LOW);
  }

  void alwaysOn()
  {
    on = true;
    flash = false;
    flashTime = 0; 
  }
  
  void flashSlow()
  {
    on = true;
    flash = true;
    flashTime = 500000; 
  }
  
  void flashFast()
  {
    on = true;
    flash = true;
    flashTime = 100000; 
  }
  
    void flashFaster()
  {
    on = true;
    flash = true;
    flashTime = 50000; 
  }
  
};


