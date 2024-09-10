#include <cstdint>
#include <array>
#include "Conditions.hpp"

#pragma once

class Registers {
private:	
	static uint16_t regs[COUNT];

public:
	enum {
		R0 = 0b000,
		R1 = 0b001,
		R2 = 0b010,
		R3 = 0b011,
		R4 = 0b100,
		R5 = 0b101,
		R6 = 0b110,
		R7 = 0b111,
		PC,
		COND
	};

	static constexpr size_t COUNT = 10;
	static constexpr uint16_t PC_START = 0x3000;

	static inline uint16_t& operator[](size_t index)
	{
		if (index > 9)
			return 0;
		return regs[index];
	}
};
