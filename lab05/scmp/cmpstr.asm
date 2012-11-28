section .text
  global cmpstr
cmpstr: 
  push ebp 	;push the adress we camwe from
  mov ebp,esp	;get the return adress
  sub esp, 8	;move the head of the stack
  mov DWORD [ebp-4], 0; int c
  mov DWORD [ebp-8],0;	inc ans

 .while:
  mov ebx, [ebp+8][c]; first param ***
  mov ecx, [ebp+12][c]; second param***

  cmp  ebx,ecx
  jne .out	;not equal
  cmp  ebx,0	;a[c]==0
  je .end	; a==b
  add [ebp-4],1	;c++
  jmp .while
  
  .out: ;they are not equal and ther cmp also hold whos bigger
  jg .first_bigger
  jl .second_beggier 

.first_bigger:
  mov 	[ebp-8],1;do we need this?
  mov 	eax,1
  jmp 	.end

.second_beggier:
  mov [ebp-8],2 ; do we need this?
  mov 	eax,2

.end
  mov esp.ebp
  pop ebp
  ret

