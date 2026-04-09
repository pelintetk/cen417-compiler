section .text
global main

main:
    push rbp
    mov rbp, rsp
    ; x: integer = 42
    mov rax, 42
    mov [rbp-8], rax
    ; return x
    mov rax, [rbp-8]
    pop rbp
    ret
