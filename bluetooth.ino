void remort_control(){
    while(true){
        if(Serial.available() > 0){
            data = Serial.read();
            Serial.println(data);

            if(data == 'F') motor(spl * 10,spr * 10);
            else if(data == 'L') motor(-spl * 10,spr * 10);
            else if(data == 'R') motor(spl * 10,-spr * 10);
            else if(data == 'G') motor(0 * 10,spr * 10);
            else if(data == 'I') motor(spl * 10,0 * 10);
            else if(data == 'H') motor(0 * 10,-spr * 10);
            else if(data == 'J') motor(-spl * 10,0 * 10);
            else if(data == 'B') motor(-spl * 10,-spr * 10);
            else if(data == 'S') motor(0,0);
            else if(data == '0') {spl = 0;spr = 0;}
            else if(data == '1') {spl = 2.5;spr = 2.5;}
            else if(data == '2') {spl = 5;spr = 5;}
            else if(data == '3') {spl = 7.5;spr = 7.5;}
            else if(data == '4') {spl = 10;spr = 10;}
            else if(data == '5') {spl = 12.5;spr = 12.5;}
            else if(data == '6') {spl = 15;spr = 15;}
            else if(data == '7') {spl = 17.5;spr = 17.5;}
            else if(data == '8') {spl = 20;spr = 20;}
            else if(data == '9') {spl = 22.5;spr = 22.5;}
            else if(data == 'q') {spl = 25;spr = 25;}

        }
    }
}