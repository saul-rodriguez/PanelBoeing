#ifndef HARDWARE_CONF_H
#define HARDWARE_CONF_H

//Raspberry pin definitions (GPIO number)
#define MCP23017_1_INTA 17
#define MCP23017_1_INTB 18
#define MCP23017_2_INTA 27
#define MCP23017_2_INTB 22

/*****************************************
 * Mcp23017 extender Hardware definitions
 *****************************************/

//I2C Addresses
#define EXT1 0x20
#define EXT2 0x21

#define TRISA1 0xFF
#define TRISB1 0xFF

#define A_PULLUP1 0xFF
#define B_PULLUP1 0xFF

#define TRISA2 0x00
#define TRISB2 0xFF

#define A_PULLUP2 0xFF
#define B_PULLUP2 0xFF

//Mcp23017 Pin interruption configuration
#define INTA_PINS1 0xFF
#define INTB_PINS1 0xFF

#define INTA_PINS2 0x00
#define INTB_PINS2 0xFF

//Some Macro definitions
//#define LED_B0_OFF myext.writePin(PORTB,0,false)
//#define LED_B0_ON myext.writePin(PORTB,0,true)

//#define LED_B1_OFF myext.writePin(PORTB,1,false)
//#define LED_B1_ON myext.writePin(PORTB,1,true)

//#define READ_GPA5 myext.readPin(PORTA,5)

/***********************
 * Display definitions *
 ***********************/

//I2C Addresses
#define DISP1 0x70
#define DISP2 0x71
#define DISP3 0x72
#define DISP4 0x73

#define BRIGHTNESS 5

/***********************
 * Encoder definitions *
 ***********************/

// Encoder mask address in port A ext1

#define ENCODER1 0b00000011
#define ENCODER2 0b00001100
#define ENCODER3 0b00110000
#define ENCODER4 0b11000000

/**********************
 * Push button/Switch *
 **********************/

// button mast address in port B ext1

#define BUT1 0b00000001
#define BUT2 0b00000010
#define BUT3 0b00000100
#define BUT4 0b00001000
#define BUT5 0b00010000
#define BUT6 0b00100000
#define BUT7 0b01000000
#define BUT8 0b10000000

/*****************
 * Buttons' LEDs *
 *****************/

#define LED_BUT1_ON  ext2.writePin(PORTA,0,1)
#define LED_BUT1_OFF ext2.writePin(PORTA,0,0)
#define LED_BUT2_ON  ext2.writePin(PORTA,1,1)
#define LED_BUT2_OFF ext2.writePin(PORTA,1,0)
#define LED_BUT3_ON  ext2.writePin(PORTA,2,1)
#define LED_BUT3_OFF ext2.writePin(PORTA,2,0)
#define LED_BUT4_ON  ext2.writePin(PORTA,3,1)
#define LED_BUT4_OFF ext2.writePin(PORTA,3,0)
#define LED_BUT5_ON  ext2.writePin(PORTA,4,1)
#define LED_BUT5_OFF ext2.writePin(PORTA,4,0)
#define LED_BUT6_ON  ext2.writePin(PORTA,5,1)
#define LED_BUT6_OFF ext2.writePin(PORTA,5,0)
#define LED_BUT7_ON  ext2.writePin(PORTA,6,1)
#define LED_BUT7_OFF ext2.writePin(PORTA,6,0)
#define LED_BUT8_ON  ext2.writePin(PORTA,7,1)
#define LED_BUT8_OFF ext2.writePin(PORTA,7,0)


#endif // HARDWARE_CONF_H
