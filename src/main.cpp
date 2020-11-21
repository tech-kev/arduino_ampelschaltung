#include <Arduino.h>

//Variablen Definieren
int carredpin = 12;
int caryellowpin = 11;
int cargreenpin = 10;
int predpin = 9;
int pgreenpin = 8;
int buzzer = 7;
int buttonpin = 2;
int buttonstate = 0;


void setup() {
  pinMode(carredpin, OUTPUT); //Pin als Output definieren
  pinMode(caryellowpin, OUTPUT);
  pinMode(cargreenpin, OUTPUT);
  pinMode(predpin, OUTPUT);
  pinMode(pgreenpin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP); //Pin als Input definieren
  Serial.begin(9600); //Serielle Schnittstelle für Debugging aktivieren
}

void loop() {
  buttonstate = digitalRead(buttonpin); //Aktuellen Status des Buttons in Variable laden
  //Serial.println(buttonstate); //Debugausgabe des Variablenwerts 
  digitalWrite(cargreenpin, HIGH); //Grüne LED einschalten
  digitalWrite(predpin, HIGH);   

  if (buttonstate == 1) //Wenn Button gedrückt wird
  {
    delay(2000); //Pause von 2s
    digitalWrite(cargreenpin, LOW);
    digitalWrite(caryellowpin, HIGH);
    delay(2500);
    digitalWrite(caryellowpin, LOW);
    digitalWrite(carredpin, HIGH);
    delay(2000);
    tone(buzzer, 450);
    digitalWrite(pgreenpin, HIGH);
    digitalWrite(predpin, LOW);
    delay(9000);
    noTone(buzzer);
    digitalWrite(pgreenpin, LOW);
    digitalWrite(predpin, HIGH);
    delay(3000);
    digitalWrite(caryellowpin, HIGH);
    delay(2500);
    digitalWrite(caryellowpin, LOW);
    digitalWrite(carredpin, LOW);
  }
}