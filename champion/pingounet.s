.name	"Super Pingouin"
.comment	"Tremblez devant Dark Pingouin /(')\\"


st		r1, 368 # TODO mettre r1 au niveau du live
st		r1, 371 #pareil

and		r16, r16, r16

live0:
	live	%42

fork: 	
	fork %:pingouin

wall:
	live 	%42
#	st		r2, -18
#	st		r2, -27
#	st		r2, -36
#	st		r2, -45	
#	st		r2, -54
#	st		r2, -63
#	st		r2, -72
#	st		r2, -81	
#	st		r2, -90
#	st		r2, -99
#	st		r2, -108
#	st		r2, -117	
#	st		r2, -126
#	st		r2, -135
#	st		r2, -144
#	st		r2, -153
#	st		r2, -162
#	st		r2, -171
#	st		r2, -180
#	st		r2, -189
#	st		r2, -198
#	st		r2, -207
#	st		r2, -216
#	st		r2, -225
#	st		r2, -234
#	st		r2, -243
#	st		r2, -252
#	st		r2, -261
#	st		r2, -270
#	st		r2, -279
#	st		r2, -288
#	st		r2, -297
#	st		r2, -306
#	st		r2, -315
#	st		r2, -324
#	st		r2, -333
#	st		r2, -342
#	st		r2, -351
#	st		r2, -360
#	st		r2, -369
#	st		r2, -378
#	st		r2, -387
#	st		r2, -396
#	st		r2, -405
#	st		r2, -414
#	st		r2, -423
#	st		r2, -432
#	st		r2, -441
#	st		r2, -450
#	st		r2, -459
#	st		r2, -468
#	st		r2, -477
#	st		r2, -486
#	st		r2, -495
#	st		r2, -504
#	st		r2, -513
#	st		r2, -522
#	st		r2, -531
#	st		r2, -540
#	st		r2, -549
#	st		r2, -558
#	st		r2, -567
#	st		r2, -576
#	st		r2, -585
#	st		r2, -594
	st		r2, -22
	st		r2, -31
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	st		r2, -511
	zjmp	%:wall

pingouin:
	live 	%42
	fork	%:live

zjmp	%:live0

live: 	
	live %42

aff		r1
live	%42
st		r1, 6
live	%42
zjmp %:live
