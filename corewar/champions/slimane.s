.name "solidus"
.comment "au bucher"

entry:			sti r1, %:live, %1
				sti r1, %:front, r2
				sti r1, %:back, %1
				ld %0, r16
				fork %:live

entry_2:
				live %42
				ld %439025904, r2
				ld %0, r16
				fork %:back

##################################################

front:
			live	%40
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			st		r2, -500
			zjmp	%:front

##################################################

live:		live %40
			zjmp %:live

##################################################

back:
			live	%40
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			st		r2, 200
			zjmp	%:back

##################################################

