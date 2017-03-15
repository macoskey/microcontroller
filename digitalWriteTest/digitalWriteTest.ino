
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
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("init");
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
  if (inputVal > 900 && inputVal < 910) {
    Serial.println("button 1 pressed");
    digitalWrite(outputPin[0],HIGH);
    delay(500);
    digitalWrite(outputPin[0],LOW);
  }
  
//  if (inputVal > 900 && inputVal < 910) {
//    if (pressState == 0){
//      pressCount = millis();
//      pressState = 1;
//    } else {
//      if (millis() > pressCount + DEBTIME){
//        Serial.println("button 1 pressed");
//        digitalWrite(outputPin[1], HIGH);
//        delay(2000);
//        pressState = 0;
//        restCount = millis();
//        restState = 1;
//      }
//    }
//  }
//  for (int i = 0; i < BUTTONNUM; i++){
//    digitalWrite(outputPin[i],HIGH);
//  }
//  Serial.println("HIGH");
//  delay(2000);
//  for (int i = 0; i < BUTTONNUM; i++){
//    digitalWrite(outputPin[i],LOW);
//  }
//  Serial.println("LOW");
//  delay(2000);
  
  
}
