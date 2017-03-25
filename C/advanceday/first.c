#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int NUM_ADS=7;
	char *ADS[]={
		"William:Ohh My Ghosh",
		"Rajat : This Man is Awesome ..Just a short guy looking for a hot girl",
		"Shoaba :She is a bitch",
		"Nida:A muslim who uses people around her",
		"shikha:The Biggest asshole of the universe",
		"Saumya:MOther Diary Shop",
		"Indiana Jones:He is the Treasure Hunter ,A Historian An Epic"
	};
	int i;
	for(i=0;i<NUM_ADS;i++)
	{
		if(strstr(ADS[i],"Raj") && !strstr(ADS[i],"shoaba"))
		{
			printf("%s\n",ADS[i]);
		}

	}

	return 0;
}
