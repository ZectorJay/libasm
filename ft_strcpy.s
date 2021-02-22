global _ft_strcpy

section .text

_ft_strcpy:
		mov		rax, -1					; using rax as counter, set start value to -1
		cmp		rdi, 0					; if there is no rdi
		je		fail					; ret 0 if no rdi
		cmp		rsi, 0					; protect from no rsi
		jnz		while					; start cicle if rsi exist
		inc		rax						; if rsi dont exist we set rax to 0
		ret								; ret (0)
while:
		inc		rax						; rax++
		mov		cl, byte [rsi + rax]	; copy symbol from rsi[rax] to cl
		mov		byte [rdi + rax], cl	; copy symbol from cl to rdi[rax]
		cmp		cl, 0					; checking that cl still contain symbols (not 0)
		jne		while					; if cl is not 0, start cicle again
		mov		rax, rdi				; put dest to rax (return)
		ret
fail:
		mov		rax, 0
		ret