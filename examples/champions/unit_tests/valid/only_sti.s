.name "name"
.comment "comment"

sti1: sti r1, r2, r3 # T_REG, T_REG, T_REG
sti2: sti r1, r2, %55 # T_REG, T_REG, T_DIR
sti3: sti r1, 6, r3 # T_REG, T_IND, T_REG
sti4: 
sti5: 
sti5bis: sti r1, 44, %55 # T_REG, T_IND, T_DIR
sti6: sti r1, %44, r3 # T_REG, T_DIR, T_REG
sti7: sti r1, %44, %55 # T_REG, T_DIR, T_DIR

