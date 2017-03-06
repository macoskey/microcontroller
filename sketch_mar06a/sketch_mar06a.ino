
// code for controlling 4-button interface for dental ultrasound positioner
// J. Macoskey
// created: 3/6/17
// edited:

const int iret_pin = A0; // input full retraction
const int ibck_pin = A1; // input back step
const int ifor_pin = A2; // input forward step
const int iext_pin = A3; // input full extension
const int oret_pin = 3;
const int obck_pin = 5;
const int ofor_pin = 6;
const int oext_pin = 9;

int ret_state = 0;
int bck_state = 0;
int for_state = 0;
int ext_state = 0;
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(iret_pin, INPUT_PULLUP);
  pinMode(ibck_pin, INPUT_PULLUP);
  pinMode(ifor_pin, INPUT_PULLUP);
  pinMode(iext_pin, INPUT_PULLUP);
  pinMode(oret_pin, OUTPUT);
  pinMode(obck_pin, OUTPUT);
  pinMode(ofor_pin, OUTPUT);
  pinMode(oext_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ret_state = analogRead(iret_pin);
  bck_state = analogRead(ibck_pin);
  for_state = analogRead(ifor_pin);
  ext_state = analogRead(iext_pin);
  num_pressed = ret_state + bck_state + for_state + ext_state;
  
  if (num_pressed <= 1){
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
  }
    
  
}
