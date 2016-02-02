.name "Zork Killer"
.comment "I kill zork"

start:
	st r1, 6
	live %0
	ld %0, r3
	zjmp %:start
