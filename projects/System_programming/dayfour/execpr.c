#include<stdio.h>
#include<unistd.h>
int main()
{
	int ret;
	ret=execl("/bin/ps","ps","-ax",0);
	return 0;
}
