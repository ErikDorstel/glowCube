struct configStruct {
  int bright=22;
  int delay=63;
  int speed=22;
  int hueA=0;
  int hueSpeedA=0;
  int hueB=160;
  int hueSpeedB=0;
  int border=0;
  int ratio=0; } config;

struct appsStruct {
  int count=0;
  int current=0;
  char name[20][20]={""};
  char config[20][100]={""};
  void (*worker[20])()={nullptr}; } apps;

void appsWorker() {
  static int currentBright=0;
  static uint64_t brightTimer;
  if (millis()>=brightTimer) { brightTimer=millis()+100;
    int deltaBright=config.bright-currentBright;
      if (deltaBright!=0) {
           if (deltaBright>100) { currentBright+=10; }
      else if (deltaBright<-100) { currentBright-=10; }
      else if (deltaBright>30) { currentBright+=5; }
      else if (deltaBright<-30) { currentBright-=5; }
      else if (deltaBright>0) { currentBright+=1; }
      else if (deltaBright<0) { currentBright-=1; }
      cubeBright(currentBright); } }

  static uint64_t hueSpeedTimer;
  if (millis()>=hueSpeedTimer) { hueSpeedTimer=millis()+200;
    if ((config.hueSpeedA>0 || config.hueSpeedB>0) && apps.current==1) {
      config.hueA+=config.hueSpeedA; config.hueA%=256;
      config.hueB+=config.hueSpeedB; config.hueB%=256;
      modifyPlasmaColors(config.hueA,config.hueB,config.border,config.ratio); } } }
