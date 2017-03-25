echo "Enter the C file name"
read file_name
file_name1=$file_name.c
gcc -c $file_name1 -o $file_name.o
ar crv libarth.a $file_name.o
echo "Enter the Program name"
read program
program1=$program.c
program2=$program.o
gcc -o $program2 $program1  libarth.a
./$program2
