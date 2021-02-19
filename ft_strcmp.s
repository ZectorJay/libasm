global _ft_strcmp

section .text

_ft_strcmp:
		mov		rax, -1					;	rax = -1
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