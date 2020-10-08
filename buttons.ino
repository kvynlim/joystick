bool CH5_A1,CH6_A2,CH7_A3,CH8_A0;
static const uint8_t PWM_MIN=130,PWM_MAX=250; 

void setup() {
//  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
}

void loop() {pwm_sbus();}

void pwm_sbus() {
  CH5_A1 = digitalRead(A1);
  if (CH5_A1 == 1) {analogWrite(3, PWM_MIN);}
  if (CH5_A1 == 0) {analogWrite(3, PWM_MAX);}
  CH6_A2 = digitalRead(A2);
  if (CH6_A2 == 1) {analogWrite(9, PWM_MIN);}
  if (CH6_A2 == 0) {analogWrite(9, PWM_MAX);}
  CH7_A3 = digitalRead(A3);
  if (CH7_A3 == 1) {analogWrite(10, PWM_MIN);}
  if (CH7_A3 == 0) {analogWrite(10, PWM_MAX);}
  CH8_A0 = digitalRead(A0);
  if (CH8_A0 == 1) {analogWrite(11, PWM_MIN);}
  if (CH8_A0 == 0) {analogWrite(11, PWM_MAX);}
  
//  Serial.print(CH5_A1);Serial.print(',');
//  Serial.print(CH6_A2);Serial.print(',');
//  Serial.print(CH7_A3);Serial.print(',');
//  Serial.println(CH8_A0);
}
