#pragma once

class Operations {	
private:
	
public:
	enum {
        BR   = 0b0000,
        ADD  = 0b0001,
        LD   = 0b0010,
        ST   = 0b0011,
        JSR  = 0b0100,
        AND  = 0b0101,
        LDR  = 0b0110,
        STR  = 0b0111,
        RTI  = 0b1000,
        NOT  = 0b1001,
        LDI  = 0b1010,
        STI  = 0b1011,
        JMP  = 0b1100,
        RES  = 0b1101,
        LEA  = 0b1110,
        TRAP = 0b1111
    };

	static inline void operator[](uint16_t instr)
	{
		uint16_t opcode = (instr >> 12) & 0b1111; 
		handler<opcode>(instr);
	}
};
