;Multiplication 8

data segment
    a db 09h
    b db 02h 
    c db ?
    
    data ends
code segment
    assume cs:code, ds:data
    start:
    mov ax, data
    mov ds,ax
    mov al,a
    mov bl,b 
    mul b
  
    mov b, al
    int 21h
code ends
end start