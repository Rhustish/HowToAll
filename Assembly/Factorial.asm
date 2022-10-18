;Factorial

data segment
    N dw 8
    Res1 dw ?
    Res2 dw ?
data ends

code segment
    assume cs:code, ds:data
    start:
    mov ax, data
    mov ds, ax

    Mov Cx, N
    Mov Ax, 0001h
    Mov Dx, 0000h

    L1: Mul Cx
    Loop L1; run until Cx becomes Zero

    Mov Res1, Ax; Lower Order
    Mov Res2, Dx; Higher Order

code ends
end start