int incomingByte = 0;   // for incoming serial data

void setup() {
  // Green
  pinMode(10, OUTPUT);
  // Yellow
  pinMode(11, OUTPUT);
  // Red
  pinMode(12, OUTPUT);
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
  }
  if (incomingByte == 'g') {
    green();
  }
  else if (incomingByte == 'y') {
    yellow();
  }
  else if (incomingByte == 'r') {
    red();
  }
  else if (incomingByte == 'a') {
    all();
  }
}

void all(){
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
}

void green() {
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}

void yellow() {
  //digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  //digitalWrite(10, LOW);
}

void red() {
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}
