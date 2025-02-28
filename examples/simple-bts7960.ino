// This code comes from https://www.youtube.com/watch?v=_zBsuyZwYzo
// Supposedly the labeling is "confusing" and do the opposite of what you think they should do
// At this point, nothing else was working anyway. Might as well give it a shot

// Update - this actually made them spin. Unfortunately, too fast and makes a 
//    high pitched sound. Maybe a different motor or psu would be worth
//    looking into

#define RPWM 7
#define LPWM 8
#define R_EN 9 // pwm pin speed
#define L_EN 10 // according to the video these pins control the speed

void motor_cw(){
  digitalWrite (LPWM, LOW);
  digitalWrite (RPWM, HIGH);
  analogWrite (L_EN, 100);
  analogWrite (R_EN, 100);
  Serial.println ("MOTOR RUNS CW");
  }

void motor_ccw(){
  digitalWrite (LPWM, HIGH);
  digitalWrite (RPWM, LOW);
  analogWrite (L_EN, 100);
  analogWrite (R_EN, 100);
  Serial.println ("MOTOR RUNS CCW");
  }

void motor_stop(){
  digitalWrite (LPWM, LOW);
  digitalWrite (RPWM, LOW);
  analogWrite (L_EN, 0); 
  analogWrite (R_EN, 0);
  Serial.println ("MOTOR STOPS");
  }

void setup() {
  Serial.begin(9600);
  Serial.println("Start");
  pinMode (RPWM, OUTPUT);
  pinMode (LPWM, OUTPUT);
  pinMode (R_EN, OUTPUT);
  pinMode (L_EN, OUTPUT);
}

void loop() {
  delay(1000);
  motor_stop();
  delay(1000);
  motor_cw();
  delay(1000);
  delay(1000);
  motor_stop();
  motor_ccw();
  delay(1000);
  motor_stop();

}
