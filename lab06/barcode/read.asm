section	.text
    global read			;must be declared for linker (ld)

read:					;tell linker entry point
    push ebp			;input
    mov	 ebp, esp
    


    call main2
    ;read(argc, argv)

    ;printBarcode();


    ;return
    mov esp,ebp
    pop ebp
    ret
section	.data
