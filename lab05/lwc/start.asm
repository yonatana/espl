section .text
	
global _start
global read
global write
global open
global close
global strlen

extern main
_start:
	lea ecx, [esp+4]   ;points on argv
	push ecx	   ;insert argv to the stack
	push DWORD [esp+4] ;insert argc to the stack
	call	main	   ;do main
        mov     ebx,eax    ;
	mov	eax,1	   ;arrange the return
	int 0x80

read:
	mov eax,3 ;read s.call
	mov ebx,[esp+4] ;first param
	mov ecx,[esp+8] ;second param
	mov edx,[esp+12];thierd param
	int 0x80 	;interupt and do eax->3=read()
	ret

write:
	mov eax,4 ;write s.call
	mov ebx,[esp+4] ;first param
	mov ecx,[esp+8] ;second param
	mov edx,[esp+12];thierd param
	int 0x80 	;interupt and do eax->3=read()
	ret
open:
	mov eax,5 ;open s.call
	mov ebx,[esp+4] ;first param
	mov ecx,[esp+8] ;second param
	mov edx,[esp+12];thierd param
	int 0x80 	;interupt and do eax->3=read()
	ret
close:
	mov eax,6 ;close s.call
	mov ebx,[esp+4] ;first param
	int 0x80 	;interupt and do eax->3=read()
	ret
strlen:
	;mov ecx,0 
	ret
