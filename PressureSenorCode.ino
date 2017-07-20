
String morsecode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.-- ", "--.."};  
String breathOutputs = "";
String pin = "";
String dotsDashes = "";
int ArduinoPIN = A1;
String myChar = "";
String finalString = "";
String sampleMorse = ".-";
void setup() {
  // put your setup code here, to run once:
pinMode(ArduinoPIN, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int pin = analogRead(ArduinoPIN);

delay(500);
  //Serial.println(pin); 
// threshhold range is between 120-140
  if (pin < 100) 
    {
    breathOutputs += ".";
    }
    else if (pin > 140)
    {
     breathOutputs += "-";
 }
 if (pin >= 100 &&  pin <= 140)
 {
  breathOutputs = "";
 }
 // else
  //{
  //breathOutputs += "  ";
 // }
  //Serial.println(pin);
  convertLetter(breathOutputs);
  Serial.println(breathOutputs);
  finalString = ( convertLetter (breathOutputs));
  Serial.print(finalString);
 
 if (breathOutputs.length() >= 4)
 {
  breathOutputs = "";
 }
  //Serial.print(myChar);
}

String convertLetter(String breathOutputs) 
{
    for(int i = 0;i < 26; i++)
  {
    //Serial.println(morsecode[i]);
    if (morsecode[i] == breathOutputs) 
    {
      char myChar = i + 65;
      return ((String)myChar);
    }
  }
   return " ";
   
}

