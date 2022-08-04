String cmd;
String args[3];
int lastindex = 0;
void setup() {
}

void loop() {
while (Serial.available()) {
  delay(3);
  cmd += (char)Serial.read();
}
  
  if (cmd.length() > 0) {
    int i = 0;
    while (cmd.indexOf(',', lastindex) != -1) {
      if (cmd[lastindex] == ',') {lastindex++;}
      args[i] = cmd.substring(lastindex, cmd.indexOf(',', lastindex));
      lastindex = cmd.indexOf(',', lastindex);
      i++;
    }
    lastindex = 0;

  if (args[0] == "pm") {
    pinMode(args[1].toInt(), args[2].toInt());
  }
  else if (args[0] == "dr") {
    Serial.println(digitalRead(args[1].toInt()));
  }
  else if (args[0] == "dw") {
    digitalWrite(args[1].toInt(), args[2].toInt());
  }
  else if (args[0] == "ar") {
    Serial.println(analogRead(args[1].toInt()));
  }
  else if (args[0] == "aw") {
    analogWrite(args[1].toInt(), args[2].toInt());
  }
  cmd = "";
  }

}
