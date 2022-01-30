
//motor
int leftmotorpin1 = 12;
int leftmotorpin2 = 13;
int rightmotorpin1 = 10;
int rightmotorpin2 = 8;

//sensor pin
int leftsensorpin = 5;
int midsensorpin = 6;
int rightsensorpin = 7;

//sensor state
int leftsensorstate;
int midsensorstate;
int rightsensorstate;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftmotorpin1, OUTPUT);
  pinMode(leftmotorpin2, OUTPUT);
  pinMode(rightmotorpin1, OUTPUT);
  pinMode(rightmotorpin2, OUTPUT);

  pinMode(leftsensorpin, INPUT);
  pinMode(midsensorpin, INPUT);
  pinMode(rightsensorpin, INPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  leftsensorstate = digitalRead(leftsensorpin);
  midsensorstate = digitalRead(midsensorpin);
  rightsensorstate = digitalRead(rightsensorpin);
  
  int result = (leftsensorstate<<2|midsensorstate<<1|rightsensorstate<<0);
//  Serial.println(result, BIN);

  if(result == 0b010){
    
    digitalWrite(leftmotorpin1, HIGH);
    digitalWrite(leftmotorpin2, LOW);
    digitalWrite(rightmotorpin1, HIGH);
    digitalWrite(rightmotorpin2, LOW);

    
  }
  else if(result == 0b011 || result == 0b001){
    digitalWrite(leftmotorpin1, HIGH);
    digitalWrite(leftmotorpin2, LOW);
    digitalWrite(rightmotorpin1, LOW);
    digitalWrite(rightmotorpin2, LOW);

    delay(50);
  }
  else if(result == 0b110 || result == 0b100){
    digitalWrite(leftmotorpin1, LOW);
    digitalWrite(leftmotorpin2, LOW);
    digitalWrite(rightmotorpin1, HIGH);
    digitalWrite(rightmotorpin2, LOW);
    
    delay(50);
  }
//  else if(result == 0b000){
//    digitalWrite(leftmotorpin1, LOW);
//    digitalWrite(leftmotorpin2, LOW);
//    digitalWrite(rightmotorpin1, HIGH);
//    digitalWrite(rightmotorpin2, LOW);
//  }

  else if (result == 0b111){
      digitalWrite(leftmotorpin1, HIGH);
      digitalWrite(leftmotorpin2, LOW);
      digitalWrite(rightmotorpin1, HIGH);
      digitalWrite(rightmotorpin2, LOW);
      delay (500);
      digitalWrite(leftmotorpin1, LOW);
      digitalWrite(leftmotorpin2, LOW);
      digitalWrite(rightmotorpin1, LOW);
      digitalWrite(rightmotorpin2, LOW);
  }
  
}
