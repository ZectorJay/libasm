global _ft_read
extern	___error

section .text

_ft_read:							;	rdi = fd, rsi = const void *str, rdx = len
		mov		rbx, rdx			;	save rdx to rbx, rdx be rewrited during syscall 
		mov		rax, 0x2000003		;	syscall to write
		syscall
		jc		error				; in case of error syscall will set -1 to rdx (or 0 in case of success)
		ret
error:
		push	rax
		call	___error
		pop		qword [rax]
		mov		rax, -1
		ret