;Barion, Ryan Onil Cruz, Section: S-11

section .text
bits 64
default rel
global asmDotProduct


asmDotProduct:
	; rdx contains the address of a
	; r8 contains the address of b
	; rcx contains the ARRAY_SIZE

	
	mov rax,0

	L1:
		mov rbx, [rdx]
		imul rbx, [r8]
		add rax, rbx

		add rdx,4
		add r8, 4

		loop L1

	
	ret