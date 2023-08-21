const int trig = 3; 
const int echo = 2; 
const int led = 13; 

long duration;
int distance;
int data;

void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  while(Serial.available()>0){
    data = Serial.read();
    if(data == 'A'){
        digitalWrite(led, HIGH);
        digitalWrite(trig, LOW);
        delayMicroseconds(2);
        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig, LOW);
        duration = pulseIn(echo, HIGH);
        distance = duration * 0.034 / 2;
        Serial.print("Distance : ");
        Serial.println(distance);
      }
      if(data == 'B'){
        digitalWrite(led, LOW);
        Serial.println("Stop");
      }
  }
  //delay(500); //Uncomment this to increase delay
}
