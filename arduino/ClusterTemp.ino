#include <TM1638.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// define a module on data pin 8, clock pin 9 and strobe pin 7
TM1638 module(D5, D6, D7);

const char *ssid = "NOMDEXARXA";
const char *password = "CONTRASENYA";

ESP8266WebServer server ( 80 );

int temp[7];
bool ciclo;
int maq;
char s[8];
int led;

void espera(int temps) {
  unsigned long ara = millis();
  unsigned long seguent = ara + temps;
  delay(1); //refresh watchdog
  while (millis()<seguent){
      server.handleClient();
  }
}

void canviar_temp() {
  int m,t;
  m = server.arg("maq").toInt();
  t = server.arg("temp").toInt();
  temp[m]=t;
  server.send(200, "text/html", "ok"); 
}

void setup() {
  temp[0]=51;
  temp[1]=52;
  temp[2]=53;
  temp[3]=54;
  temp[4]=55;
  temp[5]=56;
  temp[6]=57;
  ciclo = true;
  maq = 0;
  Serial.begin(115200);
  WiFi.begin ( ssid, password );
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/changeT", canviar_temp); 
  server.begin();

  sprintf(s, "CLUSTERT");
  module.setDisplayToString(s);
  espera(300);
  module.clearDisplay();
}

void loop() {
  sprintf(s, "C%01d %d^C", maq+1, temp[maq]);
  module.setDisplayToString(s);
  if (ciclo) {
    led = 1 << maq+8;
  }
  else {
    led = 1 << maq;
  }
  module.setLEDs(led);

  byte keys = module.getButtons();
  switch (keys) {
    case 0x80:
      ciclo = true;
      break;
    case 0x40:
      ciclo = false;
      maq = 6;
      break;
    case 0x20:
      ciclo = false;
      maq = 5;
      break;
    case 0x10:
      ciclo = false;
      maq = 4;
      break;
    case 0x8:
      ciclo = false;
      maq = 3;
      break;
    case 0x4:
      ciclo = false;
      maq = 2;
      break;
    case 0x2:
      ciclo = false;
      maq = 1;
      break;
    case 0x1:
      ciclo = false;
      maq = 0;
      break;
  }

  if(ciclo) {
    maq++;
    if(maq>6) maq=0;
  }
  espera(500);
}
