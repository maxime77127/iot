# iot


<h1>Descriptif du projet</h1>

Notre projet Iot est un jeu : Le joueur doit appuyer le plus rapidement sur le buzzer lorsque la LED s'allume.
Le composant néopixel s'allume en fonction du score que le joueur a fait, plus le joueur a appuyé rapidement et plus il y a de LED qui s'allume
rouge si le joueur appuie avant que la LED s'allume
bleu si le joueur appuie après que la LED s'allume

<h1> Montage arduino </h1>

<img src = "https://github.com/maxime77127/iot/blob/master/montage/IMG-4396.JPG" width="300">
<img src = "https://github.com/maxime77127/iot/blob/master/montage/IMG-4399.JPG" width="300">
<img src = "https://github.com/maxime77127/iot/blob/master/montage/IMG-4465.JPG" width="300">

<h1>Schéma</h1> 

<img src = "https://github.com/maxime77127/iot/blob/master/montage/Capture.JPG" width="500">

<h1>Composants</h1>

<img src = "https://github.com/maxime77127/iot/blob/master/montage/09190-03-L.jpg" width="300">
<img src = "https://github.com/maxime77127/iot/blob/master/montage/17855-dscn3894.JPG" width="300">
<img src = "https://github.com/maxime77127/iot/blob/master/montage/NEOPIXEL-STICK-8-x-5050-RGB-LED-WITH-INTEGRATED-DRIVERS-1426-00-600x600.jpg" width="300">
<img src = "https://github.com/maxime77127/iot/blob/master/montage/WEMOS-D1-mini-V3-0-0-WIFI-Internet-de-Choses-d-veloppement-conseil-bas-ESP8266-4.jpg_640x640.jpg" width="300">
<img src = "https://github.com/maxime77127/iot/blob/master/montage/a-1554.jpg" width="300">
<img src = "https://github.com/maxime77127/iot/blob/master/montage/s1533i11.PNG" width="300">

<h1>Configuration</h1>

Entrez le nom du wifi / mot de passe et nom du joueur
#include <Adafruit_NeoPixel.h>
#include "pitches.h"
#include <WiFiClient.h>
#include <ESP8266WebServer.h>



