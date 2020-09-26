uint16_t V0=0,V1=0,V2=0,V3=0;
uint8_t V0_PWM=0,V1_PWM=0,V2_PWM=0,V3_PWM=0;
volatile byte state = LOW;
static const uint8_t MIN_TRIM = 30; 
static const uint16_t MAX_TRIM = 999;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING);
}

void loop() {pwm_sbus();}

void pwm_sbus() {
  read_joystick();
  V0_PWM = map(V0, 30, 999, 130, 250);
  V1_PWM = map(V1, 30, 999, 250, 130);
  V2_PWM = map(V2, 30, 999, 250, 130);
  V3_PWM = map(V3, 30, 999, 130, 250);
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
  
  Serial.print(V0);Serial.print(',');Serial.print(V1);Serial.print(',');
  Serial.print(V2);Serial.print(',');Serial.println(V3);
  Serial.print(V0_PWM);Serial.print(',');Serial.print(V1_PWM);Serial.print(',');
  Serial.print(V2_PWM);Serial.print(',');Serial.println(V3_PWM);
}

void read_joystick() {
  V0 = analogRead(A0); // Roll
  if (V0 < MIN_TRIM) {V0 = MIN_TRIM;}
  if (V0 > MAX_TRIM) {V0 = MAX_TRIM;}
  V1 = analogRead(A1); // Pitch
  if (V1 < MIN_TRIM) {V1 = MIN_TRIM;}
  if (V1 > MAX_TRIM) {V1 = MAX_TRIM;}
  V2 = analogRead(A2); // Throttle
  if (V2 < MIN_TRIM) {V2 = MIN_TRIM;}
  if (V2 > MAX_TRIM) {V2 = MAX_TRIM;}
  V3 = analogRead(A3); // Yaw
  if (V3 < MIN_TRIM) {V3 = MIN_TRIM;}
  if (V3 > MAX_TRIM) {V3 = MAX_TRIM;}
}

void blink() {
  state = !state;
}
