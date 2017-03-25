function codechef
{
cd /home/rajat/codes/codechef
echo "Welcome to the codechef challenge"
echo "Enter the month along with year without any spaces in between"
read dir_name
if [ -d $dir_name ]
then 
echo ""
else 
mkdir $dir_name
fi
cd $dir_name
echo "Tell us whether the file name is Java OR C"
read extension
case $extension in 
c)
echo "Enter the file name"
read file_name
if [ -f $file_name ]
then
echo "File Name already exist!"
else
touch $file_name.c
fi
exec 3>$file_name.c
echo "#include<stdio.h>">&3
echo "int main()">&3
echo "{">&3
echo "int t,n;">&3
echo "scanf(\"%d\",&t);">&3
echo "while(t--)">&3
echo "{">&3
echo "}">&3
echo "return 0;" >&3
echo "}">&3
exec 3>&-
vim $file_name.c
;;
java)

echo "Enter the file name"
read file_name
touch $file_name.java
exec 3>$file_name.java
echo "import java.io.*;">&3
echo "class frst">&3
echo "{">&3
echo "public static void main(String args[])throws IOException">&3
echo "{">&3
echo "InputStreamReader reader=new InputStreamReader(System.in);">&3
echo "BufferedReader in=new BufferedReader(reader);">&3
echo "int t=Integer.parseInt(in.readLine());">&3
echo "while(t>0)">&3
echo "{">&3
echo "}">&3
echo "}">&3
echo "}">&3

vim $file_name.java
;;

esac
}

