#include <SoftwareSerial.h>


SoftwareSerial bt_iletisim(11,12);//rx ve tx arduinoya 

#define sol_ileri 8
#define sol_geri 10 //ARDUİNO İLE L298N İN TOPRAKLARI AYNI OLACAK
#define sol_hiz 9

#define sag_ileri   7
#define sag_geri    6
#define sag_hiz     5
//#define onfarsol    1 // arduinodaki tx ve rx bacakları olan 0.ve 1. girişlere tanımlanmıyor o yüzden bu ledide 2.girişe bağladım ve onfarsol diye bir bağlantı kalmadı artık onfarsol da onfarsag oldu
#define onfarsag    2

#define korna      13


int motorlar_hiz = 255;
byte son_islem;
void setup(){
  pinMode(sol_ileri, OUTPUT);
  pinMode(sag_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sag_geri, OUTPUT);
  pinMode(sol_hiz, OUTPUT);
  pinMode(sag_hiz, OUTPUT);
//  pinMode(onfarsol,OUTPUT);
  pinMode(onfarsag,OUTPUT);
  pinMode(korna,OUTPUT);
  Serial.begin(9600);
  bt_iletisim.begin(9600);
  }
  void loop(){
    if(bt_iletisim.available()){

      char data=bt_iletisim.read();
      Serial.println(data);

      if(data=='1'){
        dur();
        delay(10);
        ileri();
        son_islem=1;
        }
        else if(data=='2'){
          dur();
          delay(10);
          geri();
          son_islem=2;
          
          }
       else if(data=='3'){
        dur();
        delay(10);
        sol();
        son_islem=3;
        }
      else if(data=='4'){
        dur();
        delay(10);
        sag();
        son_islem=4;
        }
        else if(data=='9'){
          dur();
          delay(10);
          ses();
          son_islem=9;
          }
          else if(data=='6'){
            dur();
            
            }
            else if(data=='0'){
              motorlar_hiz=motorlar_hiz+25;
              if(motorlar_hiz>255){
                motorlar_hiz=255;
                }
               
                son_isleme_devam_et();
              }
              else if(data=='5'){
                motorlar_hiz=motorlar_hiz-25;
                if(motorlar_hiz<0){
                  motorlar_hiz=0;
                  }
                  
                  son_isleme_devam_et();
                }
          }
    }
void ileri()
{
  digitalWrite(korna,0);
  digitalWrite(onfarsag,1);
 // digitalWrite(onfarsol,1);
  digitalWrite(sol_ileri, 1);
  digitalWrite(sag_ileri, 1);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 0);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
}
void geri()
{
  digitalWrite(korna,0);
  //digitalWrite(onfarsol,0);
  digitalWrite(onfarsag,0);
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sol_geri, 1);
  digitalWrite(sag_geri, 1);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
}
void sol()
{
  digitalWrite(korna,0);
 // digitalWrite(onfarsol,1);
  digitalWrite(onfarsag,0);
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 1);
  digitalWrite(sol_geri, 1);
  digitalWrite(sag_geri, 0);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
  
 }

void sag()
{
  digitalWrite(korna,0);
  digitalWrite(onfarsag,0);
 // digitalWrite(onfarsol,0);
  digitalWrite(sol_ileri, 1);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 1);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
}
void dur()
{
  digitalWrite(korna,0);
  //digitalWrite(onfarsol,0);
  digitalWrite(onfarsag,0);
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 0);
  analogWrite(sol_hiz, 0);
  analogWrite(sag_hiz, 0);
}

void ses(){
  digitalWrite(korna,1);
  digitalWrite(onfarsag,0);
}

void son_isleme_devam_et(){
    if(son_islem==1){
      ileri();
      }
      else if(son_islem==2){
        geri();
        }
      else if(son_islem==3){
        sol();
        }
     else if(son_islem==4){
      sag();
      }
    
    }







