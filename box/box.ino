int in1 = 2;
int in2 = 3;

int l1 = 4;
int l2 = 5;

int butn = 6;

int p1 = A0;
int p2 = A1;


void setup(){
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(l1, OUTPUT);
pinMode(l2, OUTPUT);


pinMode(butn, INPUT);
pinMode(p1, INPUT);
pinMode(p2, INPUT);

Serial.begin(9600);

close();
}

void open(){
  Serial.println("open");
  lasers(1);
  while(!is_open()){
    Serial.println("opening");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  lasers(0);
  Serial.println("opened");
}

void close(){
  Serial.println("close");
  lasers(1);
  while(!is_close()){
    Serial.println("closing");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  lasers(0);
  Serial.println("closed");
}

void lasers(int state){
  if (state == 1){
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
  }

  if (state == 0){
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
  }
}

boolean is_close(){
  lasers(1);
  int sensor_a0 = smooth_read(A0);
  int sensor_a1 = smooth_read(A1);
  lasers(0);
  return sensor_a0 > 100 and sensor_a1 > 100;
}

boolean is_open(){
  lasers(1);
  int sensor_a0 = smooth_read(A0);
  int sensor_a1 = smooth_read(A1);
  lasers(0);
  return sensor_a0 < 100 and sensor_a1 < 100;
}

int smooth_read(int pin){
    byte num_reads = 10;
    int sum = 0;
    int avr = 0;
      for (byte i = 0; i < num_reads; i++) {
      sum = sum + analogRead(pin);
      delay(50);
      }
    
    avr = sum / num_reads;
    
    return avr;
}

void loop(){
 if (is_close() == true){
  //open();
 }
  delay(1000);
 if (is_open() == true){
  //close();
 }
  
}
