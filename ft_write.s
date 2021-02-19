global _ft_write

section .text

_ft_write:
		test	edi, edi
		js		error
		je		error
		mov		rax, 0x2000004		;	syscall to write
		syscall
		ret
error:
		mov		rax, -1
		ret