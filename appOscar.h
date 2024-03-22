void appOscar() {
  micWorker();
  static int x=0;
  cubeLine(x,0,x,12,CHSV(160,255,255));
  cubeLine(x,11,x,11-((abs(mic.max)>>4)%12),CHSV(0,255,255));
  x++; x%=32;
  cubeShow(); }

void initOscar() {
  apps.count++;
  strcpy(apps.name[apps.count-1],"Oscar");
  strcpy(apps.config[apps.count-1],"1,bright");
  apps.worker[apps.count-1]=appOscar; }
