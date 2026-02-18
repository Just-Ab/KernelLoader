vgaClearPM:
    mov eax,25
    mov ebx,80
    mul ebx
    mov ecx,eax
    mov eax,VIDEO_MEMORY
vgaClearPM_loop:
    mov WORD [eax],' '
    mov WORD [eax+1],VIDEO_MODE
    add eax,2
    loop vgaClearPM_loop
    ret