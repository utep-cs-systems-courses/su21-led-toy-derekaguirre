	.arch msp430g2553
	.p2align 1,0
	
	.text			
cases:

	.word case0
	.word case1
	.word case2
	.word case3
	.word default
	
	.global green_brightness

green_brightness:
	cmp #4, R12		;brightness - 4
	jhs default		;jmp if brightness >= 3
case0:
	cmp #0, R12
	call #green_bright
	jmp end
case1:
	cmp #1, R12
	call #green_medium
	jmp end
case2:
	cmp #2, R12
	call #green_dim
	jmp end
case3:
	cmp #3, R12
	call #disable_green
	jmp end
default:
	jmp end
end:
	pop r0
