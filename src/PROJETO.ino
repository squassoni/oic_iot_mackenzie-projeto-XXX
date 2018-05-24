#include <Wire.h>  
#include <LiquidCrystal_I2C.h> // Using version 1.2.1
#include <DHT.h> 
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
 
// The LCD constructor - address shown is 0x27 - may or may not be correct for yours
// Also based on YWRobot LCM1602 IIC V1
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  dht.begin();
  lcd.begin(16,2); // sixteen characters across - 2 lines
  lcd.backlight();
  // first character - 1st line
  //lcd.setCursor(0,0);
  //lcd.print("Hello World!");
  // 8th character - 2nd line 
  //lcd.setCursor(8,1);
  //lcd.print("-------");
  Serial.begin(9600);
}

void loop() 
{
  // A leitura da temperatura e umidade pode levar 250ms!
  // O atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h)) 
  {
    lcd.setCursor(0,0);
    lcd.print("DHT11 FALHOU");
  } 
  else 
  {
    lcd.setCursor(0,0);
    lcd.print("Temp:");

    lcd.setCursor(8,0);
    lcd.print(t);

    lcd.setCursor(0,1);
    lcd.print("Umid:");

    lcd.setCursor(8,1);
    lcd.print(h);
  }

  delay(2000);
  lcd.clear();
  
  int val;
  val=analogRead(0); //Read Gas value from analog 0
  lcd.setCursor(0,0);
  lcd.print("CO: ");//Print the value to serial port
  lcd.setCursor(8,0);
  lcd.print(val,DEC);//Print the value to serial port
  
  delay(2000);
  lcd.clear();
}

