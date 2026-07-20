#include "config.h"
#include "vfd.h"

vfd futuba_vfd(2,3);

void setup() {

               futuba_vfd.init();
               futuba_vfd.clear();                 
               futuba_vfd.start_hardware_scroll("Welcome !",6);  
                delay(4000);
               futuba_vfd.stop_hardware_scroll();
               futuba_vfd.set_line_1();
               futuba_vfd.println("This is line 1");
               futuba_vfd.animate('|', '/', '-', 19, 150, 5);              
                delay(1000);
               futuba_vfd.set_line_2();
               futuba_vfd.println("and this is line 2");

                delay(2000);
               futuba_vfd.clear();                 
               futuba_vfd.scroll("Hardscroll !",250); 
                delay(1000);
               futuba_vfd.set_cursor(7);                              
               futuba_vfd.println("Enjoy");
               futuba_vfd.set_cursor(23);                              
               futuba_vfd.println("your Display !");

for (int i= 0; i <= 8; i++) {  

               futuba_vfd.animate(0x07,0x04,0x09,17,250,0);                   
               futuba_vfd.animate(0x07,0x04,0x09,21,250,0);                   
               futuba_vfd.animate(0x07,0x04,0x09,5,250,0);                   
}

               futuba_vfd.send_command(screen_save_blank);  
}


void loop() {

}
