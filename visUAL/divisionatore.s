DIVIDENDO	dcd		13
DIVISORE	dcd		5
QUOZIENTE	fill		4
RESTO		fill		4
		
		mov		r6, #0
		mov		r5, #QUOZIENTE
		mov		r7, #RESTO
		mov		r2, #DIVIDENDO
		ldr		r2, [r2]
		mov		r3, #DIVISORE
		ldr		r3, [r3]
		
CICLO		cmp		r2, r3
		blt		FINE
		
		sub		r2, r2, r3
		add		r6, r6, #1
		B		CICLO
		
FINE		str		r6, [r5]
		str		r2, [r7]
		end
