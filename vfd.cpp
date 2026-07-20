#include <SoftwareSerial.h>
#include <Arduino.h>
#include <stdint.h>
#include "config.h"
#include "vfd.h"


vfd::vfd(uint8_t Rx, uint8_t Tx) : vfdSerial(Rx, Tx) {
    
    vfdSerial.begin(9600);
}

void vfd::init() {

    send_command(reset_display);
    delay(3000); 

}


void vfd::send_command(uint8_t cmd){
  
   vfdSerial.write(0x1B);
   vfdSerial.write((byte)cmd);  
   
  }



void vfd::set_line_1(){

 
   vfdSerial.write(0x1B);
   vfdSerial.write(0x10);        // set cursor msb
   vfdSerial.write((byte)0x00);  
   vfdSerial.write(0x1B);
   vfdSerial.write(0x13);        // set cursor lsb 
   vfdSerial.write((byte)0x00);  
   delay(10);
}


void vfd::set_line_2(){
  
  vfdSerial.write(0x1B);
  vfdSerial.write(0x10);        // set cursor msb
  vfdSerial.write((byte)0x00);  
  vfdSerial.write(0x1B);
  vfdSerial.write(0x13);        // set cursor lsb 
  vfdSerial.write((byte)0x14);  
  delay(10);
}


void vfd::set_cursor(uint8_t cell){

   send_command(cursor_position);
   vfdSerial.write((byte)cell);  
   delay(10);
}

void vfd::homing(){

set_cursor(0x00);

}

void vfd::println(const char* text) {
       uint8_t count = 0;


    while (text[count] != '\0' && count < 20) {
        vfdSerial.write(text[count]);
        count++;
    }


    while (count < 20) {
        vfdSerial.write(' '); 
        count++;
    }
    
}

void vfd::clear() {
  vfdSerial.write(0x1B);
  vfdSerial.write(0x02);
  delay(10);
}



void vfd::scroll(const char* text, uint16_t delay_ms) {
    uint8_t text_len = strlen(text);
    

    for (int step = 0; step < line_max_chars + text_len; step++) {
        set_cursor(0);
        for(uint8_t i = 0; i < line_max_chars; i++) { 
            vfdSerial.write(' ');
        }
        

        int start_cell = (line_max_chars-1) - step; 
        for (uint8_t i = 0; i < text_len; i++) {
            int current_cell = start_cell + i;

            if (current_cell >= 0 && current_cell <= (line_max_chars-1)) {
                set_cursor(current_cell);
                vfdSerial.write(text[i]);
            }
        }
        
        delay(delay_ms); 
    }
}




void vfd::start_hardware_scroll(const char* text, uint8_t cell) {
    send_command(0x05); // Display On
    set_cursor(cell);
    vfd::println(text);
    send_command(screen_save_walk); 
    send_command(screen_save_on); 
}

void vfd::stop_hardware_scroll() {
    send_command(set_display_on); 
    clear();
}


void vfd::animate(uint8_t char1, uint8_t char2, uint8_t char3, uint8_t cell,uint16_t tile_speed,uint8_t loops ){


for (int i= 0; i <= loops; i++) {  
   set_cursor(cell);
   vfdSerial.write(char1);
    delay(tile_speed);
   set_cursor(cell);
   vfdSerial.write(char2);
    delay(tile_speed);
   set_cursor(cell);
   vfdSerial.write(char3);
    delay(tile_speed);
  }
   set_cursor(cell);
     vfdSerial.write(" ");
  }
