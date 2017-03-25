//Here we will be reading from the client using recv function
//Some things to remember while using recv function
//the characters are not terminated with a \0 character
//When someone types text in telnet, the string always ends \r\n
//The recv() will return the number of characters or -1 if there is error
//you are not gurantedd to recieve al the characters in a single call to recv()...
//The format for the recv function is 
//<bytes_read>=recv(<descriptor>,<buffer>,<bytes to read>,0);
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<signal.h>
#include<unistd.h>
int listener_d;
void error(char * msg)//Dont call the function if you want the program to keep running
{
	fprintf(stderr,"%s : %s \n ",msg,strerror(errno));
	exit(1);
}
int open_listener_socket()//Create an Internet Streaming Socket
{
	int s=socket(PF_INET,SOCK_STREAM,0);
	if(s==-1)
		error("cant open the socket");
	return s;
}
void bind_to_port(int socket,int port)//bind the socket with the port 30000 of my machine using the bind function
{
struct sockaddr_in name;
name.sin_family=PF_INET;
name.sin_port=(in_port_t)htons(30000);//Internet port 30000 
name.sin_addr.s_addr=htonl(INADDR_ANY);
int reuse=1;//It is used for reuse the same port or socket after the Servr Is Off and On Again
if(setsockopt(socket,SOL_SOCKET,SO_REUSEADDR,(char *)&reuse,sizeof(int))==-1)
	error("Cant reuse the socket");
int c=bind(socket,(struct sockaddr *)&name,sizeof(name));//Bind or grap to port 30000
if(c==-1)
error("CAnt bind the port or to socket");
}
int say(int socket,char *s)//send a string to the client using the send function
{
int result=send(socket,s,strlen(s),0);
if(result==-1)//We havent called error because if there is problem it might be only with one client only and u dont want to stop the server because of that 
{
	fprintf(stderr,"%s:%s\n","Error talking to the client",strerror(errno));
}
return result;
}
void handle_shutdown(int sig)//This is actually used for handling shutdown of server by me when pressing ctrl+C 
{
	if(listener_d)
		close(listener_d);
	fprintf(stderr,"Bye ! Asta Lavista Bebe\n");
	exit(0);
}
int read_in(int socket,char * buff,int len)//Since recv is not easy to use so we have created our own Wrapper function which can handle its complexity
{
	char *s=buff;
	int slen=len;
	int c=recv(socket,s,slen,0);//recieving the bytes from the client
	while((c>0) && (s[c-1] !='\n'))//Keep reading until the last character  is \n
	{
		s+=c;
		slen-=c;
		c=recv(socket,s,slen,0);
	}
	if(c<0)
		return c;
	else if(c==0)
		buff[0]='\0';
	else
		s[c-1]='\0';//makes the last character as \0 instead of \n
	return len-slen;
}
//strncasecmp compares strings without case sensitivity
int main(int argc,char * argv[])
{
	//if(catch_signal(SIGINT,handle_shutdown)==-1)
	//	error("Cant see the interrupt handler");
	listener_d=open_listener_socket();
	bind_to_port(listener_d,30000);
	if(listen(listener_d,10)==-1)//set the listen-queue length to 10
		error("cant listen");
	struct sockaddr_storage client_addr;//This structure actually stores the Client Information
	unsigned int address_size=sizeof(client_addr);
	puts("WAiting for Connection");
	char buff[255];
	while(1)
	{
		int connect_d=accept(listener_d,(struct sockaddr *)&client_addr,&address_size);//It Accepts the connection from the client
		if(connect_d==-1)
			error("CAnt open Secondary socket");
		if(!fork())
			close(listener_d);
		if(say(connect_d,"Internet RAjat Protocol\r\nVersion 1.0 \r\nBang Bang\r\n>")!=-1)
		{
			read_in(connect_d,buff,sizeof(buff));//read data from the client
		if(strncasecmp("Who's there?",buff,12))//Compare without any case Sensitivity
			say(connect_d,"You should say who's there");
		else
		{
			if(say(connect_d,"Oscar\r\n>")!=-1)
			{
				read_in(connect_d,buff,sizeof(buff));
				if(strncasecmp("Oscar who?",buff,10))
						say(connect_d,"You should say Rajat who\r\n");
						else
						say(connect_d,"Oscar silly Question Come on Rajat");
			}
		}
		close(connect_d);
		exit(0);
	}
close(connect_d);
}
	return 0;
}
//The following program has a bug that it can handle only one client at a time .
//In order that our server can handle multiple queries we should use fork to create child processes that can handle those extra clients
