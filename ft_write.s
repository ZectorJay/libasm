global _ft_write
extern	___error

section .text

_ft_write:							;	rdi = fd, rsi = const void *str, rdx = len
		mov		rbx, rdx			;	save rdx to rbx, rdx be rewrited during syscall 
		mov		rax, 0x2000004		;	syscall to write
		syscall
		jc		error				; in case of error syscall will set -1 to rdx (or 0 in case of success)
		ret
error:
		push	rax					;	save rax value on stack
		call	___error			;	in case of error its return error_number
		pop		qword [rax]			;	pull 64-bit rax from stack
		mov		rax, -1				;	set value to -1
		ret