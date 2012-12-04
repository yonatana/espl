section .text
	global malami 			;its do atoi, turn string into int
malami:
	push	ebp				;we push the adress we came from to the stack to save it.
	mov	ebp, esp			;we get the return adress at esp and mov it to ebp.
	sub	esp, 4				;esp is the head of the stack, is decrement with 4 to move to a new part in the stack???
	mov	DWORD [ebp-4], 0	;takes 0 as a double word (8 bytes) into [ebp-4], its creating a local variable -> 'int "ebp-4" = 0' 
	jmp	.L2					;move to L2
	
.L3:
	mov	eax, DWORD [ebp-4] 	;input our local variable to eax for processing
	mov ebx, eax 			;replicat eax to ebx,  we are gonna double our number by 10
	sal eax, 3				;eax*2 -> eax 3 times, mean eax*8->eax
	sal ebx, 1				;ebx*2->ebx
	add eax, ebx			;eax+ebx->eax - over all 10*eax ->eax
	mov	ebx, DWORD [ebp+8] 	;moving our first function parameter to ebx
	movzx	ebx, BYTE [ebx]	;takes the first 'char' from ebx to ebx
	movsx	ebx, bl			;die hard 4
	add	eax, ebx			;sum whatever
	sub	eax, 48				;dec 48 to get the haskii to normal
	mov	DWORD [ebp-4], eax	;put the new eax to input
	add	DWORD [ebp+8], 1	;go to next char, it will move by 1 byte
.L2:
	mov	eax, DWORD [ebp+8]	;the "ebp+8" is the first function parameter, we insert it to eax 
	movzx	eax, BYTE [eax] ;we are taking the first byte in the word (taking the first char) of exa to eax, turn the rest of the word to ziros
	test	al, al			;test the string == cmp al,0?? should ask how it works...
	jne	.L3					;loop- jump if it not equal to L3
	mov	eax, DWORD [ebp-4]  ;what we accumilate to eax
	mov esp, ebp			;the return value to esp
	pop ebp					;pop ebp
	ret						;return erly ebp

	;a word is 1 byte, double word is 2 bytes. then om movzx we take the first (mostto the left) byte
	