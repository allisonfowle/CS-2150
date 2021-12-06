; Allison Fowle
; CS 2150
; mathlib.s
; 10/31/2021

; declare these routines global to be able to be called in mathfun.cpp
global product
global power

; Parameter 1 (in rdi) is the starting address of a sequence of 64-bit longs
; Parameter 2 (in rsi) is the number of integers in the sequence
; Return value is a long that is the sum of the integers in the sequence

section .text

; product subroutine: compute the product of two integers
; only using addition, and assuming positive integers
; non recursive

product:
	; prologue: 

	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out r10
start:	
	cmp	r10, rsi	 ; is rsi (y/param 2) in r10?
	je	done		 ; if so, we are done with the loop
	add	rax, rdi 	 ; else, add x to return register
	inc	r10		 	 ; increment our counter i
	jmp	start		 ; we are done with this loop iteration
done:	
	; epilogue:
	ret



; power subroutine: compute the power of two integers
; first parameter is base, second is exponent, both integers
; only use multiplication subroutine above 
; recursive

power:
	; epilogue
	xor	rax, rax	 ; zero out the return register
	mov rax, 1 		 ; base case, power of 0 is 1. first exponent = 1
	cmp rsi, 0 		 ; compare x to 0
	je done1 		 ; if so, exit
	jmp start1 		 ; else start loop
start1:	
	dec rsi 		 ; y--
	call power 	     ; call power
	mov rsi, rax 	 ; move return register to y
	call product 	 ; call product routine above
	ret
done1:	
	ret

