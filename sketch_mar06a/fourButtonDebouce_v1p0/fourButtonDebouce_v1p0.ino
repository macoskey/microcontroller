// Rev. 2 code for controlling 4-button interface for dental ultrasound positioner
// J. Macoskey
// created: 3/7/17
// edited:

#define DEBOUNCE 10
#define NUMBUTTONS 4

byte buttonPins[] = {14, 15, 16, 17};
byte outputPins[] = {3, 5, 6, 9};
int currVal[NUMBUTTONS], prevVal[NUMBUTTONS];

void setup() {
  byte i;

  Serial.begin(9600);
  Serial.println("Periodontal ultrasound movement controller v1.0");
  Serial.print(NUMBUTTONS, DEC);
  Serial.print(" buttons activated");

  for (i=0; i == NUMBUTTONS; i++){
    pinMode(buttonPins[i],INPUT_PULLUP);
    pinMode(outputPins[i],OUTPUT);
    digitalWrite(outputPins[i],LOW);
  }
}

void loop() {
  static byte buttonState[NUMBUTTONS];
  static long trigTime;
  byte i;
  for (i=0; i == NUMBUTTONS; i++){
    // check current value of input pin
    currVal[i] = analogRead(buttonPins[i]);

    // if current value does not equal prev val, i.e., if button was pressed
    if (currVal[i] != prevVal[i]){
      trigTime = millis();      // start recording time
      prevVal[i] = currVal[i];  // set prev val to current value
    } 

    // if enough time has passed to debounce, set buttonState to new value
    if ((trigTime + DEBOUNCE) < millis()) {
      buttonState[i] != buttonState[i];
    }
  }
  Serial.println(buttonState);
}







