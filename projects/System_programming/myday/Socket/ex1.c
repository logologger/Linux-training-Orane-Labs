//this simple C programs a server that listens on port no 30000 
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>
int  main(int argc,char * argv[])
{
	char * advice[]={
		"Take smaller bites\r\n",
		"go for the tight jeans.No they do not make you look fat\r\n",
		"One word :inappropriate\n\r",
		"Just for today,be honest.Tell your boss what you *really* think\r\n",
		"You might want to rethink that haircut\r\n"
	};
	int listener_d=socket(PF_INET,SOCK_STREAM,0);//create a scoket..listener_d is the socket descriptor
	//Now we bind this socket to a port
	struct sockaddr_in name;
	name.sin_family=PF_INET;
	name.sin_port=(in_port_t)htons(30000);//set the port number to 30000
	name.sin_addr.s_addr=htonl(INADDR_ANY);
	bind(listener_d,(struct sockaddr *) &name,sizeof(name));//bind function.
	listen(listener_d,10);//listen on the port number 30000 for 10 ppls greater then 10 gets server busy.It tells the OS how long would the queue to be.
	puts("Waiting for connection");
	while(1)
	{
		struct sockaddr_storage client_addr;//stores details about the client who just got connected.
		unsigned int address_size=sizeof(client_addr);
		int connect_d=accept(listener_d,(struct sockaddr *)&client_addr,&address_size);//Accept the connection from the client.Here is the server actually waiting.It is called socond socket desciptor.
		char *msg=advice[rand()%5];
		send(connect_d,msg,strlen(msg),0);//sending the message to the client who queried ..the first is socket descriptor,second one is the message ,third is message length and 4th is advance one
		close(connect_d);//close the connection...A typicall messages ends in telnet as \r\n not by \o

	}
	return 0;
}
//if any of them BLAB function returns -1 then there is an error
//Now u need to reuse the port .For OS does not allow to use the same port even if the port is closed .So we have used here setsockopt where settig its value to 1 will give us the option to reuse the port
//
//int reuse=1;
//if(setsockopt(listener_d,SOL_SOCKET,SO_REUSEADDR,(char *)&reuse,sizeof(int)==-1)
