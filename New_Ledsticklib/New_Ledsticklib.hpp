#include "hwlib.hpp"

#ifndef NEW_LEDSTICKLIB_HPP
#define NEW_LEDSTICKLIB_HPP

class New_ledsticklib: public hwlib::window{

protected:
hwlib::color GRB;
hwlib::xy position;
int* portarray;
int* pinarray;
int stick;

public:
New_ledsticklib(hwlib::xy total_pixels, int* portarray, int* pinarray):
window(total_pixels),
portarray(portarray),
pinarray(pinarray)
{}

auto confport(int port);

uint32_t confmask(int pin ){
return (0x1u << pin);
}

static void  wait_busy( int32_t n ) __attribute__((noinline));

int checkbit(uint8_t value, int number);

void sendBit(bool bit);

void sendByte(uint8_t value);

void showcolor();

void write_implementation( hwlib::xy pos, hwlib::color c ) override;

void flush() override;

void clear();

};

#endif