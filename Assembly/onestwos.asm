;Ones Twos complement

data segment
    num dw 16
    one dw ?
    two dw ?
    data ends

code segment
    assume cs:code , ds: data
    start:
    mov ax,data
    mov ds,ax
    
    mov ax, num
    not ax
    
    mov one , ax
    inc ax
    
    mov two,ax
    code ends
end start