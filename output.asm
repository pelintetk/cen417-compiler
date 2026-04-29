section .data
fmt db "%d", 10, 0

section .text
global main

main:
    push rbp
    mov rbp, rsp
    ; x: integer = 42
    mov rax, 42
    mov [rbp-8], rax
    ; if (x == 42)
    mov rax, [rbp-8]
    cmp rax, 42
    jne else_label
    ; if blogu
    mov rax, 1
    jmp end_label
else_label:
    ; else blogu
    mov rax, 0
end_label:
    ; for dongusu
for_start:
    mov rax, [rbp-8]
    cmp rax, 0
    jle for_end
    sub rax, 1
    mov [rbp-8], rax
    jmp for_start
for_end:
    ; print x
    mov rdi, fmt
    mov rsi, [rbp-8]
    xor rax, rax
    call printf
    ; return 0
    mov rax, 0
    pop rbp
    ret
