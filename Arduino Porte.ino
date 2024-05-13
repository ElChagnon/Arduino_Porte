#include <Keypad.h>
#include <SPI.h>
#include <MFRC522.h>
// Importation des librairie pour le pavé numérie et le lecteur RFID

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);
// Définie les port pour le lecteur RFID


byte nuidPICC[4];

const byte Longueur = 4; 
const byte Largeur = 4;
const byte Led_Verte = A0;
const byte Led_Rouge = A1;

// Définie Les ports Utilisé pour la Led ainsi que le nombre de bouton sur la largeur et la longueur du pavé numérique

char hexaKeys[Largeur][Longueur] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[Longueur] = {4, 3, 2, A5};
byte colPins[Largeur] = {8, 7, 6, 5}; 

// Définie les port utilisé pour le pavé numérique

Keypad digicode = Keypad(makeKeymap(hexaKeys), rowPins, colPins, Longueur, Largeur); 

void setup(){
  Serial.begin(9600);
  pinMode(Led_Verte, OUTPUT);
  SPI.begin();
 rfid.PCD_Init();
 digitalWrite(Led_Verte, LOW);
}


const String mdp = "123";
String keyOk[]={"f2 c7 be cd","32 ac 68 d6","92 bf 79 d6"};
String input_password;

// Permet de définir les mots de passe valide pour ouvrir la port (ou allumer la led)

void loop() { // Fait une boucle 
  RFID(); // Renvoie vers la fonction qui permet de lire le badge rfid
  Code(); // Renvoie vers la fonction qui permet de lire le pavé numérique
}
  
  
void Code() {   
  delay(200); 
  char key = digicode.getKey();
  if (key){
    Serial.println(key);
    if(key == 'A') { // Permet de reset le mdp 
      input_password = ""; 
      digitalWrite(Led_Rouge, HIGH);
      delay(100);
      digitalWrite(Led_Rouge, LOW); // Allume la led pour confirmer que cela fonctionne 
    Serial.println("Insérer De Nouveau Le Mot De Passe"); // Met dans le Moniteur Série
    } else if(key == 'D') {
      if(input_password == mdp) {
        Serial.println("Bon Mot De Passe");
        delay(1000);
        Serial.println("Ouverture des portes");
        digitalWrite(Led_Verte, HIGH);
        delay(5000);
        digitalWrite(Led_Verte, LOW); // Allume la led si le code est bon (ou le module relai)
        Serial.println("Fermeture des portes");

      } else {
        Serial.println("Mauvais Mot De Passe"); 
        digitalWrite(Led_Rouge, HIGH);
        delay(100);
        digitalWrite(Led_Rouge, LOW);
      }
      input_password = ""; // Reset le Mdp si le code est mauvais 
    } else {
      input_password += key;
    }
  }
}

void RFID(){ // Fonction pour lire le Badge RFID 
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  if ( ! rfid.PICC_ReadCardSerial())
    return;
    
String myKey=String(rfid.uid.uidByte[0],HEX) + " " + String(rfid.uid.uidByte[1],HEX) + " " + String(rfid.uid.uidByte[2],HEX) + " " + String(rfid.uid.uidByte[3],HEX);
// Récupère les données de la Carte

Serial.println(myKey); // Met dans le moniteur série la valeur de la carte (inutile si non branché)
bool accessOk = 0;
for(int y = 0; y < (sizeof(keyOk)/sizeof(String)) ; y++){

  if(keyOk[y] == myKey){ 
    accessOk = 1; // Si la clé est bonne renvoie met accessOk à 1
  }

}

 
  rfid.PICC_HaltA();

 
  rfid.PCD_StopCrypto1();


  if(accessOk == 1){ // Si accès ok est à 1 allume la led (ou module relais)
    digitalWrite(Led_Verte,HIGH);
    Serial.println("Bon Mot De Passe");
    Serial.println("Ouverture des portes");
    delay(5000); 
    digitalWrite(Led_Verte,LOW);
    Serial.println("Fermeture des portes");

    }

  if(accessOk == 0){ // Si accès ok est à 0 (donc mauvaise carte) allume la led (ou module relais)
    digitalWrite(Led_Rouge,HIGH);
    Serial.println("Mauvais Mot De Passe");
    delay(5000); 
    digitalWrite(Led_Rouge,LOW);


  
    
  }

}
