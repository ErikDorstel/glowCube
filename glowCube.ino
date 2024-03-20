bool debug=true;

const char* appName="glowCube";
const char* appDesc="RGB LED Cube";

#include "Cube.h"
#include "Palettes.h"
#include "Tilt.h"
#include "Apps.h"
#include "WLAN.h"
#include "DNS.h"
#include "HTTPserver.h"

#include "appFire.h"
#include "appPlasma.h"
#include "appRects.h"
#include "appFills.h"
#include "appAlarm.h"
#include "appInsects.h"
#include "appGlas.h"

void setup() {
  if (debug) { Serial.begin(115200); }
  initCube();
  initTilt();
  initWLAN();
  initDNS();
  initHTTPServer();

  initFire();
  initPlasma();
  initRects();
  initFills();
  initAlarm();
  initInsects();
  initGlas(); }

void loop() { apps.worker[apps.current](); appsWorker(); wlanWorker(); dnsWorker(); httpServerWorker(); }
