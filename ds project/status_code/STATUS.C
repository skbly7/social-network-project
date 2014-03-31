
typedef struct status_main
{
char name[10];
int count;
struct status_single *status;
struct status_main *next;
}status;

typedef struct status_single
{
char status[160];
struct status_single *next;
}status_single;

status *status_head,*status_end,*status_temp;
status_single *status_single_head,*status_single_temp,*status_single_end;

void save_db_file_status(void);
void add_status(char []);
void load_status(void);
void show_specific_status(char a[]);
void show_all_status_all(void);
void show_specific_user_status_new(char []);
void show_specific_user_status_all(char []);
void toupper_string(char *);

int status_main()
{
int choice;
char name[10];
load_status();
clrscr();

strcpy(name,"SHIVAM");
printf("********* MAIN MENU *********\n\n1. Add status\n2. Show latest status of a user \n3. Show all status of specific user \n4. Show all status of all users\n5. Exit\n\nEnter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 : add_status(name);
	break;
case 2 :show_specific_user_status_new(name);
	break;
case 3 :show_specific_user_status_all(name);
	break;
case 4 : show_all_status_all();
	break;
case 5 : return 0;

default : break;
}


if(choice!=5)
{
getch();
save_db_file_status();
main();
}

return 1;
}

void save_db_file_status(void)
{
char name[10],status[160];

FILE *f1;
     flushall();
     f1=fopen("STATUS/STATUS.TXT","w");
     if (f1==NULL)
     {
	fprintf(stdout,"There was an error reading your status database file!");
	getch();
     }
     else
     {
		status_temp=status_head;
		while (status_temp!=NULL)
		{
		fprintf(f1,"%s\n%d\n",status_temp->name,status_temp->count);
		status_single_temp=status_temp->status;

		for(i=0;i<status_temp->count;i++)
		{
		//string_write(f1,status_single_temp->status);
		fprintf(f1,"%s\n",status_single_temp->status);
		status_single_temp=status_single_temp->next;
		}
		status_temp=status_temp->next;
		}
	 //printf("FILE WRITTEN SUCCESSFULLLLLLLLLY........ :)");
	 // getch();
     }
     fclose(f1);
}

void toupper_string(char *s)
{
      while(*s!='\0')
      {
	 if (islower(*s))
	      *s=toupper(*s);
       }

}

void add_status(char name[])
{
int error=1;
char status_new[160];
//toupper_string(name);
status_temp=status_head;
while(status_temp!=NULL)
{
	if(strcmp(status_temp->name,name)==0)
	{
	flushall();
	printf("Enter your status : ");
	gets(status_new);
	puts(status_new);
	status_single_temp=(status_single *)malloc(sizeof(status_single));
	strcpy(status_single_temp->status,status_new);
	error=0;
	status_single_temp->next=status_temp->status;
	status_temp->status=status_single_temp;
	status_temp->count++;
	}
status_temp=status_temp->next;
}

if(error)
printf("Check your username please....");
}

void string_write(FILE *fp,char a[])
{
i=0;
while(a[i]!='\0')
{
fprintf(fp,"%c",a[i]);
i++;
}
fprintf(fp,"\n");
}

void load_status(void)
{
char name[10],status[160];

FILE *f1;
     flushall();
     f1 = fopen ("STATUS/STATUS.TXT","r");
	 if (f1==NULL)
     {
	fprintf(stderr,"There was an error reading your status database file!");
	getch();
     }
     else
     {
		status_head=NULL;
		status_end=NULL;

		while (!feof(f1))
		{
		status_temp=(struct status_main *)malloc(sizeof(struct status_main));
		fscanf(f1,"%s\n",status_temp->name);
		fscanf(f1,"%d\n",&status_temp->count);
		status_temp->next=NULL;
		status_single_head=NULL;
		status_single_end=NULL;

		for(i=0;i<status_temp->count;i++)
		{
			status_single_temp=(status_single *)malloc(sizeof(struct status_single));
			fscanf(f1,"%s\n",status_single_temp->status);
			status_single_temp->next=NULL;
			if(status_single_head==NULL)
			{
			status_single_head=status_single_temp;
			status_single_end=status_single_temp;
			}
			else
			{
			status_single_end->next=status_single_temp;
			status_single_end=status_single_temp;
			}

		}

		status_temp->status=status_single_head;
		if(status_head==NULL)
		{
		status_head=status_temp;
		status_end=status_temp;
		}
		else
		{
		status_end->next=status_temp;
		status_end=status_temp;
		}


	  }
	  printf("Status database successfully loaded!!");
	  getch();
	  }
     fclose(f1);
}

void show_specific_user_status_new(char name[])
{
//toupper_string(name);
status_temp=status_head;
while(status_temp!=NULL)
{
if(!strcmp(status_temp->name,name))
printf("%s says....\n%s\n\n",status_temp->name,status_temp->status->status);
status_temp=status_temp->next;
}
}

void show_specific_user_status_all(char name[])
{
//toupper_string(name);
status_temp=status_head;
while(status_temp!=NULL)
{
if(!strcmp(status_temp->name,name))
{
	printf("\n\n%s\nhas total %d status..",status_temp->name,status_temp->count);
	status_single_temp=status_temp->status;
	while(status_single_temp!=NULL)
	{
	printf("%s\n",status_single_temp->status);
	status_single_temp=status_single_temp->next;
	}
}


status_temp=status_temp->next;
}



}



void show_all_status_all(void)
{


char name[10],status[160];

		status_temp=status_head;
		while (status_temp!=NULL)
		{
		printf("\n\n%s\nhas total %d status..",status_temp->name,status_temp->count);
		status_single_temp=status_temp->status;
		while(status_single_temp!=NULL)
		{
		printf("%s\n",status_single_temp->status);
		status_single_temp=status_single_temp->next;
		}
		status_temp=status_temp->next;
		}
}

