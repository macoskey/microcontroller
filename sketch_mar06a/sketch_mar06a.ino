
// code for controlling 4-button interface for dental ultrasound positioner
// J. Macoskey
// created: 3/6/17
// edited: 3/7/17


    
    // need to add:
    // - debounce
    // - multi-press preventer
    // - correct trig time
    // - check if pullup needed

#include <stdio.h>

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

int i = 0;

unsigned long lastDebounce = 0;
unsigned long thisDebounce = 0;
unsigned long debounceDelay = 500;

int state = LOW;

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
  digitalWrite(oret_pin,LOW);
  digitalWrite(obck_pin,LOW);
  digitalWrite(ofor_pin,LOW);
  digitalWrite(oext_pin,LOW);
}

void loop() {
  int ret_now = analogRead(iret_pin);
  
  if ((ret_now == 1023) && state == LOW){
    thisDebounce = millis();
    Serial.println(lastDebounce);
    state = HIGH;
  } else {
    digitalWrite(oret_pin,LOW);
    state = LOW;
  }
  if ((millis() - lastDebounce) > debounceDelay && state){
    digitalWrite(oret_pin,HIGH);
    //Serial.println("pressed");
    delay(100);
  } else {
    digitalWrite(oret_pin,LOW);
  }
  

  
//  if (num_pressed == 1){
//    if (ret_state == HIGH){
//      digitalWrite(oret_pin, HIGH);
//    }
//    if (bck_state == HIGH){
//      digitalWrite(obck_pin, HIGH);
//    }
//    if (for_state == HIGH){
//      digitalWrite(ofor_pin, HIGH);
//    }
//    if (ext_state == HIGH){
//      digitalWrite(obck_pin, HIGH);
//    }
//    delay(100);
//  }
    
  
}
