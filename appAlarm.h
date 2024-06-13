void appAlarm() {
  static uint8_t hue=0,x=0;
  static uint64_t alarmTimer;
  if (millis()>=alarmTimer) { alarmTimer=millis()+config.delay;
    cubeClear();
    cubeRect(x,0,8,12,CHSV(hue,255,255));
    hue++; hue%=256;
    cubeShow();
    x++; x%=32; } }

void initAlarm() {
  strcpy(apps.name[apps.count],"Alarm");
  strcpy(apps.config[apps.count],"2,bright,delay");
  apps.worker[apps.count]=appAlarm;
  apps.count++; }
