;Division

data segment
    rem dw 0
    quo dw 0
    data ends
code segment
    assume cs:code, ds:data
    start:
    mov ax, data
    mov ds, ax
    mov ax,102 
    mov dx, 0
    mov bx , 30
    div bx
    mov quo, ax
    mov rem, dx
code ends
end start