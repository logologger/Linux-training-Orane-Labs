#include<stdio.h>
struct prefer
{
	char a;
	int b;
};
struct fish
{
	const char *name;
	const char *species;
	int teeth;
	int age;
	struct prefer kmp;i//To use the kmp struct it should be defined before this struct named fish

};
void catalog(struct fish f)
{
	printf("%s is a %s with %i teeth.He is %i. And likes %c\n",f.name,f.species,f.teeth,f.age,f.kmp.a);
}
int main()
{
	struct fish snappy={"Snappy","Piranha",90,69,{'k',12}};
	catalog(snappy);
	return 0;
}
