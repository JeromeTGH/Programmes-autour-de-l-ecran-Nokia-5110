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
                  
  Remarques :     - la librairie utilisée ici sera la PCD8544 d'Adafruit (https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library)
                  - certaines fonctionnalités d'affichage sont importées de la librairie GFX d'Adafruit (https://github.com/adafruit/Adafruit-GFX-Library)
                                    
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
  delay(500);

}


// =================
// Boucle principale
// =================
void loop() {

  // Remarques :
  //    - clearDisplay() permet de vider la mémoire tampon de l'écran
  //    - display() permet d'envoyer le contenu de la mémoire tampon de l'écran à l'écran
  //    - setTextSize(taille) permet de sélectionner la taille du texte à afficher (tailles possibles : 1, 2, 3, …)
  //    - setTextColor(couleur) permet "d'écrire" de la couleur indiquée (par exemple, "BLACK" permet d'écrire en noir sur l'écran LCD)
  //    - setTextColor(couleur, fond) permet "d'écrire" de la couleur indiquée sur le fond spécifié (par exemple, "WHITE, BLACK" permet d'écrire en blanc sur fond noir)
  //    - setCursor(x,y) permet de positionner le "curseur" à la position (x,y) (x correspondant au nbre de pixels sur l'axe horizontal, et y le nbre de px sur l'axe vertical ; l'origine étant en haut/à gauche)
  //    - print(texte) permet d'écrire du texte, à la position courante du "curseur"
  //    - println(texte) permet d'écrire du texte à la position courante du "curseur", puis de faire un saut à la ligne (déplace le curseur vers le bas pour la ligne suivante, donc)
  //    - print(nombre, base) permet d'écrire un nombre à l'écran, dans la base indiquée, avec HEX (hexadécimal) pour la base 16, DEC (décimal) pour base 10, OCT (octal) pour base 8, et BIN (binaire) pour la base 2
  //      exemples : print(0xFF, HEX) affichera "FF", et print(0xFF, DEC) affichera 255 (puisque 0xFF en hexadécimal/base16 vaut 255 en décimal/base10)
  //    - certains accents s'affichent mal à l'écran, c'est pourquoi je les ai enlevé (et mis par exemple "Bonjour a tous", à la place de "Bonjour à tous"

  
  // Affiche le texte "Bonjour à tous" à l'écran
  ecranNokia5110.clearDisplay();
  ecranNokia5110.setTextSize(1);
  ecranNokia5110.setTextColor(BLACK);
  ecranNokia5110.setCursor(0,20);
  ecranNokia5110.println("Salut a tous !");
  ecranNokia5110.display();
  delay(2000);


  // Affiche le même texte, mais en "blanc sur fond noir" (mode "inversé")
  ecranNokia5110.clearDisplay();
  ecranNokia5110.setTextColor(WHITE, BLACK); // 'inverted' text
  ecranNokia5110.setCursor(0,20);
  ecranNokia5110.println("Salut a tous !");
  ecranNokia5110.display();
  delay(2000);
  
  
    
}
