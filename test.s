global _test

section .data
		pizda	db "test string"

section .text

_test:
		mov		rax, pizda
		ret