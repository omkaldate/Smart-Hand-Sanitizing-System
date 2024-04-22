#include <reg51.h>
#define lcd P3

sbit ir = P1^0;
sbit led = P1^3;
sbit fog = P1^2;
sbit buz = P1^7;
sbit m1 = P1^4;
sbit m2 = P1^5;

sbit rs = P2^5; // Register select
sbit rw = P2^6; // Read/Write
sbit en = P2^7; // Enable

void lcd_init();
void cmd(unsigned char);
void dat(unsigned char);
void delay(unsigned int);
void lcd_string(char *s);

void main() {
	  led = 1;
    
    lcd_init();
    lcd_string("Welcome To fogmaker");
    delay(50);
    lcd_init();
    lcd_string("Ready to Sanitize");
    cmd(0xc0);
    lcd_string("Hands");
    
   while(1){
        if(ir == 1){          
            buz = 1;
            fog = 1;
					 lcd_init();
            lcd_string("Sanitizing Hands");
            cmd(0xc0);
					   delay(10);
            lcd_string("keep hands In");
            delay(500);
					
            fog = 0;
            buz = 0;
            m1 =1;
					  m2=0;
            delay(500);
					
					  m1 =0;
					  m2=0;
					
            
            lcd_init();
            lcd_string("Germs Killed ");
            cmd(0xc0);
					   delay(10);
            lcd_string("Remove Hands ...!");
            delay(500);
					
					lcd_init();
            lcd_string("Please Wait");
            cmd(0xc0);
					   delay(10);
            lcd_string("System Get Ready");
						delay(500);
        } 
			else{
				fog = 0;
					buz = 0;
					m1 = 0;
					m2 = 0;		
				
				lcd_init();
				lcd_string("Ready to Sanitize");
				cmd(0xc0);
				lcd_string("Hands");
				delay(100);
				}
    }
}

void lcd_init() {
    cmd(0x38);
    cmd(0x0e);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}

void cmd(unsigned char a) {
    lcd = a;
    rs = 0;
    rw = 0;
    en = 1;
    delay(1); // Changed delay to 1 ms for command execution
    en = 0;
}

void dat(unsigned char b) {
    lcd = b;
    rs = 1;
    rw = 0;
    en = 1;
    delay(1); // Changed delay to 1 ms for data execution
    en = 0;
}

void lcd_string(char *s) {
    while(*s) {
       dat(*s++);
     }
}

void delay(unsigned int time) {       
    unsigned int i,j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 1275; j++);
}



















