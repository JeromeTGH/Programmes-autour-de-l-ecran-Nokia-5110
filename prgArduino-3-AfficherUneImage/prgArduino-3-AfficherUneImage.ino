/*
   ______               _                  _///_ _           _                   _
  /   _  \             (_)                |  ___| |         | |                 (_)
  |  [_|  |__  ___  ___ _  ___  _ __      | |__ | | ___  ___| |_ _ __ ___  _ __  _  ___  _   _  ___
  |   ___/ _ \| __|| __| |/ _ \| '_ \_____|  __|| |/ _ \/  _|  _| '__/   \| '_ \| |/   \| | | |/ _ \
  |  |  | ( ) |__ ||__ | | ( ) | | | |____| |__ | |  __/| (_| |_| | | (_) | | | | | (_) | |_| |  __/
  \__|   \__,_|___||___|_|\___/|_| [_|    \____/|_|\___|\____\__\_|  \___/|_| |_|_|\__  |\__,_|\___|
                                                                                      | |
                                                                                      \_|
  Fichier :       prgArduino-3-AfficherUneImage.ino
  
  Description :   Programme permettant d'afficher une image sur un écran compatible Nokia 5110 (PCD8544),
                  avec un Arduino Nano, via un convertisseur de niveau logique à 8 canaux (TXS0108E)
                  
  Remarques :     - la librairie utilisée ici sera la PCD8544 d'Adafruit (https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library)
                  - la conversion "JPG" → "code arduino" de l'image sera fait depuis le site "image2cpp" (https://javl.github.io/image2cpp/)
                                    
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

// Image à afficher
const unsigned char image_a_afficher [] PROGMEM = {
  // 'logo_pse_nb_48x48, 48x48px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x38, 0x08, 0x00, 0x00, 0x00, 0x00, 0x19, 0x88, 0x00, 0x00, 0x00, 0x00, 0x19, 0x89, 0xc0, 0x00, 
  0x00, 0x01, 0x19, 0x89, 0xc0, 0x00, 0x00, 0x01, 0x99, 0x89, 0x80, 0x00, 0x00, 0x01, 0x99, 0x89, 
  0x80, 0x00, 0x00, 0x01, 0x19, 0x88, 0x80, 0x00, 0x00, 0x01, 0x99, 0x89, 0x80, 0x00, 0x00, 0x03, 
  0xff, 0xff, 0xc0, 0x40, 0x03, 0xf2, 0x00, 0x00, 0x4f, 0xe0, 0x03, 0xfa, 0x00, 0x02, 0x5f, 0xf0, 
  0x00, 0x02, 0x00, 0x03, 0x60, 0x40, 0x00, 0x02, 0x00, 0x03, 0x60, 0x00, 0x07, 0xfa, 0x1f, 0xf8, 
  0x48, 0x60, 0x07, 0xf2, 0x30, 0x0c, 0x5f, 0xf8, 0x00, 0x02, 0x30, 0x0c, 0x60, 0x00, 0x00, 0x02, 
  0x30, 0x0c, 0x60, 0x00, 0x3c, 0xf2, 0x30, 0x0c, 0x4b, 0x80, 0x3f, 0xfa, 0x30, 0x0c, 0x5f, 0x80, 
  0x38, 0x02, 0x30, 0x0c, 0x63, 0x80, 0x00, 0x02, 0x30, 0x0c, 0x60, 0x00, 0x00, 0x02, 0x30, 0x04, 
  0x60, 0x00, 0x00, 0xfa, 0x30, 0x0c, 0x5f, 0xe0, 0x00, 0x12, 0x1f, 0xf8, 0x68, 0x00, 0x00, 0x06, 
  0x00, 0x00, 0x60, 0x00, 0x03, 0x02, 0x00, 0x00, 0x40, 0x00, 0x07, 0xfa, 0x00, 0x00, 0x5f, 0x80, 
  0x03, 0x83, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0x91, 0x89, 0x80, 0x00, 0x00, 0x01, 0x91, 0x89, 0x80, 0x00, 0x00, 0x01, 
  0x91, 0x89, 0x80, 0x00, 0x00, 0x01, 0xb9, 0x99, 0x80, 0x00, 0x00, 0x01, 0xbd, 0x89, 0x80, 0x00, 
  0x00, 0x01, 0xb9, 0x88, 0x80, 0x00, 0x00, 0x01, 0x81, 0x81, 0xc0, 0x00, 0x00, 0x01, 0x01, 0x81, 
  0xc0, 0x00, 0x00, 0x00, 0x01, 0x81, 0x80, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// ========================
// Initialisation programme
// ========================
void setup() {

  // Initialisation de la liaison série (PC <-> Arduino Nano), juste en cas de besoin, au niveau débug
  Serial.begin(9600);
  Serial.println(F("================================================================="));
  Serial.println(F("Exemple #3 : afficher une image sur l'écran compatible Nokia 5110"));
  Serial.println(F("================================================================="));
  Serial.println("");

  // Allumage du rétroéclairage de l'écran
  pinMode(brocheD3_arduino_vers_brocheLIGHT_ecranNokia, OUTPUT);
  digitalWrite(brocheD3_arduino_vers_brocheLIGHT_ecranNokia, LOW);

  // Écran Nokia 5110
	ecranNokia5110.begin();             // Initialisation
  ecranNokia5110.setContrast(56);     // Changement du contraste (entre 0 et 127)   → à ajuster soi-même, au besoin
  ecranNokia5110.setBias(4);          // Changement du biais (entre 0 et 7)         → à ajuster soi-même, au besoin
  delay(500);

  // Affichage de l'image sur l'écran
  ecranNokia5110.clearDisplay();
  ecranNokia5110.drawBitmap(18, 0, image_a_afficher, 48, 48, BLACK);        // drawBitmap(posX, posY, tableau_code_image, largeur, hauteur, couleur);
  ecranNokia5110.display();
  
}


// =================
// Boucle principale
// =================
void loop() {

  // Rien ici … !
  // (tout se passe dans la partie "setup", en fait !)
  
}
