MOLTIP1			dcd		-2
MOLTIP2			dcd		-4
RIS				fill		4	; salvo 4 bytes dove mettere il risuoltato
				;		perché assumiamo words da 16 (cauli aveva detto 32??)
				
				mov		r6, #RIS
				mov		r1, #MOLTIP1 ;; metto l'indirizzo di MOLTIP1 in r1
				mov		r2, #MOLTIP2 ;; metto l'indirizzo di MOLTIP2 in r2
				ldr		r1, [r1] ;; carico il contenuto di moltip1 in r1
				ldr		r2, [r2]	;; carico il contenuto di motlip2 in r2
				
				mov		r0, #0	;clear r0
				cmp		r1, #0
				blt		COMPLdelPRIMO
				
do2nd			cmp		r2, #0
				blt		COMPLdelSECONDO
CICLO
				cmp		r2, #0 	; confronto il secondo termine(n) con 0: ovvero, controllo di star sommando n volte
				beq		FINE 	; check del bit di controllo9
				
				add		r0, r0, r1	; aggiungo il primo termine alla somma
				subs		r2, r2, #1	; decremento le "volte da sommare" quindi r2
				B		CICLO 		;salto incondizionato a ciclo
				
				;cmp		;;COMPARE IF UNO DEI DUE ALL'INIZIO ERA NEGATIVO
FINE				str		r0, [r6]	;metto il risultato ottenuto nella cella con l'indirizzo
				end		; che ho messo in r6, ovvero RIS
				
COMPLdelPRIMO
				mvn		r1, r1
				add		r1, r1, #1
				b		do2nd
				
COMPLdelSECONDO
				mvn		r2, r2
				add		r2, r2, #1
				b		CICLO
