;Subtractioni 8

data segment
    a db 10h
    b db 01h 
    c db ?
    
    data ends
code segment
    assume cs:code, ds:data
    start:
    mov ax, data
    mov ds, ax
    mov al,a
    mov bl,b 
    sub al,bl
 
code ends
end start