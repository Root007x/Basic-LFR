int button_press(){
    int count = 0;
    p:
    int t = 0;
    if(digitalRead(sw) == 0){
        digitalWrite(LED_BUILTIN,1);
        while(digitalRead(sw) == 0){
            delay(1); t++;
        }
        digitalWrite(LED_BUILTIN,0);
        if(t > 15){
            count++;
            t = 0;
            while(digitalRead(sw) == 1){
                delay(1); t++;
                if(t > 1000) return count;
            }
        }
        goto p;
    }
    return count;
}