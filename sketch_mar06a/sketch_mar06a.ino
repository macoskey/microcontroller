
// code for controlling 4-button interface for dental ultrasound positioner
// J. Macoskey
// created: 3/6/17
// edited:


    
    // need to add:
    // - debounce
    // - multi-press preventer
    // - correct trig time
    // - check if pullup needed


const int iret_pin = A0; // input full retraction
const int ibck_pin = A1; // input back step
const int ifor_pin = A2; // input forward step
const int iext_pin = A3; // input full extension
const int oret_pin = 3;
const int obck_pin = 5;
const int ofor_pin = 6;
const int oext_pin = 9;

int ret_state = LOW;
int bck_state = LOW;
int for_state = LOW;
int ext_state = LOW;

unsigned long lastDebounce = 0;
unsigned long debounceDel = 50;

void setup() {
  Serial.begin(9600);
  pinMode(iret_pin, INPUT_PULLUP);
  pinMode(ibck_pin, INPUT_PULLUP);
  pinMode(ifor_pin, INPUT_PULLUP);
  pinMode(iext_pin, INPUT_PULLUP);
  pinMode(oret_pin, OUTPUT);
  pinMode(obck_pin, OUTPUT);
  pinMode(ofor_pin, OUTPUT);
  pinMode(oext_pin, OUTPUT);

  // initialize all output pins to low
  digitalWrite(oret_pin,0);
  digitalWrite(obck_pin,0);
  digitalWrite(ofor_pin,0);
  digitalWrite(oext_pin,0);
}

void loop() {
  ret_now = analogRead(iret_pin);
  bck_now = analogRead(ibck_pin);
  for_now = analogRead(ifor_pin);
  ext_now = analogRead(iext_pin);
  
  if (num_pressed == 1){
    if (ret_state == HIGH){
      digitalWrite(oret_pin, HIGH);
    }
    if (bck_state == HIGH){
      digitalWrite(obck_pun, HIGH);
    }
    if (for_state == HIGH){
      digitalWrite(ofor_pin, HIGH);
    }
    if (ext_state == HIGH){
      digitalWrite(obck_pin, HIGH);
    }
    delay(100)
  }
    
  
}
