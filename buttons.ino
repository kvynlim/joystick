volatile byte state = LOW;

void setup() {
//  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING);
}

void loop() {pwm_sbus();}

void pwm_sbus() {
  analogWrite(9, 110);
  analogWrite(11, 110);
  
  if (state == HIGH) {
    analogWrite(10, 250); 
  }
  else if (state == LOW) {
    analogWrite(10, 110);
  }
}

void blink() {
  state = !state;
}
