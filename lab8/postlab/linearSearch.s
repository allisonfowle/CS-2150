; Allison Fowle
; CS 2150
; linearSearch.s
; 11/2/2021

global linearSearch

section .text

; C++ pseudocode
; int i (target value)
; for i less than size of array for(i=0; i<n; i++)
; 	if array index == i
;			return i
; 	else return -1

; parameter passing rdi, rsi, rdx, rcx, r8, r9
; param 1 rdi = pointer to int array
; param 2 rsi = integer representing size of array (n)
; param 3 rdx = integer representing target element to find (x)
; r8 is counter (i)
; ecx is location of element

linearSearch:
	; prologue
	mov r8, 0 				; counter = 0

loop:
	cmp r8, rsi 			; is counter == n?
	je option2				; jump to return i
							; else if i < n, continue parsing through array
	;mov rdi, rsi 			; move size of array into pointer

	mov ecx, DWORD[rdi+4*r8] 	; move base address + 4 (int) * counter = 32, location of element
	


	cmp edx, ecx 			; does x == the location of element
	je option1
	inc r8 					; i++
	jmp loop 				; continue with for loop

option1:
	mov rax, r8 			; move location of element in array to return register. 
	ret 					; return type is int, is the index into the array that the target value was found.

option2:
	mov rax, -1 			; move -1 into return register
	ret 					; if target is not found return -1
