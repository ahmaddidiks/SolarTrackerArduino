#include <Servo.h> //library servo

//variabel
unsigned int ski,ska; //sensor
unsigned int pos =90; //posisi sudut servo (posisi saat pertama hidupkan di anggap tegak (90 derajat)) 
int error; //error
int offset = 3; //error yg di tolerir

Servo myservo; // inisiasi nama servo

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A3, INPUT);
pinMode(A2, INPUT);
myservo.attach(9); //servo nyambung ke pin D9
}

void loop() {
  // put your main code here, to run repeatedly:
ski = 1023 - analogRead(A3); //membaca nilasi sensor kiri
ska = 1023 - analogRead(A2); //membaca nilasi sensor kanan

//on off
error = ski-ska;
if (error >= -offset && error <= offset) pos = pos;
else if (error < -offset) { 
                        if (pos > 50) pos--;
                        else pos = 50;                
                      }
else if (error > offset) { 
                        if (pos < 130) pos++;
                        else pos = 130;                
                      }
//menggerakan servo sesuai sudut
myservo.write(pos); //perintah servo bergerak ke sudut perhitungan

//menampilkan data di monitor
Serial.print("sensor kanan = ");
Serial.print(ska);
Serial.print("      ");
Serial.print("sensor kiri = ");
Serial.print(ski);
Serial.print("      ");
Serial.print("error (kiri - kanan) = ");
Serial.print(error);
Serial.print("      ");
Serial.print("sudut = ");
Serial.println(pos);
delay(100);

}