#include<stdio.h>
typedef struct islands
{
	char * name;
	char *open;
	char *close;
	struct islands *next;
}islands;
int main()
{
	islands rajat={"Rajat","4:00","10:00",NULL};
	islands shoaba={"shoaba","2:00","2:05",NULL};
	islands mera={"mera","1:00","12:00",NULL};
	rajat.next=&shoaba;
	shoaba.next=&mera;
	display(&rajat);
	return 0;
}
void display(islands *i)
{
	islands *start=i;
	for(;start!=NULL;start=start->next)
	{
		printf("Name %s open : %s -- %s \n",start->name,start->open,start->close);
	}
}
