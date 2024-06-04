#include <LiquidCrystal.h>
#include <DHT.h>
LiquidCrystal lcd(12,11,5,4,3,2);

#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int foto = A0;
float luz = 0;

void setup(){
lcd.begin(16,2);
lcd.setCursor(4,1);
dht.begin();
pinMode(foto, INPUT);
}

void loop(){
float temp = dht.readTemperature();
String tempquali = "ok";

luz = analogRead(A0);

String luzquali = "ok";

if (temp >= 19 || temp <=2){
  tempquali = "Ruim";
} else if (temp <= 5 || temp >= 15){
  tempquali = "Ok";
} else{
  tempquali = "Bom";
}

if (luz >= 640 || luz <= 220){
  luzquali = "Ruim";
} else if (luz >= 500 || luz <= 350){
  luzquali = "Ok";
} else{
  luzquali = "Bom";
}

lcd.setCursor(0,0);
lcd.print("Temp: ");
lcd.print(dht.readTemperature(), 0);
lcd.print("C ");
lcd.print(tempquali);

lcd.setCursor(0,1);
lcd.print("Luz: ");
lcd.print(luz);
lcd.print(" ");
lcd.print(luzquali);

luz = analogRead(A0);

delay(500);

lcd.clear();
}
