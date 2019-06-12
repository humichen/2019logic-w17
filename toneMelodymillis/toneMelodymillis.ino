#include "pitches.h"
#include "muisc.h"
#include "picture.h"
int btnpin=13;
int tonePin=8;
int latchPin = 11;
int clockPin = 7;
int dataPin = 12;

int btnstate=0;
int oldbtn=0;
int thisNote = 0;
int i = 0;
int check=1;
boolean picst=true;

unsigned long cT=0,pT=0;
int pauseBetweenNotes=0;
boolean nexttone=true;

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(btnpin,INPUT);
}



void loop() {
          //i=0;
          //thisNote=0;
          if(check==1){
           
            if(nexttone){ 
                int noteDuration = 1000 / noteDurations[thisNote];
                tone(tonePin, melody[thisNote], noteDuration);

                pauseBetweenNotes = noteDuration*1.30;
                nexttone=false;
                }
                
                
                  if(picst){
                    for(i=0;i<8;i++){
                      digitalWrite(latchPin,LOW);
                      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
                      shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);
                      digitalWrite(latchPin,HIGH);
                      delay(1);
                   }
                  }
                  else{
                    for(i=0;i<8;i++){
                      digitalWrite(latchPin,LOW);
                      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
                      shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix2[i]);
                      digitalWrite(latchPin,HIGH);
                      delay(1);
                   }
                  }
                
                
                
                //noTone(tonePin);
                cT=millis();
                if((cT-pT)>pauseBetweenNotes){
                  nexttone=true;
                  thisNote++;
                  pT=cT;
                  picst=!picst;
                  }
                
                btnstate=digitalRead(btnpin);
                if(btnstate==HIGH && oldbtn==0){
                  check=2;
                  i=0;
                  thisNote=0;
                  }
                
                if(thisNote==8){
                  check=2;
                  i=0;
                  thisNote=0;
                  }
              
          }
          oldbtn=btnstate;
          if(check==2){
              if(nexttone){ 
                  int noteDuration = 1000 / noteDurations2[thisNote];
                  tone(tonePin, melody2[thisNote], noteDuration);

                   pauseBetweenNotes = noteDuration*1.30;
                  nexttone=false;
                }
                
                  if(picst){
                    for(i=0;i<8;i++){
                      digitalWrite(latchPin,LOW);
                      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
                      shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix3[i]);
                      digitalWrite(latchPin,HIGH);
                      delay(1);
                   }
                  }
                  else{
                    for(i=0;i<8;i++){
                      digitalWrite(latchPin,LOW);
                      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
                      shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix4[i]);
                      digitalWrite(latchPin,HIGH);
                      delay(1);
                   }
                  }
                
                cT=millis();
                if((cT-pT)>pauseBetweenNotes){
                  nexttone=true;
                  thisNote++;
                  picst=!picst;
                  pT=cT;
                  }
                
                btnstate=digitalRead(btnpin);
                if(btnstate==HIGH && oldbtn==0){
                  check=1;
                  i=0;
                  thisNote=0;
                  }
                
                if(thisNote==42){
                  check=1;
                  i=0;
                  thisNote=0;
                }

               
          }
          oldbtn=btnstate;
  
}
