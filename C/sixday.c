Some String function in  C are
strstr(s,b)  will return the address of the string b in string a

strcmp() compares two strings

strcat()

	concatenates two strings
strcpy()
	copies one string to another
strchr()
	finds the location of a character inside a string
strlen()
	finds the length of the string

This are some of the string function that will be needed to you

Now See this two important things 

char * str1="Rajat"

char str[]="Rajat" 

The First char array of str helps is defined in constant part of memory and thus it cant be changed

While on the hand you can change the content  of the other array

str1[2]='s' is not possible and will show an error

while

str[2]='s' is possible as it is defined in stack part of memory

But 

void fucntion_name(char * str) is equivalent to void function_name(char str[])

size_t is also a type of data structre that stores the length of the returne length by the function,In other words it is just an integer type data structre that stores the numbers

The proper way to format a short value is given by

short n;
scanf("%hi",&n);

You can specify the input and output as follows 

input is specified as follows <in.txt 
while output is specified with the help of this >out.txt

On the other hand statndard error which is in default displayed in the console is specified with the help of >2 error.txt

fscanf and fprintf are used for file reading and writing 

fscanf has the following syntax as follows 

fscanf(out_file,"Output this on console %d",i);

Here out_file is the file from where it gets the input

fprintf similarly has the same syntax

fprintf(out_file,"Rajat singh %d".i);

To close the data stream from the FILE pointer tha we have created using the fopen function is given as follows 

fclose(f);

The maximum number of data streams that we can have is 256 


There are two types of main declaration 

int main()

int main(int argc,char * argv[])


