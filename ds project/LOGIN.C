#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <ctype.h>
#include <string.h>




void loaddatabase(void);
void menu_exit(void);
void add_user(void);
void load_users(void);
void stats(void);
void login(void);
void login_main()
{
int choice;
clrscr();
load_users();
clrscr();

printf("********* MAIN MENU *********\n\n1. Login\n2. Register\n3. Stats\n4. Exit\n\nEnter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 : login();
	break;
case 2 : add_user();
	login_main();
	break;
case 3 : stats();
	login_main();
	break;
case 4 : break;
}
getch();

//loaddatabase();
//menu_exit();

}

void stats()
{
clrscr();
printf("We have %d members registered.\nOur Newest member is %s",total_entry,end->username);
}

void login()
{
char username[10],password[10];
int found=0;
flushall();
printf("Enter username : ");
gets(username);
temp=head;
	while(temp!=NULL)
	{
	if(strcmp(temp->username,username)==0)
	{
	found=1;
	break;
	}
	temp=temp->next;
	}

while(found==0)
{
clrscr();
printf("Sorry no such username found\nPlease try again...\n\n");
printf("Enter username : ");
gets(username);
found=0;
temp=head;
	while(temp!=NULL)
	{
	if(strcmp(temp->username,username)==0)
	{
	found=1;
	break;
	}
	temp=temp->next;
	}
	if(strcmp(username,"exit")==0)
	found=1;
}
printf("Enter password : ");
gets(password);

if(strcmp(temp->password,password)==0)
{
printf("Successfully logged in...!!");
strcpy(login_user,username);
}
else if ( !(strcmp(username,"exit")) && !(strcmp(password,"exit")))
printf("We understand your problem.. Taking you to main page.. :)");
else
printf("Wrong username/password combination");

}

void add_user()
{
char username[10],pass[10],sex;
int error=0;
FILE *add;
clrscr();
add=fopen("users.txt","a");
if(add==NULL)
printf("Error in loading database...");
else
{
flushall();
printf("Enter your desired username : ");
gets(username);
temp=head;
	while(temp!=NULL)
	{
	if(strcmp(temp->username,username)==0)
	error=1;
	temp=temp->next;
	}

while(strlen(username)>=10||error==1)
{
clrscr();
printf("Sorry your username cant be more than 9 letters\nPlease try again...\n\n");
printf("Enter your desired username : ");
gets(username);
error=0;
temp=head;
	while(temp!=NULL)
	{
	if(strcmp(temp->username,username)==0)
	error=1;
	temp=temp->next;
	}
}
printf("Enter your desired password : ");
gets(pass);
while(strlen(pass)>=10)
{
printf("Sorry your password cant be more than 9 letters\nPlease try again...\n\n");
printf("Enter your desired password : ");
gets(pass);
}

printf("Enter your sex (M/F) : ");
scanf("%c",&sex);


fprintf(add,"%s\t%s\t%c\n",username,pass,sex);
}
fclose(add);
}

void load_users(void)
{
int count,nofilen,dbfilecount=0;
char username[10],password[10];
FILE *f1;
head=NULL;
end=NULL;
     flushall();
     f1 = fopen ("users.txt","r");
     if (f1==NULL)
     {
	fprintf(stderr,"There was an error reading your database file!");
	getch();
     }
     else
     {
		count=0;
		head=NULL;
		end=NULL;

		while (!feof(f1))
		{
		temp=(member *)malloc(sizeof(member));
		fscanf(f1,"%s\t%s\t%c\n",temp->username,temp->password,temp->sex);
		temp->next=NULL;

		if(head==NULL)
		{
		head=temp;
		end=temp;
		}
		else
		{
		end->next=temp;
		end=temp;
		}
		count++;
	  }
	  printf("Database successfully loaded! Records count : %d",count);
	  total_entry = count;
	  getch();
	  }
     fclose(f1);
}

void loaddatabase(void)
{
int count,nofilen,dbfilecount=0;
char finphone[80];
char finroom[80];
char dbload[20];
int error_junk;

long int l_finphone;
int i_finroom;

FILE *f1;
     printf("Enter the filename of the database: ");
	 printf("Example: c:\\hostel.txt or c:\\flat.txt");
     gets(dbload);
     flushall();
     f1 = fopen (dbload,"r");
     if (f1==NULL)
     {
	fprintf(stderr,"There was an error reading your database file!");
	strcpy(dbload, "DATABASE ERROR...");
	getch();
     }
     else
     {

		count=0;
		while (!feof(f1))
	    {
		fscanf(f1,"%s\t%s\n",&finroom,&finphone);
	     i_finroom = atoi(finroom);
	     l_finphone = atol(finphone);
		room[count] = i_finroom;
		phone[count] = l_finphone;
		count++;
	  }
	  printf("Database %s, was successfully loaded! Records no : %d",dbload,count);
	  getch();
	  total_entry = count;

	  }

     fclose(f1);
}
