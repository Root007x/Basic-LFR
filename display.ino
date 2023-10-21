void initial_display() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();
  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);
  display.display();
  delay(2000);  // Pause for 2 seconds
}

void displaymenu() {
  int up = digitalRead(direction);
  int enter = digitalRead(select);
  int back = digitalRead(main_manue);

  if (up == LOW) {
  };
  if (up == LOW) {
    selected = selected + 1;
    if (selected == 3) selected = 0;
    delay(200);
  };
  if (enter == LOW) {
    entered = selected;
  };
  if (back == LOW) {
    entered = -1;
  };

  const char *options[3] = {
    "1.Sensors Check ",
    "2.Auto Calibration ",
    "3. Exit "
  };

  if (entered == -1) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(36, 0);
    display.println(F("***BOT***"));
    display.println("");
    for (int i = 0; i < 3; i++) {
      if (i == selected) {
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
        display.println(options[i]);
      } else if (i != selected) {
        display.setTextColor(SSD1306_WHITE);
        display.println(options[i]);
      }
    }
  } else if (entered == 0) {
    reading();
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(25, 0);
    display.println(F("***Sensors***"));
    display.setCursor(15, 25);
    for (int i = 0; i < 6; i++) {
      display.print(String(s[i], 10) + "  ");
    }
    display.setCursor(0, 50);
    display.println("Sum = " + String(sum));

  } else if (entered == 1) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 30);
    display.println("Calibration Activated");
    display.display();
    delay(1000);
    cal();
    entered = 10;
  }
  else if(entered == 2) resetFunc();
  if(entered == 10){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(20, 30);
    display.println("Calibration Done");
  }
    display.display();
}