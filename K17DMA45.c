#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
struct bus
{
char busnumber[20];
char name[50];
char pname[50];
float amount;
char destination[20];
char source[20];
char arrivaltime[11];
char departuretime[10];
char seat[10];
int i;
}s;
void addbuses();
void bookticket();
void listofbuses();
void listofticket();
void updateticket();
void searchticket();
void cancelticket();
char get;
int main()
{ 
 char choice;
 int i;
 while (1)
 {
 	printf("\n\n\n\n\n\n\n\n\n\t\t\t##############################################################");
 printf("\n\t\t\t  -------------WELCOME TO BUS RESESRVATION SYSTEM-----------");
 printf("\n\t\t\t##############################################################");
  printf("\n\n\t\t\t\t Enter your choice:-\n\n\t\t\t\t A : Add a New Bus  (For Administrator)\n\t\t\t\t L : List of Buses\n\t\t\t\t B : Book a Ticket");
  printf("\n\t\t\t\t D : List of Tickets");
  printf("\n\t\t\t\t S : Search your Ticket");
  printf("\n\t\t\t\t U : Update your Ticket");
  printf("\n\t\t\t\t C : Delete your Ticket");
  printf("\n\t\t\t\t E : Exit");
  printf("\n\n\t\t\t\t\t");
  choice=getche();
  choice=toupper(choice);
  switch(choice)
  {
    case 'B': 
     bookticket();break;
     case 'C':
     cancelticket();break;
   case 'A':
    addbuses();break;
   case 'L':
    listofbuses();break;
    case 'D':
    	listofticket();break;
   case 'U':
    updateticket();break;
   case 'S':
    searchticket();break;
   case 'E':
    system("cls");
    printf("\n\n\t\t     THANK YOU");
    printf("\n\n\t\tFOR USING OUR BUS SERVICE");
    exit(0);
    break;
   default:
    system("cls");
    printf("WRONG INPUT");
    printf("\nAny key to continue");
    getch();
    system("cls");
  }
 }
}
void addbuses()
{
	int i;
   printf("\n\n\t\t\t\tPlease enter password.:---");
scanf("%d",&i);                                 // password 123;
if (i==123)                           
{
printf ("you can proceed now\n\n");
 FILE *f;
 f=fopen("file.txt","a+");
  system("cls");
  printf("\n Enter Bus number:");
  scanf("%s",&s.busnumber);
  printf("\n\t\t Enter Source:");
  scanf("%s",&s.source);
  printf("\n\t\t\t Enter Destination:");
  scanf("%s",s.destination);
  printf("\n\t\t\t\t Enter Departure time:");
  scanf("%s",s.departuretime);
  printf("\n\t\t\t\t\t Enter Arrival time:");
  scanf("%s",s.arrivaltime);
  printf("\n\t\t\t\t\t\t Enter fare:");
  scanf("%f",&s.amount);
  fwrite(&s,sizeof(s),1,f);
  fflush(stdin);
  system("cls");
  printf("\n\n\t\t\t\tBus successfully added");
getche();
 fclose(f);
}
else
{
	printf("WRONG PASSWORD");
}
}
void listofbuses()
{
 FILE *f;
 int i;
 if((f=fopen("file.txt","r"))==NULL)
  exit(0);
 system("cls");
 printf("Bus Number\tSource\t\tDestination\tArrival Time\tDeparture time\tFare\n");
 for(i=0;i<120;i++)
  printf("-");
 while(fread(&s,sizeof(s),1,f)==1)
 {	
  printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\tRs. %.2f /-",s.busnumber,s.source,s.destination,s.arrivaltime,s.departuretime,s.amount);
 }
 printf("\n");
 for(i=0;i<120;i++)
  printf("-");

fclose(f);
getch();
system("cls");
}
void bookticket()
{	char busnumber[20];
 FILE *f;

 f=fopen("ticket.txt","a+");
  system("cls");
 bus:
  printf("\n Enter Bus number:");
  scanf("%s",&s.busnumber);
  printf("\n Enter Passenger Name:");
  fflush(stdin);
  scanf("%s",&s.pname);
  printf("\n Enter your mobile number:");
  scanf("%s",&s.name);
  printf("\n Enter Source:");
  scanf("%s",&s.source);
  printf("\n Enter Destination:");
  scanf("%s",&s.destination);
  printf("\n Seat to be Alloted:");
  scanf("%s",s.seat);
  fwrite(&s,sizeof(s),1,f);
  fflush(stdin);
  printf("\n Ticket Successfully Booked");
  printf("\n Press ESC key to exit, Any other key to add other Ticket:");
  system("pause");
 fclose(f);
 system("cls");
}
void listofticket()
{
 FILE *f;
 FILE *n;
 int i;
 if((f=fopen("ticket.txt","r"))==NULL)
  exit(0);
 system("cls");
 n=fopen("display.txt","r");
 printf("Bus Number\tPassenger Name\tMobile number\tSource\t\tDestination\tAlloted Seat\tFare\n");
 for(i=0;i<100;i++)
  printf("-");
 while(fread(&s,sizeof(s),1,f)==1)
 {	
  printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\tRs %.2f/-",s.busnumber,s.pname,s.name,s.source,s.destination,s.seat,atof(s.busnumber)*100);
 }
 printf("\n");
 for(i=0;i<100;i++)
  printf("-");
fclose(n);
fclose(f);
getch();
system("cls");
}

void searchticket()
{
 FILE *f;
 char pname[20];
 int flag=1;
 int i;
 f=fopen("ticket.txt","r+");
 if(f==0)
  exit(0);
 fflush(stdin);
 system("cls");
 printf("Enter Passenger name to search in our database\n");
 scanf("%s",&pname);
 while(fread(&s,sizeof(s),1,f)==1)
 {
  if(strcmp(s.pname,pname)==0)
  { system("cls");
   printf(" Record Found ");
   printf("\n");
 for(i=0;i<100;i++)
  printf("-");
  printf("\nBus Number\tPassenger Name\tMobile number\tSource\t\tDestination\tAlloted Seat\tFare\n");
    printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\tRs %.2f/-\n",s.busnumber,s.pname,s.name,s.source,s.destination,s.seat,atof(s.busnumber)*100);
   flag=0;
 for(i=0;i<100;i++)
  printf("-");
  break;
  }
  else if(flag==1)
  { system("cls");
   printf("Requested Ticket Not found in our database");
  }
 }
 getch();
 fclose(f);
 system("cls");
}
void updateticket()
{
 FILE *f;
 
 char pname[20];
 long int size=sizeof(s);
 if((f=fopen("ticket.txt","r+"))==NULL)
  exit(0);
 system("cls");
 printf("Enter Passenger name to modify:\n");
 scanf("%s",&pname);
 fflush(stdin);
 while(fread(&s,sizeof(s),1,f)==1)
 {
  if(strcmp(s.pname,pname)==0)
  {
   system("cls");
   printf("\n Enter bus number:");
   scanf("%s",&s.busnumber);
   printf("\n Enter Passenger name: ");
   fflush(stdin);
   scanf("%s",&s.pname);
   printf("\n Enter your mobile number:");
  scanf("%s",&s.name);
   printf("\n Enter Source:");
  scanf("%s",&s.source);
  printf("\n Enter Destination:");
  scanf("%s",s.destination);
  printf("\n Enter seat number:-");
  scanf("%s",s.seat);
   fseek(f,-size,SEEK_CUR);
   fwrite(&s,sizeof(s),1,f);
   break;
  }
  else
  {
  	printf("\nRequested Ticket Not found in our database");
  	break;
  }
 }
 fclose(f);
 system("cls");
}
void cancelticket()
{
	FILE *f;
	FILE *p;
    char pname[50];
    int found=0;
    p=fopen("ticket.txt","r");
    f=fopen("temp.txt","w+");
    system("cls");
    printf("\nEnter Passenger name to be deleted:");
    scanf("%s",&pname);
    rewind(p);
    while(fread(&s,sizeof(s),1,p)!=0)
    {
    	if(strcmp(s.pname,pname)!=0)
    	{
    		fwrite(&s,sizeof(s),1,f);
    	}
    	printf("\nTICKET DELETED");
    }
	fclose(p);
	fclose(f);
	remove("ticket.txt");
	rename("temp.txt","ticket.txt");
	getch();
	system("cls");
}
