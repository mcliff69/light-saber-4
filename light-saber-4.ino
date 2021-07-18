/*
   СВЕТОВОЙ МЕЧ НА WEMOS, MP3 PLAYER И АДРЕСНЫХ СВЕТОДИОДАХ!

   Версия 4.0
     
   УПРАВЛЕНИЕ:
   
      Включение питания. 
      1. Плавно загорается красным на 2 сек, показывая процент зарядки. Включается дежурный режим. 
      Первый светодиод моргает синим.
      
      2. Во время включения питания нажата кнопка 1. Включается режим прошивки кода по wifi (OTA). 
      Первый светодиод моргает оранжевым. Для корректной работы режима нужно подставить в коде WIFI_SSID и WIFI_PWD для входа в Вашу сеть WIFI. Для загрузки прошивки зайдите в браузере на 
      http://IP_ADDRESS/update , где IP_ADDRESS - IP адрес контроллера в сети. Его можно найти в админке маршрутизатора. Компьютер должен быть в той же сети (подключен к тому же маршрутизатору).
      
      3. Заряд аккумулятора меньше 10%. Ничего не работает, только первый светодиод моргает красным.
      
      
      В дежурном режиме.
      1. Длительное нажатие кнопок 1 + 2 - включение меча (переход в рабочий режим). Если заряд меньше 10%, то не включается. Если выбран режим МЕЧ, то плавно загорается и проигрывается звук включения. Если звук долгий, его можно прервать кнопкой 2 или ударом меча.
      
      2. Нажатие кнопок 1 + 2 более 3 секунд - настройка звука включения (только если выбран режим МЕЧ). Первый светодиод моргает зеленым. В этом режиме однократное нажатие кнопок 1/2 выбирает следующий/предыдущий звук включения. Выбранный звук проигрывается. Если не было нажатий 5 секунд, переходит в рабочий режим.
      
      3. Клик кнопки 1 или 2 - неправильная попытка включить меч. Воспроизводится шуточное сообщение.
      
      4. Удар или взмах в дежурном режиме. Сообщение о неправильном использовании меча.
      
      5. Если питание включено, но меч в дежурном режиме, то через 10 минут воспроизводится напоминание, что нужно выключить питание. Дальше напоминание повторяется каждую минуту.
      


      В рабочем режиме.
      1. Длительное нажатие кнопок 1 + 2 - выключение меча. Если выбран режим МЕЧ, то плавно гасится и проигрывается звук выключения.
      
      2. Нажатие кнопок 1 + 2 более 3 секунд - настройка звука выключения (только если выбран режим МЕЧ). Первый светодиод моргает зеленым. В этом режиме однократное нажатие кнопок 1/2 выбирает следующий/предыдущий звук выключения. Выбранный звук проигрывается. Если не было нажатий 5 секунд, переходит в дежурный режим.

      3. Клик кнопки 1. В режиме МЕЧ, ЛАМПА переключает цвет по кругу (Красный - Оранжевый - Жёлтый - Зелёный - Голубой - Синий - Фиолетовый - Белый). В режиме АВТОМАТ переключает цвет выстрела. В режиме ФАКЕЛ меняет палитру огня. В режиме МИГАЛКА переключает вариант мигания.
        
      4. Двойной клик кнопки 1. В режиме МЕЧ, ФАКЕЛ переключает фоновый звук. В режиме АВТОМАТ переключает звук выстрела. В режиме МИГАЛКА переключает звук сирены.
      
      5. Тройной клик кнопки 1. Переход на следующий режим по кругу:
      МЕЧ - АВТОМАТ - ФАКЕЛ - МИГАЛКА - ЖЕЗЛ - ЛАМПА
      
      6. Клик кнопки 2. В режиме МЕЧ воспроизводит произвольную фразу из набора 1. В режиме АВТОМАТ воспроизводит выстрел. Траектория пули подсвечивается. Отрисовываеется пламя из дула. Если кончились патроны, воспроизводит щелчок. В режиме МИГАЛКА воспроизводит звук полицейской машины "Кря".
      
      7. Двойной клик кнопки 2. В режиме МЕЧ воспроизводит произвольную фразу из набора 2. В режиме АВТОМАТ перезаряжает обойму автомата. В режиме МИГАЛКА воспроизводит звук полицейской машины "Кря - кря".
      
      8. Длительное нажатие кнопки 2. В режиме АВТОМАТ стрельба очередью. В режиме ФАКЕЛ усиление пламени. В режиме МИГАЛКА звук полицейской сирены.
      
      9. Клик кнопки 1 при нажатой кнопке 2 / Клик кнопки 2 при нажатой кнопке 1. Громче / тише (кроме режимов ЛАМПА, ЖЕЗЛ). Длина зеленой полосы показывает уровень громкости. 
      
      10. Удар в режиме МЕЧ. Звук удара из набора 1. Вспышка.
      
      11. Удар с нажатой кнопкой 1 в режиме МЕЧ. Звук удара из набора 2. Вспышка.
      
      12. Удар с нажатой кнопкой 2 в режиме МЕЧ. Звук удара из набора 3. Вспышка.
      
      13. Взмах в режиме МЕЧ. Звук взмаха.
      
      14. Резкий взмах в режиме МЕЧ. Звук резкого взмаха.
      
      15. Если пользователь ничего не нажимает (не машет, не ударяет) 10 минут. Переходит в дежурный режим.

      16. Если аккумулятор разряжается в процессе работы. Проигрывается звук умирающего меча. Всё выключается. Первый светодиод моргает красным.
      
      Выбранные настройки (режим работы меча, цвет меча, палитра огня, цвет выстрела, цвет лампы, вариант полицейской мигалки, громкость, звук включения, звук выключения, звук фона меча, звук фона факела, звук выстрела, звук сирены) сохраняются в энергонезависимой памяти и восстанавливаются при следующем включении. 
*/



//#define DEBUG_SERIAL               // вывод в порт отладочной информации 

#ifdef DEBUG_SERIAL
  #define LOG(x) Serial.println(x)
  #define LOG2(x,y) Serial.print(x); Serial.println(y)
#else
  #define LOG(x)
  #define LOG2(x,y)
#endif

#define CYCLE_INC(x,count) x++;  x %= count
#define CYCLE_DEC(x,count) x += count - 1;  x %= count

// ---------------------------- НАСТРОЙКИ -------------------------------
#define NUM_LEDS 50          // число МИКРОСХЕМ на ленте
#define BRIGHTNESS 255       // максимальная яркость ленты (0 - 255)

#define SWING_THR 220        // порог угловой скорости для взмаха
#define SWING_S_THR 400      // порог угловой скорости для сильного взмаха
#define STRIKE_THR 120       // порог ускорения для распознавания удара
#define FLASH_DELAY 80       // время вспышки при ударе (миллисекунды)

#define BLINK_ALLOW 1        // разрешить мерцание (1 - разрешить, 0 - запретить)
#define BLINK_AMPL 20        // амплитуда мерцания клинка
#define BLINK_DELAY 30       // задержка между мерцаниями

#define R1 470               // сопротивление резистора делителя (kOm)   
#define BATTERY_THR 10       // порог заряда АКБ в %, если 0, то не выключаться до конца

// подставьте реальные SSID и пароль Вашей Wi-Fi сети, если хотите обнавлять прошивку по поздуху (OTA)
#define WIFI_SSID "Change_it"   // wifi сеть
#define WIFI_PWD "Change_it" // пароль wifi сети


// ---------------------------- ПИНЫ -------------------------------

#define BTN1_PIN   D5          // пин кнопки 1
#define BTN2_PIN   D0          // пин кнопки 2

#define VOLT_PIN   A0          // пин вольтметра
//#define BTN_LED    1           // светодиод кнопки
#define SERIAL_RX  D3          // Software Serial RX
#define SERIAL_TX  D4          // Software Serial TX
#define SERIAL2_RX D1          // Software Serial2 RX
#define SERIAL2_TX D2          // Software Serial2 TX
#define LED_PIN    D8          // DIN ленты
#define SDA_PIN    D6
#define SCL_PIN    D7

// -------------------------- БИБЛИОТЕКИ ---------------------------
// подключение по wi-fi к сети для прошивки по воздуху (OTA)
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

#include "Wire.h"           // вспомогательная библиотека для работы с акселерометром
#include "MPU6050.h"        // библиотека для работы с акселерометром
#include "FastLED.h"        // библиотека для работы с адресной лентой
#include <EEPROM.h>         // библиотека для работы с энергонезависимой памятью
#include <SoftwareSerial.h>  // связь с mp3 плеером по последовательному порту
#include <MD_YX5300.h>   // mp3 плеер
#include "GyverButton.h"    // работа кнопок
#include "strobo.h"   // варианты полицейской мигалки


// ----------------------------- ОБЪЕКТЫ -------------------------------------
CRGB leds[NUM_LEDS];
MPU6050 accelgyro;
SoftwareSerial  swSerial(SERIAL_RX, SERIAL_TX);
SoftwareSerial  sw2Serial(SERIAL2_RX, SERIAL2_TX);
MD_YX5300 mp3(swSerial);
MD_YX5300 mp3bg(sw2Serial);
GButton btn1(BTN1_PIN, HIGH_PULL, NORM_OPEN);
GButton btn2(BTN2_PIN, HIGH_PULL, NORM_OPEN);
ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

// ------------------------------ КОНСТАНТЫ ----------------------------------

// значения для переменной playing
#define    SOUND_ON         1
#define    SOUND_SETUP      2
#define    SOUND_STRIKE     3
#define    SOUND_SWING      4

// папки на SD1
#define FLD_BG_SABER        1  // sd:/01/   
#define FLD_BG_FIRE         2  // sd:/02/   

// папки на SD2
#define FLD_SOUND_ON        1  // sd:/01/
#define FLD_SOUND_OFF       2  // sd:/02/
#define FLD_STRIKE_1        3  // sd:/03/
#define FLD_STRIKE_2        4  // sd:/04/
#define FLD_STRIKE_3        5  // sd:/05/
#define FLD_LONG_SWING      6  // sd:/06/
#define FLD_SHORT_SWING     7  // sd:/07/
#define FLD_PHRASE_1        8  // sd:/08/
#define FLD_PHRASE_2        9  // sd:/09/
#define FLD_SHOT            10 // sd:/10/
#define FLD_MISL            11 // sd:/11/
#define FLD_POLICE          12 // sd:/12/
#define FLD_WRONG_ON        13 // sd:/13/

// файлы в папке FLD_MISL
#define MISL_MACHINE_GUN    1  // sd:/11/001.wav
#define MISL_CLICK          2  // sd:/11/002.wav
#define MISL_RECHARGE       3  // sd:/11/003.wav
#define MISL_DYING          4  // sd:/11/004.wav
#define MISL_REMIND_OFF     5  // sd:/11/005.wav
#define MISL_CRYA           6  // sd:/11/006.wav
#define MISL_CRYA_CRYA      7  // sd:/11/007.wav
#define MISL_FORCED_FIRE    8  // sd:/11/008.wav
#define MISL_WRONG_STRIKE    9  // sd:/11/009.wav
#define MISL_WRONG_SWING    10  // sd:/11/010.wav


// Режим работы меча
#define MODE_SABER nowMode == 0      // МЕЧ
#define MODE_GUN   nowMode == 1      // АВТОМАТ
#define MODE_FIRE  nowMode == 2      // ФАКЕЛ
#define MODE_POLICE nowMode == 3     // МИГАЛКА
#define MODE_POLICE_STICK nowMode == 4     // ЖЕЗЛ
#define MODE_LAMP nowMode == 5      // ЛАМПА
#define MODE_WITH_SOUND nowMode < 4     // режимы со звуком

// Настройки автомата
#define SHOTS_P_S   4         // стрельба очередью, выстрелов в секунду
#define BULLETS_INI 50        // патронов в магазине

// Настройки мигалки
#define POLICE_ROTATE_PERIOD 500      // период вращения мигалки миллисекунды

// ------------------------------ ПЕРЕМЕННЫЕ ---------------------------------
int16_t 
    ax, 
    ay, 
    az,
    gx, 
    gy, 
    gz;
unsigned long 
    ACC, 
    GYR, 
    COMPL;
int 
    gyroX, 
    gyroY, 
    gyroZ, 
    accelX, 
    accelY, 
    accelZ;
float 
    k = 0.2;
    
    
boolean 
    isOn = 0;
    
byte
    playing = 0;

unsigned long 
    now, 
    mpuTimer, 
    blinkTimer, 
    batteryTimer, 
    fireTimer = 0, 
    remindToOff = 0, 
    ledTime = 0,
    setupVolumeTimer = 0,
    lastShotTime = 0,
    offTimer;
    
byte 
    nowMode,         //  режим меча
    nowSaberColor,   //  цвет меча
    nowFireColor,    //  цвет огня
    nowGunColor,     //  цвет выстрела
    nowLampColor,   //  цвет фонарика
    nowVolume,       //  громкость
    nowSoundShot,    //  звук выстрела
    nowSoundOn,      //  звук включения
    nowSoundOff,     //  звук выключения
    nowBgSaber,      //  фон меч
    nowBgFire,       //  фон огня
    nowPoliceColor,  //  цвет мигалки
    nowSoundPolice;  //  звук мигалки

byte 
    redOffset, 
    greenOffset, 
    blueOffset;
int 
    blinkOffset;
CRGB 
    nowRGB;

// количество mp3 файлов в папках
int 
    numBgSaber      = 7, 
    numBgFire       = 5, 
    numSoundOn      = 11, 
    numSoundOff     = 4, 
    numStrike1      = 17, 
    numStrike2      = 13, 
    numStrike3      = 8, 
    numLongSwing    = 4, 
    numShortSwing   = 5, 
    numPhrase1      = 17, 
    numPhrase2      = 7, 
    numSoundShot    = 5, 
    numSoundPolice  = 7,
    numSoundWrongOn = 7;



CRGBPalette16 
  firePal,
  policePal1,
  policePal2;

  // красный, оранжевый, жёлтый, зелёный, голубой, синий, фиолетовый, белый
CRGB COLORS[8] = {0xE00000, 0xB03000, 0x805000, 0x00E000, 0x005060, 0x0000E0, 0x400090, 0xB0B0B0};

    
int 
  bullets = BULLETS_INI;
  
bool 
  isPress1,
  isPress2,
  isHolded1,
  isHolded2,
  isClick1,
  isClick2,
  isSingle1,
  isSingle2,
  isDouble1,
  isDouble2,
  isTriple1,
  isRelease1,
  isRelease2,
  isMachineGunSound = 0,
  isPoliceSound = 0,
  isForcedFireSound = 0,
  isOtaMode = 0,
  isBatteryLow = 0;

unsigned long 
  holdedBothFrom = 0,
  setupOnOffSound = 0,
  userLastActivity = 0,
  repeatTimer = 0,
  repeatBgTimer = 0;

// ------------------------------ ФУНКЦИИ -------------------------------------------
int countFolderFiles(MD_YX5300 &mp3, int folder);
void blink(CRGB color);
void volumeShow();
void remindOff();
void showShot();
void colorNext();
void setFirePal();
void setBgSound();
void setMode (bool firstOn = 0);
void on();
void off();
void randomBlink();
void strikeTick();
void swingTick();
void readAccel();
void setPixel(int pixel, CRGB rgb);
void setAll(CRGB rgb);
void lightUp();
void lightDown();
void strikeFlash();
void setColor(byte color);
void batteryTick();
byte voltageMeasure();
void fire2012();
void readSettings();
void saveSettings();
void police();
  
// ------------------------------ ВКЛЮЧЕНИЕ ПИТАНИЯ ---------------------------------
void setup() {
    #ifdef DEBUG_SERIAL
    Serial.begin(9600);
    Serial.flush();
    #else
    //pinMode(BTN_LED, FUNCTION_3);
    //pinMode(BTN_LED, OUTPUT);
    //digitalWrite(BTN_LED, 0);
    #endif

    setAll(0);
    FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.show();

    // получить процент заряда аккумулятора
    byte capacity = voltageMeasure();
    // заряд аккума ниже порога
    if (capacity < BATTERY_THR) {
        isBatteryLow = 1;
        // больше ничего не включаем
        return;
    } 
        
    // при включении питания нажата кнопка 1
    if (!digitalRead(BTN1_PIN)) {
        // режим OTA
        isOtaMode = 1;
        // включаем wifi и подключаемся к сети
        WiFi.mode(WIFI_STA);
        WiFi.begin(WIFI_SSID, WIFI_PWD);
        delay(500);
        // запускаем веб-сервер для OTA
        httpUpdater.setup(&httpServer);
        httpServer.begin();
        // больше ничего не включаем
        return;
    }

  
    initPoliceLightAll();
  
    // инициализация и настройка IMU
    Wire.begin(SDA_PIN, SCL_PIN);
    accelgyro.initialize();
    accelgyro.setFullScaleAccelRange(MPU6050_ACCEL_FS_16);
    accelgyro.setFullScaleGyroRange(MPU6050_GYRO_FS_250);
  
    if (accelgyro.testConnection()) 
        LOG("MPU6050 ok");
    else 
        LOG("MPU6050 fail");

    // YX5300 Serial interface
    // 9600
    swSerial.begin(MD_YX5300::SERIAL_BPS);
    sw2Serial.begin(MD_YX5300::SERIAL_BPS);
  
    mp3.begin();
    mp3bg.begin();
    // не ждем подтверждения от mp3 после каждой команды 
    mp3.setSynchronous(false);
    mp3bg.setSynchronous(false);

/*
  // если активно экспериментировать с наборами звуков, 
  // можно не исправлять количество файлов в каждой папке каждый раз, а посчитать их динамически
  // но это замедляет включение
  numBgSaber    = countFolderFiles(mp3bg, FLD_BG_SABER);
  numBgFire     = countFolderFiles(mp3bg, FLD_BG_FIRE);
  
  numSoundOn    = countFolderFiles(mp3, FLD_SOUND_ON);
  numSoundOff   = countFolderFiles(mp3, FLD_SOUND_OFF);
  numStrike1    = countFolderFiles(mp3, FLD_STRIKE_1);
  numStrike2    = countFolderFiles(mp3, FLD_STRIKE_2);
  numStrike3    = countFolderFiles(mp3, FLD_STRIKE_3);
  numLongSwing  = countFolderFiles(mp3, FLD_LONG_SWING);
  numShortSwing = countFolderFiles(mp3, FLD_SHORT_SWING);
  numPhrase1    = countFolderFiles(mp3, FLD_PHRASE_1);
  numPhrase2    = countFolderFiles(mp3, FLD_PHRASE_2);
  numSoundShot  = countFolderFiles(mp3, FLD_SHOT);
  numSoundPolice    = countFolderFiles(mp3, FLD_POLICE);
  numSoundWrongOn    = countFolderFiles(mp3, FLD_WRONG_ON);

  LOG2("numBgSaber = ",     numBgSaber);
  LOG2("numBgFire = ",      numBgFire);
  LOG2("numSoundOn = ",     numSoundOn);
  LOG2("numSoundOff = ",    numSoundOff);
  LOG2("numStrike1 = ",     numStrike1);
  LOG2("numStrike2 = ",     numStrike2);
  LOG2("numStrike3 = ",     numStrike3);
  LOG2("numLongSwing = ",   numLongSwing);
  LOG2("numShortSwing = ",  numShortSwing);
  LOG2("numPhrase1 = ",     numPhrase1);
  LOG2("numPhrase2 = ",     numPhrase2);
  LOG2("numSoundShot = ",   numSoundShot);
  LOG2("numSoundPolice = ", numSoundPolice);
  LOG2("numSoundWrongOn = ", numSoundWrongOn);
*/

    EEPROM.begin(256);
    readSettings();
  
    mp3.volume(nowVolume * 3);
    mp3bg.volume(nowVolume * 3);
  
    LOG2("mp3.volume: ", nowVolume);

    now = millis();
    offTimer = now;
  
    // напомнить выключить меч через 10 мин
    remindToOff = now + 600000;

    // проценты заряда аккума в длину клинка
    capacity = map(capacity, 0, 100, 0, NUM_LEDS + 1);
    // яркость ленты 20%
    FastLED.setBrightness(50);      
    // плавно отобразить заряд аккумулятора как длину клинка
    setColor(nowSaberColor);
    for (byte i = 0; i < capacity; i++) {
        setPixel(i, CRGB::Red);
        FastLED.show();
        delay(12);
    }
    // две секунды для отображения заряда аккума
    delay(2000);
    // возвращаем яркость                    
    FastLED.setBrightness(BRIGHTNESS); 
    // гасим ленту                         
    setAll(0);
    FastLED.show();     
}


// -------------------------------- ОСНОВНОЙ ЦИКЛ --------------------------------
void loop() {
 
  delay(1);

  now = millis();

  // в режиме OTA
  if (isOtaMode) {
    // принимает входящие пакеты
    httpServer.handleClient();
    // моргаем оранжевым светодиодом
    blink(0x502000);
    return;
  }
  
  if (isBatteryLow) {
    // моргаем красным светодиодом
    blink(0x500000);
    return;  
  }
  
  // забрать сообщения от mp3
  mp3.check();
  
  if (mp3.getStatus()->code == MD_YX5300::STS_FILE_END && playing) {
    LOG("STS_FILE_END");
    // закончился звук включения
    if (playing == SOUND_ON && isOn) {
      // включаем фоновый звук
      setBgSound();
    }
    // звук закончился
    playing = 0;
  }
  
  if (repeatTimer && now - repeatTimer > 200) {
    mp3.repeat(true);
    repeatTimer = 0;
  }
  
  if (repeatBgTimer && now - repeatBgTimer > 200) {
    mp3bg.repeat(true);
    repeatBgTimer = 0;
  }
  
  // опрос и отработка кнопки
  btnTick();
  
  // в режиме Установки звука вкл/выкл
  if (setupOnOffSound) {
    // моргаем зеленым светодиодом
    blink(0x005000);
    // если меч включен, можно выйти из режима установки ударом
    if (isOn) {
      // получить ускорение
      readAccel();
      // отработка удара          
      strikeTick();
    }
    
  // в дежурном режиме
  } else if (!isOn) {
      /*
        глубокий сон имеет смысл, если так же выключать питание ленты и другой переферии
        это пока не реализовано
        
      // пользователь не активен 15 минут
      if (now - userLastActivity > 15 * 60000) {
        // гасим ленту                         
        setAll(0);
        FastLED.show();
        // переводим плееры в спящий режим
        mp3.sleep();
        mp3bg.sleep();
        // переводим ESP8266 в спящий режим
        ESP.deepSleep(0); 
      }
      */
      
        // получить ускорение
        readAccel();
        // отработка удара          
        strikeTick();
        // отработка взмаха       
        swingTick();
      
        // напомнить, что надо выключить меч
        remindOff();
        // моргаем синим светодиодом
        blink(0x000050);
    
  // меч включен
  // пользователь не активен 10 минут
  } else if (now - userLastActivity > 10 * 60000) {
    // выключаем меч
    off();
  // в режиме Регулировка громкости
  } else if (setupVolumeTimer) {
    // 3 секунды не было нажатий
    if (now - setupVolumeTimer > 3000) {
      // выходим из режима
      setupVolumeTimer = 0;
      // сбрасываем флаги нажатия
      isPress1 = isPress2 = isHolded1 = isHolded2 = holdedBothFrom = 0;
      //гасим ленту
      setAll(0);
      FastLED.show();
    } else {
      // показываем громкость длиной светящейся части
      volumeShow();
    }

  // в режиме МЕЧ
  } else if (MODE_SABER) {
    // мерцание
    randomBlink();
    // получить ускорение
    readAccel();
    // отработка удара          
    strikeTick();
    // отработка взмаха       
    swingTick();

  // в режиме АВТОМАТ
  } else if (MODE_GUN) {
    // если режим стрельбы очередью, то стрелять с частотой SHOTS_P_S выстрелов в секунду
    if (isMachineGunSound && bullets && now - lastShotTime > 1000 / SHOTS_P_S) {
      lastShotTime = now;
      showShot();
    }

  // в режиме ФАКЕЛ
  } else if (MODE_FIRE) {
      // отрисовываем ФАКЕЛ
      fire2012();

  // в режиме МИГАЛКА
  } else if (MODE_POLICE) {
      // обновляем мигалку
      police();
  }
    
  // проверка аккума         
  batteryTick();        
}


// ------------------------------ УПРАВЛЕНИЕ КНОПКАМИ ------------------------------------
void btnTick() {
    btn1.tick();
    btn2.tick();
  
    if (btn1.isPress()) {
        isPress1 = 1;
        userLastActivity = now;
    }
    if (btn1.isHolded()) {
        isHolded1 = 1;
    }
    if (btn1.isRelease()) {
        isPress1 = isHolded1 = 0;
        isRelease1 = 1;
    } else {
        isRelease1 = 0;
    }
    if (btn2.isPress()) {
        isPress2 = 1;
        userLastActivity = now;
    }
    if (btn2.isHolded()) {
        isHolded2 = 1;
    }
    if (btn2.isRelease()) {
        isPress2 = isHolded2 = 0;
        isRelease2 = 1;
    } else {
        isRelease2 = 0;
    }

    isClick1 = btn1.isClick();
    isClick2 = btn2.isClick();
    isSingle1 = btn1.isSingle();
    isSingle2 = btn2.isSingle();
    isDouble1 = btn1.isDouble();
    isDouble2 = btn2.isDouble();
    isTriple1 = btn1.isTriple();
      

    // стрельба очередью
    if (isMachineGunSound) {
        // кнопка 2 отпускается или заканчиваются патроны
        if (!isHolded2 || !bullets) {
            isMachineGunSound = 0;
            mp3.playStop(); 
            LOG("стоп очередь");
        }
        return;
        
    // сирена
    } else if (isPoliceSound) {
        // кнопка 2 отпускается
        if (!isHolded2) {
            isPoliceSound = 0;
            repeatTimer = 0;
            mp3.repeat(false);
            mp3.playStop(); 
            LOG("стоп сирена");
        }
        return;
        
    // горелка
    } else if (isForcedFireSound) {
        // кнопка 2 отпускается
        if (!isHolded2) {
            isForcedFireSound = 0;
            repeatTimer = 0;
            mp3.repeat(false);
            mp3.playStop(); 
            LOG("стоп горелка");
        }
        return;
    } 


    // долгое нажатие обеих кнопок
    // вкл/выкл меча
    // настройка звука для вкл/выкл
    if (isHolded1 && isHolded2) {
        if (holdedBothFrom) {
            // обе кнопки удерживаются больше 3 сек после включения/выключения меча
            // только для режима МЕЧ
            if (!setupOnOffSound && (now - holdedBothFrom > 3000) && MODE_SABER) {
                // вход в режим настройки звука вкл/выкл
                setupOnOffSound = now;
                LOG("Вход в режим настройки звука вкл/выкл");
            }
        } else {
            LOG("Включение / выключение меча");
            holdedBothFrom = now;
            if (isOn) {
                off();
            } else {
                on();
            }
        }
        return;
    }
  
    // были нажаты обе кнопки, одну или обе отпускаем
    if (holdedBothFrom) {
        // сбрасываем флаги нажатия
        isPress1 = isPress2 = isHolded1 = isHolded2 = holdedBothFrom = 0;
        return;
    }
  
    // в режиме настроек
    if (setupOnOffSound) {

        bool clicked = 0;
        // если меч включен
        if (isOn) {
            
            // клик кнопки 1
            if (isClick1) {
                // выбираем следующий звук включения
                CYCLE_INC(nowSoundOn,  numSoundOn);
                clicked = 1;
            // клик кнопки 2
            } else if (isClick2) {
                // выбираем предыдущий звук включения
                CYCLE_DEC(nowSoundOn,  numSoundOn);
                clicked = 1;
            }
            
            if (clicked) {
                // проигрываем выбранный звук
                mp3.playSpecific(FLD_SOUND_ON, nowSoundOn + 1);
                LOG2("Устанавливаем nowSoundOn в ", nowSoundOn);
            }
         
        // если меч выключен
        } else {
            
            // клик кнопки 1
            if (isClick1) {
                // выбираем следующий звук выключения
                CYCLE_INC(nowSoundOff,  numSoundOff);
                clicked = 1;
                
            // клик кнопки 2
            } else if (isClick2) {
                // выбираем предыдущий звук выключения
                CYCLE_DEC(nowSoundOff,  numSoundOff);
                clicked = 1;
            }
            
            if (clicked) {
                // проигрываем выбранный звук
                mp3.playSpecific(FLD_SOUND_OFF, nowSoundOff + 1);

                LOG2("Устанавливаем nowSoundOff в ", nowSoundOff);
            }
         
        }

        if (clicked) {
            // идет проигрывание
            playing = SOUND_SETUP;
            // сохранить
            saveSettings();
        }   

        if (playing == SOUND_SETUP) {
            // обновить метку времени 
            setupOnOffSound = now;
        }   

        // если не было активности больше 5 сек 
        if (now - setupOnOffSound > 5000) {
            // выйти из режима настроек
            setupOnOffSound = 0;
            LOG("Выход из настройки звука вкл/выкл");
          
            // включить светодиод
            //#ifdef DEBUG_SERIAL
            //#else
            //digitalWrite(BTN_LED, 0);
            //#endif
          
            return;
        }
    
    // меч выключен
    } else if (!isOn) {
        // неправильное включение, пропускаем 5 секунд после выключения меча
        if ((isRelease1 || isRelease2) && now - offTimer > 5000) {
            static int wrongOn = 0;
            mp3.playSpecific(FLD_WRONG_ON, wrongOn); 
            CYCLE_INC(wrongOn, numSoundWrongOn);
        }


    // меч включен
  
    // кнопка 2 нажата, кнопка 1 клик
    } else if (isClick1 && isPress2) {
        // режим установки громкости (выключен, если режим ЖЕЗЛ или ЛАМПА)
        if (MODE_WITH_SOUND) {
            // таймер для отображения громкости подсветкой
            setupVolumeTimer = now;
          
            if (nowVolume < 9) {
                // увеличить громкость
                nowVolume++;                           
                mp3.volume(nowVolume * 3);
                mp3bg.volume(nowVolume * 3);
              
                LOG2("громкость: ", nowVolume);

                // сохранить
                saveSettings();
            }
        }

    // кнопка 1 нажата, кнопка 2 клик
    } else if (isClick2 && isPress1) {
        // режим установки громкости (выключен, если режим ЖЕЗЛ или ЛАМПА)
        if (MODE_WITH_SOUND) {
            // таймер для отображения громкости подсветкой
            setupVolumeTimer = now;
          
            if (nowVolume > 0) {
                // уменьшить громкость
                nowVolume--;                           
                mp3.volume(nowVolume * 3);
                mp3bg.volume(nowVolume * 3);
              
                LOG2("громкость: ", nowVolume);

                // сохранить
                saveSettings();
            }
        }
     
    // в процессе регулировки громкости
    } else if (setupVolumeTimer) {
        // не реагируем на другие нажатия
        return;
    
    // кнопка 1 клик
    } else if (isSingle1) {
        // следующий цвет
        colorNext();
      
        // сохранить
        saveSettings();
      
    // кнопка 1 двойной клик, режим МЕЧ
    } else if (isDouble1 && MODE_SABER) {
        // выбираем следующий фоновый звук меча
        CYCLE_INC(nowBgSaber,  numBgSaber);
        LOG2("фоновый звук МЕЧ: ", nowBgSaber);
        setBgSound();
        // сохранить
        saveSettings();

    // кнопка 1 двойной клик, режим ФАКЕЛ
    } else if (isDouble1 && MODE_FIRE) {
        // выбираем следующий фоновый звук огня
        CYCLE_INC(nowBgFire,  numBgFire);
        LOG2("фоновый звук ФАКЕЛ: ", nowBgFire);
        setBgSound();
        // сохранить
        saveSettings();
      
    // кнопка 1 двойной клик, режим АВТОМАТ
    } else if (isDouble1 && MODE_GUN) {
        // выбираем следующий звук выстрела
        CYCLE_INC(nowSoundShot,  numSoundShot);
        LOG2("звук выстрела: ", nowSoundShot);
        mp3.playSpecific(FLD_SHOT, nowSoundShot + 1);
        // сохранить
        saveSettings();
     
    // кнопка 1 двойной клик, режим МИГАЛКА
    } else if (isDouble1 && MODE_POLICE) {
        // выбираем следующий звук мигалки
        CYCLE_INC(nowSoundPolice,  numSoundPolice);
        LOG2("звук мигалки: ", nowSoundPolice);
        mp3.playSpecific(FLD_POLICE, nowSoundPolice + 1);
        // сохранить
        saveSettings();
     
    // кнопка 1 тройной клик
    } else if (isTriple1) {
        // следующий режим (МЕЧ - АВТОМАТ - ФАКЕЛ - МИГАЛКА - ЖЕЗЛ - ЛАМПА)
        CYCLE_INC(nowMode, 6);
        LOG2("режим: ", nowMode);
        // переключить режим
        setMode();
        // сохранить
        saveSettings();
    
    // кнопка 2 клик, режим МИГАЛКА 
    } else if (isSingle2 && MODE_POLICE) {
        // кря
        mp3.playSpecific(FLD_MISL, MISL_CRYA);
        LOG("кря");
    
    // кнопка 2 двойной клик, режим МИГАЛКА 
    } else if (isDouble2 && MODE_POLICE) {
        // кря-кря
        mp3.playSpecific(FLD_MISL, MISL_CRYA_CRYA);
        LOG("кря-кря");
    
    // кнопка 2 удерживается, режим МИГАЛКА 
    } else if (isHolded2 && MODE_POLICE && !isPoliceSound) {
        // сирена
        mp3.playSpecific(FLD_POLICE, nowSoundPolice + 1); 
        repeatTimer = now;
        isPoliceSound = 1;
        LOG("сирена");
      
    // кнопка 2 клик, режим МЕЧ 
    } else if (isSingle2 && MODE_SABER) {
        // фраза (набор 1)
        mp3.playSpecific(FLD_PHRASE_1, random(numPhrase1) + 1);
        LOG("фраза (набор 1)");
    
    // кнопка 2 двойной клик, режим МЕЧ 
    } else if (isDouble2 && MODE_SABER) {
        // фраза (набор 2)
        mp3.playSpecific(FLD_PHRASE_2, random(numPhrase2) + 1);
        LOG("фраза (набор 2)");
    
    // кнопка 2 клик, режим АВТОМАТ 
    } else if (isSingle2 && MODE_GUN) {
        if (bullets) {
            // выстрел
            mp3.playSpecific(FLD_SHOT, nowSoundShot + 1); 
            showShot();
            LOG("выстрел");
            
        // кончились патроны
        } else {
            // щелчок
            mp3.playSpecific(FLD_MISL, MISL_CLICK); 
            LOG("кончились патроны");
        }
      
    // кнопка 2 двойной клик, режим АВТОМАТ 
    } else if (isDouble2 && MODE_GUN) {
        // перезарядка
        mp3.playSpecific(FLD_MISL, MISL_RECHARGE);
        bullets = BULLETS_INI;
        LOG("перезарядка");
      
    // кнопка 2 удерживается, режим АВТОМАТ 
    } else if (isHolded2 && MODE_GUN && !isMachineGunSound) {
        if (bullets) {
            // очередь
            mp3.playSpecific(FLD_MISL, MISL_MACHINE_GUN); 
            isMachineGunSound = 1;
            LOG("очередь");
          
        // кончились патроны
        } else {
            // щелчок
            mp3.playSpecific(FLD_MISL, MISL_CLICK);
            LOG("кончились патроны");
        }
      
    // кнопка 2 удерживается, режим ФАКЕЛ
    } else if (isHolded2 && MODE_FIRE && !isForcedFireSound) {
        isForcedFireSound = 1;
        mp3.playSpecific(FLD_MISL, MISL_FORCED_FIRE); 
        repeatTimer = now;
        LOG("горелка");
    }

}

// ----------------------------- УТИЛИТЫ ----------------------------------

// подсчет файлов в папке
int countFolderFiles(MD_YX5300 &mp3, int folder) {
  mp3.queryFolderFiles(folder);
  do {
    mp3.check();
    delay(10);
  } while (mp3.getStatus()->code != 65);
  int count = mp3.getStatus()->data;
  
  LOG2("folder: ", folder);
  LOG2("YX5300 code: ", mp3.getStatus()->code);
  LOG2("YX5300 data: ", mp3.getStatus()->data);

  return count;
}

// моргать светодиодом
void blink(CRGB color) {
  static bool ledOn = 0;
  // период 1000 мс =  300 мс горит, 700 мс гаснет
  bool toOn = now % 1000 < 300;
  if (ledOn != toOn) {
    ledOn = toOn;
    setAll(0);
    // включить led, если надо
    if (ledOn) {
      setPixel(0, color);
    }
    FastLED.show();
  }
}

// отобразить уровень громкости длиной зажженной части меча
void volumeShow() {
  // перевести громкость в длину клинка
  byte length = map(nowVolume, 0, 9, 0, NUM_LEDS);

  setAll(0);
  for (byte i = 0; i < length; i++) {
    //зеленый пунктир
    CRGB col = (i % 2)? 0x000000: 0x005000;
    setPixel(i, col);
  }
  FastLED.show();
}

// напоминание выключить питание
void remindOff() {
    // если пора напомнить
    if (now > remindToOff) {
      mp3.playSpecific(FLD_MISL, MISL_REMIND_OFF);
      // напомнить через минуту опять
      remindToOff = now + 60000;
    }
}

// отобразить выстрел
void showShot() {
  // расход патрона
  bullets--;
  // гасим всё
  setAll(0);
  // пуля летит, подсвечиваем каждый 7-ой светодиод
  for (int i = random(7); i < NUM_LEDS; i += 7) {
    setPixel(i, nowRGB);
    FastLED.show();
    setPixel(i, 0);
    delay(5);
  }
  // огонь из дула
  for (int i = 0; i < 1 + NUM_LEDS*0.06; i++) {
    // красный, оранжевый, желтый, черный
    CRGB f[4] = {0xE00000, 0xB02000, 0x705000, 0x000000};
    // случайный цвет
    int r = random(4);
    setPixel(i, f[r]);
    FastLED.show();
    delay(5);
  }
  setAll(0);
  FastLED.show();
}

// следующий цвет
void colorNext() {

  if (MODE_SABER) {
    CYCLE_INC(nowSaberColor,  8);
    setColor(nowSaberColor);
    lightUp();     
    LOG2("цвет меча: ", nowSaberColor);
    
  } else if (MODE_GUN) {
    CYCLE_INC(nowGunColor,  8);
    bullets++;
    setColor(nowGunColor);
    showShot();
    LOG2("цвет выстрела: ", nowGunColor); 
    
  } else if (MODE_LAMP) {
    CYCLE_INC(nowLampColor,  8);
    setColor(nowLampColor);
    lightUp();                         
    LOG2("цвет лампы: ", nowLampColor);   
    
  } else if (MODE_FIRE) {                 
    CYCLE_INC(nowFireColor,  4);
    setFirePal();
    LOG2("палитра огня: ", nowFireColor); 
    
  } else if (MODE_POLICE) {
    CYCLE_INC(nowPoliceColor,  5);
    LOG2("цвет мигалки: ", nowPoliceColor);    
  }
}

// установить фоновый звук
void setBgSound() {
  if (MODE_SABER) {
    mp3bg.playSpecific(FLD_BG_SABER, nowBgSaber + 1);
    repeatBgTimer = now;
  } else if (MODE_FIRE) {
    mp3bg.playSpecific(FLD_BG_FIRE, nowBgFire + 1);
    repeatBgTimer = now;
  } else {
    mp3bg.playStop();
  }
}
  
// устанавить выбранный режим работы (МЕЧ - АВТОМАТ - ФАКЕЛ - МИГАЛКА - ЖЕЗЛ - ЛАМПА)
// firstOn = 1, идет включение меча
void setMode (bool firstOn) {
    // остановить основной и фоновый звук
    mp3.playStop();
    mp3bg.playStop();
    
    if (MODE_SABER) {
      if (firstOn) {
          // воспроизвести звук включения
          mp3.playSpecific(FLD_SOUND_ON, nowSoundOn + 1);
          // отслеживаем окончание воспроизведения в loop() и тогда включим фоновый звук
          playing = SOUND_ON;
      } else {
           // включить фоновый звук
          setBgSound();
      }
      // устанавливаем цвет клинка
      setColor(nowSaberColor);
      // плавно зажечь ленту
      lightUp();
    } else if (MODE_GUN) {
      // перезарядка
      mp3.playSpecific(FLD_MISL, MISL_RECHARGE);
      bullets = BULLETS_INI;
      // устанавливаем цвет выстрела
      setColor(nowGunColor);
      // погасить ленту
      setAll(0);
      FastLED.show();
    } else if (MODE_FIRE) {
      // устанавливаем палитру для огня
      setFirePal();
      // включить фоновый звук
      setBgSound();
    } else if (MODE_LAMP) {
      // устанавливаем цвет лампы
      setColor(nowLampColor);
      // плавно зажечь ленту
      lightUp();
    } else if (MODE_POLICE_STICK) {
      policeStick();
    }    

}

// включение меча
void on() {
    userLastActivity = now;
    if (voltageMeasure() < BATTERY_THR) {
        // аккум разряжен
        LOG("LOW VOLTAGE!");
        isBatteryLow = 1;
    } else {
        // запомнить, что меч включен
        isOn = 1;                
        LOG("SABER ON");
        // установить текущий режим работы, включение
        setMode(true);
    }
}

// выключение меча
void off() {
  userLastActivity = now;
  mp3bg.playStop();
                      
  if (isBatteryLow) {
    // звук умирающего телефона
    mp3.playSpecific(FLD_MISL, MISL_DYING);
  } else if (MODE_SABER) {
    // звук выключения меча
    mp3.playSpecific(FLD_SOUND_OFF, nowSoundOff + 1);
  }
  // лента выключается                    
  lightDown();                   

  LOG("SABER OFF");

  // запомнить, что меч выключен
  isOn = 0;
  // запомнить, когда выключили
  offTimer = now;  

  // напомнить через 5 мин, что надо выключить питание
  remindToOff = now + 300000;
}

// мерцание 
void randomBlink() {
  if (BLINK_ALLOW && (millis() - blinkTimer > BLINK_DELAY)) {
    blinkTimer = millis();
    blinkOffset = blinkOffset * k + random(-BLINK_AMPL, BLINK_AMPL) * (1 - k);
    if (nowSaberColor == 0) blinkOffset = constrain(blinkOffset, -15, 5);
    redOffset = constrain(nowRGB.red + blinkOffset, 0, 255);
    greenOffset = constrain(nowRGB.green + blinkOffset, 0, 255);
    blueOffset = constrain(nowRGB.blue + blinkOffset, 0, 255);
    setAll(CRGB(redOffset, greenOffset, blueOffset));
  }
}

// отработка удара
void strikeTick() {

  /*
  // проигрывать звук удара до конца
  if (playing == SOUND_STRIKE) {
    return;
  }
  */
  
  // если ускорение превысило порог
  if (ACC > STRIKE_THR) {
    // если в дежурном режиме
    if (!isOn) {
        // прошло больше 5 секунд после выключения
        if (now - offTimer > 5000) {
            mp3.playSpecific(FLD_MISL, MISL_WRONG_STRIKE);
            playing = SOUND_STRIKE;
        }
        return;
    }
  
    
    userLastActivity = now;    

    // выйти из режима установки звука вкл/выкл
    if (setupOnOffSound) {
      setupOnOffSound = 0;
    }
    // если воспроизводился звук включения
    if (playing == SOUND_ON) {
      // включить фоновый звук
      setBgSound();
    }

    if (isPress2) {
      mp3.playSpecific(FLD_STRIKE_3, random(numStrike3) + 1);
    } else if (isPress1) {
      mp3.playSpecific(FLD_STRIKE_2, random(numStrike2) + 1);
    } else {
      mp3.playSpecific(FLD_STRIKE_1, random(numStrike1) + 1);
    }
    playing = SOUND_STRIKE;
    
    LOG2("STRIKE: ", ACC);
    // вспышка
    strikeFlash();
  }
}

// отработка взмаха
void swingTick() {
  // не отрабатывать взмах, если что-то проигрывается
  if (playing) {
    return;
  }
  
  // если в дежурном режиме
  if (!isOn) {
      // сильный взмах
      if (GYR > SWING_S_THR && now - offTimer > 5000) {
          // не правильное использование
          mp3.playSpecific(FLD_MISL, MISL_WRONG_SWING);
          playing = SOUND_SWING;
      }
      return;
  }
  // превышен порог углового ускорения
  if (GYR > SWING_THR) {
    // пользователь активен
    userLastActivity = now;
    
    // сильный короткий взмах
    if (GYR > SWING_S_THR) {
      mp3.playSpecific(FLD_SHORT_SWING, random(numShortSwing) + 1);
    // плавный взмах
    } else {
      mp3.playSpecific(FLD_LONG_SWING, random(numLongSwing) + 1);
    }
    playing = SOUND_SWING;
    LOG2("SWING: ", GYR);
  }
}

// прочесть датчик ускорения
void readAccel() {
  // каждые полмиллисекунды
  if (micros() - mpuTimer > 500) {                            
    // сбросить таймер
    mpuTimer = micros();                                      

    // получить показания с IMU
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);       
    // найти среднеквадратичное (сумма трёх векторов в общем)
    ACC = (long)sqrt(sq((double)ax) + sq((double)ay) + sq((double)az)) / 100;
    GYR = (long)sqrt(sq((double)gx) + sq((double)gy) + sq((double)gz)) / 100;
    COMPL = ACC + GYR;
  }
}


// функция выбора цвета одного светодиода
void setPixel(int pixel, CRGB rgb) {
  leds[pixel] = rgb;
}

// функция заливки всех светодиодов выбранным цветом
void setAll(CRGB rgb) {
  for (int i = 0; i < NUM_LEDS; i++ ) {
    leds[i] = rgb;
  }
  FastLED.show();
}

// плавное включение меча
void lightUp() {
  for (int i = 0; i < NUM_LEDS; i++) { 
    setPixel(i, nowRGB);
    FastLED.show();
    delay(10);
  }
}

// плавное выключение меча
void lightDown() {
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    setPixel(i, CRGB::Black);
    FastLED.show();
    delay(10);
  }
}

// моргание при ударе
void strikeFlash() {
    setAll(CRGB::White);     // цвет клинка белым
    delay(FLASH_DELAY);      // ждать
    setAll(nowRGB);          // цвет клинка старым цветом
}

// выбор цвета
// 0-красный, 1-оранжевый, 2-жёлтый, 3-зелёный, 4-голубой, 5-синий, 6-фиолетовый, 7-белый
void setColor(byte color) {
    nowRGB = COLORS[color];
}

// проверка аккума
void batteryTick() {
    // проверять каждые 30 сек
    if (now - batteryTimer > 30000) {
        // когда была последняя проверка аккума
        batteryTimer = now;
        // заряд аккума ниже порога
        if (voltageMeasure() < BATTERY_THR) {
            isBatteryLow = 1;
            if (isOn) {
                // выкл меча
                off();                              
            }
        }    
    }
}

// алгоритм, получающий из напряжения остаток заряда в процентах
// аппроксимировано вручную по графику разряда литий-иона
byte voltageMeasure() {
    // сумма 10 измерений
    long voltage = 0;
    for (int i = 0; i < 10; i++) {    
        voltage += analogRead(VOLT_PIN);
    }
    // R1 добавляется к наплатному делителю 220кОм + 100кОм, 10 измерений, 100 для повышения точности, 
    // если на входе чипа 1 вольт, analogRead() выдает 1023
    // 2 банки
    // если в среднем на каждой банке 4.2 Вольт, то voltage = 420, voltageMeasure() = 100 (%)
    // voltage = voltage * ((R1 + 220 + 100) / 100) / 10 * (1 / 1023) / 2 * 100;
    voltage *= R1 + 220 + 100;
    voltage /= 20460;
    if (voltage > 387)
        voltage =  map(voltage, 420, 387, 100, 77);
    else if (voltage > 375)
        voltage =  map(voltage, 387, 375, 77, 54);
    else if (voltage > 368)
        voltage =  map(voltage, 375, 368, 54, 31);
    else if (voltage > 340)
        voltage =  map(voltage, 368, 340, 31, 8);
    else
        voltage =  map(voltage, 340, 260, 8, 0);
    return constrain(voltage, 0, 100);
}



// установить палитру огня
void setFirePal() {
    if (nowFireColor == 0)
        firePal = CRGBPalette16 (CRGB::Black, CRGB::DarkRed, CRGB::OrangeRed, CRGB::Yellow);
    else if (nowFireColor == 1)
        firePal = CRGBPalette16 (CRGB::Black, CRGB::DarkBlue, CRGB::Green, CRGB::Yellow);
    else if (nowFireColor == 2)
        firePal = CRGBPalette16 (CRGB::Black, CRGB::DarkGreen, 0x004080, CRGB::Cyan);
    else
        firePal = CRGBPalette16 (CRGB::Black, CRGB::DarkRed, CRGB::DarkMagenta, 0xFF77FF);
}

// todo менять COOLING при взмахе
// режим огня
#define COOLING  55
#define SPARKING 120
#define COOLING_F  35
#define SPARKING_F 200

// отрисовка огня
void fire2012() {
  
  if (now - fireTimer > 16) {
    fireTimer = now;

    int cooling = isForcedFireSound? COOLING_F: COOLING;
    int sparking = isForcedFireSound? SPARKING_F: SPARKING;
    // Array of temperature readings at each simulation cell
    static byte heat[NUM_LEDS];

    // Step 1.  Cool down every cell a little
    for( int i = 0; i < NUM_LEDS; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / NUM_LEDS) + 2));
    }
  
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= NUM_LEDS - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    
    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if( random8() < sparking ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }

    // Step 4.  Map from heat cells to LED colors
    for( int j = 0; j < NUM_LEDS; j++) {
      byte colorIndex = scale8( heat[j], 240);
      leds[j] = ColorFromPalette( firePal, colorIndex);
    }
    FastLED.show();
  }
}


// отрисовка мигалки
void police() {
    // текущий шаг анимации
    static int step = 0;
    // всего шагов анимации в выбранной программе
    // строб состоит из 4 морганий = 8 шагов вкл/выкл
    // в последнем режиме кроме 89 стробов есть бегущие огни 
    // 7 циклов 3 цвета 4 повторения каждым цветом
    int stepsCount = (nowPoliceColor == 4)? 89*8 + 7*3*4: 2*8;
    // длительность шага
    int stepTime = 80;
    // длительность полного цикла
    int period = stepTime * stepsCount;
    // номер шага от текущего времени
    int s = (now % period) / stepTime; // 0 .. stepsCount
    // переход на следующий шаг
    if (step != s) {
        step = s;
        // строб
        if (s < 89*8) {
            // гасим ленту
            if (s % 2) {
                if (nowPoliceColor == 0) {
                    clearO();
                } else {
                    clear();
                }
            // включаем ленту выбранным образом
            } else {
                if (nowPoliceColor == 4) {
                    policeLightAll[s/8]();
                } else {
                    policeLight[nowPoliceColor][s/8]();
                }
            }
            FastLED.show();
        // бегущие огни
        } else {
            // номер шага бегущего огня
            s -= 89*8; // 0 .. 7*3*4
            // цикл из 7 повторений, номер шага в цикле
            s %= 3*4; // 0 .. 3*4
            // первые 4 шага пробегает красный
            if (s < 4) {
                redRun();
            // 4 шага пробегает белый
            } else if (s < 8) {
                whiteRun();
            // 4 шага пробегает синий
            } else {
                blueRun();
            }
        }
    }
}
  
// отрисовка жезла
void policeStick() {
    // 5 полосок, длина каждой
    int p = NUM_LEDS / 5;
    setAll(0);
    for (int i = 0; i < NUM_LEDS; i++) {
        // от белых полос идет засветка черных,
        // поэтому уменьшаем длину белых полосок
        // условие (i % p > 1) гасит первые 2 led в каждой полоске
        if ((i / p) % 2 == 0 && (i % p > 1)) {
            setPixel(i, 0xA0A0A0);
        }
    }  
    FastLED.show();
}

// чтение настроек из энергонезависимой памяти
void readSettings() {
    nowMode        = EEPROM.read(0)  % 6;              //  режим меча (0-4)
    nowSaberColor  = EEPROM.read(1)  % 8;              //  цвет меча (0-7)
    nowFireColor   = EEPROM.read(2)  % 4;              //  цвет огня (0-3)
    nowGunColor    = EEPROM.read(3)  % 8;              //  цвет выстрела (0-7)
    nowLampColor  = EEPROM.read(4)  % 8;              //  цвет фонарика (0-7)
    nowVolume      = EEPROM.read(5)  % 10;             //  громкость (0-9)
    nowSoundShot   = EEPROM.read(6)  % numSoundShot;   //  звук выстрела
    nowSoundOn     = EEPROM.read(7)  % numSoundOn;     //  звук включения
    nowSoundOff    = EEPROM.read(8)  % numSoundOff;    //  звук выключения
    nowBgSaber     = EEPROM.read(9)  % numBgSaber;     //  звуковой фон меч
    nowBgFire      = EEPROM.read(10) % numBgFire;      //  звуковой фон факел
    nowPoliceColor = EEPROM.read(11) % 5;              //  цвет мигалки
    nowSoundPolice = EEPROM.read(12) % numSoundPolice; //  звук мигалки
}

// сохранение настроек в энергонезависимую память
void saveSettings() {
    EEPROM.write(0,   nowMode);        // режим меча
    EEPROM.write(1,   nowSaberColor);  // цвет меча
    EEPROM.write(2,   nowFireColor);   // цвет огня
    EEPROM.write(3,   nowGunColor);    // цвет выстрела
    EEPROM.write(4,   nowLampColor);  // цвет фонарика
    EEPROM.write(5,   nowVolume);      // громкость
    EEPROM.write(6,   nowSoundShot);   // звук выстрела
    EEPROM.write(7,   nowSoundOn);     // звук включения
    EEPROM.write(8,   nowSoundOff);    // звук выключения
    EEPROM.write(9,   nowBgSaber);     // звуковой фон меч
    EEPROM.write(10,  nowBgFire);      // звуковой фон факел
    EEPROM.write(11,  nowPoliceColor); // цвет мигалки
    EEPROM.write(12,  nowSoundPolice); // звук мигалки
    EEPROM.commit();
}
  
