/*
   ______               _                  _///_ _           _                   _
  /   _  \             (_)                |  ___| |         | |                 (_)
  |  [_|  |__  ___  ___ _  ___  _ __      | |__ | | ___  ___| |_ _ __ ___  _ __  _  ___  _   _  ___
  |   ___/ _ \| __|| __| |/ _ \| '_ \_____|  __|| |/ _ \/  _|  _| '__/   \| '_ \| |/   \| | | |/ _ \
  |  |  | ( ) |__ ||__ | | ( ) | | | |____| |__ | |  __/| (_| |_| | | (_) | | | | | (_) | |_| |  __/
  \__|   \__,_|___||___|_|\___/|_| [_|    \____/|_|\___|\____\__\_|  \___/|_| |_|_|\__  |\__,_|\___|
                                                                                      | |
                                                                                      \_|
  Fichier :       prgArduino-1-EcritureDeTexte.ino
  
  Description :   Programme permettant d'écrire du texte sur un écran compatible Nokia 5110 (PCD8544),
                  avec un Arduino Nano, via un convertisseur de niveau logique à 8 canaux (TXS0108E)
                  
  Remarques :     La librairie utilisée ici sera la PCD8544 d'Adafruit (https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library)
                                    
  Auteur :        Jérôme TOMSKI (https://passionelectronique.fr/)
  Créé le :       05.12.2023

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

// Instanciation de cette librairie, de la sorte : "Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);"
Adafruit_PCD8544 ecranNokia5110 = Adafruit_PCD8544(brocheD4_arduino_vers_brocheCLK_ecranNokia, brocheD5_arduino_vers_brocheDIN_ecranNokia, brocheD6_arduino_vers_brocheDC_ecranNokia, brocheD7_arduino_vers_brocheCE_ecranNokia, brocheD8_arduino_vers_brocheRST_ecranNokia);



// ========================
// Initialisation programme
// ========================
void setup() {

  // Initialisation de la liaison série (PC <-> Arduino Nano), juste en cas de besoin, au niveau débug
  Serial.begin(9600);
  Serial.println(F("================================================================="));
  Serial.println(F("Exemple #1 : écriture de texte, sur l'écran compatible Nokia 5110"));
  Serial.println(F("================================================================="));
  Serial.println("");

  // Allumage du rétroéclairage de l'écran
  pinMode(brocheD3_arduino_vers_brocheLIGHT_ecranNokia, OUTPUT);
  digitalWrite(brocheD3_arduino_vers_brocheLIGHT_ecranNokia, LOW);

  // Écran Nokia 5110
	ecranNokia5110.begin();             // Initialisation
  ecranNokia5110.setContrast(56);     // Changement du contraste (entre 0 et 127) → à ajuster soi-même, au besoin
  ecranNokia5110.setBias(4);          // Changement du biais (entre 0 et 7)       → à ajuster soi-même, au besoin
  ecranNokia5110.clearDisplay();      // Effaçage de la mémoire tampon
  delay(500);

  // Suite du programme
  afficherDuTexteAlEcran();

}


// ===========================
// Afficher du texte à l'écran
// ===========================
void afficherDuTexteAlEcran() {
  
  ecranNokia5110.setTextSize(1);
	ecranNokia5110.setTextColor(BLACK);
	ecranNokia5110.setCursor(0,0);
	ecranNokia5110.println("Salut a tous !");         // Attention, les accents peuvent entraîner des problèmes d'affichage, comme c'est le cas avec le "à" ici
	ecranNokia5110.display();
    
}


// =================
// Boucle principale
// =================
void loop() {
  
    // Vide (tout se passe dans la fonction "loop", en fait)
    
}
