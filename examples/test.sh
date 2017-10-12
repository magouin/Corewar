echo "\n\n\n**** OPERATIONS VALIDES ****\n\n\n"

for l in champions/unit_tests/valid/*
do
if [[ $l == *.s ]] ; then
		FILENAME="${l%.*}"
		EXTENSION=".cor"
		COR_NAME=$FILENAME$EXTENSION
		echo "\n"$COR_NAME
		./asm  "$l"
		hexdump $COR_NAME > f1
		../asm/asm "$l"
		hexdump $COR_NAME > f2
		diff f1 f2
fi
done

echo "\n\n\n***** OPERATIONS NON VALIDES *****\n\n\n"
for l in champions/unit_tests/non_valid/*
do
if [[ $l == *.s ]] ; then
		echo "\n"$l
		./asm  "$l"
		../asm/asm "$l"
fi
done

