TaskHandle_t MaTache;

void tacheCore0(void * parameter)
{
  while(true)
  {
    Serial.println("Je tourne sur le coeur 0");
    delay(1000);
  }
}

void setup()
{
  Serial.begin(115200);

  xTaskCreatePinnedToCore(
    tacheCore0,      // fonction
    "Tache0",        // nom
    10000,           // taille pile
    NULL,            // paramètre
    1,               // priorité
    &MaTache,        // handle
    0                // coeur 0
  );
}

void loop()
{
  Serial.println("Je tourne sur le coeur 1");
  delay(500);
}