echo "This is the program for Creating Shared library"
echo "Enter the Program for which u want to create the library"
read file_name
gcc -c -fPIC $file_name.c -o $filename.o
gcc -shared -o libarth.so $filename.o
export LD_LIBRARY_PATH=.
echo "Enter the Program which is going to be execute with the help of your library file"
read program
gcc -o $program $program.c -larth -L.
./$program
