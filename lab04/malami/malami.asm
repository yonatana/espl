section .text
	global malami
malami:
	push	ebp			;input
	mov	ebp, esp
	sub	esp, 4   		;give memory for local mishtane
	mov	DWORD [ebp-4], 0 	;edb-4 is a mishtane localy 
	jmp	.L2			;label fro row 22
.L3:
	mov	eax, DWORD [ebp-4] 	;put whatever ebp-4 to eax
	mov ebx, eax			;moving
	sal eax, 3			;sal-shift aritmetic left, really just double 2^3
	sal ebx, 1			;double 2
	add eax, ebx			;add ebx to eax	totaly times10
	mov	ebx, DWORD [ebp+8]	; mov what we got to ebx
	movzx	ebx, BYTE [ebx]		;mov with zero extention-move one bytes from a word
	movsx	ebx, bl			;some optimization, dont worry
	add	eax, ebx		;add ebx to eax to eax
	sub	eax, 48			;sub eax by 48
	mov	DWORD [ebp-4], eax	;mov eax to edp-4
	add	DWORD [ebp+8], 1	;add 1 to edp+8 (first parameter)
.L2:
	mov	eax, DWORD [ebp+8]	;move edp+8 to eax
	movzx	eax, BYTE [eax]		;move first byte from eax to eax and the rest foes to 
	test	al, al			;
	jne	.L3			;if there a diffrent we jump to L3
	mov	eax, DWORD [ebp-4]	
	mov esp, ebp	;return-1
	pop ebp		;return0
	ret		;return

  ;cmp to sub
  ;test binary- to flag but dont save the result- is the result is 0 or non 0
  ;test al,al == cmp al,0 but test is faster
  ;2&8==0
  ;2&2==2
  ;3&1==1
  ;esp stack pointer to the head of the stack