//library for using analog - digital multiplexers
#include "Type4067Mux.h" 
// library allows you to communicate with I2C / TWI devices
#include <Wire.h>
//This is a library for the Adafruit BMP085/BMP180 Barometric Pressure + Temp sensor
#include <Adafruit_BMP085.h>
Type4067Mux mux(A0, INPUT, ANALOG, D5, D6, D7, D8);

//include the libraries for using ESP8266 and firebase.
// esp8266 library
#include <ESP8266WiFi.h> 
// firebase library
#include <FirebaseArduino.h> 

// include libraries for set up time 
//libraries to connect to Wi-Fi and get time and create an NTP client.
#include <NTPClient.h>
#include <WiFiUdp.h>

Adafruit_BMP085 bmp;
//get time through the wifi connection
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 19800, 60000); //initalize the time zone and add +5:30 x 60 x 60 

// dht11 temperature and humidity sensor library 
#include "DHT.h"     
// select dht type as DHT 11 or DHT22 
#define DHTTYPE DHT11  
// what digital pin we're connected to 
#define dht_dpin 0    
DHT dht(dht_dpin, DHTTYPE); 

String a,b,c,d,e,f,xx,yy,cc,co,coo,ttt;

#include <ACROBOTIC_SSD1306.h>

 float data1, data2, data3;
 int uuu = 1,count = 0,count1 = 0;
 float data4, data5, data, h, t, countt = 0, countt1 = 0;
 float cad = 0;
 
//FIREBASE SETUP
// the project name address from firebase id
#define FIREBASE_HOST "final-f582e.firebaseio.com"  
// the secret key generated from firebase
#define FIREBASE_AUTH "vvNIjbBLf8sIIksShCqLRU5lT8Apwr2xwkzGbyuS" 
//CONNECT WITH YOUR NETWORK
#define WIFI_SSID "J.A.R.V.I.S"  // input your home or public wifi name 
#define WIFI_PASSWORD "12345567"   //password of wifi ssid

#define motor1 D0
#define motor2 D4


void setup() {

 pinMode(motor1, OUTPUT);
 pinMode(motor2, OUTPUT);

 Wire.begin();  
 oled.init();


 Serial.begin(9600);

 dht.begin();

 if (!bmp.begin()) {
 Serial.println("Could not find a valid BMP085 sensor, check wiring!");
 while (1) {}
 }
 
//CONNECT TO THE WIFI NETWORK
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  //try to connect with wifi
 Serial.print("connecting");
 oled.clearDisplay();
 oled.setTextXY(0,4);             
 oled.putString("--WIFI--");
 oled.setTextXY(5,2);             
 oled.putString("-Connecting-");

 while (WiFi.status() != WL_CONNECTED) {
   Serial.print(".");

   delay(500);
 }
 Serial.println();
 Serial.print("connected: ");
 oled.clearDisplay();
 oled.setTextXY(5,0);             
 oled.putString("-Connected-");
 delay(1000);
 Serial.println(WiFi.localIP());  //print local IP address
//FIREBASE INITIALIZATION & connect to the firebase database server.
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

 digitalWrite(motor1, HIGH);

delay(1000);     
digitalWrite(motor1, LOW); 
delay(1000);


digitalWrite(motor2, HIGH);

delay(1000);     
digitalWrite(motor2, LOW); 
delay(1000);

timeClient.begin();



}

void read(){
  
   data = mux.read(8);
   data1 = mux.read(9);
   data2 = mux.read(10);
   data3 = mux.read(11);
   data4 = bmp.readTemperature();
   data5 = bmp.readPressure();
   h = dht.readHumidity();
   t = dht.readTemperature();  

   data1 = (data1/1024)*100;
   data1 = 100-data1;
   data2 = (data2/1024)*100;
   data2 = 100-data2;
   data3 = (data3/1024)*100;
   data3 = 100-data3;
   data = (data/1024)*100;
   data = 100-data;

 }

 
//print the sensors values in LED display
 void display(){

  a = data;
  b = data1;
  c = data2;
  d = data3;
  e = data4;
  f = data5;
  xx = h;
  yy = t;
  
// Displaying rain sensor value
  oled.setTextXY(0,0);  
  oled.putString("-Rain Sensor-");  
  oled.setTextXY(4,3);         
  oled.putString(a);
  delay(1000);
  oled.clearDisplay();
  
// Displaying soil moisture sensor 01 value
  oled.setTextXY(0,0);   
  oled.putString("-water Sensor_1-");  
  oled.setTextXY(4,3);         
  oled.putString(b);
  delay(1000);
  oled.clearDisplay();
  
// Displaying Light sensor value
  oled.setTextXY(0,0);   
  oled.putString("-LDR Sensor-");  
  oled.setTextXY(4,3);         
  oled.putString(c);
  delay(1000);
  oled.clearDisplay();
  
// Displaying soil moisture sensor 02 value
  oled.setTextXY(0,0);   
  oled.putString("-water Sensor_2-");  
  oled.setTextXY(4,3);         
  oled.putString(d);
  delay(1000);
  oled.clearDisplay();
  
// Displaying temperature sensor value
  oled.setTextXY(0,0);   
  oled.putString("-temp Sensor-");  
  oled.setTextXY(4,3);         
  oled.putString(e);
  delay(1000); 
  oled.clearDisplay();
  
// Displaying pressure sensor value
  oled.setTextXY(0,0);   
  oled.putString("-preasure Sensor-");  
  oled.setTextXY(4,3);         
  oled.putString(f);
  delay(1000);
  oled.clearDisplay();
  
// Displaying humidity sensor value
  oled.setTextXY(0,0);   
  oled.putString("-humadity Sensor-");  
  oled.setTextXY(4,3);         
  oled.putString(xx);
  delay(1000);
  oled.clearDisplay();

   }

   
//   send data to the Firebase realtime database
   void sent_fire_base(){
//    Firebase.pushString("/DHT11/Temperature", fireTemp); 
Firebase.setString("Variable/"+ +"/rain_sensor",a +"%");
     Firebase.setString("Variable/"+cc+"/rain_sensor",a +"%");
     Firebase.setString("Variable/"+cc+"/water_sensor_1",b +"%");
     Firebase.setString("Variable/"+cc+"/ldr_sensor",c +"%");
     Firebase.setString("Variable/"+cc+"/water_sensor_2",d +"%");
     Firebase.setString("Variable/"+cc+"/temperature_sensor",e +"°C");
     Firebase.setString("Variable/"+cc+"/preasure_sensor",f +"Pa");
     Firebase.setString("Variable/"+cc+"/humadity_sensor",xx +"%");

     Firebase.setString("Variable/"+cc+"/motor1",co +"min");
     Firebase.setString("Variable/"+cc+"/motor2",coo +"min");

     Firebase.setString("Variable/"+cc+"/time",ttt);

     delay(500);
     }


void loop() {
 countt = 0;
 countt1 = 0;

 co = countt;
 coo = countt1;

read();

   // 8----rain sensor
   // 9----water sensor 1 left
   // 10---LDR sensor
   // 11---water sensor 2 middle

display();

 oled.setTextXY(3,0);   
 oled.putString("-Sending Data-");  
 uuu++;
 cc = String(uuu);



if(data1 < 50 || count > 0) {
 digitalWrite(motor1, HIGH);
 count++;
 delay(10);
 if( data1 > 90){
   countt = count;
   countt = countt*7.5;
   countt = countt/60;
   co = countt;

   digitalWrite(motor1, LOW);
   count = 0;
   }
 }

 if (data3 < 50 || count1 > 0){
 digitalWrite(motor2, HIGH);
 count1++;
 Serial.println(count);
 delay(10);
 if( data3 > 90){
   cad = count1;
   cad = cad*7.5;
   cad = cad/60;
   coo = cad;

   Serial.println(coo);

   digitalWrite(motor2, LOW);
   count1 = 0;
   }
 }

 timeClient.update();
 ttt = timeClient.getFormattedTime();

 sent_fire_base();
 oled.clearDisplay();

}
