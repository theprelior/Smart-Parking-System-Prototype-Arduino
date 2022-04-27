//Kodlar Arduino Mega 2560 için yazılmıştır.

#include "Arduino.h"
#include"Servo.h"

//RG
#include "LoRa_E32.h"
LoRa_E32 e32ttl100(11, 12); // Config without connect AUX and M0 M1

//SERVO

Servo servo1;
Servo servo2;
int buzzer=51;



//ekran
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);



void setup() {
  pinMode(30,OUTPUT);
  pinMode(31,OUTPUT);//Direk Ledler
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);

  pinMode(40,OUTPUT);
  pinMode(41,OUTPUT);
  pinMode(42,OUTPUT);
  pinMode(43,OUTPUT);
  pinMode(44,OUTPUT);
  pinMode(45,OUTPUT);
  pinMode(46,OUTPUT);
  pinMode(47,OUTPUT);
  pinMode(39,OUTPUT);
  pinMode(49,OUTPUT);
  pinMode(51,OUTPUT); //buzzer
  pinMode(28,INPUT); 
  

  

  
 Serial.begin(9600);
 
  //Servo 
  
  servo1.attach(53);
  delay(500);
  servo1.attach(50);
  delay(500);
 
  

  //RF
  e32ttl100.begin();

  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Hosgeldiniz");
 
}
struct  Gelen {
 byte Yer1;
 byte Yer2;
 byte Yer3;
 byte Yer4;
 byte Yer5;
 byte Yer6;
 byte Yer7;
 byte Yer8;
 byte Yer9;
 byte Yer10;
} data;


int parks[]={0,0,0,0,0,0,0,0,0,0};


void loop() {
  int countofCars=0;
int anahtar=digitalRead(28);
 int tepe = analogRead(A12);
  if(anahtar==1){
    digitalWrite(30,HIGH);
    digitalWrite(31,HIGH);
    digitalWrite(32,HIGH);
    digitalWrite(33,HIGH);
   
  }
  
    if(tepe<30 && anahtar==0){
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
      digitalWrite(32,HIGH);
      digitalWrite(33,HIGH);
    }
 
  delay(50);
  if(tepe>30 && anahtar==0){
      digitalWrite(30,LOW);
      digitalWrite(31,LOW);
      digitalWrite(32,LOW);
      digitalWrite(33,LOW);
  }




 int kapi1 = analogRead(A0); 
 int kapi2 = analogRead(A1);


 int park1 = analogRead(A2);
 int park2 = analogRead(A3);
 int park3 = analogRead(A4);
 int park4 = analogRead(A5);
 int park5 = analogRead(A6);
 int park6 = analogRead(A7);
 int park7 = analogRead(A8);
 int park8 = analogRead(A9);
 int park9 = analogRead(A10);
 int park10 = analogRead(A11);












  
int yerkontrol=20;

  if(park1<yerkontrol){
    data.Yer1=1;
      digitalWrite(41,HIGH);
      parks[0]=1;
      
  }
  else{
    data.Yer1=0;
    digitalWrite(41,LOW);
    parks[0]=0;
  }
  if(park2<yerkontrol){
    data.Yer2=1;
    digitalWrite(44,HIGH);
    parks[1]=1;
  }
   else{
    data.Yer2=0;
    digitalWrite(44,LOW);
    parks[1]=0;
  }
  if(park3<yerkontrol){
   data.Yer3=1;
   digitalWrite(39,HIGH);
   parks[2]=1;
  }
   else{
    data.Yer3=0;
    digitalWrite(39,LOW);
    parks[2]=0;
  }
  if(park4<yerkontrol){
    data.Yer4=1;  
    digitalWrite(47,HIGH);
    parks[3]=1;
    }
   else{
    data.Yer4=0;
    digitalWrite(47,LOW);
    parks[3]=0;
  }
  if(park5<yerkontrol){
    
    data.Yer5=1;
    digitalWrite(45,HIGH);
    parks[4]=1;
  }
   else{
    data.Yer5=0;
    digitalWrite(45,LOW);
    parks[4]=0;
  
  }
  if(park6<yerkontrol){
    
   data.Yer6=1;
  digitalWrite(42,HIGH);
  parks[5]=1;
  }
   else{
    data.Yer6=0;
    digitalWrite(42,LOW);
    parks[5]=0;
  }
 if(park7<yerkontrol){
    data.Yer7=1;
    digitalWrite(43,HIGH);
    parks[6]=1;
  }
   else{
    data.Yer7=0;
    digitalWrite(43,LOW);
    parks[6]=0;
  }
  if(park8<yerkontrol){
    data.Yer8=1;
    digitalWrite(49,HIGH);
    parks[7]=1;
  }
   else{
    data.Yer8=0;
    digitalWrite(49,LOW);
    parks[7]=0;
  }
  if(park9<yerkontrol){
    data.Yer9=1;
    digitalWrite(46,HIGH);
    parks[8]=1;
  }
   else{
    data.Yer9=0;
    digitalWrite(46,LOW);
    parks[8]=0;
  }
  if(park10<yerkontrol){
    data.Yer10=1;
    digitalWrite(40,HIGH);
    parks[9]=1;
  }
   else{
    data.Yer10=0;
    digitalWrite(40,LOW);
    parks[9]=0;
  }
  int kalan=0;
  for(int i = 0 ; i<10 ; i++){
    if(parks[i]==1){
     
      countofCars+=countofCars+1;
    }
    else{
      kalan++;
    }
   
    Serial.print(parks[i]);
    Serial.print(" ");
   
  }
   Serial.println();
 if(kalan>0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Hosgeldiniz");
    lcd.setCursor(0,1);
    lcd.print("Kalan Yer : ");
  
   lcd.print(kalan);
 }
 else{
     lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("HosGeldiniz ");
      lcd.setCursor(0,1);
      lcd.print("Yerimiz yok");
 }
  
 //Kapıların açılma durumu
  if(kapi2<32&&kalan>0){
    servo1.write(0);//sol kapı açık konum
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Hosgeldiniz");
      lcd.setCursor(0,1);
      lcd.print(kalan);
      lcd.print(" Araclikyervar");
      digitalWrite(buzzer,HIGH);
      delay(200);
      digitalWrite(buzzer,LOW);
      delay(3000);
  }
  else if(kapi2>32){
    servo1.write(100);
  
  }
  else if(kapi2<32 && kalan==0){
     lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Hosgeldiniz ancak");
      lcd.setCursor(0,1);
      lcd.print("Yerimiz yok");
      delay(900);
  }
  if(kapi1<32){
    servo2.write(90);//sol kapı açık konum
       lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Hoscakalin");
      
      digitalWrite(buzzer,HIGH);
      delay(200);
      digitalWrite(buzzer,LOW);
      delay(3000);
  }
  else if(kapi1>32){
    servo2.write(10);
     
  } 
    servo1.detach();
    servo2.detach();
   
	ResponseStatus rs = e32ttl100.sendFixedMessage(0, 63, 23, &data, sizeof(Gelen));   
	servo1.attach(53);
	servo2.attach(50);
	delay(100);
	Serial.println(tepe);
	Serial.print("Sayı");
	Serial.println(countofCars);*/
	delay(500);
    

}
