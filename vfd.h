#pragma once
#include <SoftwareSerial.h>
class vfd {

       

public:

        vfd(uint8_t Rx,uint8_t Tx);

        void init(); 
        void send_command(uint8_t cmd);
        void set_line_1();
        void set_line_2();
        void set_cursor(uint8_t cell);
        void homing();                
        void println(const char* text);
        void clear();
        void scroll(const char* text, uint16_t delay_ms);
        void start_hardware_scroll(const char* text, uint8_t cell);
        void stop_hardware_scroll();
        void animate(uint8_t char1, uint8_t char2, uint8_t char3, uint8_t cell,uint16_t tile_speed,uint8_t loops );
 
private:

        SoftwareSerial vfdSerial; 




};
