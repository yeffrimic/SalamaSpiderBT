/*
    Este softwares fue creado para demostrar el uso
    del modulo bluetooth hc-05 en la universidad mariano
    galvez de guatemala en Salama Baja verapaz
    Gracias por la invitacion
    Yeffri J. Salazar Comunidad Arduino Guatemala.

*/


#include "LedControl.h"
#include <SoftwareSerial.h>;
SoftwareSerial BT(8, 9); //rx,tx
LedControl lc = LedControl(16, 15, 10, 1); // leonardo
//LedControl lc=LedControl(12,11,10,1);// old wire uno, mega.
byte derecha[] = {
  B00010000,
  B00111000,
  B01111100,
  B00111000,
  B00111000,
  B00111000,
  B00111000,
  B00111000,
};
byte izquierda[] = {
  B00111000,
  B00111000,
  B00111000,
  B00111000,
  B00111000,
  B01111100,
  B00111000,
  B00010000,
};

byte arriba[] = {
  B00000000,
  B00000000,
  B00000100,
  B11111110,
  B11111111,
  B11111110,
  B00000100,
  B00000000
};

byte abajo[] = {
  B00000000,
  B00000000,
  B00100000,
  B01111111,
  B11111111,
  B01111111,
  B00100000,
  B00000000,
};
byte parar[] = {
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100
};


void setup() {
  // put your setup code here, to run once:

  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);

  BT.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  while (!BT) {
    ; // wait for BT port to connect. Needed for native USB port only
  }
}





void loop() {
  // put your main code here, to run repeatedly:
  if (BT.available() > 0) {
    char a = BT.read();
    BT.println(a);
    switch (a) {
      case 'a':
        for (int i = 0; i < 8; i++) {
          lc.setRow(0, i, derecha[i]);
        }
        digitalWrite(2, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        break;
      case 's':
        for (int i = 0; i < 8; i++) {
          lc.setRow(0, i, abajo[i]);
        }
        digitalWrite(5, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        break;
      case 'd':
        for (int i = 0; i < 8; i++) {
          lc.setRow(0, i, izquierda[i]);
        }
        digitalWrite(3, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(2, LOW);
        digitalWrite(4, LOW);
        break;
      case 'w': for (int i = 0; i < 8; i++) {
          lc.setRow(0, i, arriba[i]);
        }
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
        break;
      case 'q':
        for (int i = 0; i < 8; i++) {
          lc.setRow(0, i, parar[i]);
        }
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
        break;

    }
  }
}
