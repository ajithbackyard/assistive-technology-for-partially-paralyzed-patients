#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

const char* ssid = "vivo 1951";
const char* password = "iamajith";

// Initialize Telegram BOT
#define BOTtoken "5466187759:AAHbinA5FYc9RtclBZvOkeiw2xvY89rhWpo"  

#define CHAT_ID "739056624"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

const int flexpin1 = 14; 
const int flexpin2 = 12; 
const int flexpin3 = 13; 
const int flexpin4 = 15; 
const int flexpin5 = 4; 
bool water = false;
bool food = false;
bool emergency = false;
bool music = false;
bool light = false;

void ICACHE_RAM_ATTR waters() {
  water = true;
}
void ICACHE_RAM_ATTR foods() {
  food = true;
}
void ICACHE_RAM_ATTR emergencys() {
  emergency = true;
}
void ICACHE_RAM_ATTR musics() {
  music = true;
}
void ICACHE_RAM_ATTR lights() {
  light = true;
}


void setup() {
  Serial.begin(115200);
  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org

  // PIR Motion Sensor mode INPUT_PULLUP
  pinMode(flexpin1, INPUT_PULLUP);
  pinMode(flexpin2, INPUT_PULLUP);
  pinMode(flexpin3, INPUT_PULLUP);
  pinMode(flexpin4, INPUT_PULLUP);
  pinMode(flexpin5, INPUT_PULLUP);
  // Set motionSensor pin as interrupt, assign interrupt function and set RISING mode
  attachInterrupt(digitalPinToInterrupt(flexpin1), waters, RISING);
  attachInterrupt(digitalPinToInterrupt(flexpin2), foods, RISING);
  attachInterrupt(digitalPinToInterrupt(flexpin3), emergencys, RISING);
  attachInterrupt(digitalPinToInterrupt(flexpin4), musics, RISING);
  attachInterrupt(digitalPinToInterrupt(flexpin5), lights, RISING);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  bot.sendMessage(CHAT_ID, "Bot started up", "");
}

void loop() {
  if(water){
    bot.sendMessage(CHAT_ID, "Water!!", "");
    Serial.println("water");
    water = false;
  }
  else if(food){
    bot.sendMessage(CHAT_ID, "Food!!", "");
    Serial.println("food");
    food = false;
  }
  else if(emergency){
    bot.sendMessage(CHAT_ID, "Emergency!!", "");
    Serial.println("Emergency");
    emergency = false;
  }
  else if(music){
    bot.sendMessage(CHAT_ID, "Music!!", "");
    Serial.println("Music");
    music = false;
  }
  else if(light){
    bot.sendMessage(CHAT_ID, "light!!", "");
    Serial.println("light");
    light = false;
  }
}
