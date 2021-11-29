ARR1		dcd		-2,40,31,5,66,30,17,89,90,23
NUMEL	dcd		10
RIS		fill		4
		
		mov		r0, #NUMEL
		ldr		r0, [r0]
		
		mov		r1, #ARR1
		mov		r2, #0
		
CICLO	ldr		r3, [r1]
		add		r2, r2, r3
		sub		r0, r0, #1
		add		r1, r1, #4
		cmp		r0, #0
		bgt		CICLO
		
		mov		r4, #RIS
		str		r2, [r4]
