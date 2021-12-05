; threexplusone.s
; Allison Fowle
; 11/11/2021

global threexplusone

section .text

; parameter passing options: rdi, rsi, rdx, rcx, r8, r9
; param 1 edi = x, positive integer to pass into subroutine
; r8 is counter (i)
; rax is return register, obviously
; using "e" register because we are dealing with integers which are 32-bits

; Optimization: using test which is ANDing x and 1, lea for ease of arithmetic


threexplusone:
	; prologue
	xor rax, rax 		; zero out return register

loop:
	cmp edi, 1 			; x == 1? base case
	je done				; exit loop, you've done the conjecture!
	test edi, 1 		; edi AND 1, if last bit == 0, then even, else odd
	je ifeven 			; edi is even
	; continue otherwise, which is when it's odd

	lea edi, [edi*2 + edi + 1] ; since you can only multiply registers by 2, 4, or 8 lea allows you to multiply
	; edi by 2 and then add it again, plus 1 which is (3x + 1) in the collatz conjecture

	call threexplusone 	; recursive call
	inc rax 			; step++
	ret

ifeven:
	shr edi, 1 			; x / 2
	call threexplusone 	; recursive call
	inc rax 			; step++
	ret

done:
	mov rax, 0 			; return rax to normal
	ret