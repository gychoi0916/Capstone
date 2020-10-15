int trig = 12;      
int echo = 14;
int led[3] = {15, 4, 17};
int gnd[3] = {2, 16, 5};

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);   
  for (int i=0; i<3; i++) {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], 1);
    
    pinMode(gnd[i], OUTPUT);
    digitalWrite(gnd[i], 0);
  }
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int distance = pulseIn(echo, HIGH) * 17 / 1000;       
  Serial.print(distance);
  Serial.println("cm"); 
  delay(100);
   if (distance > 20)
  {
    digitalWrite(led[2], HIGH);
    digitalWrite(led[1], LOW);
    digitalWrite(led[0], LOW);
  }
  if (distance > 10 & distance <= 20)
  {
    digitalWrite(led[2], LOW);
    digitalWrite(led[1], HIGH);
    digitalWrite(led[0], LOW);
  }
  if (distance > 0 & distance <= 10)
  {
    digitalWrite(led[2], LOW);
    digitalWrite(led[1], LOW);
    digitalWrite(led[0], HIGH);
  }
}
