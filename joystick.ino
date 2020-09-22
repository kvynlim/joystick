uint16_t V0=0,V1=0,V2=0,V3=0;
uint8_t V0_PWM=0,V1_PWM=0,V2_PWM=0,V3_PWM=0;
volatile byte state = LOW;

void setup() {
  //Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING);
}

void loop() {pwm_sbus();}

void pwm_sbus() {
  read_joystick();
  V0_PWM = map(V0, 0, 1023, 110, 250);
  V1_PWM = map(V1, 0, 1023, 110, 250);
  V2_PWM = map(V2, 0, 1023, 250, 110);
  V3_PWM = map(V3, 0, 1023, 110, 250);
  analogWrite(3, V0_PWM);
  analogWrite(9, V1_PWM);
  analogWrite(10, V2_PWM);
  analogWrite(11, V3_PWM);
  
  if (state == HIGH) {
    analogWrite(6, 100); 
  }
  else if (state == LOW) {
    analogWrite(6, 2);
  }
  
//  Serial.print(V0);Serial.print(',');Serial.print(V1);Serial.print(',');
//  Serial.print(V2);Serial.print(',');Serial.println(V3);
//  Serial.print(V0_PWM);Serial.print(',');Serial.print(V1_PWM);Serial.print(',');
//  Serial.print(V2_PWM);Serial.print(',');Serial.println(V3_PWM);
}

void read_joystick() {
  V0 = analogRead(A0); // Roll
  V1 = analogRead(A1); // Pitch
  V2 = analogRead(A2); // Throttle
  V3 = analogRead(A3); // Yaw
}

void blink() {
  state = !state;
}
