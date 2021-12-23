
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
int bassl = 0, bassr = 0, treble = 0;
int r, g, b;
int pos = 0;    // variable to store the servo position
int amax = 0;
#define PIN1          6

#define NUMPIXELS      31
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pixels.begin(); // This initializes the NeoPixel library.
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  r = random(0, 128);
  g = random(0, 128);
  b = random(0, 128);
  for (int i = 0; i < 3; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(r, g, b)); // Moderately bright green color.
  
  }
}
int temmax = 0;
uint64_t messageTimestamp = 0 ;

void loop() {

  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.print(analogRead(A1));
//  Serial.print(" ");
//  Serial.print(analogRead(A2));
 Serial.println("");
  bassl = analogRead(A0);
   treble= analogRead(A1);
//  bassr = analogRead(A2);
  if (temmax < bassl) {
    temmax = bassl;
  }
//  if (temmax < bassr) {
//    temmax = bassr;
//  }
//  if (temmax < treble) {
//    temmax = treble;
//  }
   
  uint64_t now = millis();
  if (now - messageTimestamp > 10000) {
    amax = temmax;
    r = random(0, 128);
    g = random(0, 128);
    b = random(0, 128);
    messageTimestamp = now;
    for (int i = 0; i < 3; i++) {
      
      pixels.setPixelColor(i, pixels.Color(r, g, b)); // Moderately bright green color.
    
      pixels.show(); // This sends the updated pixel color to the hardware.
     

    }
  }
  for (int i = 30; i >= 3; i--) {

      pixels.setPixelColor(i, pixels.Color(0, 0,0)); // Moderately bright green color.
      
      pixels.show(); // This sends the updated pixel color to the hardware.
     

    }
  bassl= map(bassl,0,600,3,31); 
   
   r = random(0, 128);
    g = random(0, 128);
    b = random(0, 128);
    for (int i = 3; i < bassl; i++) {

      pixels.setPixelColor(i, pixels.Color(r, g, b)); // Moderately bright green color.
      
      pixels.show(); // This sends the updated pixel color to the hardware.
     

    }
   
}
