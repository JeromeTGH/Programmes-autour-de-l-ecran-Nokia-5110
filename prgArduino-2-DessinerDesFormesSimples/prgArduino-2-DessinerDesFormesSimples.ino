/*
   ______               _                  _///_ _           _                   _
  /   _  \             (_)                |  ___| |         | |                 (_)
  |  [_|  |__  ___  ___ _  ___  _ __      | |__ | | ___  ___| |_ _ __ ___  _ __  _  ___  _   _  ___
  |   ___/ _ \| __|| __| |/ _ \| '_ \_____|  __|| |/ _ \/  _|  _| '__/   \| '_ \| |/   \| | | |/ _ \
  |  |  | ( ) |__ ||__ | | ( ) | | | |____| |__ | |  __/| (_| |_| | | (_) | | | | | (_) | |_| |  __/
  \__|   \__,_|___||___|_|\___/|_| [_|    \____/|_|\___|\____\__\_|  \___/|_| |_|_|\__  |\__,_|\___|
                                                                                      | |
                                                                                      \_|
  Fichier :       prgArduino-2-DessinerDesFormesSimples.ino
  
  Description :   Programme permettant de dessiner des formes simples sur un écran compatible Nokia 5110 (PCD8544),
                  avec un Arduino Nano, via un convertisseur de niveau logique à 8 canaux (TXS0108E)
                  
  Remarques :     - la librairie utilisée ici sera la PCD8544 d'Adafruit (https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library)
                  - certaines fonctionnalités d'affichage sont importées de la librairie GFX d'Adafruit (https://github.com/adafruit/Adafruit-GFX-Library)
                                    
  Auteur :        Jérôme TOMSKI (https://passionelectronique.fr/)
  Créé le :       06.12.2023

*/

// Inclusion de la librairie PCD8544 de Adafruit
#include <Adafruit_PCD8544.h>

// Définition des broches de raccordemenet Arduino ↔ convertisseur ↔ écranNokia
#define brocheD3_arduino_vers_brocheLIGHT_ecranNokia  3
#define brocheD4_arduino_vers_brocheCLK_ecranNokia    4
#define brocheD5_arduino_vers_brocheDIN_ecranNokia    5
#define brocheD6_arduino_vers_brocheDC_ecranNokia     6
#define brocheD7_arduino_vers_brocheCE_ecranNokia     7
#define brocheD8_arduino_vers_brocheRST_ecranNokia    8

// Instanciation de cette librairie, de telle sorte : "Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);"
Adafruit_PCD8544 ecranNokia5110 = Adafruit_PCD8544(brocheD4_arduino_vers_brocheCLK_ecranNokia, brocheD5_arduino_vers_brocheDIN_ecranNokia, brocheD6_arduino_vers_brocheDC_ecranNokia, brocheD7_arduino_vers_brocheCE_ecranNokia, brocheD8_arduino_vers_brocheRST_ecranNokia);



// ========================
// Initialisation programme
// ========================
void setup() {

  // Initialisation de la liaison série (PC <-> Arduino Nano), juste en cas de besoin, au niveau débug
  Serial.begin(9600);
  Serial.println(F("==========================================================================="));
  Serial.println(F("Exemple #2 : dessiner des formes simples, sur l'écran compatible Nokia 5110"));
  Serial.println(F("==========================================================================="));
  Serial.println("");

  // Allumage du rétroéclairage de l'écran
  pinMode(brocheD3_arduino_vers_brocheLIGHT_ecranNokia, OUTPUT);
  digitalWrite(brocheD3_arduino_vers_brocheLIGHT_ecranNokia, LOW);

  // Écran Nokia 5110
	ecranNokia5110.begin();             // Initialisation
  ecranNokia5110.setContrast(56);     // Changement du contraste (entre 0 et 127) → à ajuster soi-même, au besoin
  ecranNokia5110.setBias(4);          // Changement du biais (entre 0 et 7)       → à ajuster soi-même, au besoin
  delay(500);

}


// =================
// Boucle principale
// =================
void loop() {

  // Remarques :
  //    - clearDisplay() permet de vider la mémoire tampon de l'écran
  //    - display() permet d'envoyer le contenu de la mémoire tampon de l'écran à l'écran
  //    - drawRect(posX, posY, largeur, hauteur, couleur) permet de dessiner un rectangle (son contour) à l'écran, depuis la position (X,Y), avec pour dimension largeur x hauteur
  //    - fillRect(posX, posY, largeur, hauteur, couleur) fait la même chose que drawRect, mais rempli (noirci) à l'intérieur
  //    - drawRoundRect(posX, posY, largeur, hauteur, nbPixelsAngles, couleur) permet de dessiner un rectangle à bords arrondis (son contour) à l'écran, depuis la position (X,Y), avec dimensions largeur x hauteur, et des angles arrondis de nbPixelsAngles
  //    - fillRoundRect(posX, posY, largeur, hauteur, nbPixelsAngles, couleur) fait la même chose que drawRoundRect, mais rempli (noirci) à l'intérieur
  //    - drawCircle(posCentreX, posCentreY, rayon, couleur) permet de dessiner un cercle (son contour) à l'écran, avec pour centre la position (X,Y), et un rayon donné
  //    - fillCircle(posCentreX, posCentreY, rayon, couleur) fait la même chose que drawCircle, mais rempli (noirci) à l'intérieur
  //    - drawTriangle(Xhaut, Yhaut, Xgauche, Ygauche, Xdroite, Ydroite, couleur) permet de dessiner un triangle (son contour) à l'écran, avec (Xhaut, Yhaut) comme coordonnées pour le sommet, (Xgauche, Ygauche) pour l'angle gauche, et idem pour la droite
  //    - fillTriangle(Xhaut, Yhaut, Xgauche, Ygauche, Xdroite, Ydroite, couleur) fait la même chose que drawTriangle, mais rempli (noirci) à l'intérieur
  //    - drawLine(xDebut, yDebut, xFin, yFin, couleur) permet de dessiner une droite à l'écran, ayant pour point d'origine (xDebut, yDebut) et de fin (xFin, yFin)
  //    - drawPixel(posX, posY, couleur) permet de dessiner un point à l'écran, à la position (posX, posY)

  

  // Dessine un rectangle (son contour plutôt, devrais-je dire)
  ecranNokia5110.clearDisplay();
  ecranNokia5110.drawRect(10, 10, 64, 28, BLACK);
  ecranNokia5110.display();
  delay(2000);


  // Dessine un rectangle "plein"
  ecranNokia5110.clearDisplay();
  ecranNokia5110.fillRect(10, 10, 64, 28, BLACK);
  ecranNokia5110.display();
  delay(2000);


  // Dessine un rectangle à bords arrondis (son contour, uniquement)
  ecranNokia5110.clearDisplay();
  ecranNokia5110.drawRoundRect(10, 10, 64, 28, 8, BLACK);
  ecranNokia5110.display();
  delay(2000);


  // Dessine un rectangle "plein", à bords arrondis
  ecranNokia5110.clearDisplay();
  ecranNokia5110.fillRoundRect(10, 10, 64, 28, 8, BLACK);
  ecranNokia5110.display();
  delay(2000);


  // Dessine un cercle (son contour, uniquement) - nota : le rond ne sera pas très rond, à l'écran !
  ecranNokia5110.clearDisplay();
  ecranNokia5110.drawCircle(42, 24, 20, BLACK);
  ecranNokia5110.display();
  delay(2000);


  // Dessine un disque ("cercle rempli") - nota : le rond ne sera pas très rond à l'écran, là non plus !
  ecranNokia5110.clearDisplay();
  ecranNokia5110.fillCircle(42, 24, 20, BLACK);
  ecranNokia5110.display();
  delay(2000);


  // Dessine un triangle (son contour, uniquement)
  ecranNokia5110.clearDisplay();
  ecranNokia5110.drawTriangle(24, 4, 12, 40, 72, 40, BLACK);
  ecranNokia5110.display();
  delay(2000);


  // Dessine un triangle "rempli"
  ecranNokia5110.clearDisplay();
  ecranNokia5110.fillTriangle(24, 4, 12, 40, 72, 40, BLACK);
  ecranNokia5110.display();
  delay(2000);


  // Traçage de lignes aléatoires
  int xDebut, yDebut, xFin, yFin;
  ecranNokia5110.clearDisplay();
  for(int i = 0 ; i < 25 ; i++) {
    xDebut = random(0, 41);
    yDebut = random(0, 47);
    xFin = random(42, 83);
    yFin = random(0, 47);
    ecranNokia5110.drawLine(xDebut, yDebut, xFin, yFin, BLACK);
    ecranNokia5110.display();
    delay(200);
  }
  delay(2000);


  // Traçage de points aléatoires (comme des flocons de neige !)
  int posX, posY;
  ecranNokia5110.clearDisplay();
  for(int j = 0 ; j < 500 ; j++) {
    posX = random(0, 87);
    posY = random(0, 47);
    ecranNokia5110.drawPixel(posX, posY, BLACK);
    ecranNokia5110.display();
    delay(10);
  }
  delay(2000);


  // Et on reboucle ce programme à l'infini, pour le fun !
  
}
