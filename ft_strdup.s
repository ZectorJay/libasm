global _ft_strdup
extern	___error
extern	_ft_strlen
extern	_malloc

section .text

_ft_strdup:
		cmp		rdi, 0					;	check if there is no rdi
		je		fail					;	no rdi? return -1
		mov		rdi, rdi				;	push rdi to ft_strlen
		call	_ft_strlen
		mov		rbx, rax				;	put result of ft_strlen(rdi) to rbx
		push	rdi						;	push rdi to stack
		mov		rdi, rbx				;	malloc ft_strlen(rdi) byte for new string	
		call	_malloc					;	rax = malloc(ft_strlen(rdi))
		jc		error					;	if error during allocation
		pop		rdi						;	return rdi value back
		mov		rcx, -1					;	counter rcx = -1
		jmp		while

while:
		inc		rcx						;	rcx++
		mov		dl,	byte [rdi + rcx]	;	copy rdi[rcx] to dl
		mov		byte [rax + rcx], dl	;	copy dl to new string rax[rcx]
		cmp		rcx, rbx				;	while rcx < ft_strlen(rdi)
		je		finish					;	finish if rcx = ft_strlen(rdi)
		jmp		while					;	else loop again

finish:
		ret

fail:
		mov		rax, 0
		ret

error:
		push	rax
		call	___error
		pop		qword [rax]
		mov		rax, 0
		ret