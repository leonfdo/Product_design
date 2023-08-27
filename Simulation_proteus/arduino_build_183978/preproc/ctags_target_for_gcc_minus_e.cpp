# 1 "C:\\Users\\leonf\\Music\\sem 4\\EDR\\arduino_for_rain\\sketch_apr13a\\sketch_apr13a.ino"
# 2 "C:\\Users\\leonf\\Music\\sem 4\\EDR\\arduino_for_rain\\sketch_apr13a\\sketch_apr13a.ino" 2
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Arduino pins to lcd


int adc_value;
int percent_value;


int silent=0;






void setup() { // put your setup code here, to run once 

//pinMode(sensor_pin, INPUT);

pinMode(A5, 0x2);
Serial.begin(9600);
pinMode(9,0x1); // declare Red LED as output
pinMode(8,0x1); // declare Green LED as output
pinMode(13,0x1); // declare Buzzer as output 

lcd.begin(16, 2); // Configura lcd numero columnas y filas
lcd.clear();
lcd.setCursor (0,0);
lcd.print("   Welcome To   ");
lcd.setCursor (0,1);
lcd.print(" Rain  Detector ");
delay(2000);
lcd.clear();
}

void loop() {

adc_value= digitalRead(A0);
//percent_value = map(adc_value,0,1023,100,0);
Serial.println(adc_value);
if(adc_value){
  percent_value=100;
}else{
  percent_value=0;
}

if(digitalRead (A5) == 0){
silent = 1;
delay(100);
}

lcd.setCursor(0, 0);
lcd.print("Rain Level: ");
lcd.print(percent_value);
lcd.print("%  ");

lcd.setCursor(0, 1);
if(percent_value>30){
if(silent==0){digitalWrite(13, 0x1);}
lcd.print("Rain Alert...!!!");
digitalWrite(8, 0x0); // Turn LED off.   
digitalWrite(9, 0x1); // Turn LED on.
delay(300);
}else{ silent=0;
lcd.print(".....Normal.....");
digitalWrite(8, 0x1); // Turn LED on.  
digitalWrite(9, 0x0); // Turn LED off.
}

digitalWrite(13, 0x0);
delay(100);
}
