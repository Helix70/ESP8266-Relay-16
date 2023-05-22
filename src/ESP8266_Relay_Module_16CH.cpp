// REQUIRES the following Arduino libraries:
// - Lien vidéo: https://youtu.be/Q8P5yrs1a_w
// - Getting Started ESP8266 : https://youtu.be/QRnPRKbtEGU
// Find All "Great Projects" Videos : https://www.youtube.com/c/GreatProjects

#include <SPI.h>
#include <FS.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "index.h"
#include "credentials.h" // put overrides for ssid, pass, ip, dns, gateway etc here

#define NUM_RELAYS 16
#if NUM_RELAYS > 16
# error "NUM_RELAYS must not be larger than 16"
#endif

#define EEPROM_SIZE 2

ESP8266WebServer server(80);

#define DO_LATCH 0

IPAddress ip(192, 168, 97, 62);
IPAddress dns(192, 168, 97, 1);
IPAddress gateway(192, 168, 97, 1);
IPAddress gatewayap(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

// Master Branch -  Latching Relays

//***************************************************
// Create a credentials.h with the following defined
// const char *Apssid = "ESP8266-Relay-Ant-Protection";
// const char *Appassword = "3tawi-GP";
// char ssid[30] = "";
// char pass[30] = "";
// IPAddress ip(192, 168, 1, 62);
// IPAddress dns(192, 168, 1, 1);
// IPAddress gateway(192, 168, 1, 1);
// IPAddress gatewayap(192, 168, 4, 1);
// IPAddress subnet(255, 255, 255, 0);
//***************************************************

#define DELAY_MS 5
#define DELAYS_PER_SECOND (1000 / DELAY_MS)

#ifdef DO_LATCH
#define LATCH_TIMEOUT_SEC 10
#define LATCH_TIMEOUT_COUNT (LATCH_TIMEOUT_SEC * DELAYS_PER_SECOND)

int latchcounter3 = 0;
int latchcounter4 = 0;
#endif

void (*resetFunc)(void) = 0; // declare reset function at address 0

// Pin connected to ST_CP of 74HC595
uint8_t latchPin = 8;
// Pin connected to SH_CP of 74HC595
uint8_t clockPin = 12;
////Pin connected to DS of 74HC595
uint8_t dataPin = 11;
////Pin connected to OE of 74HC595
uint8_t enablePin = 11;

uint16_t relay_mask[NUM_RELAYS];
uint16_t relays; // short that holds the 16 bits

void createBitMask()
{
  for (int i = 0; i < NUM_RELAYS; i++)
  {
    relay_mask[i] = (0x01 << i);
  }
}

void writeRelays() // Write the contents of the relays array out to the relays
{
  uint8_t register_low;
  uint8_t register_high;

  register_low = (uint8_t)(relays & 0xff);
  register_high = (uint8_t)((relays >> 8) & 0xff);

  digitalWrite(latchPin, LOW);
  // shift out the bits:
  shiftOut(dataPin, clockPin, MSBFIRST, register_high);
  shiftOut(dataPin, clockPin, MSBFIRST, register_low);

  digitalWrite(latchPin, HIGH);

  // update EEPROM
  EEPROM.write(0,register_high);
  EEPROM.write(1,register_low);
  EEPROM.commit();
}

void allRelaysOff() // Clear relays variables
{
  relays = 0;
  writeRelays();
}

void allRelaysOn()
{
  #ifdef DO_LATCH
    relays = 0xfff3;  // leave relay 3 and 4 off - latching
  #else
    relays = 0xffff;
  #endif
  writeRelays();
}

uint8_t checkRelayNumber(uint8_t relay_number_u8)
{
  if ((relay_number_u8 < 1) || (relay_number_u8 > NUM_RELAYS))
  {
    Serial.println("Invalid relay selected! Must be 1-" + NUM_RELAYS);
    return 0;
  }
  return 1;
}

int getRelay(uint8_t relay_number_u8)
{
  if (!checkRelayNumber(relay_number_u8))
  {
    return -1;
  }

  return (relays & relay_mask[relay_number_u8]);
}

// relay_number_u8 is from 1 - 16
int setRelay(uint8_t relay_number_u8, uint8_t value_u8)
{
  if (!checkRelayNumber(relay_number_u8))
  {
    return -1;
  }

  if (value_u8)
  {
    // set register
    relays |= relay_mask[relay_number_u8 - 1];
  }
  else
  {
    // clear register
    relays &= ~relay_mask[relay_number_u8 - 1];
  }
  writeRelays();

  return 0;
}

int toggleRelay(uint8_t relay_number_u8)
{
  uint8_t value_u8;

  if (!checkRelayNumber(relay_number_u8))
  {
    return -1;
  }

  value_u8 = getRelay(relay_number_u8);
  if (value_u8)
  {
    setRelay(relay_number_u8, 0);
  }
  else
  {
    setRelay(relay_number_u8, 1);
  }

  return 0;
}

void handleRoot()
{
  String s = MAIN_page;             // Read HTML contents
  server.send(200, "text/html", s); // Send web page
}

void handleResetESP()
{
  handleRoot();
  delay(1000);
  resetFunc();
}

void getWifi()
{
  WiFi.config(ip, dns, gateway, subnet);
  int xc = 0;
  int attempts = 0;
  Serial.println("");
  Serial.println("");
  Serial.print("delaying start ");
  while (xc < 120)
  {
    Serial.print(".");
    delay(500);
    xc++;
  }
  Serial.println("*");

  while ((WiFi.status() != WL_CONNECTED) && (attempts <= 5))
  {
    WiFi.disconnect();
    WiFi.begin(ssid, pass);

    xc = 0;
    attempts++;
    Serial.print("attempt ");
    Serial.print(attempts);
    while ((WiFi.status() != WL_CONNECTED) && (xc < 60))
    {
      Serial.print(".");
      delay(500);
      xc++;
    }
    Serial.println("*");
  }

  Serial.println("");
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Status=WL_CONNECTED");
    Serial.print("CONNECTED To: ");
    Serial.println(ssid);
    Serial.print("IP Address: http://");
    Serial.println(WiFi.localIP().toString().c_str());
    WiFi.softAPdisconnect(true);
  }
  else
  {
    WiFi.disconnect();
    Serial.println("Status= NOT WL_CONNECTED");
    handleResetESP();
  }
}

#ifdef DO_LATCH
void setlatch_3()
{
  handleRoot();
  if ((latchcounter3 == 0) && (latchcounter4 == 0))
  {
    latchcounter3 = LATCH_TIMEOUT_COUNT;
    setRelay(3,HIGH);
  }
}

void setlatch_4()
{
  handleRoot();
  if ((latchcounter3 == 0) && (latchcounter4 == 0))
  {
    latchcounter4 = LATCH_TIMEOUT_COUNT;
    setRelay(4,HIGH);
  }
}

void clearlatch_3()
{
  handleRoot();
  setRelay(3,LOW);
}

void clearlatch_4()
{
  handleRoot();
  setRelay(4,LOW);
}
#endif

void handlestate1()
{
  handleRoot();
  toggleRelay(1);
}

void handlestate2()
{
  handleRoot();
  toggleRelay(2);
}

void handlestate3()
{
  handleRoot();
  toggleRelay(3);
}

void handlestate4()
{
  handleRoot();
  toggleRelay(4);
}

void handlestate5()
{
  handleRoot();
  toggleRelay(5);
}

void handlestate6()
{
  handleRoot();
  toggleRelay(6);
}

void handlestate7()
{
  handleRoot();
  toggleRelay(7);
}

void handlestate8()
{
  handleRoot();
  toggleRelay(8);
}

void handlestate9()
{
  handleRoot();
  toggleRelay(9);
}

void handlestate10()
{
  handleRoot();
  toggleRelay(10);
}

void handlestate11()
{
  handleRoot();
  toggleRelay(11);
}

void handlestate12()
{
  handleRoot();
  toggleRelay(12);
}

void handlestate13()
{
  handleRoot();
  toggleRelay(13);
}

void handlestate14()
{
  handleRoot();
  toggleRelay(14);
}


void handlestate15()
{
  handleRoot();
  toggleRelay(15);
}

void handlestate16()
{
  handleRoot();
  toggleRelay(16);
}

void handleallon()
{
  handleRoot();
  allRelaysOn();
}

void handlealloff()
{
  handleRoot();
  allRelaysOff();
}

void handlestate()
{
  String content = "<?xml version = \"1.0\" ?>";
  for (int i = 0; i<NUM_RELAYS; i++) {
    content += "<inputs><analog>";
    content += String(getRelay(i));
  }
  content += "</analog></inputs>";
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "text/xml", content); // Send web page
}

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW); // disable output (high-Z)

  Serial.begin(115200);
  EEPROM.begin(EEPROM_SIZE);
  
  uint8_t register_high = EEPROM.read(0);
  uint8_t register_low = EEPROM.read(1);
  relays = (register_high << 8) | register_low;
  writeRelays();

  createBitMask();

  WiFi.mode(WIFI_STA);
  getWifi();

  server.on("/", handleRoot);
  server.on("/LED1", handlestate1);
  server.on("/LED2", handlestate2);
#if DO_LATCH
  server.on("/LED3", setlatch_3);
  server.on("/LED4", setlatch_4);
#else
  server.on("/LED3", handlestate3);
  server.on("/LED4", handlestate4);
#endif
  server.on("/LED5", handlestate5);
  server.on("/LED6", handlestate6);
  server.on("/LED7", handlestate7);
  server.on("/LED8", handlestate8);
  server.on("/LED9", handlestate9);
  server.on("/LED10", handlestate10);
  server.on("/LED11", handlestate11);
  server.on("/LED12", handlestate12);
  server.on("/LED13", handlestate13);
  server.on("/LED14", handlestate14);
  server.on("/LED15", handlestate15);
  server.on("/LED16", handlestate16);
  server.on("/allon", handleallon);
  server.on("/alloff", handlealloff);
  server.on("/redstate", handlestate);
  server.on("/restesp", handleResetESP);
  server.begin();
}

#ifdef DO_LATCH
void handleCounters(void)
{
  // check if the latch is active
  if (latchcounter3 > 0)
  {
    // decrement the count
    latchcounter3--;
    if (latchcounter3 == 0)
    {
      // if expired, reset the latched relays and update the relay states
      clearlatch_3();
    }
  }
  if (latchcounter4 > 0)
  {
    // decrement the count
    latchcounter4--;
    if (latchcounter4 == 0)
    {
      // if expired, reset the latched relays and update the relay states
      clearlatch_4();
    }
  }
}
#endif

void loop()
{
#if DO_LATCH
  handleCounters();
#endif
  server.handleClient();
  delay(DELAY_MS);
}

