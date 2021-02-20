global _ft_strcmp

section .text

_ft_strcmp:
		mov		rax, -1					;	rax = -1
		cmp		rsi, 0					;	check if there is source string
		je		check_rdi				;	if no - check rdi too
		cmp		rdi, 0					;	check if there is dest string
		je		check_rsi				;	if no dest, check source string
while:
		inc		rax						;	rax++
		mov		cl, byte[rdi + rax]		;	cl = rdi[rax]
		mov		dl, byte[rsi + rax]		;	dl = rsi[rax]
		cmp		cl, dl					;	compare cl and dl
		je		check					;	cl = dl ?
		jmp		return

check:									;	check if its not last symbol in cl and return to while
		cmp		cl, 0
		jne		while					;	cl - not last symbol in cl? check next
		jmp		return

return:
		movzx	rax, cl					;	copy cl into rax (zeroing other bytes). rax = 64 bit, cl = 8 bit
		movzx	rbx, dl					;	copy dl into rbx (zeroing other bytes). rbx = 64 bit, dl = 8 bit
		sub		rax, rbx				;	write difference between rax and rbx (in rax)
		ret
check_rsi:								;	check rsi string if there was no rdi string
		cmp		rsi, 0
		je		no_both
		jmp		no_rdi
check_rdi:								;	check rdi string if there was not rdi string
		cmp		rdi, 0
		je		no_both
		jmp		no_rsi

no_rsi:									;	return -1 if there was no rsi
		mov		rax, -1
		ret
no_rdi:									;	return 1 if there was no rdi
		mov		rax, 1
		ret
no_both:								;	return 0 if no both strings
		xor		rax, rax
		ret