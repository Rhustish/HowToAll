;Multiplication 16

data segment
    a dw 2000h
    b dw 4000h 
    c dw ?
    d dw ?
    
    data ends
code segment
    assume cs:code, ds:data
    start:
    mov ax, data
    mov ds, ax
    mov ax,a 
    mov bx,b
    mul bx
  
    mov c, ax
    mov d, dx
code ends
end start