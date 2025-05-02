const int outputPin = 8;    // Arduino digital output to NI myDAQ
const int inputPin = 7;     // Arduino digital input from NI myDAQ
const int ledPin = 13;      // Built-in LED on Arduino board
const int pwmPin = 9;       // PWM output pin
const int relayPin = 4;       // Relay signal pin
const float referenceVolts = 5.0; //the default reference 0n a 5-volt board
const int batteryPin = 0; 

int startDIOtest = 0;
int StartSCtest = 0;
int StartPWMs = 0;
int StartPWM30test = 0;
int StartPWM60test = 0;
int StartPWM90test = 0;
int counter = 0;

void setup() {
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(outputPin, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(relayPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int receivedSignal = digitalRead(inputPin);
  if (analogRead(batteryPin) == HIGH && counter == 0) {
    counter += 1;
    digitalWrite(relayPin, HIGH);   // Send HIGH signal to close array
    delay(2500);
    }
  int voltread = analogRead(batteryPin);
  if (voltread >= 900) {
    digitalWrite(ledPin, HIGH);
    }
    
  // ===== DIGITAL I/O TEST =====
  if (receivedSignal == HIGH && startDIOtest == 0 && counter == 1) {
    digitalWrite(relayPin, LOW);
    digitalWrite(outputPin, HIGH);   // Send signal to myDAQ
    digitalWrite(ledPin, HIGH);      // Turn on LED
    delay(100);                      // Short pulse
    digitalWrite(outputPin, LOW);    // Reset output
    digitalWrite(ledPin, LOW);     // Turn off LED
    startDIOtest = 1;
    //digitalWrite(relayPin, LOW);
    while (digitalRead(inputPin) == HIGH) {
      delay(10);  // Wait for signal to go LOW
    }
  }

  // ===== SERIAL COMM TEST =====
  if (Serial.available() >= 19 && startDIOtest == 1 && StartPWM30test == 1 && StartPWM60test == 1 && StartPWM90test == 1 && StartSCtest == 0 && counter == 1) {
    StartSCtest = 1;
    String message = "";
    for (int i = 0; i < 19; i++) {
      char receivedChar = Serial.read();
      message += receivedChar;
    }
    Serial.print(message);
    // Reset all states for next full test cycle
    startDIOtest = 0;
    StartSCtest = 0;
    StartPWM30test = 0;
    StartPWM60test = 0;
    StartPWM90test = 0;
    counter = 0; 
    Serial.flush();
  }

  // ===== PWM TEST 30% =====
//  if (digitalRead(inputPin) == HIGH && startDIOtest == 1 && StartSCtest == 1 && StartPWM30test == 0) {
  if (analogRead(batteryPin) >= 900 && startDIOtest == 1 && StartPWM30test == 0 && counter == 1) {
    //Serial.println("PWM 30%");
    analogWrite(pwmPin, 77); // ~30% duty
    delay(1000);
    StartPWM30test = 1;
    while (analogRead(batteryPin)>= 900) {
      delay(10);
    }
  }

  // ===== PWM TEST 60% =====
//  if (digitalRead(inputPin) == HIGH && startDIOtest == 1 && StartPWM30test == 1 && StartPWM60test == 0) {
  if (analogRead(batteryPin) >= 900 && startDIOtest == 1 && StartPWM30test == 1 && StartPWM60test == 0 && counter == 1) {
    analogWrite(pwmPin, 153); // ~60% duty
    StartPWM60test = 1;
    while (analogRead(batteryPin)>= 900) {
      delay(10);
   }
  }

  // ===== PWM TEST 90% =====
//  if (digitalRead(inputPin) == HIGH && StartPWM60test == 1 && StartPWM90test == 0) {
  if (analogRead(batteryPin) >= 900 && startDIOtest == 1 && StartPWM30test == 1 && StartPWM60test == 1 && StartPWM90test == 0 && counter == 1) {
    //Serial.println("PWM 90%");
    analogWrite(pwmPin, 230); // ~90% duty
    StartPWM90test = 1;
    digitalWrite(ledPin, LOW);      // Turn off LED
    while (analogRead(batteryPin)>= 900) {
      delay(10);
    }
  }
}
