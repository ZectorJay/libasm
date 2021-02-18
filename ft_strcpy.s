global _ft_strcpy

section .text
	extern _ft_strlen

_ft_strcpy:
		cmp rdi, rsi
		jl lesser
		jmp bigger
bigger:
		mov rax, rdi
		jmp finish
lesser:
		mov rax, rsi
		jmp finish
finish:
		ret