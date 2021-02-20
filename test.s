global _test

section .data
		test_string		db "segf"
		working			db "working"
section .text

_test:
		test			edi, edi
		js				fail
		mov				rax, working
		ret
fail:
		mov				rax, 0
		ret