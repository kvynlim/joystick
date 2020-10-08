uint16_t V0=0,V1=0,V2=0,V3=0;
uint8_t V0_PWM=0,V1_PWM=0,V2_PWM=0,V3_PWM=0;
static const uint8_t MIN_LIMIT=30,PWM_MIN=130,PWM_MAX=250; 
static const uint16_t MAX_LIMIT=999;

void setup() {//Serial.begin(9600);
}

void loop() {pwm_sbus();}

void pwm_sbus() {
  read_joystick();
  V0_PWM = map(V0, MIN_LIMIT, MAX_LIMIT, PWM_MIN, PWM_MAX);
  V1_PWM = map(V1, MIN_LIMIT, MAX_LIMIT, PWM_MIN, PWM_MAX);
  V2_PWM = map(V2, MIN_LIMIT, MAX_LIMIT, PWM_MAX, PWM_MIN);
  V3_PWM = map(V3, MIN_LIMIT, MAX_LIMIT, PWM_MIN, PWM_MAX);
  analogWrite(3, V0_PWM);
  analogWrite(9, V1_PWM);
  analogWrite(10, V2_PWM);
  analogWrite(11, V3_PWM);
  
//  Serial.print(V0);Serial.print(',');Serial.print(V1);Serial.print(',');
//  Serial.print(V2);Serial.print(',');Serial.print(V3);Serial.print(',');
//  Serial.print(V0_PWM);Serial.print(',');Serial.print(V1_PWM);Serial.print(',');
//  Serial.print(V2_PWM);Serial.print(',');Serial.println(V3_PWM);
}

void read_joystick() {
  V0 = analogRead(A0); // Roll
  if (V0 < MIN_LIMIT) {V0 = MIN_LIMIT;}
  if (V0 > MAX_LIMIT) {V0 = MAX_LIMIT;}
  V1 = analogRead(A1); // Pitch
  if (V1 < MIN_LIMIT) {V1 = MIN_LIMIT;}
  if (V1 > MAX_LIMIT) {V1 = MAX_LIMIT;}
  V2 = analogRead(A2); // Throttle
  if (V2 < MIN_LIMIT) {V2 = MIN_LIMIT;}
  if (V2 > MAX_LIMIT) {V2 = MAX_LIMIT;}
  V3 = analogRead(A3); // Yaw
  if (V3 < MIN_LIMIT) {V3 = MIN_LIMIT;}
  if (V3 > MAX_LIMIT) {V3 = MAX_LIMIT;}
}
