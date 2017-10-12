../asm/asm champions/championships/2014/bguy/sam_2.0.s
../asm/asm champions/championships/2014/bjacob/doge.s
../asm/asm champions/championships/2014/brandazz/Rainbow_dash.s
../asm/asm champions/championships/2014/cdivry/youforkmytralala.s
../asm/asm champions/championships/2014/dcohen/loose.s
../asm/asm champions/championships/2014/evlasova/terminator.s
../asm/asm champions/championships/2014/gjestin/salamahenagalabadoun.s
../asm/asm champions/championships/2014/gpetrov/MarineKing.s
../asm/asm champions/championships/2014/sbuono/Asombra.s

./corewar champions/championships/2014/bguy/sam_2.0.cor champions/championships/2014/bjacob/doge.cor -v 22 > f2
../vm/corewar champions/championships/2014/bguy/sam_2.0.cor champions/championships/2014/bjacob/doge.cor -v 22 > f1
diff f1 f2
echo "DIFF OK"


./corewar champions/championships/2014/brandazz/Rainbow_dash.cor champions/championships/2014/cdivry/youforkmytralala.cor champions/championships/2014/dcohen/loose.cor -v 22 > f2
../vm/corewar champions/championships/2014/brandazz/Rainbow_dash.cor champions/championships/2014/cdivry/youforkmytralala.cor champions/championships/2014/dcohen/loose.cor -v 22 > f1
diff f1 f2
echo "DIFF OK"

./corewar champions/championships/2014/evlasova/terminator.cor champions/championships/2014/gjestin/salamahenagalabadoun.cor -v 22 > f2
../vm/corewar champions/championships/2014/evlasova/terminator.cor champions/championships/2014/gjestin/salamahenagalabadoun.cor -v 22 > f1
diff f1 f2
echo "DIFF OK"

./corewar champions/championships/2014/gpetrov/MarineKing.cor champions/championships/2014/cdivry/youforkmytralala.cor champions/championships/2014/dcohen/loose.cor champions/championships/2014/sbuono/Asombra.cor -v 22 > f2
../vm/corewar champions/championships/2014/gpetrov/MarineKing.cor champions/championships/2014/cdivry/youforkmytralala.cor champions/championships/2014/dcohen/loose.cor champions/championships/2014/sbuono/Asombra.cor -v 22 > f1
diff f1 f2
echo "DIFF OK"

