/*

    Futaba M202LD08A VFD-Display

    24  22  20  18  16  14   12  10   8   6    4    2
    DTR RTS TXD GND GND +12V GND ACK GND BUSY GND /STROBE

    DSR CTS RXD GND D0   D1  D2  D3  D4   D5   D6   D7 
    23  21  19  17  15  13   11   9   7    5    4    1


    Power: Pin 14 for 12V+ and couple all GND
    TXD (and GND) to send from Txd 

    Use a MAX232 to drive proper RS232-Level
*/


const uint8_t line_max_chars = 20;

const uint8_t reset_display      = 0x01;
const uint8_t clear_display      = 0x02;
const uint8_t set_diagnostic_on  = 0x04;
const uint8_t set_display_on     = 0x05;
const uint8_t set_low_power_on   = 0x06;
const uint8_t enable_cursor      = 0x07;
const uint8_t disable_cursor     = 0x08;
const uint8_t screen_save_blank  = 0x09;
const uint8_t screen_save_walk   = 0x0a;
const uint8_t screen_save_on     = 0x0b;
const uint8_t screen_save_off    = 0x0c;
const uint8_t enable_char_blink  = 0x0d;
const uint8_t disable_char_blink = 0x0e;
const uint8_t move_cursor_left   = 0x0f;
const uint8_t move_cursor_right  = 0x10;
const uint8_t move_cursor_up     = 0x11;
const uint8_t move_cursor_down   = 0x12;
const uint8_t cursor_position    = 0x13;
