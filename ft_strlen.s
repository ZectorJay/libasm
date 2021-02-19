global _ft_strlen

section .text

_ft_strlen: 
		mov	rax, -1					; counter = -1
while:
		inc rax						; counter++
		mov cl, byte [rdi + rax]	; shifting string (pointer) on next byte. cl = 8 bit (1 byte), thats 1 symbol
		cmp cl, 0					; comparing if there is nothing on that byte
		jne while					; if not equal to 0, we are checking next byte
		ret							; return rax