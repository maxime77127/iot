#include <Adafruit_NeoPixel.h>
#include "pitches.h"
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define ssid      "Maxime"       // WiFi SSID
#define password  "14071993"  // WiFi password

// Création des objets
ESP8266WebServer server ( 80 );

#define PIN_MUSIC  D5
#define PIN          D4
#define LED  D6
#define BUTTON_PIN   D2
#define NUMPIXELS      8

int fin = 0;

String array_nom[10]={"Joueur1","Joueur2","Joueur3","Joueur4","Joueur5","Joueur6","Joueur7","Joueur8","Joueur9","Joueur10"};
int array_temps[10] = {3000, 3000, 3000, 3000, 3000, 3000, 3000, 3000, 3000, 3000};
unsigned long temps_partie = 4000;
unsigned long tempsLancement = random(5000, 10000);;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//page web
String getPage() {
  String page = "<html lang=fr-FR><head><meta http-equiv='refresh' content='10'/>";
  page += "<title>Reflex-Lum</title>";
  page += "<style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style>";
  page += "</head><body><h1>Reflex-Lum</h1>";
  page += "<form action='/' method='POST'>";
  page += "Votre nom";
  page += "<input type=\"text\"/ name=\"nom\">";
  page += "<br>";
  page += "<br>";
  page += "<INPUT type='submit' value='Start'>";
  page += "<br>";
  page += "<br>";
  page += "<br>";
  page += "<TABLE BORDER>";
  page += "<TR>";
  page += "<TH COLSPAN=3>TABLEAU TOP 10</TH>";
  page += "</TR>";
  page += "<TR>";
  page += "<TH>Rang</TH> <TH>Nom</TH> <TH>SCORE</TH>";
  page += "</TR>";
  for (int i = 0; i < 10; i++) {
    page += "<TR>";
    page += "<TD>";
    page += i+1;
    page += "</TD> <TD>";
    page += array_nom[i];
    page += "</TD> <TD>";
    page += array_temps[i];
    page += "</TD>";
    page += "<TR>";
  }
  page += "</TABLE>";
  page += "</body></html>";

  return page;
}

void handleRoot() {

  handleSubmit();
}

void handleSubmit() {

  server.send ( 200, "text/html", getPage() );
}

//classement
void array_classement(String nom, int temps) {

  String tmp_nom;
  int tmp_temps;
  String tmp_nom2;
  int tmp_temps2;

  for (int i = 0; i <= 9; i++) {
    if (temps < array_temps[i]) {
      if(i==0)
      playMusicVictory();
      tmp_temps = array_temps[i];
      tmp_nom = array_nom[i];
      array_temps[i] = temps;
      array_nom[i] = nom;
      for (i = i + 1; i <= 9; i++) {
        tmp_temps2 = array_temps[i];
        tmp_nom2 = array_nom[i];
        array_temps[i] = tmp_temps;
        array_nom[i] = tmp_nom;
        tmp_temps = tmp_temps2;
        tmp_nom = tmp_nom2;
      }
    }
  }
}

//classemnt LED
void classement(int temps) {
  if (temps <= 200) {
    for (int i = 0; i < 8; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 150));
      pixels.show();
      delay(1500);
    }
  }
  else if (temps <= 300) {
    for (int i = 0; i < 7; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 150));
      pixels.show();
      delay(1500);
    }
  }
  else if (temps <= 400) {
    for (int i = 0; i < 6; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 150));
      pixels.show();
      delay(1500);
    }
  }
  else if (temps <= 500) {
    for (int i = 0; i < 5; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 150));
      pixels.show();
      delay(1500);
    }
  }
  else if (temps <= 600) {
    for (int i = 0; i < 4; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 150));
      pixels.show();
      delay(1500);
    }
  }
  else if (temps <= 700) {
    for (int i = 0; i < 3; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 150));
      pixels.show();
      delay(1500);
    }
  }
  else if (temps <= 8000) {
    for (int i = 0; i < 2; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 150));
      pixels.show();
      delay(1500);
    }
  }
  else
    for (int i = 0; i < 1; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 150));
      pixels.show();
    }
}

void erreure() {
  for (int i = 0; i <= 8; i++) {
    pixels.setPixelColor(i, pixels.Color(150, 0, 0));
    pixels.show();
    delay(500);
    playMusicDefeat();
  }
}

void playMusic(const int noteNumber, const int speedNote, const int noteDurations[], const int melody[]) {
  for (int thisNote = 0; thisNote < 11; thisNote++) {
    int noteDuration = speedNote / noteDurations[thisNote];
    tone(PIN_MUSIC, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(PIN_MUSIC);
  }
}

void playMusicVictory() {
  const int notesVictory[] = {  NOTE_ZERO, NOTE_C6 , NOTE_C6, NOTE_C6, NOTE_C6, NOTE_GS5 , NOTE_AS5 , NOTE_C6, NOTE_ZERO , NOTE_AS5 , NOTE_C6};
  const int rythmeVictory[] = { 2, 12, 12, 12, 4, 4, 4, 12, 16, 12, 1 };
  const int speedNoteVictory = 1500;

  playMusic(sizeof(notesVictory) / sizeof(int), speedNoteVictory, rythmeVictory,  notesVictory);
}

void playMusicDefeat() {
  const int notesDefeat[] = { NOTE_B4, NOTE_F5, NOTE_ZERO , NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_E4, NOTE_ZERO, NOTE_E4 , NOTE_C4 };
  const int noteDurations[] = { 4, 4, 4, 4, 3, 3, 3, 4, 4, 4, 4, 4 };
  const int speedNote = 500;

  playMusic(sizeof(notesDefeat) / sizeof(int), speedNote, noteDurations,  notesDefeat);
}

// the setup function runs once when you press reset or power the board
void setup() {
  // Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show(); // Pixels off

  //server
  Serial.begin ( 115200 );
  WiFi.begin ( ssid, password );
  // Attente de la connexion au réseau WiFi / Wait for connection
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 ); Serial.print ( "." );
  }
  // Connexion WiFi établie / WiFi connexion is OK
  Serial.println ( "" );
  Serial.print ( "Connected to " ); Serial.println ( ssid );
  Serial.print ( "IP address: " ); Serial.println ( WiFi.localIP() );

  // On branche la fonction qui gère la premiere page / link to the function that manage launch page
  server.on ( "/", handleRoot );

  server.begin();
  Serial.println ( "HTTP server started" );



}


// the loop function runs over and over again forever
void loop() {


  //Server
  server.handleClient();
  ///////////
  unsigned long now = millis();

  int buttonState = digitalRead(BUTTON_PIN);
  // Serial.println(buttonState); 

  if (now < tempsLancement && buttonState == LOW) // erreur
   erreure();


 else if (now > tempsLancement) { //demarre dès que le random est dépassé
    digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)



    if (buttonState == LOW) { //fin de la partie
      temps_partie = now - tempsLancement;
      fin = 1;
    }

    if (fin == HIGH) { // affiche le classement et éteint la led
      digitalWrite(LED, LOW);
      // Serial.println(temps);
      classement(temps_partie);
      array_classement(server.arg("nom"), temps_partie);

    }
  }


}

