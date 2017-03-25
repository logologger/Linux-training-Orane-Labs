//This Example is greatly for who want to know what is call by value 
//In Call by value When we pass the data through the function ,we actually pass the copy of the data ,So what hAPPENS THAT Original value of the variable that is passed remains the same irrespective of the fact that it is changed in the original function ,...Simple logic
//Why  in scanf we pass the address and not simply the name
//scanf("%d",&name);
//Because u are going to update the value of the name variable ...
//And in order to update the value of the variable u need to tell the compiler where the variable is actually stored ..Right thats why u use this
//Please go through the example of page number 244
#include<stdio.h>
typedef struct 
{
	const char * name;
	const char * species;
	int age;
}turtle;
void happy_birthdayref(turtle *t)
{
	(*t).age=(*t).age+1;
	//t->age=t->age+1 //both are same
	printf("Happy Birthday %s ! you are now %i age\n",(*t).name,(*t).age);
}
void happy_birthday(turtle t)
{
	t.age=t.age+1;
	printf("Happy Birthday %s ! You are now %i years old !\n",t.name,t.age);
}
int main()
{
	turtle myrtle={"Myrtle","Leatherback sea",99};
	happy_birthday(myrtle);//Call by Value
	printf("%s's age is now %i\n",myrtle.name,myrtle.age);
	happy_birthdayref(&myrtle);
	printf("%s age is now %i\n",myrtle.name,myrtle.age);
	return 0;
}

