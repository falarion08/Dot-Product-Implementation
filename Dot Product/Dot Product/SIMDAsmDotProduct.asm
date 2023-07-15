;Barion, Ryan Onil Cruz, Section: S-11

section .text
bits 64
default rel
global SIMDDotProduct

SIMDDotProduct:
	; rdx contains the address of a
	; r8 contains the address of b
	; rcx contains the ARRAY_SIZE


	shr rcx, 3 ; There are 8 cells in a ymm register which consists of 4 bytes each
	mov rax, 0 

	L1:
		vmovdqu ymm0, [rdx]
		vmovdqu ymm1, [r8] 

		vpmulld ymm2, ymm1, ymm0 ; Perform Vertical Multiplication
	
		vphaddd ymm3, ymm2,ymm2 ; Perform horizontal addition stored in y register and store in register ymm3

		vextractf128 xmm4,ymm3,0 ; Extract lower contents of the vector array
		vpextrd rbx, xmm4, 0 
		add rax, rbx
		vpextrd rbx, xmm4, 1
		add rax, rbx

		vextractf128 xmm4,ymm3,1 ;Extract upper contents of the vector array
		vpextrd rbx, xmm4, 0
		add rax, rbx
		vpextrd rbx, xmm4, 1
		add rax, rbx
		

		add rdx, 32 ; Increment by 32 to get the next 8 integer variables
		add r8, 32 ; Increment by 32 to get the next 8 integer variables

		loop L1

	ret
