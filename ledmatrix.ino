int interval = 100;
unsigned long previousMillis = 0;
String in = "";
bool bcheck = 0;
int c = 2;

int rightTronArr[] = {2,5,8,9,10,7,4,3};
int leftTronArr[] = {2,3,4,7,10,9,8,5};
int mill[][3] = {{2,6,10},{5,6,7},{8,6,4},{9,6,3}};

void setup() {
  // put your setup code here, to run once:
  for(int i=2;i<=13; i++){
    pinMode(i, OUTPUT);
  }
  randomSeed(analogRead(A0));
  Serial.begin(9600);
  off();
}

void loop() {
  // put your main code here, to run repeatedly:
  //
  if(Serial.available()>0){
    in = Serial.readString();
  }
  if(in=="on"){
    on();
  }
  
  if(in=="off"){
    off();
  }

  if(in=="blink"){
    blinkled();
  }

  if(in=="tr"){
    tronRight();
    Serial.println(millis());
  }
  if(in=="tl"){
    tronLeft();
    Serial.println(millis());
  }
  if(in=="mr"){
    millRight();
    Serial.println(millis());
  }
  if(in=="ml"){
    millLeft();
    Serial.println(millis());
  }
  if(in=="rn"){
    randomLed();
    Serial.println(millis());
  }
  
}

void on(){
  for(int i=2; i<=10; i++){
      digitalWrite(i, HIGH);
  }
  for(int i=11; i<=13; i++){
      digitalWrite(i, LOW);
  }
}

void off(){
  for(int i=2; i<=10; i++){
      digitalWrite(i, LOW);
  }
  for(int i=11; i<=13; i++){
      digitalWrite(i, LOW);
  }
}

void blinkled(){
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;
    if (bcheck == 0) {
      on();
      bcheck = 1;
    } else {
      off();
      bcheck = 0;
    }
  }
}

void tronRight(){
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;
    if(c>7){
      c=0;
    }
    off();
    digitalWrite(rightTronArr[c], HIGH);
    c++;
  }
}

void tronLeft(){
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;
    if(c>7){
      c=0;
    }
    off();
    digitalWrite(leftTronArr[c], HIGH);
    c++;
  }
}

void millRight(){
    unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;
    if(c>3){
      c=0;
    }
    off();
    digitalWrite(mill[c][0], HIGH);
    digitalWrite(mill[c][1], HIGH);
    digitalWrite(mill[c][2], HIGH);
    c++;
  }
}

void millLeft(){
    unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;
    if(c>3){
      c=0;
    }
    int p = 3-c;
    off();
    digitalWrite(mill[p][0], HIGH);
    digitalWrite(mill[p][1], HIGH);
    digitalWrite(mill[p][2], HIGH);
    c++;
  }
}

void randomLed(){
      unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;
    off();
    int l = random(11,14);
    int p = random(2,11);
    for(int i = 11; i<=13; i++){
      digitalWrite(i, HIGH);
    }
    digitalWrite(l,LOW);
    digitalWrite(p,HIGH);
  }
}

