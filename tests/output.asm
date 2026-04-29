section .text
global main

main:
    push rbp
    mov rbp, rsp
    ; x: integer = 42
    mov rax, 42
    mov [rbp-8], rax
    ; return 0
    mov rax, 0
    pop rbp
    ret
