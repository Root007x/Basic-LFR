void recording() {
  for (byte i = 0;; i++) {
    EEPROM.write(i + 30, path[i]); delay(10);
    if (path[i] == 5) return;
  }
}

void show_maze_scan(){
    for (byte i = 0; EEPROM.read(i + 30) != 5; i++) Serial.println(EEPROM.read(i + 30));
}