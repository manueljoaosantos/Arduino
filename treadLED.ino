class treadLED {
  int ledPin;
  int ledState = 0;
  long duration;
  unsigned long millisMarker;

public:
  treadLED(int pin, long interval){
    ledPin = pin;
    pinMode(ledPin, OUTPUT);

    duration = interval;
    millisMarker = 0;
  };

  void Update() {
    digitalWrite(ledPin, ledState);
  
    if ( (millis() - millisMarker) > duration) {
      millisMarker = millis();
      if (ledState == LOW) {
        ledState = HIGH;
      } else if (ledState == HIGH) {
        ledState = LOW;
      }
      Serial.println("["+String(ledPin)+"]-> "+String(ledState));
    }
  }  
};

treadLED LED1(8, 1000);
treadLED LED2(9, 500);
treadLED LED3(10, 300);
treadLED LED4(11, 2000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  LED1.Update();
  LED2.Update();
  LED3.Update();
  LED4.Update();
}
