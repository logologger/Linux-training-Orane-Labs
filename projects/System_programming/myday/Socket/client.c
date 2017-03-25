//In this example i am going to  create a client that will connect to a specific IP address or a domain name using netdb.h and getaddrinfo() function 
//While  a simple server follows BLAB 
//On the other hand client follows this steps
//CONNECT TO A REMOTE PORT
//BEGIN TALKING
//A server will bind the socket to a local port ,While on the other hand A cient will connect to a socket on a remote host
//Before A web SerVer Connects to a client It needs to send to the server three things 
//GET Command
//Host:www.google.com
//A blank Line
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>//getaddrinfo() function is in this header
#include<arpa/inet.h>
#include<sys/socket.h>
void error(char *msg)
{
	fprintf(stderr,"%s : %s\n",msg,strerror(errno));
	exit(1);
}
int open_socket(char *host,char *port)
{
	struct addrinfo *res;
	struct addrinfo hints;
	memset(&hints,0,sizeof(hints));
	hints.ai_family=PF_UNSPEC;
	hints.ai_socktype=SOCK_STREAM;
	if(getaddrinfo(host,port,&hints,&res)==-1)//It constructs a new Data structure on the heap called as naming resource.It has hidden inside the IP address of the host that the server needs .It expects both host and port to be string
		error("CAnt resolve the address");
	//Create the socket using the naming resource
	int d_sock=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	if(d_sock==-1)
		error("CAnt open the socket");
	int c=connect(d_sock,res->ai_addr,res->ai_addrlen);//Connect it remote socket
	freeaddrinfo(res);//free the structre or delete the address data
	if(c==-1)
		error("CAnt connect to socket");
	return d_sock;

}
int say(int socket,char *s)
{
	int result=send(socket,s,strlen(s),0);
	if(result==-1)
		fprintf(stderr,"%s :%s\n","Error  talking to the server",strerror(errno));
	return result;
}
int main(int argc,char * argv[])
{
	int d_sock;
	d_sock=open_socket("en.wikipedia.org","80");
	char buff[255];
	sprintf(buff,"GET /wiki/%s http/1.1\r\n",argv[1]);//The client needs to send three things to the client for connection 
	//GET.......HOST.........An empty blank line..Create a string for the path to the page you want to connect
	say(d_sock,buff); 
	say(d_sock,"Host: en.wikipedia.org\r\n\r\n");//send the host as well as the empty blank line
	char rec[256];
	int bytesRcvd=recv(d_sock,rec,255,0);//recv function for reading from the server
	while(bytesRcvd)
	{
		if(bytesRcvd==-1)
			error("CAnt read from the server");
		rec[bytesRcvd]='\0';
		printf("%s",rec);
		bytesRcvd=recv(d_sock,rec,255,0);

	}
	close(d_sock);
}
