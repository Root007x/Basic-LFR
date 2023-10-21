void reading(){
    sensor = 0;
    sum = 0;
    for(int i = 0;i < 6;i++){ // 0 1 2 
        if(i == 4 || i == 5){
            s[i] = analogRead(i + 2);
            goto lvl;
        }
        s[i] = analogRead(i);
        lvl:
        (s[i] > mid[i]) ? s[i] = 1: s[i] = 0;
        sensor += s[i] * base[i];
        sum += s[i];
    }
}

void show_the_value(){
    for(int i = 0;i < 6;i++){
        Serial.print(String(s[i],10) + " ");
    }
    Serial.println(sensor);
}