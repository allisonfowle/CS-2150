; binarySearch.s
; Allison Fowle
; 11/16/2021

global binarySearch

section .text

; parameter passing options: rdi, rsi, rdx, rcx, r8, r8

; param 1 rdi = pointer to int array
; param 2 rsi = integer representing beginning of array (low)
; param 3 rdx = integer representing end of array (high)
; param 4 rcx = integer representing the target element to find in the array (x)
; r8 is mid
; rax is return register, obviously


binarySearch:

while:
	; while (low <= high)
	cmp rsi, rdx 			; is low <= high?
	jg didntfind			; jump if low is greater to end binarySearch, target not found
							; else if low < high, continue parsing through array
	; int mid = (low + high) /2
	mov r8, rsi 			; move low into mid
	add r8, rdx				; add high to mid
	shr r8, 1 				; divide by 2

if:
	; if (a[mid] < key)
	cmp ecx, [rdi + 4*r8] 	; is x > mid?
	jl elseif 				; if mid > key, do not go through if, go to else if. else continue
	je else 				; if they are equal, you found the value
	mov rsi, r8 			; move mid into low
	inc rsi 				; ++
	call binarySearch 		; recursive call
	

elseif:
	; else if(a[mid] > key)
	mov rdx, r8 			; move mid into high
	dec rdx 				; --
	call binarySearch 		; recursive call
	
else:
	mov rax, r8 			; move mid into return register
	ret 					; if mid is not > or < key, then you found it

didntfind:
	mov rax, -1 			; move -1 into return register
	ret 					; if target is not found return -1