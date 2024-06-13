void appInsects() {
  static struct pixelStruct { float x[20]; float y[20]; uint8_t c[20]; float xDiff[20]; float yDiff[20]; uint8_t xOld[20]; uint8_t yOld[20]; } pixel;
  static uint64_t insectsTimer;
  if (millis()>=insectsTimer) { insectsTimer=millis()+config.delay;
    for (int i=0;i<20;i++) {
      pixel.x[i]+=pixel.xDiff[i]; pixel.y[i]+=pixel.yDiff[i];
      if (pixel.xDiff[i]==0 && pixel.yDiff[i]==0) {
        pixel.xDiff[i]=random(50,100)/100.0; pixel.yDiff[i]=random(50,100)/100.0; pixel.c[i]=random(0,256); }
      if (pixel.y[i]<4) { if (transform[(uint8_t)(pixel.x[i]+pixel.xDiff[i])][(uint8_t)(pixel.y[i]+pixel.yDiff[i])]==64) { pixel.yDiff[i]=random(50,100)/100.0; } }
      if (pixel.x[i]<0) { pixel.x[i]=31; }
      if (pixel.x[i]>=32) { pixel.x[i]=0; }
      if (pixel.y[i]<0) { pixel.yDiff[i]*=-1; }
      if (pixel.y[i]>=12) { pixel.yDiff[i]*=-1; }
      cubeSet(pixel.xOld[i],pixel.yOld[i],CHSV(0,0,0));
      uint8_t x=pixel.x[i]; uint8_t y=pixel.y[i];
      cubeSet(x,y,CHSV(pixel.c[i],255,255));
      pixel.xOld[i]=x; pixel.yOld[i]=y; }
    cubeShow(); } }

void initInsects() {
  strcpy(apps.name[apps.count],"Insects");
  strcpy(apps.config[apps.count],"2,bright,delay");
  apps.worker[apps.count]=appInsects;
  apps.count++; }
