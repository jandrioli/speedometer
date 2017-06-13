volatile int average = 0;
volatile int counter = 1;
int interval = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
  Serial.println("Started!");
  interval = millis();
  attachInterrupt(0, interrupt, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - interval > 1000)
  {
    Serial.print(" Avg:");
    Serial.print(average);
    Serial.print(" Cnt:");
    Serial.println(counter);
    interval = millis();
    delay(1);
  }
}

void interrupt() {
  int readValue = analogRead(A1);
  average = (readValue+average) / counter++;
}
