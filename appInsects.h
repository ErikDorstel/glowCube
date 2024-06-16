void appInsects() {
  static struct pixelStruct { float x[20]; float y[20]; uint8_t c[20]; float xDiff[20]; float yDiff[20]; uint8_t xOld[20]; uint8_t yOld[20]; } pixel;
  static uint64_t insectsTimer;
  if (millis()>=insectsTimer) { insectsTimer=millis()+config.delay;
    for (int i=0;i<20;i++) {

      if ((pixel.xDiff[i]==0 && pixel.yDiff[i]==0) || random8()==0) {
        pixel.xDiff[i]=random8(60,100)/100.0; pixel.yDiff[i]=random8(20,100)/100.0;
        pixel.c[i]=random8(min(config.hueA,config.hueB),max(config.hueA,config.hueB)); }

      pixel.x[i]+=pixel.xDiff[i]; pixel.y[i]+=pixel.yDiff[i];
      if (pixel.x[i]<0) { pixel.x[i]=31; }
      if (pixel.x[i]>=32) { pixel.x[i]=0; }
      if (pixel.y[i]<0) { pixel.yDiff[i]*=-1; pixel.y[i]=0; }
      if (pixel.y[i]>=12) { pixel.yDiff[i]*=-1; pixel.y[i]=11; }

      if ((uint8_t)pixel.y[i]<4) { while (transform[(uint8_t)pixel.x[i]][(uint8_t)pixel.y[i]]==64) {
        pixel.x[i]+=pixel.xDiff[i]; pixel.y[i]+=pixel.yDiff[i];
        if (pixel.x[i]<0) { pixel.x[i]=31; }
        if (pixel.x[i]>=32) { pixel.x[i]=0; }
        if (pixel.y[i]<0) { pixel.yDiff[i]*=-1; pixel.y[i]=0; }
        if (pixel.y[i]>=12) { pixel.yDiff[i]*=-1; pixel.y[i]=11; } } }

      cubeSet(pixel.xOld[i],pixel.yOld[i],CHSV(0,0,0));
      cubeSet(pixel.x[i],pixel.y[i],CHSV(pixel.c[i],255,255));
      pixel.xOld[i]=pixel.x[i]; pixel.yOld[i]=pixel.y[i]; }
    cubeShow(); } }

void initInsects() {
  strcpy(apps.name[apps.count],"Insects");
  strcpy(apps.config[apps.count],"4,bright,delay,hueA,hueB");
  apps.worker[apps.count]=appInsects;
  apps.count++; }
