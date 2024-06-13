void appRects() {
  static uint64_t rectTimer;
  if (millis()>=rectTimer) { rectTimer=millis()+config.delay;
   cubeRect(random(32),random(12),random(2,8),random(2,4),CHSV(0,0,0));
   cubeRect(random(32),random(12),random(2,8),random(2,4),CHSV(random(256),255,255)); cubeShow(); } }

void initRects() {
  strcpy(apps.name[apps.count],"Rects");
  strcpy(apps.config[apps.count],"2,bright,delay");
  apps.worker[apps.count]=appRects;
  apps.count++; }
