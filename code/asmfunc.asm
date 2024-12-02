section .text
global imgCvtGrayInttoFloat

imgCvtGrayInttoFloat:
    push rdi
    push rsi
    xor rsi, rsi
    mov rax, 255 ; Initialize 255 constant
    cvtsi2ss xmm1, rax
    
loop:
    cmp rsi, rcx ; Check loop termination condition
    jge done
    
    ;Main functionality
    movzx rax, byte [rdx + rsi]
    cvtsi2ss xmm0, rax
    divss xmm0, xmm1
    movss [r8 + rsi * 4], xmm0

    inc rsi ; Increment loop counter
    jmp loop

done:
    pop rsi
    pop rdi

    ret ; end
