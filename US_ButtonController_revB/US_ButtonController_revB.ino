// Rev. 3.2 code for controlling 4-button interface for dental ultrasound positioner
// J. Macoskey
// created: 3/11/17
// edited:

#define BUTTONNUM 4
#define DEBTIME 50
#define RESTTIME 500

const int inputPin = A0;
const int outputPin[] = {2,3,4,5};
const int ledPin = 13;

int ledState = HIGH;  // debug led state

int pressCount = 0;   // button debounce counter
int pressState = 0;   // state for debounce counter

int restCount = 0;    // counter for rest state
int restState = 0;    // state for rest counter

void setup() {
  Serial.begin(9600);
  Serial.println("Periodontal ultrasound movement controller v1.0");
  Serial.print(BUTTONNUM, DEC);
  Serial.println(" buttons activated");
  for (int i=0; i<BUTTONNUM; i++){
    pinMode(outputPin[i],INPUT_PULLUP);
  }
  for (int i=0; i<BUTTONNUM; i++){
    pinMode(outputPin[i],OUTPUT);
    digitalWrite(outputPin[i],LOW);
  }
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,ledState);

  pinMode(inputPin,INPUT);
}

void loop() {
  int inputVal = analogRead(inputPin);

  // check to see if we are in a rest state
  // BUTTON 1:
  if (inputVal > 900 && inputVal < 910) {
    if (pressState == 0){
      pressCount = millis();
      pressState = 1;
    } else {
      if (millis() > pressCount + DEBTIME){
        Serial.println("button 1 pressed");
        digitalWrite(outputPin[0], HIGH);
        delay(RESTTIME);
        pressState = 0;
        restCount = millis();
        restState = 1;
      }
    }
  }
   // BUTTON 2:
   if (inputVal > 800 && inputVal < 810) {
    if (pressState == 0){
      pressCount = millis();
      pressState = 1;
    } else {
      if (millis() > pressCount + DEBTIME){
        Serial.println("button 2 pressed");
        digitalWrite(outputPin[1], HIGH);
        delay(RESTTIME);
        pressState = 0;
        restCount = millis();
        restState = 1;
      }
    }
   }
   // BUTTON 3:
   if (inputVal > 620 && inputVal < 630) {
    if (pressState == 0){
      pressCount = millis();
      pressState = 1;
    }else {
      if (millis() > pressCount + DEBTIME){
        Serial.println("button 3 pressed");
        digitalWrite(outputPin[2], HIGH);
        delay(RESTTIME);
        pressState = 0;
        restCount = millis();
        restState = 1;
      }
    }
   }
   // BUTTON 4:
   if (inputVal > 445 && inputVal < 455) {
    if (pressState == 0){
      pressCount = millis();
      pressState = 1;
    }else {
      if (millis() > pressCount + DEBTIME){
        Serial.println("button 4 pressed");
        digitalWrite(outputPin[3], HIGH);
        delay(RESTTIME);
        pressState = 0;
        restCount = millis();
        restState = 1;
      }
    } 
  }
  for (int i=0; i<BUTTONNUM; i++){
    digitalWrite(outputPin[i],LOW);
  }
}
