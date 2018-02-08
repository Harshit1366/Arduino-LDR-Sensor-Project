#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);
const int ldr=A0;
int ldrval;
const int buzz=3;
const int r=4;
const int g=5;
const int b=6;

void setup() {
Serial.begin(9600);

pinMode(r,OUTPUT);
pinMode(g,OUTPUT);
pinMode(b,OUTPUT);
pinMode(buzz,OUTPUT);
pinMode(ldr,INPUT);
pinMode(13,OUTPUT);
lcd.begin(16,2);
lcd.home();
lcd.print("Hello LDR Sensor");
lcd.setCursor(0,1);
lcd.print("     Project");
}


void buzzer(){
  if (ldrval>1){
    if(ldrval>=50){ 
      digitalWrite(buzz,HIGH);
      delay(ldrval);
      digitalWrite(buzz,LOW);
      delay(ldrval);
    }
    else if(ldrval<50){
      digitalWrite(buzz,HIGH);
      }
    }
  else{ 
    digitalWrite(buzz,LOW);
  }
}

void loop(){
ldrval=analogRead(ldr);
Serial.println(ldrval);

if(ldrval<155 && ldrval>50){
  buzzer();
int i=0;
analogWrite(r,255);
analogWrite(g,0);
analogWrite(b,255);
lcd.clear();
lcd.print("LDR VALUE : ");
lcd.print(ldrval);
lcd.setCursor(0,1);
lcd.print("LIGHT GETING DIM !");

}
else if(ldrval<=50){
  digitalWrite(13,HIGH);
  buzzer();
  analogWrite(r,0);
  analogWrite(g,255);
  analogWrite(b,255);
lcd.clear();
lcd.print("LDR VALUE : ");
lcd.print(ldrval);
lcd.setCursor(0,1);
lcd.print("LIGHT : DIM !");
}
else if(ldrval>900){
   buzzer();
digitalWrite(13,LOW);
int i=0;
analogWrite(r,255);
analogWrite(g,0);
analogWrite(b,0);
lcd.clear();
lcd.print("LDR VALUE : ");
lcd.print(ldrval);
lcd.setCursor(0,1);
lcd.print("LIGHT : BRIGHT !");
}
else{
  buzzer();
  int i=0;
analogWrite(r,0);
analogWrite(g,255);
analogWrite(b,0);
  digitalWrite(13,LOW);
  digitalWrite(buzz,HIGH);
lcd.clear();
lcd.print("LDR VALUE : ");
lcd.print(ldrval);
lcd.setCursor(0,1);
lcd.print("LIGHT : MODERATE !");
}

delay(500);

}



