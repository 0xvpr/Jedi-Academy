section .data
    player_addr DD 0x20282B18       ; inconsistent player signature
    return_addr DD 0x20067840       ; addr of take damage instruction

segment .text
global _health_detour

_health_detour:
    mov     esi, [edi + 0x244]      ; default code
    mov     edx, [esp + 0x14]       ; default code
    mov     ecx, [esp + 0x8F4]      ; default code

    cmp     edi, [player_addr]      ; compare target with player
    jne     return                  ; if target is not player, jump to return address
    xor     edx, edx                ; set edx to 0

return:
    jmp     [return_addr]           ; return address