<p align="center">
 <h1 align="center">AquaSensor</h1>
 <p align="center">O novo projeto de captura de informações da água</p>
</p>

## Introdução
Este é nosso projeto em c++ com arduino em que visamos solucionar o problema de falta e dificuldade a acesso e informação sobre as águas do oceano. O projeto foi originalmente feito do Wokwi, junto com a simulação. Para ver a simulação entre no link: https://wokwi.com/projects/399793052773957633

## 1- Definições:
A primeira coisa que fizemos no código foi chamar as bibliotecas da LiquidCristal e DHT para utilizar a tela lcd e o sensor dht22 respectivamente
> **Note**
> As bibliotecas foram instaladas previamente no ambiente de trabalho (no caso, o wokwi)
Depois definimos a porta de entrada do dht e o tipo dele, no caso dht22. Por ultimo declaramos as váriaveis que serão usadas para o sensor de luz ldr

```md
#include <LiquidCrystal.h>
#include <DHT.h>
LiquidCrystal lcd(12,11,5,4,3,2);

#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int foto = A0;
float luz = 0;
```

## 2- Setup:
Em nosso void setup iniciamos o lcd e o dht, e colocamos a variavel foto (que se refere ao ldr na porta A0) e "ligamos" ele como INPUT
> **Note**
> INPUT se refere a entrada de informação

```md
void setup(){
lcd.begin(16,2);
lcd.setCursor(4,1);
dht.begin();
pinMode(foto, INPUT);
}
```

## 3- Verificando as váriaveis:
Dentro do void loop iremos usar as informações providas pelos sensores para passar pelos parametros normais da água, assim podemos compara o valor das variaveis com as codiçoes dos 'if' para mostrar para o usuário a qualidade da água (podendo ser 'bom', 'ok' e 'ruim')

```md
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
```

## 4- Apresentação no lcd
Para finalizar o void loop, configuramos o lcd para mostrar um pequeno texto (como temp e luz), Adicionamos o valor providos pelos sensores, e por fim passamos o nivel de qualidade obtido ao passar pelas codicionais de 'if'

```md
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
```
> **Note**
> Os setCursor servem para dizer em qual parte do lcd eles devem aparecer, por exemplo, o lcd.setCursor(0,0) mostra o texto na primeira coluna e na primeira linha

Após um delay o lcd é limpo e o loop recomeça


INTEGRANTES:
- Luiz Fernando Souza RM: 555561
- Bruno Otavio RM:556196
