// Rev. 2 code for controlling 4-button interface for dental ultrasound positioner
// J. Macoskey
// created: 3/7/17
// edited:

#define NUMBUTTONS 4

const int buttonPin[] = {2, 3, 4, 5};
const int outputPin[] = {6, 7, 8, 9};
const int ledPin = 13;

int ledState = LOW;
int currButtonState[NUMBUTTONS];
int lastButtonState[NUMBUTTONS];

unsigned long debTime[NUMBUTTONS];
unsigned long debDelay = 50;

void setup() {
  Serial.begin(9600);
  Serial.println("Periodontal ultrasound movement controller v1.0");
  Serial.print(NUMBUTTONS, DEC);
  Serial.print(" buttons activated with ");
  Serial.print(debDelay, DEC);
  Serial.print(" ms debounce time");
  Serial.println("");

  for (int i=0; i < NUMBUTTONS; i++){
    debTime[i] = 0;
    pinMode(buttonPin[i],INPUT);
    pinMode(outputPin[i],OUTPUT);
    digitalWrite(outputPin[i],LOW);
  }
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin,ledState);
}

void loop() {
  for (int i=0; i<3; i++){
    int reading[i] = {digitalRead(buttonPin[i])};
    if (reading[i] != lastButtonState[i]){
      debTime[i] = millis();
    }
    if ((millis() - debTime[i]) > debDelay){
      if (reading[i] != currButtonState[i]){
        currButtonState[i] = reading[i];
        if (currButtonState[i] == HIGH){
          ledState = !ledState;
          Serial.println(" text");
          //Serial.println(i);
        }
      }
    }
    digitalWrite(ledPin,ledState);
    digitalWrite(outputPin[i],currButtonState[i]);
    lastButtonState[i] = reading[i];
  }
}


//void loop() {
//  static long trigTime[NUMBUTTONS];
//  for (int i=0; i < NUMBUTTONS; i++){
//    // check current value of input pin
//    currVal[i] = {analogRead(buttonPins[i])};
//    //Serial.print(currVal[i]);
//    //Serial.print(", ");
//    // if current value does not equal prev val, i.e., if button was pressed
//    if (currVal[i] != prevVal[i]){
//      trigTime[i] = millis();      // start recording time
//      prevVal[i] = currVal[i];  // set prev val to current value
//    } 
//
//    // if enough time has passed to debounce, set buttonState to new value
//    if ((trigTime[i] + DEBOUNCE) > millis()) {
//      if (buttonState[i] == 1){
//        buttonState[i] = 0;
//      } else {
//        buttonState[i] = 1;
//      }
//      Serial.print(buttonState[i]);
//    }
//  }
//}







