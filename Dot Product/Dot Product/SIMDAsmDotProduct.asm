;Barion, Ryan Onil Cruz, Section: S-11

section .text
bits 64
default rel
global SIMDDotProduct

SIMDDotProduct
	; rdx contains the address of a
	; r8 contains the address of b
	; rcx contains the ARRAY_SIZE

	vmovdqu ymm0, [r8];
	
	ret
