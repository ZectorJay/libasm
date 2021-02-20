global _test

section .data
		test_string		db "test string"

section .text

_test:
		mov				rax, test_string
		ret