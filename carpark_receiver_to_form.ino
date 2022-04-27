
#include "Arduino.h"
#include "LoRa_E32.h"
LoRa_E32 e32ttl100(3, 4); // Config without connect AUX and M0 M1

void setup() {
  Serial.begin(9600);
  delay(500);

  // RF 
  e32ttl100.begin();
  Serial.println("Hi, I'm going to send a message!");
  ResponseStatus rs = e32ttl100.sendMessage("Hello, world?");
  Serial.println(rs.getResponseDescription());
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
void loop() {
  
 if (e32ttl100.available()>1) {
  ResponseStructContainer rsc = e32ttl100.receiveMessage(sizeof(Gelen));
  struct Gelen data = *(Gelen*) rsc.data;
 
    Serial.print(data.Yer1);
    Serial.print(data.Yer2);
    Serial.print(data.Yer3);
    Serial.print(data.Yer4);
    
    Serial.print(data.Yer5);
    
    Serial.print(data.Yer6);
    
    Serial.print(data.Yer7);
    
    Serial.print(data.Yer8);
    
    Serial.print(data.Yer9);
    
    Serial.print(data.Yer10);
   
    Serial.println();
    rsc.close();
   }
  
  }
