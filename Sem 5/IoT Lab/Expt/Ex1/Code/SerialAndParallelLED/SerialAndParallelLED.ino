#define LED1 9
#define LED2 10
#define LED3 11

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
}

void loop() {
  serial();
  parallel();
}

//Copy these functions into Sensor Code if Necessary

void serial(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delayMicroseconds(1000);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  delayMicroseconds(1000);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delayMicroseconds(1000);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delayMicroseconds(1000);
}

void parallel(){
  delayMicroseconds(1000);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delayMicroseconds(1000);
}
