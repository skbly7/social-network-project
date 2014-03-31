
#include<conio.h>
#include<stdio.h>

typedef struct member {
	int id;
	int tf,ts,tr;
	char name[10],password[10];
	char dob[11];
	char gender;
	char answer[10];
	struct status *status;
	struct id *req;
	struct id *friend;
	struct member *next;
} member;

typedef struct status {
	char show[160];
	struct status *next;
} status;

typedef struct id {
	int id;
	struct id *next;
} id_struct;

member *top[27];
int id=1001;
struct member *logined;
int run=0;
void initialize();
void main_register();
void main_login();
void insert_register(struct member *,int);
void main_reset();
void dashboard();
void member_stats(struct member *);
void add_status(struct member *);
void show_status(struct member *);
void send_req(struct member *);
void add_req(struct member *,int);
void show_req(struct member *);
struct member * search_by_id(int);
struct member * search_by_name(char []);
void main()
{
	int choice;
	clrscr();
	if(run==0)
	{
		initialize();
		run++;
	}

	do
	{

		flushall();
		//getch();
		clrscr();
		printf("MAIN MENU :\n1. Register\n2. Login\n3. Forget Password\n4. Exit\n\nEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: main_register();
			break;
			case 2: main_login();
			break;
			case 3: main_reset();
			break;
			case 4:
			break;
			default : printf("Wrong chice entered...!!\nPlease try again... :)");
			getch();
			break;
		}
	} while(choice!=4);	
}

void initialize()
{
	int i;
	for(i=0;i<26;i++)
	{
		top[i]=NULL;
	}
}


void main_register()
{
	struct member *new_member;
	int i,sucess;
	clrscr();
	flushall();

	new_member=(member *)malloc(sizeof(member));
	new_member->id=id++;
	printf("WELCOME TO REGISTRATION PAGE \n\n");
	printf("Enter your name :");
	gets(new_member->name);
	//new_member->name=string_up(new_member->name);
	printf("Enter your desired password :");
	gets(new_member->password);
	printf("Enter your DOB (DD/MM/YYYY) :");
	gets(new_member->dob);
	printf("Enter your gender (M/F) :");
	scanf("%c",&new_member->gender);
	flushall();
	printf("Security question in case you forget your password will be :\nWhat is your mother maiden name ?\nEnter your desired answer for it :");
	gets(new_member->answer);
	new_member->ts=0;
	new_member->tf=0;
	new_member->tr=0;
	new_member->next=NULL;
	new_member->status=NULL;
	new_member->req=NULL;
	new_member->friend=NULL;
	sucess=0;
	for(i=65;i<91;i++)
	{       //printf("%c %c\n",i,i+32);
		if(((int)new_member->name[0]==i)||((int)new_member->name[0]==i+32))
		{
			sucess=1;
			insert_register(new_member,i-65);
		}
	}

	if(sucess==0)
	{
		clrscr();
		printf("Hey it seems you entered wrong name....\nPlease take care while entering it, all the best...!!\n\nLets try again... :)");
		free(new_member);
		getch();
	}


}

void insert_register(struct member *new,int i)
{
	struct member *current_top;
	current_top=top[i];

	if(top[i]==NULL)
	{
		top[i]=new;
		//printf("%s %s %d",top[i]->name,top[i]->password,i);

	}
	else
	{
		while(current_top->next!=NULL)
		{
			current_top=current_top->next;
		}
		current_top->next=new;
	}
}

void main_login()
{
	char name[10],password[10];
	int found=1,sucess=0,i,j;
	struct member *temp;
	int login_userr=0;
	clrscr();
	flushall();

	printf("WELCOME TO OUR LOGIN PAGE\n");
	printf("Enter your username :");
	gets(name);
	printf("Enter your password :");
	gets(password);

	for(i=65;i<91;i++)
	{
		if((name[0]==i)||(name[0]==i+32))
		{
			j=i-65;
			sucess=1;
		}
	}

	if(sucess==0)
	{
		clrscr();
		printf("Hey it seems you entered wrong name....\nPlease take care while entering it, all the best...!!\n\nLets try again... :)");
		getch();
	}
	else if(sucess==1)
	{
		sucess=0;
		temp=top[j];
		while(temp!=NULL)
		{
			if(!strcmp(name,temp->name))
			{
				sucess=1;
				if(!strcmp(password,temp->password))
				{
					printf("LOGIN SUCCESSFULL TO YOUR A/C WITH ID : %d",temp->id);
					logined=temp;
					login_userr=1;
					getch();
				}
			}
		temp=temp->next;
		}
	}

	if(sucess==0)
	{
		printf("Sorry, we were unable to find your a/c. Please contact the admin at skbly7@gmail.com");
		getch();
	}
	
	if(login_userr==1)
	{
		dashboard();
	}
	
}


void main_reset()
{
	char name[10],answer[10];
	int found=1,sucess=0,i,j;
	struct member *temp;
	clrscr();
	flushall();
	printf("WELCOME TO OUR PASSWORD RESET PAGE\n");
	printf("Enter your username :");
	gets(name);
	printf("Security question :\nWhat is your mother`s Maiden Name : ");
	gets(answer);
	for(i=65;i<91;i++)
	{
		if((name[0]==i)||(name[0]==i+32))
		{
			j=i-65;
			sucess=1;
		}
	}
	if(sucess==0)
	{
		clrscr();
		printf("Hey it seems you entered wrong name....\nPlease take care while entering it, all the best...!!\n\nLets try again... :)");
		getch();
	}
	else if(sucess==1)
	{
		sucess=0;
		temp=top[j];
		while(temp!=NULL)
		{
			if(!strcmp(name,temp->name))
			{
				sucess=1;
				if(!strcmp(answer,temp->answer))
				{
					clrscr();
					printf("You provided us the correct answer.\nWell Done...!!\n\nPlease save this information at some secure place for future.\nYour password is : %s\nYour account id : %d",temp->password,temp->id);
					getch();
				}
			}
		temp=temp->next;
		}
	}
	if(sucess==0)
	{
		clrscr();
		printf("Sorry, we were unable to find your a/c.\nPlease contact the admin at skbly7@gmail.com for further help...");
		getch();
	}
}

void dashboard()
{
	int choice;
	
	do
	{
		getch();
		clrscr();
		printf("WELCOME %s, TO YOUR DASHBOARD\n\n",logined->name);
		printf("1. Add status\n");
		printf("2. See all your past status\n");
		printf("3. News Feed\n");
		printf("4. View your friends\n");
		printf("5. Add friend\n");
		printf("6. See pending friend request\n");
		printf("7. See your statistics\n");
		printf("8. Logout\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: add_status(logined);
		break;
		case 2: show_status(logined);
		break;
		case 5: send_req(logined);
		break;
		case 6: show_req(logined);
		break;
		case 7: member_stats(logined);
		break;
		default : printf("Wrong choice... :P\nPlease try again...\nThank you.. ");
		break;
		}
	}while(choice!=8);

	main();
}
	

void member_stats(struct member *temp)
{
	clrscr();
	flushall();
	printf("Name				: %s\n",temp->name);
	printf("DOB				: %s\n",temp->dob);
	printf("Gender			: %c\n",temp->gender);
	printf("Total Friends	: %d\n",temp->tf);
	printf("Pending			: %d\n",temp->tr);
	printf("Total Status		: %d\n",temp->ts);
	//getch();
}

void add_status(struct member *temp)
{
	struct status *newr,*add;
	//getch();
	clrscr();
	flushall();
	newr=(status *)malloc(sizeof(status));
	printf("Enter your status : ");
	gets(newr->show);
	newr->next=NULL;
	if(temp->status==NULL)
	{
		temp->status=newr;
	}
	else
	{
	newr->next=temp->status;
	temp->status=newr;
		//add=temp->status;
	 //	while(add->next!=NULL)
	  //	{
	  //		add=add->next;
	    ///	}
	       //	add->next=newr;
	}
	temp->ts++;
	printf("Status added successfully.........");
}

void show_status(struct member *temp)
{
	struct status *skbly7;
	skbly7=temp->status;
	while(skbly7!=NULL)
	{
		printf("%s\n",skbly7->show);
		skbly7=skbly7->next;
	}
	//getch();
}

void send_req(struct member *temp)
{
	struct member *send_to;
	int choice,id;
	char name[10],b;
	clrscr();
	printf("1. Search by Name\n");
	printf("2. Search by ID \n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	if(choice==1)
	{       flushall();
		printf("Enter friend`s name : ");
		gets(name);
		send_to=search_by_name(name);
	}
	else if(choice==2)
	{
		printf("Enter friend`s id : ");
		scanf("%d",&id);
		send_to=search_by_id(id);
		getch();
	}
       //	else {
       //	send_to=
       //	}
	if(choice==1||choice==2)
	{
	if(send_to!=NULL)
	{
		flushall();
		printf("We have found %s (ID : %d )....",send_to->name,send_to->id);
		printf("\nPress 'Y' to confirm sending request......");
		b=getch();
		if(b=='Y'||b=='y')
		add_req(send_to,temp->id);
	}
	}

}

struct member * search_by_name(char name[])
{
	int i,j,sucess;
	struct member *temp;
	for(i=65;i<91;i++)
	{
		if((name[0]==i)||(name[0]==i+32))
		{
			j=i-65;
			sucess=1;
		}
	}
	if(sucess==0)
	{
		clrscr();
		printf("Hey it seems you entered wrong name....\nPlease take care while entering it, all the best...!!\n\nLets try again... :)");
		return NULL;
		//getch();
	}
	else if(sucess==1)
	{ //    printf("%d %c",j,j);
		sucess=0;
		temp=top[j];
		while(temp!=NULL)
		{
			if(!strcmp(name,temp->name))
			{
				flushall();
				//printf("We found %s with userid : %d",temp->name,temp->id);
				//getch();
				return temp;
			}
		temp=temp->next;
		}
	}

	printf("Ohh NO !!!\nNo user with this name found... :(\nTry searching with ID...");
	return NULL;
}


struct member * search_by_id(int id_n)
{
	int j;
	struct member *temp;
	if(id_n>id||id_n<1001)
	{
		printf("Wrong id..!! No user exist with this id...");
		getch();
		return NULL;
	}
	for(j=0;j<26;j++)
	{
		temp=top[j];
		while(temp!=NULL)
		{
			if(id_n==temp->id)
			{
				//printf("We found %s with userid : %d",temp->name,temp->id);
				//getch();
				return temp;
			}
		temp=temp->next;
		}
	}
	printf("Internal script error.. \nPlease report problem to skbly7@gmail.com");
	return NULL;
}

void add_req(struct member *temp,int id)
{
	id_struct *newr;
	//getch();
	clrscr();
	flushall();
	newr=(id_struct *)malloc(sizeof(id_struct));
	newr->id=id;
	newr->next=NULL;
	if(temp->req==NULL)
	{
		temp->req=newr;
	}
	else
	{
	newr->next=temp->req;
	temp->req=newr;
	}
	temp->tr++;
	printf("Request sent successfully.........");
}

void show_req(struct member *temp)
{
	id_struct *reqq;
	member *from;
	int accept;
	clrscr();
	reqq=temp->req;
	while(reqq!=NULL)
	{
		from=search_by_id(reqq->id);
		printf("You have request from %s (ID : %d)\n",from->name,from->id);
		reqq=reqq->next;
	}

	printf("\nEnter id of user whose friend request you want to accept :",&accept);
	accept_req(temp,accept);
}

void accept_req(struct member *temp,int accept)
{
	id_struct *reqq,*reqqq,*new_friend;
	member *from;
	reqq=temp->req;
	reqqq=NULL;
	while(reqq!=NULL)
	{
		if(accept==reqq->id)
		{
			if(reqqq==NULL)
			{
				temp->req=reqq->next;
				if(temp->friend==NULL)
				{
					temp->friend=reqq;
					reqq->next=NULL;
				}
				else
				{
					reqq->next=temp->friend;
					temp->friend=reqq;
				}
			}
			else
			{
				reqqq->next=reqq->next;
				reqq->next=temp->friend;
				temp->friend=reqq;
			}
			printf("Friend Successfully added... :)");
		}
		reqqq=reqq;
		reqq=reqq->next;
	}
	from=search_by_id(accept);
	new_friend=(id_struct *)malloc(sizeof(id_struct));
	new_friend->id=temp->id;
	new_friend->next=from->friend;
	from->friend=new_friend;
}