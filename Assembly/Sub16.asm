;Subtraction 16

data segment
    a dw 1234h
    b dw 2134h 
    c dw ?
    
    data ends
code segment
    assume cs:code, ds:data
    start:
    mov ds, ax
    mov ax,a
    mov bx,b 
    sub ax,bx
    mov c, ax
    int 21h
    
 
code ends
end start