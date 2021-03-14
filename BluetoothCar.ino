
#define l1 46
#define l2 48

#define r2 50
#define r1 52

#define red 10
#define gre 9
#define blu 8

#define buz 2


String input;
bool f = false, b = false, l = false, r = false, rl = false, rr = false;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);

  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);

  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);

  pinMode(red, OUTPUT);
  pinMode(gre, OUTPUT);
  pinMode(blu, OUTPUT);

  pinMode(buz, OUTPUT);

  digitalWrite(buz, 1);
  delay(500);
  digitalWrite(buz, 0);
  digitalWrite(blu, 1);

}



void loop() {
  input = "";

  while (Serial3.available()) {
    input += (char)Serial3.read();
    delay(5);
  }


  if (input == "@u1") {
    f = true;
    car();
  }
  else if (input == "@d1") {
    b = true;
    car();
  }
  else if (input == "@l1") {
    rl = true;
    car();
  }
  else if (input == "@r1") {
    rr = true;
    car();
  }
  else if (input == "@x") {
    l = true;
    car();
  }
  else if (input == "@y") {
    r = true;
    car();
  }

  //stop
  else if (input == "0") {
    f = false;
    b = false;

    rl = false;
    rr = false;
    car();
  }
  else if (input == "o") {
    l = false;
    r = false;
    car();
  }

  //fnc
  else if (input == "@a_on") {
    digitalWrite(buz, 1);
  }
  else if (input == "M") {
    digitalWrite(buz, 0);
  }


  if (input != "") {
    Serial.println(f);
    Serial.println(b);
    Serial.println(l);
    Serial.println(r);

    Serial.println(rl);
    Serial.println(rr);

    Serial.println("\n\n");
  }


}

void car() {
  if (f & !b & !l & !r & !rl & !rr) {
    digitalWrite(l1, 1);
    digitalWrite(l2, 0);

    digitalWrite(r1, 1);
    digitalWrite(r2, 0);

    Serial.println("forword");

    digitalWrite(red, 0);
    digitalWrite(gre, 1);
    digitalWrite(blu, 0);
  }
  else if (!f & b & !l & !r & !rl & !rr) {
    digitalWrite(l1, 0);
    digitalWrite(l2, 1);

    digitalWrite(r1, 0);
    digitalWrite(r2, 1);

    Serial.println("backword");

    digitalWrite(red, 1);
    digitalWrite(gre, 0);
    digitalWrite(blu, 0);
  }
  else if (!f & !b & !l & !r & rl & !rr) {
    digitalWrite(l1, 0);
    digitalWrite(l2, 1);

    digitalWrite(r1, 1);
    digitalWrite(r2, 0);

    Serial.println("left rotate");
    digitalWrite(red, 1);
    analogWrite(gre, 100);
    digitalWrite(blu, 0);
  }
  else if (!f & !b & !l & !r & !rl & rr) {
    digitalWrite(l1, 1);
    digitalWrite(l2, 0);

    digitalWrite(r1, 0);
    digitalWrite(r2, 1);

    Serial.println("right rotate");
    digitalWrite(red, 1);
    analogWrite(gre, 100);
    digitalWrite(blu, 0);
  }
  else if (f & !b & l & !r & !rl & !rr) {
    digitalWrite(l1, 0);
    digitalWrite(l2, 0);

    digitalWrite(r1, 1);
    digitalWrite(r2, 0);

    Serial.println("forword left turn");

    digitalWrite(red, 1);
    analogWrite(gre, 100);
    digitalWrite(blu, 0);
  }
  else if (f & !b & !l & r & !rl & !rr) {
    digitalWrite(l1, 1);
    digitalWrite(l2, 0);

    digitalWrite(r1, 0);
    digitalWrite(r2, 0);

    Serial.println("forword right turn");

    digitalWrite(red, 1);
    analogWrite(gre, 100);
    digitalWrite(blu, 0);
  }
  else if (!f & b & l & !r & !rl & !rr) {
    digitalWrite(l1, 0);
    digitalWrite(l2, 0);
    
    digitalWrite(r1, 0);
    digitalWrite(r2, 1);

    Serial.println("back left turn");

    digitalWrite(red, 1);
    analogWrite(gre, 100);
    digitalWrite(blu, 0);
  }
  else if (!f & b & !l & r & !rl & !rr) {
    digitalWrite(l1, 0);
    digitalWrite(l2, 1);
    
    digitalWrite(r1, 0);
    digitalWrite(r2, 0);

    Serial.println("back right turn");


    digitalWrite(red, 1);
    analogWrite(gre, 100);
    digitalWrite(blu, 0);
  }
  else if (!f || !b) {
    digitalWrite(l1, 0);
    digitalWrite(l2, 0);

    digitalWrite(r1, 0);
    digitalWrite(r2, 0);

    Serial.println("Stop");

    digitalWrite(red, 0);
    digitalWrite(gre, 0);
    digitalWrite(blu, 1);
  }
}
