#include<stdio.h>
typedef struct//Struct Without names are called anonymous struct
{
	float tank_capacity;
	int tank_psi;
	const char *suit_material;
}equipment;
typedef struct scuba//This is NOT an anonymous struct
{
const char * name;
equipment kit;
}diver;
void badge(diver d)
{
	printf("Name :%s Tank: %2.2f(%i) Suit :%s\n",d.name,d.kit.tank_capacity,d.kit.tank_psi,d.kit.suit_material);
}
int main()
{
	diver randy={"Randy",{2.2,3500,"Neopprene"}};
	badge(randy);
	return 0;
}
