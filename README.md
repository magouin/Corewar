Prerequisites:
  -ncurse
  
There is two main files:
  -ASM is a program that compile a ASMlike(.s) language in hexa opcode file (.cor)
  -VM is the Virtual Machine (something like a arena), where the programs were fight
  
#Compile the project with:

$> make

#You will get tow executable named asm and corewar
#You have to create hex opcode file with

$> ./asm <nameofthefile>.s

#You can find .s file example in the champion directory
#After compiled asm file you can fight your programs with ./corewar
#To get the usage juste run ./corewar 

##############################################################################################

Example:

$> ./asm champion/Kappa.s                                  #Created .cor of the Kappa.s file
$> ./asm champion/Asombra.s                                #Created .cor of the Asombra.s file
$> ./corewar -g champion/Kappa.cor champion/Asombra.cor    #Run ncurse to see the fight between Kappa and Asombra
