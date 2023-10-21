#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include<EEPROM.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int selected = 0;
int entered = -1;
int direction = 4, select = 5, main_manue = 6;

uint32_t m1,m2;

int lmf = 3, lmb = 11;
int rmf = 9, rmb = 10;
double spl = 18, spr = 18; // motor speed
int s[6],maximum[6],minimum[6],mid[6];
int base[6] = {1,2,4,16,32,64};
int sensor;
//int pwm = 380;
char data;
int sum = 0;
int flag = 's';
int sw = 12;
char cross =  's';
int node_delay = 10; // if robot slow turn not perfectly increase value
char side = 'l'; // left or right rule
int stop_timer = 100;
int u_turn_delay = 90; // if don't u turn change delay
byte path[50];
byte counter = 0;
int pos;
int brake_time = 175; // adjust brake time
int turn_brake = 40; // turn adjust

void(* resetFunc) (void) = 0;

void setup() {
    Serial.begin(9600);
    pinMode(direction, INPUT_PULLUP);
    pinMode(select, INPUT_PULLUP);
    pinMode(main_manue, INPUT_PULLUP);
    pinMode(sw, INPUT_PULLUP);
    pinMode(LED_BUILTIN,OUTPUT);
    pinMode(lmf, OUTPUT);
    pinMode(lmb, OUTPUT);
    pinMode(rmf, OUTPUT);
    pinMode(rmb, OUTPUT);
    Serial.println("Welcome To Nano World");

    show_cal();
    initial_display();
    //show_maze_scan();
    
}
void loop() {
    int r = button_press();
    if(r != 0){
        if(r == 1) {
            while(true){
                displaymenu();
            }
        }
        else if(r == 2) maze_scan();
        else if(r == 3) maze_solving(0);
        else if(r == 4) remort_control();
        else if(r == 5) line_follow();
    }
}
