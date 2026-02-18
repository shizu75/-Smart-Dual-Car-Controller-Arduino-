 #include <SoftwareSerial.h>

 #define enA 5 //Enable1 L293 Pin enA
 #define in1 6 //Motor1  L293 Pin in1
 #define in2 7 //Motor1  L293 Pin in1
 #define in3 9 //Motor2  L293Pin in1
 #define in4 10 //Motor2  L293 Pin in1
 #define enB 8 //Enable2 L298 Pin enB
 #define R_S 12 // Right sensor
 #define L_S 13 // Left sensor

 #define horn 4

 #define line_fol A4
 #define obstacle A5
 char data;

 SoftwareSerial BT(3, 2);

 int line;
 int obs;

void setup() {
  Serial.begin(9600);
  pinMode(R_S, INPUT);
  pinMode(L_S, INPUT);

  pinMode(line_fol, INPUT);
  pinMode(obstacle, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  analogWrite(enA, 250);
  analogWrite(enB, 130);
  Serial.begin(9600);

  BT.begin(9600);

  Serial.println("Initializing...");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() 
{

  if(digitalRead(line_fol) == HIGH && digitalRead(obstacle) == LOW){
    line = 1;
    obs = 0;
  }

  else if(digitalRead(line_fol) == LOW && digitalRead(obstacle) == HIGH){
    line = 0;
    obs = 1;
  }

  else{
    if(BT.available()) {
      data = toupper(BT.read());

      // Ignore junk / newline
      if (data == '\n' || data == '\r') return;

      Serial.println(data);

      switch (data) {
        case 'F': forward();   break;
        case 'B': backward();  break;
        case 'L': left();      break;
        case 'R': right();     break;
        case 'S': stopMotors(); break;
        case 'Y': tone(horn, 1000); break;
        case 'X': noTone(horn); break;
      }
      }
  }

  if(line == 1){
      if(digitalRead(L_S) == 0 && digitalRead(R_S) == 0){
        analogWrite(in1, 110); 
        digitalWrite(in2, LOW); 
        analogWrite(in3, 90); 
        digitalWrite(in4, LOW);
      }

      else if(digitalRead(L_S) == 0 && digitalRead(R_S) == 1){
            analogWrite(in1, 110); 
            digitalWrite(in2, LOW); 
            digitalWrite(in3, LOW); 
            digitalWrite(in4, LOW);
      }

      else if(digitalRead(L_S) == 1 && digitalRead(R_S) == 0){
            digitalWrite(in1, LOW); 
            digitalWrite(in2, LOW); 
            analogWrite(in3, 90); 
            digitalWrite(in4, LOW);
      }

      else{
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
      }
  }
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  digitalWrite(horn, LOW);
}
