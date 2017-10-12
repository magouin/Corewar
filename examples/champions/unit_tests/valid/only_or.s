.name "name"
.comment "comment"

or r1, r2, r3 # T_REG, T_REG, T_REG
or	r1, %32, r3 # T_REG, T_DIR, T_REG
or	r1, 32, r3 # T_REG, T_IND, T_REG
or	32, r2, r3 # T_IND, T_REG, T_REG
or	32, %43, r3 # T_IND, T_DIR, T_REG
or	32, 43, r3 # T_IND, T_IND, T_REG
or	%32, r2, r3 # T_DIR, T_REG, T_REG
or	%32, %43, r3 # T_DIR, T_DIR, T_REG
or	%32, 43, r3 # T_DIR, T_IND, T_REG
