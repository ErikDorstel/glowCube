struct rainsStruct {
  uint8_t x;
  uint8_t y=100;
  uint8_t c;
} rains[200];

void appRain() {
  static uint64_t rainTimer=millis();
  if (millis()>rainTimer) {
    rainTimer=millis()+config.delay;
    for (uint8_t i=0;i<config.count;i++) {
      if (rains[i].y>=height+config.length-2) {
        if (random8(3)==0) {
          rains[i].x=random8(width);
          rains[i].y=0;
          rains[i].c=random8(min(config.hueA,config.hueB),max(config.hueA,config.hueB));
          cubeSet(rains[i].x,rains[i].y,CHSV(rains[i].c,255,255));
        }
      } else {
        rains[i].y++;
        for (int j=0;j<config.length;j++) {
          if (rains[i].y-j<height && rains[i].y>=j) {
            cubeSet(rains[i].x,rains[i].y-j,CHSV(rains[i].c,255,255/(config.length-1)*(config.length-1-j)));
          }  
        }
      }
    }
    FastLED.show();
  }
}

void initRain() {
  apps.count++;
  strcpy(apps.name[apps.count-1],"Rain");
  strcpy(apps.config[apps.count-1],"6,bright,delay,hueA,hueB,count,length");
  apps.worker[apps.count-1]=appRain;
  config.hueA=0; config.hueB=255; }
