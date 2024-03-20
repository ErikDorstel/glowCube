void appRects() {
  static uint64_t rectTimer;
  if (millis()>=rectTimer) { rectTimer=millis()+config.delay;
   cubeRect(random(32),random(12),random(2,8),random(2,4),CHSV(0,0,0));
   cubeRect(random(32),random(12),random(2,8),random(2,4),CHSV(random(256),255,255)); cubeShow(); } }

void initRects() {
  apps.count++;
  strcpy(apps.name[apps.count-1],"Rects");
  strcpy(apps.config[apps.count-1],"2,bright,delay");
  apps.worker[apps.count-1]=appRects; }
