#include <FastLED.h>

#define width   32
#define height  12
#define centreX 15
#define centreY  5

CRGB cube[5][64];

const uint16_t transform[32][4]=
{ { 64,64,64, 7 },{ 64,64,14, 6 },{ 64,21,13, 5 },{ 28,20,12, 4 },{ 64,19,11, 3 },{ 64,64,10, 2 },{ 64,64,64, 1 },{ 64,64,64,64 },
  { 64,64,64, 0 },{ 64,64, 9, 8 },{ 64,18,17,16 },{ 27,26,25,24 },{ 64,34,33,32 },{ 64,64,41,40 },{ 64,64,64,48 },{ 64,64,64,64 },
  { 64,64,64,56 },{ 64,64,49,57 },{ 64,42,50,58 },{ 35,43,51,59 },{ 64,44,52,60 },{ 64,64,53,61 },{ 64,64,64,62 },{ 64,64,64,64 },
  { 64,64,64,63 },{ 64,64,54,55 },{ 64,45,46,47 },{ 36,37,38,39 },{ 64,29,30,31 },{ 64,64,22,23 },{ 64,64,64,15 },{ 64,64,64,64 } };

void cubeBright(uint8_t bright) { FastLED.setBrightness(bright); }
void cubeClear() { FastLED.clear(); }
void cubeShow() { FastLED.show(); }

void cubeSet(uint8_t x, uint8_t y, CRGB c) {
  x=x%32; y=y%12;
  if (y<4) { uint16_t idx=transform[x][y]; if (idx<64) { cube[4][idx]=c; } }
  else { cube[x>>3][(x%8)+((y-4)<<3)]=c; } }

void cubeSet(uint8_t x, uint8_t y, CHSV c) {
  x=x%32; y=y%12;
  if (y<4) { uint16_t idx=transform[x][y]; if (idx<64) { cube[4][idx]=c; } }
  else { cube[x>>3][(x%8)+((y-4)<<3)]=c; } }

void cubeFill(CHSV c, bool now) {
  for (uint8_t y=0;y<12;y++) { for (uint8_t x=0;x<32;x++) {
    cubeSet(x,y,c); if (now) { cubeShow(); } } } }

void cubeRect(uint8_t xa, uint8_t ya, uint8_t xb, uint8_t yb, CHSV c) {
  for (uint8_t y=ya;y<ya+yb;y++) {
    for (uint8_t x=xa;x<xa+xb;x++) {
      cubeSet(x,y,c); } } }

void cubeLine(uint8_t xa, uint8_t ya, uint8_t xb, uint8_t yb, CHSV c) {
  int dx=abs(xb-xa),sx=xa<xb?1:-1,dy=-abs(yb-ya),sy=ya<yb?1:-1,err1=dx+dy,err2;
  while (1) { cubeSet(xa,ya,c); if (xa==xb && ya==yb) break; err2=2*err1;
    if (err2>dy) { err1+=dy; xa+=sx; } if (err2<dx) { err1+=dx;ya+=sy; } } }

void initCube() {
  FastLED.addLeds<NEOPIXEL,25>(cube[0],64);
  FastLED.addLeds<NEOPIXEL,26>(cube[1],64);
  FastLED.addLeds<NEOPIXEL,27>(cube[2],64);
  FastLED.addLeds<NEOPIXEL,32>(cube[3],64);
  FastLED.addLeds<NEOPIXEL,33>(cube[4],64);
  cubeBright(0); cubeClear(); cubeShow(); }
