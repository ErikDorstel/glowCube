void appRects() {
  static uint64_t rectTimer;
  if (millis()>=rectTimer) { rectTimer=millis()+config.delay;
   cubeRect(random8(32),random8(12),random8(2,8),random8(2,4),CHSV(0,0,0));
   cubeRect(random8(32),random8(12),random8(2,8),random8(2,4),CHSV(random8(min(config.hueA,config.hueB),max(config.hueA,config.hueB)),255,255));
   cubeShow(); } }

void initRects() {
  strcpy(apps.name[apps.count],"Rects");
  strcpy(apps.config[apps.count],"4,bright,delay,hueA,hueB");
  apps.worker[apps.count]=appRects;
  apps.count++; }
