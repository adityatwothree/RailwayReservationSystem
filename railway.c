# include<stdio.h>
# include<string.h>
#include<stdlib.h>
#include <time.h>
#include <ctype.h>
int ticket_list_size=0,train_list_size=0;
int fare[]={750,600,500};

struct ticket
{
char name[10];
  int phno;
  int age;
  int ticketno;
  int seatno;
  int trainno;
  char gen;
  int status;
  char time[50];
  int fare;
  int class;
}*s;

struct train
{
  char name[40];
  int trainno;
  int reserved;
  int size;
  int seats[90];
  char route[200];
  char time[10];
  int available;
  int startpos;
  int endpos;
}*t;




void menu();
void view();
void reserve();
void form();
void cancel();
void display();
void dates();

int main()
{ //textcolor(RED);
 printf("\n\n******************************************************\n\n");
 printf("\t  WELCOME TO SOUTH WESTERN RAILWAY RESERVATION PORTAL ");
 printf("\n\n******************************************************\n\n");
 FILE *train,*tick;
 tick=fopen("Ticket.txt","r+");
 train=fopen("Trains.txt","r");
 if (train==NULL)
 {
 	printf("Error\n");
 	exit(0);
 }

while(!feof(train))
 	{
 		
 		int pos=train_list_size++;
 		t=realloc(t,train_list_size*sizeof(struct train));
 		fscanf(train,"%d %s %s %s",&t[pos].trainno,t[pos].name,t[pos].time,t[pos].route);
 		//printf("%d %s %s %s\n",t[pos].trainno,t[pos].name,t[pos].time,t[pos].route);
 		t[pos].size=90;
 		t[pos].reserved=0;
 		t[pos].available=0;

 	}




 if(tick!=NULL)
 {

 	while(1)	
	{	char r = fgetc(tick);
      	int k = 0;
      	int chk=0;
      	char *line=NULL;

      	while(r!='\n' && !feof(tick)){
          	line=realloc(line,(k+1)*sizeof(char));
        	line[k++] = r;
        	r = fgetc(tick);
        	chk=1;
      	}
      	if(chk==1)
      	{line[k]='\0';
      	      	
 		int pos=ticket_list_size++;
 		s=realloc(s,ticket_list_size*sizeof(struct ticket));

 		sscanf(line,"%d %d %s %c %d %d %d %d %d %s",&s[pos].ticketno,&s[pos].trainno,s[pos].name,&s[pos].gen,&s[pos].age,&s[pos].phno,&s[pos].seatno,&s[pos].class,&s[pos].fare,s[pos].time);
 		printf("%d %d %s %c %d %d %d %d %d %s\n",s[pos].ticketno,s[pos].trainno,s[pos].name,s[pos].gen,s[pos].age,s[pos].phno,s[pos].seatno,s[pos].class,s[pos].fare,s[pos].time);
 		

 		s[pos].status=1;
 		int l;
 		for (l = 0; l < train_list_size; ++l)
 		{
 			if (t[l].trainno==s[pos].trainno)
 			{
 				t[l].seats[s[pos].seatno-1]=1;
 				t[l].reserved++;
 				break;
 			}
 		}

      	      	}
      	if(feof(tick)){   
          break;
      	}

 		



    	
    }
 	}
 	else
 		tick=fopen("Ticket.txt","w+");

 	

 	//printf("%d\n",train_list_size);

 	fclose(train);
 	fclose(tick);
 


 menu();
 return 1;
}


void viewAllTicket()
{
	int i;
	for (i = 0; i < ticket_list_size ; ++i)
	{
		
		if (s[i].status==1)
		{
			printf("\t%d   %s   %d   %d\n",s[i].trainno,s[i].name,s[i].ticketno,s[i].seatno);
		
		
		}
	}



}







void menu()
{
 int ch;
  int i;
 FILE *file;
 printf("\n\n1.VIEW ALL TRAINS");
 printf("\n\n2.RESERVE A TICKET");
 printf("\n\n3.CANCEL A TICKET");
 printf("\n\n4.VIEW ALL TICKET");
 printf("\n\n5.EXIT");
 printf("\n\nEnter your choice(1,2,3,4,5)\n--");
 scanf("%d",&ch);
 printf("\n\n*****************************************************\n\n");;
 switch(ch)
 { 
 case 1:view();
 menu();
 break;
 case 2:reserve(); 
 menu();
 break;
 case 3:cancel();
 menu();
 break;
 case 4:
 viewAllTicket();
 menu();
 break;
 case 5:
 file=fopen("Ticket.txt","w+");
 for (i = 0; i < ticket_list_size; ++i)
 {	
 	if(s[i].status==1)
 	{	
 			fprintf(file, "%d %d %s %c %d %d %d %d %d %s\n",s[i].ticketno,s[i].trainno,s[i].name,s[i].gen,s[i].age,s[i].phno,s[i].seatno,s[i].class,s[i].fare,s[i].time);

 	}
 }
 exit(0);
 } 
}



void view()
{ 
 printf("CODE         NAME            TIMINGS        ROUTE\n\n");
 int i;
 for(i=0;i<train_list_size;i++)
 	printf("%d\t%s\t%s\t\t%s\n",t[i].trainno,t[i].name,t[i].time,t[i].route);
 printf("\n\n*****************************************************\n\n");
 return; 
}
void display(int pos)
{
  printf("\n\tTICKET DETAILS ARE \n");
   printf("\n\n*****************************************************\n\n");
   printf("**\tName-- %s                                         \n",s[pos].name );
   printf("**\tAge-- %d                                       \n",s[pos].age );
   printf("**\tGender-- %c                                       \n",s[pos].gen );
   printf("**\tPhone number-- %d                                 \n",s[pos].phno );
   printf("**\tTrain Number-- %d                                  \n",s[pos].trainno );
   printf("**\tSeat Number-- %d                                  \n",s[pos].seatno );
   printf("**\tTicket Number-- %d                                \n",s[pos].ticketno );
   printf("**\tClass-- %d                                  \n",s[pos].class );
   printf("**\tTotal Fare-- %d                                  \n",s[pos].fare );
   printf("**\tTime of Booking-- %s",s[pos].time);

   
   printf("\n******************************************************\n");
}

void replace(char *string, char original, char replacement) {
    int n=strlen(string),i;
    for (i = 0; i < n; ++i)
    {
    	if(string[i]==original)
    		string[i]=replacement;
    }
    
}


void form(int trainpos,int class)
{

 int pos=ticket_list_size++;
 s=realloc(s,(ticket_list_size+1)*sizeof(struct ticket));

 
 printf("\n\n****************************************************\n\n");
 printf("\n\tEnter Passenger Details\n  ");

 printf("\nEnter the Name\n--");
 scanf("%s",s[pos].name);
 char c;
 gend:
 printf("\nEnter your gender\n--");
 scanf("%c",&c);

 c=toupper(c);

 if (c!='M' && c!='F' && c!='O')
 {
 	printf("Please enter M,F or O\n");
 	goto gend;
 }
 s[pos].gen=c;

 printf("\nEnter the Phone Number\n--");
 scanf("%d",&s[pos].phno);

 printf("\nEnter the Age\n--");
 scanf("%d",&s[pos].age);
 int j;
 for(j=0;j<t[trainpos].size;j++)
 {
 	if(t[trainpos].seats[j]!=1)
 	{	
 		s[pos].seatno=j+1;
 		t[trainpos].seats[j]=1;
 		t[trainpos].reserved++;
 		break;
 	}
 }
 s[pos].status=1;
 s[pos].ticketno=t[trainpos].trainno*100+s[pos].seatno;
 s[pos].trainno=t[trainpos].trainno;
 s[pos].class=class;
 time_t tm= time(NULL);
 strcpy(s[pos].time,ctime(&tm));
 replace(s[pos].time,' ','-');
 int stationcounter=0,strt,end;
 if(t[trainpos].startpos<t[trainpos].endpos)
 	{strt=t[trainpos].startpos;
 	end=t[trainpos].endpos;
 	}
 else
 	{end=t[trainpos].startpos;
 	strt=t[trainpos].endpos;
 	}
 for (j = strt-1; j <end; ++j)
 {
 	if(t[trainpos].route[j]=='-')
 		stationcounter++;
 }
 s[pos].fare=stationcounter*fare[class-1];
 for (j = 0; j < train_list_size; ++j)
 {
 	t[trainpos].available=0;
 }
 printf("\n\n**************************************************************\n\n");
 printf("\tYOUR TICKET HAS BEEN CONFIRMED YOUR TICKET NUMBER ");
 printf("\n\n**************************************************************\n\n");
 display(pos);
 return;
}





int search(int pos,char *str)
{
	int i,n1=strlen(t[pos].route),n2=strlen(str);
	


	for(i=0;i<=n1-n2;i++)
	{
		int j;

		for (j = 0; j < n2; j++)
		{
			
			if(tolower(str[j])!=tolower(t[pos].route[i+j]))
				break;
		}
		if(j==n2)
			return i;

	}
	return -1;




}







 
void reserve()
{
 int i,code,class,found=0;
  char start[50],stop[50];
  printf("\nEnter the boarding station name\n--");
  scanf("%s",start);
  printf("\nEnter the destination station name\n--");
  scanf("%s",stop);
  printf("\n\nAvailable Trains\n");
  printf("\nCODE         NAME            TIMINGS        ROUTE\n\n");
  for(i=0;i<train_list_size;i++)
  {
  	int startpos=search(i,start)+1,endpos=search(i,stop)+1;
  	if(startpos && endpos)
  	{	printf("%d\t%s\t%s\t%s\n",t[i].trainno,t[i].name,t[i].time,t[i].route);
  		t[i].available=1;
  		t[i].startpos=startpos;
  		t[i].endpos=endpos;
  		found=1;
  	}
  }
  if(!found)
  {
  	printf("SORRY NO TRAINS ARE AVAILABLE FOR THIS ROUTE\n");
  	return;
  }
  printf("\nEnter the train code\n--");
  scanf("%d",&code);
  int trainpos,check=0;
  for (i = 0; i < train_list_size; ++i)
  {
  	if(t[i].trainno==code && t[i].available)
  		{
  			trainpos=i;
  			check=1;
  			break;
  		}
  }
  if(t[trainpos].reserved<t[trainpos].size){
  printf("\n\n******************************************************\n\n");
  if(check)
  { here:
   printf("\n1.First class\n");
   printf("\n2.Second class\n");
   printf("\n3.Sleeper class\n");
   printf("\nEnter the Class\n--");
   scanf("%d",&class);
   printf("\n\n******************************************************\n\n");
   if(class==1 || class==2 || class == 3)
   {
    form(trainpos,class);
    menu();
   }
   else
   { 
    goto here;
   }
   return;
  }
  else
  printf("\nWARNING!YOU HAVE ENTERED THE WRONG CODE\n");
 }
 else printf("Seats not available\n");
 printf("\n\n******************************************************\n\n");
}

void cancel()
{
 int ticket;
 char ch;
 printf("\nEnter the Ticket Number\n--");
 scanf("%d",&ticket);
 for (int i = 0; i < ticket_list_size; ++i)
 {
 	if(ticket==s[i].ticketno)
 {    
 display(i);
 int j;
 s[i].status=0;
 for(j=0;j<train_list_size;j++)
 {
 	if(t[j].trainno==s[i].trainno)
 		t[j].seats[s[i].seatno-1]=0;
 		t[j].reserved--;
 }
 printf("\tYOUR TICKET HAS BEEN CANCELED");
 printf("\n\n******************************************************\n\n");
 
 return; 
 }
 }
 
  printf("\nTicket Number is Invalid\n");
  menu();

}
