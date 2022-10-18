;Division

data segment
    rem db 0
    quo db 0
    data ends
code segment
    assume cs:code, ds:data
    start:
    mov ax, data
    mov ds, ax
    mov ax, 28
    mov bl, 5
    div bl
    mov rem, ah
    mov quo, al
code ends
end start