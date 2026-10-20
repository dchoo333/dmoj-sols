; libc
section .data
    fmt_in  db "%lld %lld %lld", 0
    fmt_out db "%lld", 10, 0

section .bss
    a resq 1
    b resq 1
    m resq 1

section .text
    global main
    extern scanf, printf

mulmod:
    mul     rdi    
    div     rsi  
    mov     rax, rdx
    ret

main:
    sub     rsp, 8

    lea     rdi, [rel fmt_in]
    lea     rsi, [rel a]
    lea     rdx, [rel b]
    lea     rcx, [rel m]
    xor     eax, eax
    call    scanf

    mov     r12, [rel a]
    mov     r13, [rel b]
    mov     r14, [rel m]
    mov     r15, 1            

    xor     rdx, rdx
    mov     rax, r12
    div     r14
    mov     r12, rdx

.loop:
    test    r13, r13
    jz      .done

    test    r13, 1
    jz      .no_mul

    mov     rax, r15
    mov     rdi, r12
    mov     rsi, r14
    call    mulmod
    mov     r15, rax

.no_mul:

    mov     rax, r12
    mov     rdi, r12
    mov     rsi, r14
    call    mulmod
    mov     r12, rax

    shr     r13, 1
    jmp     .loop

.done:
    lea     rdi, [rel fmt_out]
    mov     rsi, r15
    xor     eax, eax
    call    printf

    xor     eax, eax
    add     rsp, 8
    ret