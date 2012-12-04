section .text
  global cmpstr
cmpstr: 
  push ebp 	;push the adress we camwe from
  mov ebp,esp	;get the return adress
  ;sub esp, 8	;move the head of the stack- get place for local veriables
  mov eax,0

 .while:
  mov	ebx, DWORD [ebp+8]; first param ***
  movzx	ebx, BYTE [ebx]
  mov	ecx, DWORD [ebp+12]; second param***
  movzx	ecx, BYTE [ecx]

  cmp  ebx,ecx
  jne .out	;not equal, go to out
  test  ebx,ebx	;a[c]==0 , equal
  je .end	; a==b	, end & equal
  add DWORD[ebp+8],1	;c++
  add DWORD[ebp+12],1;c++
  jmp .while
  
  .out: ;they are not equal and ther cmp also hold whos bigger
  jg .first_bigger
  jl .second_beggier 

.first_bigger:
  mov 	eax,1
  jmp 	.end

.second_beggier:
  mov 	eax,2

.end:
  mov esp,ebp
  pop ebp
  ret

