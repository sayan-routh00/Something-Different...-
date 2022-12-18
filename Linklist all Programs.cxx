#include<stdio.h>
#include<alloc.h>

struct record
{
	int id;
	char name[20];
};
typedef struct record RD;

struct node
{
	RD info;
	struct node *next;
};
typedef struct node ND;

void insert_beg(ND**, RD);
void insert_mid(ND**, RD, int);
void insert_end(ND**, RD);
void del_etc(ND**, int);
int count_node(ND*);
ND* search(ND*, int);
void display(ND*);
void rev_disp(ND*);

void main(void)
{
	ND *start, *q;
	RD rec;
	int i, x;
	start = NULL;
	do{
		printf("\n\n 1. Insert at the begining" );
		printf("\n 2. Insert at the middle");
		printf("\n 3. Insert at the end" );
		printf("\n 4. Delete a node" );
		printf("\n 5. Count the number of nodes" );
		printf("\n 6. Search for a particular node" );
		printf("\n 7. Display a particular node");
		printf("\n 8. Display all nodes" );
		printf("\n 9. Display reversly all nodes" );
		printf("\n 0. To Exit" );
		
		printf("\n\n Enter your choice : " );
		scanf("%d", &i);
		
		switch(i)
		{
			case 1 : printf("\n Enter a record to insert");
						   printf("\n ID : ");
						   scanf("%d", &rec.id);
						   fflush(stdin);
						   printf("Name : ");
						   gets(rec.name);
						   insert_beg(&start, rec);
						   break;
			case 2 : printf("\n Enter the ID after which you want to insert : ");
						   scanf("%d", &x);
						   printf("\n Enter a record to insert");
						   printf("\n ID : ");
						   scanf("%d", &rec.id);
						   fflush(stdin);
						   printf("Name : ");
						   gets(rec.name);
						   insert_mid(&start, rec, x);
						   break;
			case 3 : printf("\n Enter a record to insert");
						   printf("\n ID : ");
						   scanf("%d", &rec.id);
						   fflush(stdin);
						   printf("Name : ");
						   gets(rec.name);
						   insert_end(&start, rec);
						   break;
			case 4 : printf("\n Enter the particular ID : ");
						   scanf("%d", &x);
						   del_etc(&start, x);
						   break;
			case 5 : x = count_node(start);
						   printf("\n No. of nodes is %d", x);
						   break;
			case 6 : printf("\n Enter ID : ");
						   scanf("%d", &x);
						   if(search(start, x))
						   	printf("\n Record Found");
						   else 
						   	printf("\n Record Not Found");
						   break;
			case 7 : printf("\n Enter ID : ");
						   scanf("%d", &x);
						   if(search(start, x))
						   	{
						   		q = search(start, x);
						   		printf("\n Your searched record is :	%d	%s", q->info.id, q->info.name);
						   	}
						   else 
						   	printf("\n Record Not Found");
						   break;
			case 8 : display(start);
						   break;
			case 9 : rev_disp(start);
						   break;
			case 0 : printf("\n The End");
						   break;
			default : printf("\n Invalid Choice");
		}
	}while(i != 0);
}

void insert_beg(ND **ptr, RD item)
{
	ND *temp;
	temp = (ND*)malloc(sizeof(ND));
	if(!temp)		/* temp == NULL */
		{
			printf("\n Insufficient Memory");
			return;
		}
		temp->info = item;
		temp->next = *ptr;
		*ptr = temp;
}

void insert_mid(ND **ptr, RD item, int x)
{
	ND *temp, *current;
	temp = (ND*)malloc(sizeof(ND));
	if(!temp)
		{
			printf("\n Insufficient Memory");
			return;
		}
	temp->info = item;
	current = *ptr;
	while(current != NULL)
		{
			if(current->info.id == x)
				break;
			current = current->next;
		}
	if(!current)
		{
			printf("\n ID not found");
			return;
		}
	temp->next = current->next;
	current->next = temp;
}

void insert_end(ND **ptr, RD item)
{
	ND *temp, *current;
	temp = (ND*)malloc(sizeof(ND));
	if(!temp)
		{
			printf("\n Insufficient Memory");
			return;
		}
	temp->info = item;
	temp->next = NULL;
	if(!*ptr)		/* *ptr == NULL */
		{
			*ptr = temp;
			return;
		}
	current = *ptr;
	while(current->next != NULL)
		current = current->next;
	current->next = temp;
}

void del_etc(ND **ptr, int x)
{
	ND *current, *prev;
	prev = current = *ptr;
	while(current != NULL)
		{
			if(current->info.id == x)
				break;
			prev = current;
			current = current->next;
		}
	if(!current)
	{
		printf("\n Void Deletion");
		return;
	}
	if(prev == current)
		*ptr = current->next;
	else
		prev->next = current->next;
	printf("\n Deleted element is :	%d	%s", current->info.id, current->info.name);
	free(current);
}

int count_node(ND *p)
{
	int count = 0;
	while(p != NULL)
	{
		count++;
		p = p->next;
	}
	return(count);
}

ND* search(ND *p, int x)
{
	while(p != NULL)
	{
		if(p->info.id == x)
			return(p);
		p = p->next;
	}
	return(NULL);
}

void display(ND *p)
{
	while(p != NULL)
	{
		printf("\n %d	%s", p->info.id, p->info.name);
		p = p->next;
	}
}

void rev_disp(ND *p)
{
	if(!p)
		return;
	rev_disp(p->next);
	printf("\n %d	%s", p->info.id, p->info.name);
}