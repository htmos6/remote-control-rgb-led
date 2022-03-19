#include <IRremote.h>
#define g 5
#define b 4
#define r 3
int const IR_REC_PIN = 11; 
IRrecv irrecv(IR_REC_PIN);       // create instance of 'irrecv'
decode_results irresults;        // create instance of 'decode_results'

void setup(){
  Serial.begin(9600);   // Initialize serial port
  irrecv.enableIRIn(); // Start the IR_REC_PIN
  pinMode(g, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop(){
  if (irrecv.decode(&irresults)) // We have received an IR command
  { 
    Serial.print(irresults.value, HEX);  // Printout raw value
    Serial.print(" : ");
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}

void translateIR(){
  switch(irresults.value){
    case 0xFF18E7: 
      Serial.println(" FORWARD"); 
      break;
    case 0xFF10EF: 
      Serial.println(" LEFT");    
      break;
    case 0xFF38C7: 
      Serial.println(" -OK-");    
      break;
    case 0xFF5AA5: 
      Serial.println(" RIGHT");   
      break;
    case 0xFF4AB5: 
      Serial.println(" REVERSE"); 
      break;
    case 0xFFA25D: 
      Serial.println(" 1");  
      digitalWrite(g, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(b, LOW);
      break;
    case 0xFF629D: 
      Serial.println(" 2");    
      digitalWrite(g, LOW);
      digitalWrite(r, HIGH);
      digitalWrite(b, LOW);
      break;
    case 0xFFE21D: 
      Serial.println(" 3");   
      digitalWrite(g, LOW);
      digitalWrite(r, LOW);
      digitalWrite(b, HIGH);
      break;
    case 0xFF22DD: 
      Serial.println(" 4"); 
      digitalWrite(g, HIGH);
      digitalWrite(r, HIGH);  
      digitalWrite(b, LOW); 
      break;
    case 0xFF02FD: 
      Serial.println(" 5");   
      digitalWrite(g, LOW);
      digitalWrite(r, HIGH); 
      digitalWrite(b, HIGH);
      break;
    case 0xFFC23D: 
      Serial.println(" 6"); 
      digitalWrite(g, HIGH);
      digitalWrite(r, LOW);  
      digitalWrite(b, HIGH); 
      break;
    case 0xFFE01F: 
      Serial.println(" 7"); 
      digitalWrite(g, HIGH);
      digitalWrite(r, HIGH);
      digitalWrite(b, HIGH);  
      break;
    case 0xFFA857: 
      Serial.println(" 8");   
      digitalWrite(g, LOW);
      digitalWrite(r, LOW);
      digitalWrite(b, LOW);     
      break;
    case 0xFF906F: 
      Serial.println(" 9");    
      break;
    case 0xFF6897: 
      Serial.println(" *");    
      break;
    case 0xFF9867: 
      Serial.println(" 0");    
      break;
    case 0xFFB04F: 
      Serial.println(" #");    
      break;
    case 0xFFFFFFFF: 
      Serial.println(" REPEAT");
      break;  
    default: 
      Serial.println(" Unidentified button");
    }
    delay(600); // Delay to help avoid accidental repeats
} 
