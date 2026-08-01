// Motor driver pins
const int LM_FWD = 5;
const int LM_BWD = 6;
const int RM_FWD = 9;
const int RM_BWD = 10;

// IR sensor pins (5-channel)
const int S1 = A0; // Left-most (L2)
const int S2 = A1; // Left (L1)
const int S3 = A2; // Center (C)
const int S4 = A3; // Right (R1)
const int S5 = A4; // Right-most (R2)

void setup() {
  pinMode(LM_FWD, OUTPUT);
  pinMode(LM_BWD, OUTPUT);
  pinMode(RM_FWD, OUTPUT);
  pinMode(RM_BWD, OUTPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);
  int s4 = digitalRead(S4);
  int s5 = digitalRead(S5);

  // For debugging
  Serial.print(s1); Serial.print(" ");
  Serial.print(s2); Serial.print(" ");
  Serial.print(s3); Serial.print(" ");
  Serial.print(s4); Serial.print(" ");
  Serial.println(s5);

  // Maze navigation logic
  if (s1 == HIGH && s2 == HIGH && s3 == LOW && s4 == HIGH && s5 == HIGH) {
    moveForward();  // Perfectly centered
  }
  else if (s3 == LOW && s4 == LOW && s5 == HIGH) {
    slightRight();
  }
  else if (s3 == LOW && s2 == LOW && s1 == HIGH) {
    slightLeft();
  }
  else if (s4 == LOW && s5 == LOW) {
    hardRight();
  }
  else if (s1 == LOW && s2 == LOW) {
    hardLeft();
  }
  else if (s1 == LOW && s2 == LOW && s3 == LOW && s4 == LOW && s5 == LOW) {
    crossJunction();
  }
  else if (s1 == HIGH && s2 == HIGH && s3 == HIGH && s4 == HIGH && s5 == HIGH) {
    turnAround(); // Dead end
  }
  else {
    moveForward(); // Default
  }
}

// Motor functions
void moveForward() {
  analogWrite(LM_FWD, 200);
  analogWrite(LM_BWD, 0);
  analogWrite(RM_FWD, 200);
  analogWrite(RM_BWD, 0);
}

void slightLeft() {
  analogWrite(LM_FWD, 150);
  analogWrite(RM_FWD, 200);
}

void slightRight() {
  analogWrite(LM_FWD, 200);
  analogWrite(RM_FWD, 150);
}

void hardLeft() {
  analogWrite(LM_FWD, 0);
  analogWrite(LM_BWD, 200);
  analogWrite(RM_FWD, 200);
  analogWrite(RM_BWD, 0);
  delay(300);
}

void hardRight() {
  analogWrite(LM_FWD, 200);
  analogWrite(LM_BWD, 0);
  analogWrite(RM_FWD, 0);
  analogWrite(RM_BWD, 200);
  delay(300);
}

void turnAround() {
  analogWrite(LM_FWD, 200);
  analogWrite(LM_BWD, 0);
  analogWrite(RM_FWD, 0);
  analogWrite(RM_BWD, 200);
  delay(600); // Adjust as needed
}

void crossJunction() {
  moveForward();
  delay(300);
}
