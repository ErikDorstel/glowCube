void appFills() {
  static uint8_t hue=0;
  static uint64_t fillsTimer;
  if (millis()>=fillsTimer) { fillsTimer=millis()+config.delay;
    cubeFill(CHSV(hue,255,255),0);
    cubeShow();
    hue+=32; if (hue>224) { hue=0; } } }

void initFills() {
  apps.count++;
  strcpy(apps.name[apps.count-1],"Fills");
  strcpy(apps.config[apps.count-1],"2,bright,delay");
  apps.worker[apps.count-1]=appFills; }
