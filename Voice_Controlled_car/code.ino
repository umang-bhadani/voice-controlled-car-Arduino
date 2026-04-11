String voice;

// Pins definition
int motor1_pin1 = 8;
int motor1_pin2 = 9;
int motor2_pin1 = 10;
int motor2_pin2 = 11;

void setup() {
  Serial.begin(9600); // Bluetooth aur Serial Monitor ke liye

  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
  
  Serial.println("System Ready! Voice command ka intezar hai...");
}

void loop() {
  // Serial data read karne ka sabse solid tarika
  while (Serial.available() > 0) {
    delay(10); 
    char c = Serial.read();
    if (c == '#') {break;} // Kuch apps command ke aage # lagati hain
    voice += c; 
  }

  if (voice.length() > 0) {
    voice.toLowerCase(); // Sabse zaroori: Taaki "Forward" aur "forward" dono chalein
    voice.trim();        // Extra space hatane ke liye
    
    Serial.print("Command mili: ");
    Serial.println(voice);

    // Commands Match Karna
    if (voice.indexOf("forward") >= 0 || voice.indexOf("aage") >= 0) {
      forward();
    }
    else if (voice.indexOf("backward") >= 0 || voice.indexOf("peeche") >= 0) {
      backward();
    }
    else if (voice.indexOf("left") >= 0 || voice.indexOf("baaye") >= 0) {
      left();
    }
    else if (voice.indexOf("right") >= 0 || voice.indexOf("daaye") >= 0) {
      right();
    }
    else if (voice.indexOf("stop") >= 0 || voice.indexOf("ruko") >= 0) {
      stopCar();
    }

    voice = ""; // Word process hone ke baad memory khali
  }
}

// Motor Movements Functions
void forward() {
  digitalWrite(motor1_pin1, HIGH); digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, HIGH); digitalWrite(motor2_pin2, LOW);
}

void backward() {
  digitalWrite(motor1_pin1, LOW);  digitalWrite(motor1_pin2, HIGH);
  digitalWrite(motor2_pin1, LOW);  digitalWrite(motor2_pin2, HIGH);
}

void left() {
  digitalWrite(motor1_pin1, LOW);  digitalWrite(motor1_pin2, HIGH);
  digitalWrite(motor2_pin1, HIGH); digitalWrite(motor2_pin2, LOW);
}

void right() {
  digitalWrite(motor1_pin1, HIGH); digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, LOW);  digitalWrite(motor2_pin2, HIGH);
}

void stopCar() {
  digitalWrite(motor1_pin1, LOW);  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, LOW);  digitalWrite(motor2_pin2, LOW);
}
