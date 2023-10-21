void cal(){
    for(int i = 0;i < 6;i++){
        maximum[i] = 0;
        minimum[i] = 1023;
    }
    motor(130, -130);
    for(int i = 0;i < 9000;i++){
        for(int i = 0;i < 6;i++){
            if(i == 4 || i == 5){
                s[i] = analogRead(i + 2);
                goto lvl;
            }
            s[i] = analogRead(i);
            lvl:
            maximum[i] = max(maximum[i],s[i]);
            minimum[i] = min(minimum[i],s[i]);
        }
    }
    motor(0,0);
    for(int i = 0;i < 6;i++){
        mid[i] = (maximum[i] + minimum[i])/2;
        EEPROM.write(i,mid[i]/4);
        delay(10);
        EEPROM.write(i+6,maximum[i]/4);
        delay(10);
        EEPROM.write(i+12,minimum[i]/4);
        delay(10);
    }
}

void show_cal(){
    for(int i = 0;i < 6;i++){
        mid[i] = EEPROM.read(i) * 4;
        maximum[i] = EEPROM.read(i+6) * 4;
        minimum[i] = EEPROM.read(i+12) * 4;
        Serial.println(String(maximum[i]) + " " + String(mid[i]) + " " + String(minimum[i]));
    }
}