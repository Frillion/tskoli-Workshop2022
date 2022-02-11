#include <Servo.h>


Servo servo_motor;

int delay_time;
int servo_analog = 9;
int degree = 0;
int starting_pos = 30;
int stopping_pos = 120;
int potentio_value;
int potentio_to_degree;

void setup() {
  // put your setup code here, to run once:
  delay_time = 15;
  servo_motor.attach(servo_analog);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potentio_value = analogRead(A2);
  potentio_to_degree = map(potentio_value,0,1023,0,180);
  Serial.println(potentio_to_degree);
  if(potentio_to_degree > 0)
  {
    servo_motor.write(potentio_to_degree);
    delay(delay_time);
  }
  else
  {
    for(degree = starting_pos;degree <= stopping_pos;degree++)
    {
      servo_motor.write(degree);
      delay(delay_time);
    }
    for(degree = stopping_pos;degree >= starting_pos;degree--)
    {
      servo_motor.write(degree);
      delay(delay_time);
    }
  }
}
