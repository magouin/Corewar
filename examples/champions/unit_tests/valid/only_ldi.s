.name "name"
.comment "comment"

ldi r1, r2, r3 # T_REG, T_REG, T_REG
ldi	r1, %32, r3 # T_REG, T_DIR, T_REG
ldi	32, r2, r3 # T_IND, T_REG, T_REG
ldi	32, %43, r3 # T_IND, T_DIR, T_REG
ldi	%32, r2, r3 # T_DIR, T_REG, T_REG
ldi	%32, %43, r3 # T_DIR, T_DIR, T_REG

