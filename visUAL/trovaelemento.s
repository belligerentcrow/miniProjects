ARR				dcd		4,9,1,10,-8,5,90,13,2,30
NUM1				dcd		10
INDEXFOUND			fill		4
				
				mov		r1, #ARR
				ldr		r1, [r1]
				mov		r2, #NUM1
				ldr		r2, [r2]
				mov		r3, #INDEXFOUND
				mov		r4, #0
				mov		r5, #10
				mov		r6, #ARR
				mov		r7, #4
				
CICLO				add		r4, r4, #1
				ldr		r1, [r6, r7]
				cmp		r1, r2
				beq		FINE1_TROVATO
				
				add		r7, r7, #4
				cmp		r4, r5
				beq		FINE2_NONTROVATO
				B		CICLO
				
FINE1_TROVATO			str		r4, [r3]
				
FINE2_NONTROVATO		end
