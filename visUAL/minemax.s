NUM1		dcd		40
NUM2		dcd		40
MIN		fill		4
MAX		fill		4
		
		mov		r1, #NUM1
		ldr		r1, [r1]
		mov		r2, #NUM2
		ldr		r2, [r2]
		mov		r3, #MIN
		mov		r4, #MAX
		
		cmp		r1, r2
		blt		FINE1
		bgt		FINE2
		beq		FINE3
		
		
FINE1	str		r1, [r3]
		str		r2, [r4]
		B		ENDING
		
FINE2	str		r2, [r3]
		str		r1, [r4]
		B		ENDING
		
FINE3	str		r2, [r3]
		str		r2, [r4]
		
ENDING	end
