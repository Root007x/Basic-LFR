// void forword(int right_s,int left_s){

//     digitalWrite(rmf, HIGH);
//     digitalWrite(rmb, LOW);
//     digitalWrite(lmf, HIGH);
//     digitalWrite(lmb,LOW);

//     analogWrite(rms, right_s);
//     analogWrite(lms, left_s);
// }

// void motor_stop(){
//     digitalWrite(rmf, LOW);
//     digitalWrite(rmb, LOW);
//     digitalWrite(lmf, LOW);
//     digitalWrite(lmb,LOW);

//     analogWrite(rms, LOW);
//     analogWrite(lms, LOW);
// }

void motor(int a, int b) {  //a = left, b = right
  if (a >= 0) {  // left motor forward
    analogWrite(lmf, a);
    analogWrite(lmb, 0);
  } else {  // left motor backward
    a = -a;
    analogWrite(lmf, 0);
    analogWrite(lmb, a);
  }

  if (b >= 0) {  // right motor forward
    analogWrite(rmf, b);
    analogWrite(rmb, 0);
  } else {  // right motor backward
    b = -b;
    analogWrite(rmf, 0);
    analogWrite(rmb, b);
  }
}


void brake(){
    motor(-255,-255); delay(brake_time);
    motor(0,0); delay(100);
}