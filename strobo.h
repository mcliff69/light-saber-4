#define NUM_3    (NUM_LEDS/3)
#define NUM_6    (NUM_LEDS/6)
#define NUM_9    (NUM_LEDS/9)

#define RED      0xFF0000
#define DARK_RED      0x0F0000
#define WHITE    0xE0E0E0
#define BLUE     0x0000FF
#define DARK_BLUE     0x00000F
#define ORANGE      0xFF6000
#define DARK_ORANGE      0x0F0600

#define RED_FROM   0
#define WHITE_FROM   NUM_3
#define BLUE_FROM   2*NUM_3



extern CRGB leds[];
extern unsigned long now;


void fill(int from, int count, CRGB color) {
    for (int i = from; i < from + count; i++) {
        leds[i] = color;
    }    
}
// гасим ленту, оранжевые фонари
void clearO()  {
    FastLED.clear();
    // подсветка расположения фонарей
    fill(RED_FROM, NUM_3, DARK_ORANGE);
    fill(BLUE_FROM, NUM_3, DARK_ORANGE);
}
// OOOO ______ ____
void orange1()  {
    fill(RED_FROM, NUM_3, ORANGE);
}
// ____ ______ OOOO
void orange2()  {
    fill(BLUE_FROM, NUM_3, ORANGE);
}
// гасим ленту, красный и синий фонари
void clear()  {
    FastLED.clear();
    // подсветка расположения фонарей
    fill(RED_FROM, NUM_3, DARK_RED);
    fill(BLUE_FROM, NUM_3, DARK_BLUE);
}
// RRRR WWW BBBB
void redWhiteBlue()  {
    fill(RED_FROM, NUM_3, RED);
    fill(WHITE_FROM, NUM_3, WHITE);
    fill(BLUE_FROM, NUM_3, BLUE);
}
// ____ WWW ____
void white()  {
    fill(WHITE_FROM, NUM_3, WHITE);
}
// RRRR ______ ____
void red()  {
    fill(RED_FROM, NUM_3, RED);
}
// ____ ______ BBBB
void blue()  {
    fill(BLUE_FROM, NUM_3, BLUE);
}
// RR__ ______ __BB
void redBlue1()  {
    fill(RED_FROM, NUM_6, RED);
    fill(BLUE_FROM + NUM_6, NUM_6, BLUE);
}
// __RR ______ BB__
void redBlue2()  {
    fill(RED_FROM + NUM_6, NUM_6, RED);
    fill(BLUE_FROM, NUM_6, BLUE);
}
// RR__ _W_ __BB
void redWhiteBlue1()  {
    fill(RED_FROM, NUM_6, RED);
    fill(WHITE_FROM + NUM_9, NUM_9, WHITE);
    fill(BLUE_FROM + NUM_6, NUM_6, BLUE);
}
// ____ _W_ ____
void white2()  {
    fill(WHITE_FROM + NUM_9, NUM_9, WHITE);
}
// ____ W_W ____
void white13()  {
    fill(WHITE_FROM, NUM_9, WHITE);
    fill(WHITE_FROM + 2*NUM_9, NUM_9, WHITE);
}
// R -------> R
void redRun()  {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = RED; 
        FastLED.show();         
    }
    FastLED.clear ();
}
// B <-------- B
void blueRun()  {
    for (int i = NUM_LEDS - 1; i >= 0; i--) {
        leds[i] = BLUE; 
        FastLED.show();  
    }
    FastLED.clear ();
}
// W <------- W
void whiteRun()  {
    for (int i = NUM_LEDS - 1; i >= 0; i--) {
        leds[i] = WHITE; 
        FastLED.show();  
    }
    FastLED.clear ();
}

typedef void (*VoidFunc)();

VoidFunc policeLightAll[89];

VoidFunc policeLight[4][2] = {
    {orange1, orange2},
    {red, blue},
    {redBlue1, redBlue2},
    {redWhiteBlue1, redBlue2}
};


void initPoliceLightAll() {
    VoidFunc *ptr = policeLightAll;
    for (int i = 0; i < 2; i++) {
        *ptr++ = red;
        *ptr++ = blue;
    }
    for (int i = 0; i < 2; i++) {
        *ptr++ = redWhiteBlue;
    }
    *ptr++ = red;
    *ptr++ = blue;
    for (int i = 0; i < 4; i++) {
        *ptr++ = redBlue1;
        *ptr++ = redBlue2;
    }
    *ptr++ = white;
    for (int i = 0; i < 7; i++) {
        *ptr++ = redWhiteBlue1;
        *ptr++ = redBlue2;
    }
    for (int i = 0; i < 14; i++) {
        *ptr++ = red;
        *ptr++ = blue;
    }
    for (int i = 0; i < 14; i++) {
        *ptr++ = redBlue1;
        *ptr++ = redBlue2;
    }
    *ptr++ = white2;
    *ptr++ = white13;
};
