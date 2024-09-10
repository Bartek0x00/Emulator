#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Registers.hpp"
#include "Conditions.hpp"
#include "Operations.hpp"

namespace Memory {
	constexpr size_t SIZE = UINT16_MAX;
};

uint16_t memory[Memory::SIZE];

constexpr inline uint16_t sign_extend(uint16_t reg, int len)
{
	// if the first digit is 1,
	// then the number is negative,
	// fill the upper bits with one's
	if ((x >> (len - 1)) & 1)
		x |= (0xFFFF << len);
	
	return x;
}

void update_flags(uint16_t reg)
{
	if (!Registers[reg])
		Registers[Registers::COND] = Conditions::ZRO;
	else if (Registers[reg] >> 15)
		Registers[Registers::COND] = Conditions::NEG;
	else
		Registers[Registers::COND] = Conditions::POS;
}

void add_handler(uint16_t instr)
{
	uint16_t r0 = (instr >> 9) & 0b0111;
	uint16_t r1 = (instr >> 6) & 0b0111;
	bool is_imm = (instr >> 5) & 0b0001;

	if (is_imm)
		regs[r0] = regs[r1] + sign_extend(instr & 0x00011111, 5);
	else
		regs[r0] = regs[r1] + regs[(instr & 0b0111)];
	
	update_flags(r0);
}

static inline void error(const char *err)
{
	fprintf(stderr, "%s\n", err);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		error("lc3 [image]");
	
	if (!read_image(argv[1]))
		error("failed to load image");

	while (1) {
		uint16_t instr = mem_read(regs[Registers::PC]++);
		Operations

	}
	
	return 0;
}
