#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<stdbool.h>

#define PORT 4444

bool check(char grid1[11][17])		//To check for winner
{
    int flag=0;
    if((grid1[1][2]=='x' && grid1[1][8]=='x' && grid1[1][14]=='x')||(grid1[5][2]=='x' && grid1[5][8]=='x' && grid1[5][14]=='x')||(grid1[9][2]=='x' && grid1[9][8]=='x' && grid1[9][14]=='x'))
   	 {
   		 flag=1;
   		 printf("\n\t\twinner = Client");
   	 }
   	 if((grid1[1][2]=='x' && grid1[5][2]=='x' && grid1[9][2]=='x')||(grid1[1][8]=='x' && grid1[5][8]=='x' && grid1[9][8]=='x')||(grid1[1][14]=='x' && grid1[5][14]=='x' && grid1[9][14]=='x'))
   	 {
   		 flag=1;
   		 printf("\n\t\twinner = Client");
   	 }
   	 if((grid1[1][2]=='x' && grid1[5][8]=='x' && grid1[9][14]=='x')||(grid1[1][14]=='x' && grid1[5][8]=='x' && grid1[9][2]=='x'))
   	 {
   		 flag=1;
   		 printf("\n\t\twinner = Client");
   	 }

   	 if((grid1[1][2]=='o' && grid1[1][8]=='o' && grid1[1][14]=='o')||(grid1[5][2]=='o' && grid1[5][8]=='o' && grid1[5][14]=='o')||(grid1[9][2]=='o' && grid1[9][8]=='o' && grid1[9][14]=='o'))
   	 {
   		 flag=1;
   		 printf("\n\t\twinner = Server");
   	 }
   	 if((grid1[1][2]=='o' && grid1[5][2]=='o' && grid1[9][2]=='o')||(grid1[1][8]=='o' && grid1[5][8]=='o' && grid1[9][8]=='o')||(grid1[1][14]=='o' && grid1[5][14]=='o' && grid1[9][14]=='o'))
   	 {
   		 flag=1;
   		 printf("\n\t\twinner = Server");
   	 }
   	 if((grid1[1][2]=='o' && grid1[5][8]=='o' && grid1[9][14]=='o')||(grid1[1][14]=='o' && grid1[5][8]=='o' && grid1[9][2]=='o'))
   	 {
   		 flag=1;
   		 printf("\n\t\twinner = Server");
   	 }
   	 else if(grid1[1][2]!=' ' && grid1[1][8]!=' ' && grid1[1][14]!=' ' && grid1[5][2]!=' ' && grid1[5][8]!=' ' && grid1[5][14]!=' ' && grid1[9][2]!=' ' && grid1[9][8]!=' ' && grid1[9][14]!=' ')
   	 {
   		 flag=1;
   		 printf("\n\t\tDraw Match");
   	 }

   	 if(flag==1)
   		 return(true);
   	 else
   		 return(false);
}

void modifyx(char cli,char grid1[11][17])			//To modify grid1 with new ‘x’ value
{
    if(cli=='1'  && grid1[9][2]==' ')
   	 grid1[9][2]='x';
    else if(cli=='2' && grid1[9][8]==' ')
   	 grid1[9][8]='x';
    else if(cli=='3' && grid1[9][14]==' ')
   	 grid1[9][14]='x';
    else if(cli=='4' && grid1[5][2]==' ')
   	 grid1[5][2]='x';
    else if(cli=='5' && grid1[5][8]==' ')
   	 grid1[5][8]='x';
    else if(cli=='6' && grid1[5][14]==' ')
   	 grid1[5][14]='x';
    else if(cli=='7' && grid1[1][2]==' ')
   	 grid1[1][2]='x';
    else if(cli=='8' && grid1[1][8]==' ')
   	 grid1[1][8]='x';
    else if(cli=='9' && grid1[1][14]==' ')
   	 grid1[1][14]='x';
}

int modifyo(char ser,char grid1[11][17],int flag)		//To modify grid1 with new ‘y’ value
{
    if(ser=='1' && grid1[9][2]==' ')
   	 grid1[9][2]='o';
    else if(ser=='2' && grid1[9][8]==' ')
   	 grid1[9][8]='o';
    else if(ser=='3' && grid1[9][14]==' ')
   	 grid1[9][14]='o';
    else if(ser=='4' && grid1[5][2]==' ')
   	 grid1[5][2]='o';
    else if(ser=='5' && grid1[5][8]==' ')
   	 grid1[5][8]='o';
    else if(ser=='6' && grid1[5][14]==' ')
   	 grid1[5][14]='o';
    else if(ser=='7' && grid1[1][2]==' ')
   	 grid1[1][2]='o';
    else if(ser=='8' && grid1[1][8]==' ')
   	 grid1[1][8]='o';
    else if(ser=='9' && grid1[1][14]==' ')
   	 grid1[1][14]='o';
    else
    {
   	 printf("Invalid input!\n\n");
   	 flag=1;
    }
    return(flag);
}

void printgrid(char grid1[11][17])
{
    int i,j;
    for(i=0;i<11;i++)
    {
   	 for(j=0;j<17;j++)
   	 {
   		 printf("%c",grid1[i][j]);
   	 }
   	 printf("\n");
    }
}


void main(){

    	int sockfd;
    	struct sockaddr_in serverAddr;

    	int newSocket;
    	struct sockaddr_in newAddr;

    	socklen_t addr_size;
    	char sen[2];
    	char rec[2];
    	int flag=0;

    	//Making grids
    
    char grid[11][17];
    	char grid1[11][17];
    	int i,j;
    	for(i=0;i<11;i++)
            	for(j=0;j<17;j++)
            	{
                    	if(i==3 || i==7)
                    	{
                            	grid[i][j]='-';
                            	grid1[i][j]='-';
                    	}
                    	else if(j==5 || j==11)
                    	{
                            	grid[i][j]='|';
                            	grid1[i][j]='|';
                    	}
                    	else
                    	{
                            	grid[i][j]=' ';
                            	grid1[i][j]=' ';
                    	}
            	}
    	for(i=0;i<11;i++)
    	{
   	 for(j=0;j<17;j++)
            	{
                    	if(i==9 && j==2)
                            	grid[i][j]='1';
                    	if(i==9 && j==8)
                            	grid[i][j]='2';
                    	if(i==9 && j==14)
                            	grid[i][j]='3';
                    	if(i==5 && j==2)
                            	grid[i][j]='4';
                    	if(i==5 && j==8)
                            	grid[i][j]='5';
                    	if(i==5 && j==14)
                            	grid[i][j]='6';
                    	if(i==1 && j==2)
                            	grid[i][j]='7';
                    	if(i==1 && j==8)
                            	grid[i][j]='8';
                    	if(i==1 && j==14)
                            	grid[i][j]='9';
            	}
    	}

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    	printf("[+]Server Socket Created Sucessfully.\n");
    	memset(&serverAddr, '\0', sizeof(serverAddr));

    	serverAddr.sin_family = AF_INET;
    	serverAddr.sin_port = htons(PORT);
    	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    	bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    	printf("[+]Bind to Port number %d.\n", 4455);

    	listen(sockfd, 5);
    	printf("[+]Listening...\n");

    	newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);


    	printf("\n\n\t\tWelcome to Tic-Tac-Toe game!\n\n");
    	printf("Here are the numbers to type to play:\n");
   	 
    //Printing initial grid
    
    for(i=0;i<11;i++)
    	{
            	for(j=0;j<17;j++)
            	{
                    	printf("%c",grid[i][j]);
            	}
            	printf("\n");
    	}
    	printf("\n\n");
    	printf("\tServer: o, Client: x\n");
    	printf("You: Server\n\n");


    //Beginning of round1
    

    printf("\t--------CLIENT'S TURN--------\n");
    	recv(newSocket,rec,2,0);
    	char pos_rec;
    	pos_rec=rec[0];
    	printf("\nReceived data: %c\n\n",pos_rec);

    //updating received value in grid
    modifyx(pos_rec,grid1);

    //printing updated grid
    

    	printf("\n");
    	printf("\n");
    printgrid(grid1);

    //Input

    	printf("\n\n--------YOUR TURN--------\n");
    	here:
    	printf("\nEnter: ");
    	fgets(sen,2,stdin);
    	send(newSocket,sen,strlen(sen),0);

    	char pos;
    	pos=sen[0];

    	//Updating value in grid
    int o=modifyo(pos,grid1,flag);
    if(o==1)
   	 goto here;
    
    send(newSocket,sen,strlen(sen),0);	//sending value

    	//printing updated grid


    	printf("\n");
    	printf("\n");

    printgrid(grid1);

    //End of round1
    
    //-----------------Start of round2
    
    printf("\t--------CLIENT'S TURN--------\n");
    	recv(newSocket,rec,2,0);
  	 
    	pos_rec=rec[0];
    	printf("\nReceived data: %c\n\n",pos_rec);

    	//updating received value in grid
    	modifyx(pos_rec,grid1);

    	//printing updated grid


    	printf("\n");
    	printf("\n");
    	printgrid(grid1);

    	//Input

        	printf("\n\n--------YOUR TURN--------\n");
    	here1:
    getchar();
    	printf("\nEnter: ");
    	fgets(sen,2,stdin);
    	send(newSocket,sen,strlen(sen),0);

    	pos;
    	pos=sen[0];

    	//Updating value in grid
    flag=0;
    	o=modifyo(pos,grid1,flag);
    	if(o==1)
            	goto here1;

    	send(newSocket,sen,strlen(sen),0);	//sending value

    	//printing updated grid


    	printf("\n");
    	printf("\n");

    	printgrid(grid1);

    //End of round2
    //---------------------Start of round3
    
    printf("\t--------CLIENT'S TURN--------\n");
    	recv(newSocket,rec,2,0);

    	pos_rec=rec[0];
    	printf("\nReceived data: %c\n\n",pos_rec);

    	//updating received value in grid
    	modifyx(pos_rec,grid1);

    	//printing updated grid


    	printf("\n");
    	printf("\n");
    	printgrid(grid1);

    bool check_var;             	//checking for winner
    	check_var=check(grid1);
    	if(check_var==true)
    {
   	 printf("\n\nThank you for playing!\n\n");
   	 printf("\n[+]Closing the connection.\n\n");
   	 close(newSocket);
            	exit(0);
    }


    	//Input

            	printf("\n\n--------YOUR TURN--------\n");
    	here2:
    getchar();
    	printf("\nEnter: ");
    	fgets(sen,2,stdin);
    	send(newSocket,sen,strlen(sen),0);

    	pos;
    	pos=sen[0];

    	//Updating value in grid
    	flag=0;
    	o=modifyo(pos,grid1,flag);
    	if(o==1)
            	goto here2;

    	send(newSocket,sen,strlen(sen),0);	//sending value

    	//printing updated grid
    
    printgrid(grid1);
    //End of round3
    
    //checking for winner
    check_var=check(grid1);
    if(check_var==true)
    	{
            	printf("\n\nThank you for playing!\n\n");
   	 printf("\n[+]Closing the connection.\n\n");
            	close(newSocket);
   	 exit(0);
    	}

    
    //----------------------Start of round4
    
    printf("\t--------CLIENT'S TURN--------\n");
    	recv(newSocket,rec,2,0);

    	pos_rec=rec[0];
    	printf("\nReceived data: %c\n\n",pos_rec);

    	//updating received value in grid
    	modifyx(pos_rec,grid1);

    	//printing updated grid


    	printf("\n");
    	printf("\n");
    	printgrid(grid1);

    //checking for winner
    	check_var=check(grid1);
    	if(check_var==true)
    	{
            	printf("\n\nThank you for playing!\n\n");
   	 printf("\n[+]Closing the connection.\n\n");
            	close(newSocket);
   	 exit(0);
    	}

    
    //Input

            	printf("\n\n--------YOUR TURN--------\n");
    	here3:
    	getchar();
    	printf("\nEnter: ");
    	fgets(sen,2,stdin);
    	send(newSocket,sen,strlen(sen),0);

    	pos;
    	pos=sen[0];

    	//Updating value in grid
    	flag=0;
    	o=modifyo(pos,grid1,flag);
    	if(o==1)
            	goto here3;

    	send(newSocket,sen,strlen(sen),0);	//sending value

    	//printing updated grid

    	printgrid(grid1);
    //checking for winner
    	check_var=check(grid1);
    	if(check_var==true)
    	{
            	printf("\n\nThank you for playing!\n\n");
   	 printf("\n[+]Closing the connection.\n\n");
            	close(newSocket);
   	 exit(0);
    	}
    
    //End of round4
    
    //--------------Start of round5
    
    printf("\t--------CLIENT'S TURN--------\n");
    	recv(newSocket,rec,2,0);

    	pos_rec=rec[0];
    	printf("\nReceived data: %c\n\n",pos_rec);

    	//updating received value in grid
    	modifyx(pos_rec,grid1);

    	//printing updated grid


    	printf("\n");
    	printf("\n");
    	printgrid(grid1);

    	//checking for winner
    	check_var=check(grid1);
    	if(check_var==true)
    	{
            	printf("\n\nThank you for playing!\n\n");
   	 printf("\n[+]Closing the connection.\n\n");
            	close(newSocket);
   	 exit(0);
    	}

}
