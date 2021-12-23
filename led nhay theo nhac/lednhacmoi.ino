#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN        6 // On Trinket or Gemma, suggest changing this to 1
#define NUM_LEDS 19 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
int r=152;
int g=0;
int b=10;

 int mode =0; 
int leds[3][NUM_LEDS];
int led_con[3][3][7];  // mode -R,G,B -led  

int s=0;
 int tinh =0; 
 int led =0; 
 int preled =0; 
 void hienthitinh(int i){
   pixels.setPixelColor(i, pixels.Color( led_con[mode][0][3], led_con[mode][1][3],led_con[mode][2][3]));
   pixels.show(); 
  }
 void hienthi(int i){
  if(i>=2){
    
//      pixels.setPixelColor(i, pixels.Color( led_con[0][0][3], led_con[0][1][3],led_con[0][2][3]));
      pixels.setPixelColor(i, pixels.Color( led_con[mode][0][2], led_con[mode][1][2],led_con[0][2][2]));
      pixels.setPixelColor(i-1, pixels.Color( led_con[mode][0][1], led_con[mode][1][1],led_con[0][2][1]));
      pixels.setPixelColor(i-2, pixels.Color( led_con[mode][0][0], led_con[mode][1][0],led_con[0][2][0]));
      if(i>2){
        for(int j = i-3 ;j>=0; j-- ){
          pixels.setPixelColor(j, pixels.Color( led_con[mode][0][0], led_con[mode][1][0],led_con[mode][2][0]));
          }
        }
      pixels.show();
    }  
  }
 void def(){
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(60, 10, 10));
      pixels.setPixelColor(1, pixels.Color(0, 10, 10));
      pixels.setPixelColor(2, pixels.Color(0, 0, 5));
      pixels.setPixelColor(3, pixels.Color(0, 100, 0));
      pixels.show();
  }
void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

       pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
       for(int j=0 ;j<=NUM_LEDS;j++){
         for(int i =NUM_LEDS ; i>=j; i--){
          if(i<NUM_LEDS){
           pixels.setPixelColor(i+1, pixels.Color(0, 0, 0));
           pixels.show();
          }
           pixels.setPixelColor(i, pixels.Color(50, 0, 30));
             pixels.show(); 
            delay(10); 
            
          }
       }
      for(int j=NUM_LEDS ;j>=0;j--){
         for(int i =j ; i<=NUM_LEDS; i++){
          if(i>j){
             pixels.setPixelColor(i-1, pixels.Color(0, 0, 0));
             pixels.show(); 
             }
           pixels.setPixelColor(i, pixels.Color(50, 0, 30));
             pixels.show(); 
            delay(10);
             
          }
       }
       def(); 


       led_con[0][0][0] = 60; 
       led_con[0][1][0] = 10; 
       led_con[0][2][0] = 10; 
      
       led_con[0][0][1] = 30; 
       led_con[0][1][1] = 0; 
       led_con[0][2][1] = 10; 

       led_con[0][0][2] = 100; 
       led_con[0][1][2] = 10; 
       led_con[0][2][2] = 100; 
      

       led_con[0][0][3] = 0; 
       led_con[0][1][3] = 100; 
       led_con[0][2][3] = 0;
///////////////////////////////////////////////////
        led_con[1][0][0] = 50; 
       led_con[1][1][0] = 200; 
       led_con[1][2][0] = 10; 
      
       led_con[1][0][1] = 50; 
       led_con[1][1][1] = 100; 
       led_con[1][2][1] = 30; 

       led_con[1][0][2] = 50; 
       led_con[1][1][2] = 50; 
       led_con[1][2][2] = 10; 
      

       led_con[1][0][3] = 0; 
       led_con[1][1][3] = 0; 
       led_con[1][2][3] = 100;
       
       //////////////////////////
       Serial.begin(9600);
       pinMode(A0,INPUT);

   //1200-900-700-500-400-300-200-100-0; 
}
unsigned long time1 =0;
unsigned long time2 =0;

void loop() {
  if ((unsigned long) (millis() - time2) > 100)
    {
      if(digitalRead(D3)){
       while(digitalRead(D3)); 
       mode = (mode+1 )%3;
       if(mode==2){
         pixels.clear(); 
        pixels.show(); 
         }
      time2 = millis(); 
      }
    } 
  if(mode%3!=2){
   
    
    
   s=analogRead(A0);
   s-=500;
   s= s>150?s:0; 
   s= s<1000?s:1000;  
   Serial.println(s); 
    if((s>800)&&(s<=1000))
  {
    
    led = map(s, 801, 1000, 16, 18);
  }
  else if((s>650)&&(s<=800))
  
   {
    led = map(s, 651, 800, 11, 15);
   }
   else if((s>450)&&(s<=650))
  {
    led = map(s, 451, 650, 8,10 );
  }
    else if((s>250)&&(s<=450))
   {
      led = map(s, 251, 450, 5, 7);
   }
   
  else if((s>150)&&(s<=250))
   {
  led = map(s, 151, 250, 3, 4);
    
   }
   else if((s<=150))
   {
     led =2; 
   }
    if(preled>led){
           for(int i=preled; i>=led; i--){
           pixels.setPixelColor(i, pixels.Color(0,0,0));
        }
        preled =led; 
      }
 
     hienthi(led);
     preled =led ; 
     if(led+1>tinh){
        tinh = led +1; 
          hienthitinh(tinh);
      }

 

    
 if ((unsigned long) (millis() - time1) > 80)
    {
        pixels.setPixelColor(tinh, pixels.Color(0,0,0));
        pixels.show();
        tinh -=1;  
        pixels.setPixelColor(tinh, pixels.Color( led_con[mode][0][3], led_con[mode][1][3],led_con[mode][2][3]));
        time1 = millis();
    }

    }
    
}
