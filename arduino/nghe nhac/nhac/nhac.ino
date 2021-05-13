

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

int r,g,b; 
int pos = 0;    // variable to store the servo position

#define PIN          6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      8
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
int delayval = 500; // delay for half a second



//int x =30; 
int a1 =450; 
int a2 = 480; 
int a3 = 500; 
int a4 = 520;
int a5 =550; 
int a6 = 600; 
int a7 = 650; 
int a8 = 700;

void setup() {
  
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
 
  pixels.begin(); // This initializes the NeoPixel library.
//
//for(int i=0;i<NUMPIXELS;i++){
//
//    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//    pixels.setPixelColor(i, pixels.Color(64,128,64)); // Moderately bright green color.
//
//    pixels.show(); // This sends the updated pixel color to the hardware.
//    delay(200);
//}
//delay(1000);
//for(int i=0;i<NUMPIXELS;i++){
//
//    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
//
//    pixels.show(); // This sends the updated pixel color to the hardware.
//    
//}
//  
 }

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  if(sensorValue>a1){
     r =random(0,128); 
     g =random(0,128); 
     b = random(0,128); 
      pixels.setPixelColor(0, pixels.Color(r,g,b)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }else{
       pixels.setPixelColor(0, pixels.Color(0,0,0)); // Moderately bright green color.
       pixels.show(); // This sends the updated pixel color to the hardware.
      }
    
  if(sensorValue>a2){
        r =random(0,128); 
     g =random(0,128); 
     b = random(0,128); 
      pixels.setPixelColor(1, pixels.Color(r,g,b)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      }else{
    pixels.setPixelColor(1, pixels.Color(0,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.
        }
        
  if(sensorValue>a3){
    r =random(0,128); 
     g =random(0,128); 
     b = random(0,128); 
           pixels.setPixelColor(2, pixels.Color(r,g,b)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }else{
    pixels.setPixelColor(2, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
      }
    
  if(sensorValue>a4){
      r =random(0,128); 
     g =random(0,128); 
     b = random(0,128); 
      pixels.setPixelColor(3, pixels.Color(r,g,b)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      }else{
         pixels.setPixelColor(3, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
      }
      
  if(sensorValue>a5){
     r =random(0,128); 
     g =random(0,128); 
     b = random(0,128);  
           pixels.setPixelColor(4, pixels.Color(r,g,b)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }else{
       pixels.setPixelColor(4, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
      }
    
  if(sensorValue>a6){
       r =random(0,128); 
     g =random(0,128); 
     b = random(0,128);  
           pixels.setPixelColor(5, pixels.Color(r,g,b)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      }else{
         pixels.setPixelColor(5, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
        }
  if(sensorValue>a7){
    r =random(0,128); 
     g =random(0,128); 
     b = random(0,128); 
           pixels.setPixelColor(6, pixels.Color(r,g,b)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    } else{
       pixels.setPixelColor(6, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
      }
    
  if(sensorValue>a8){
      r =random(0,128); 
     g =random(0,128); 
     b = random(0,128);  
           pixels.setPixelColor(7, pixels.Color(r,g,b)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      }else{
         pixels.setPixelColor(7, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
        }
}
