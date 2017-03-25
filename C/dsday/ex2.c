#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct islands
{

	char * name;//character pointers stores only name while name[] array has its copy of every indivual data
	//use of char arrays is limited because u need to space(max) before hand for storing the character while in character pointer there is no such limit 
	char * open;
	char *close;
	struct islands *next;
}islands;
void display(islands *i)
{
	islands *start=i;
	for(;start!=NULL;start=start->next)
	{
		printf("%s open :%s=%s\n",start->name,start->open,start->close);
	}

}
islands * create(char * name)
{
	islands *i = malloc(sizeof(islands));//allocates space for the structre
	i->name=strdup(name);//assign name
	i->open="12:00";
	i->close="3:00";
	i->next=NULL;//return the next 
	return i;//return the pointer to the newly made struct
}
int main()
{
	char name[40];
	fgets(name,40,stdin);

	islands *p0=create(name);
	fgets(name,40,stdin);
	islands *p1=create(name);
	p0->next=p1;
	display(p0);
	return 0;

}
