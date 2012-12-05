section	.text
    global main			;must be declared for linker (ld)

;extern read
;extern printBarcode
extern main2

main:					;tell linker entry point
    push ebp			;input
    mov	 ebp, esp
    push DWORD [ebp+12]		;push argc
    push DWORD [ebp+8]		;push argv
    call main2
    ;read(argc, argv)

    ;printBarcode();


    ;return
    mov esp,ebp
    pop ebp
    ret
section	.data
