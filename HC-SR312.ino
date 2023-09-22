// Définition des broches

#define LED_PIN 13 // Broche de la LED

#define SENSOR_PIN 2 // Broche du capteur SENSOR

// Définition des variables

int sensorState = LOW; // Etat initial du capteur

int sensorValue; // Valeur lue sur le capteur

void setup() {

  // Initialiser la communication série à 9600 bauds , la vitesse

  //de transfert entre l'Arduino et l'ordinateur

  Serial.begin(9600);

  // Initialisation des broches

  pinMode(LED_PIN, OUTPUT); // Broche de la LED en sortie

  pinMode(SENSOR_PIN, INPUT); // Broche du capteur SENSOR en entrée

} 

void loop() {

  // Lecture de la valeur du capteur

  sensorValue = digitalRead(SENSOR_PIN);

  // Si le capteur détecte un mouvement

  if (sensorValue == HIGH) {

    // Allumer la LED

    digitalWrite(LED_PIN, HIGH);

    // Si l'état du capteur a changé

    if (sensorState == LOW) {

      // Afficher un message sur le moniteur série

      Serial.println("------------------------------------------------------------------     " );

      Serial.println("     " );

      Serial.println("Mouvement détecté !");

      // Mettre à jour l'état du capteur

      sensorState = HIGH;

    }

  }

  // Sinon, si le capteur ne détecte pas de mouvement

  else {

    // Eteindre la LED

    digitalWrite(LED_PIN, LOW);

    // Si l'état du capteur a changé

    if (sensorState == HIGH) {

      // Afficher un message sur le moniteur série

      Serial.println("------------------------------------------------------------------     " );

      Serial.println("     " );

      Serial.println("aucun mouvement détecté!");

      // Mettre à jour l'état du capteur

      sensorState = LOW;

    }

  }

}
