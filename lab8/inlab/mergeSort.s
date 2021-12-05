; University of Virginia
; CS 2150 In-Lab 8
; Spring 2018
; mergeSort.s	
; Allison Fowle 11.2.2021 

	global mergeSort
	global merge

	section .text

; parameter passing rdi, rsi, rdx, rcx, r8, r9
; Parameter 1 is a pointer to the int array  rdi (int a[])
; Parameter 2 is the left index in the array  rsi (start)
; Parameter 3 is the right index in the array rdx (end)
; Return type is void 
mergeSort:
	
	cmp  rsi, rdx 		; is start < end?
	jge  done 			; if yes, jmp if greater than/equal -> done

	; int mid = (start + end) / 2
	push rsi 			; push start onto stack
	push rdx 			; push end onto stack
	add rdx, rsi		; (start + end)
	mov r10, rdx 		; move start + end value into mid
	shr  r10, 1 		; shift mid by 1, this divides by 2
 	push r10 			; save mid

 	; merge_sort (A, start, mid)
 	mov rdx, r10 		; move mid to rdx register
 	call mergeSort 		; recursive
 	pop r10 			; pop mid off stack
 	pop rdx 			; pop end off stack
 	pop rsi 			; pop start off stack

 	; merge_sort(A, mid+1, end)
 	push rdx 			; push end onto stack
 	push rsi 			; push start onto stack
 	push r10 			; push mid onto stack
 	inc r10 			; (mid + 1)
 	mov rsi, r10 		; move mid value into start value
 	call mergeSort 		; recursive
 	pop r10 			; pop mid off stack
 	pop rsi 			; pop start off stack
 	pop rdx 			; pop end off stack

 	; merge(A, start, mid, end)
 	push r10 			; push mid onto stack
 	push r11 			; extra register that merge routine below uses
 	push rdi 			; int a[]
 	push rsi 			; push start onto stack
 	push rdx 			; push end onto stack
 	push rcx 			; this is the register for the 4th parameter of merge()
 	mov rcx, rdx 		; move end to rcx 4th param
 	mov rdx, r10 		; move mid to 3rd param register
 	call merge 			; recursive
 	pop rcx 			; pop new end value off stack
 	pop rdx 			; pop mid off stack
 	pop rsi 			; pop start off stack
 	pop rdi 			; pop int a[] off stack
 	pop r11 			; xtra
 	pop r10 			; register mid was in

done:
 	ret

	
; Parameter 1 is a pointer to the int array 
; Parameter 2 is the left index in the array
; Parameter 3 is the middle index in the array 
; Parameter 4 is the right index in the array
; Return type is void 
merge:
	; Save callee-save registers
	; Store local variables 
	push rbx			; int i
	push r12			; int j
	push r13			; int k
	push r14			; int n1
	push r15			; int n2
	
	mov r14, rdx			; n1 = mid - left + 1
	sub r14, rsi
	inc r14

	mov r15, rcx			; n2 = right - mid 
	sub r15, rdx

	lea r11, [r14+r15]		; r11 = rsp offset = 4(n1 + n2)
	lea r11, [4*r11]		
	sub rsp, r11			; allocate space for temp arrays

	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	
; Copy elements of arr[] into L[]	
copyLloop:
	cmp rbx, r14			; is i >= n1?
	jge copyRloop
					; L[i] = arr[left + i]
	lea r10, [rsi+rbx]		
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[left + i]
	mov DWORD [rsp+4*rbx], r10d	; L[i] = r10
	inc rbx				; i++
	jmp copyLloop

; Copy elements of arr[] into R[]
copyRloop:
	cmp r12, r15			; is j >= n2?
	jge endcopyR
 					; R[j] = arr[mid + 1 + j]
	lea r10, [rdx+r12+1]	
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[mid + 1 + j]
	lea rax, [r12+r14]		
	mov DWORD [rsp+4*rax], r10d	; R[j] = r10
	inc r12				; j++
	jmp copyRloop

endcopyR:	
	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	mov r13, rsi			; k = left

; Merge L[] and R[] into arr[]
mergeLoop:
	cmp rbx, r14			; is i >= n1 or j >= n2?
	jge loopL
	cmp r12, r15
	jge loopL
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	; r10d = R[j]
	cmp DWORD [rsp+4*rbx], r10d	; is L[i] <= R[j]?
	jle if
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]
	inc r12				; j++
	jmp endif 
if:
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i] 
	inc rbx				; i++
endif:	
	inc r13				; k++	
	jmp mergeLoop
	
; Copy elements of L[] into arr[]
loopL:				
	cmp rbx, r14			; is i >= n1?
	jge loopR
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i]
	inc rbx				; i++
	inc r13				; k++
	jmp loopL

; Copy elements of R[] into arr[]
loopR:	
	cmp r12, r15			; is j >= n2?
	jge endR
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]

	inc r12				; j++
	inc r13				; k++
	jmp loopR
	
endR:
	; deallocate temp arrays
	; restore callee-save registers
	add rsp, r11	
	pop r15			
	pop r14
	pop r13
	pop r12
	pop rbx
	ret