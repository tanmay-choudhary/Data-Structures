#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int info;
	struct node *link;
};
struct node *create_list1(struct node *last);
void display1(struct node *last);
struct node *addtoempty1(struct node *last,int data);
struct node *addatbeg1(struct node *last,int data);
struct node *addatend1(struct node *last,int data);
struct node *addafter1(struct node *last,int data,int item);
struct node *del1(struct node *last,int data);
circular_list()
{
	int choice,data,item;
	struct node	*last=NULL;
	
	while(1)
	{
		system("cls");
		printf("1.Create List\n");
		printf("2.display1\n");
		printf("3.Add to empty list\n");
		printf("4.Add at beginning\n");
		printf("5.Add at end\n");
		printf("6.Add after \n");
		printf("7.Delete\n");
		printf("8.Quit\n");
		printf("9.back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			last=create_list1(last);
			break;
		 case 2:
			display1(last);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addtoempty1(last,data);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addatbeg1(last,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addatend1(last,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert3 : ");
			scanf("%d",&item);
			last=addafter1(last,data,item);
			break;
		 case 7:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			last=del1(last,data);
			break;
		 case 8:
		 	exit(0);
		case 9:
			return linked_list();
		 default:
			printf("Wrong choice\n");
		}
	}
}

struct node *create_list1(struct node *last)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	last=NULL;
	if(n==0)
		return last;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	last=addtoempty1(last,data);
			
	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		last=addatend1(last,data);	
	}
	printf("list is created successfully\n");
	system("PAUSE");
	return last;
}

struct node *addtoempty1(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	last=tmp;
	last->link=last;
	return last;
}

struct node *addatbeg1(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	return last;
}

struct node *addatend1(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
	return last;
}

struct node *addafter1(struct node *last,int data,int item)
{
	struct node *tmp,*p;
	p=last->link;
	do
	{
		if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			if(p==last)
				last=tmp;
			return last;
		}
		p=p->link;
	}while(p!=last->link);
	printf("%d not present in the list\n",item);
	return last;
}

struct node *del1(struct node *last,int data)
{
	struct node *tmp,*p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return last;
	}

	if(last->link==last && last->info==data)  
	{
		tmp=last;
		last=NULL;
		free(tmp);
		return last;
	}
	
	if(last->link->info==data)    
	{
		tmp=last->link;
		last->link=tmp->link;
		free(tmp);
		return last;
	}
	
	p=last->link;
	while(p->link!=last)
	{
		if(p->link->info==data)     
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return last;
		}
		p=p->link;
	}
	
	if(last->info==data)    
	{
		tmp=last;
		p->link=last->link;
		last=p;
		free(tmp);
		return last;
	}
	printf("Element %d not found\n",data);
	return last;
}

void display1(struct node *last)
{
	struct node *p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=last->link;
	do 
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=last->link);
	system("PAUSE");
	printf("\n");
}
//DLL

struct node *create_list2(struct node *start);
void display2(struct node *start);
struct node *addtoempty2(struct node *start,int data);
struct node *addatbeg2(struct node *start,int data);
struct node *addatend2(struct node *start,int data);
struct node *addafter2(struct node *start,int data,int item);
struct node *addbefore2(struct node *start,int data,int item);
struct node *del3(struct node *start,int data);
struct node *reverse2(struct node *start);

doubly_list()
{
	int choice,data,item;
	struct node *start=NULL;
	while(1)
	{
		printf("1.Create List\n");
		printf("2.display3\n");
		printf("3.Add to empty list\n");
		printf("4.Add at beginning\n");
		printf("5.Add at end\n");
		printf("6.Add after\n");
		printf("7.Add before\n");
		printf("8.Delete\n");
		printf("9.Reverse\n");
		printf("10.Quit\n");
		printf("11.back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			start=create_list2(start);
			break;
		 case 2:
			display2(start);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addtoempty2(start,data);
			break;
		 case 4:
	        printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatbeg2(start,data);
			break;
		 case 5: 
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatend2(start,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert3 : ");
			scanf("%d",&item);
			start=addafter2(start,data,item);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert3 : ");
			scanf("%d",&item);
			start=addbefore2(start,data,item);
			break;
		 case 8:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			start=del3(start,data);
	   		break;
		 case 9:
		 	start=reverse2(start);
			break;
		 case 10:
			exit(0);
		case 11:
			return linked_list();
		 default:
			printf("Wrong choice\n");
	}
   }
}

struct node *create_list2(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=addtoempty2(start,data);
		
	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=addatend2(start,data);	
	}
	return start;
}

void display2(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n");
}

struct node *addtoempty2(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->link=NULL;
	start=tmp;
	return start;
}

struct node *addatbeg2(struct node *start,int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->link=start;
	start->prev=tmp;
	start=tmp;
	return start;
}

struct node *addatend2(struct node *start,int data)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	tmp->prev=p;
	return start;
}

struct node *addafter2(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp->prev=p;
			tmp->link=p->link;
			if(p->link!=NULL) 
				p->link->prev=tmp;
			p->link=tmp;
			return start;	
		}
		p=p->link;
	}
	printf("%d not present in the list\n\n",item);
	return start;
}

struct node *addbefore2(struct node *start,int data,int item)
{
	struct node *tmp,*q;
	if(start==NULL )
	{
		printf("List is empty\n");
		return start;
	}
	if(start->info==item)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->prev=NULL;
		tmp->link=start;
		start->prev=tmp;
		start=tmp;
		return start;
	}
	q=start;
	while(q!=NULL)
	{
		if(q->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->prev=q->prev;
			tmp->link = q;
			q->prev->link=tmp;
			q->prev=tmp;
			return start;
		}	
		q=q->link;
	}
	printf("%d not present in the list\n",item);
	return start;
}		

struct node *del3(struct node *start,int data)
{
	struct node  *tmp;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->link==NULL)	
		if(start->info==data) 
		{
			tmp=start;
			start=NULL;
			free(tmp);
			return start;
		}
		else
		{
			printf("Element %d not found\n",data);
			return start;
		}
		if(start->info==data)
	{
		tmp=start;
		start=start->link;  
		start->prev=NULL;
		free(tmp);
		return start;
	}
	
	tmp=start->link;
	while(tmp->link!=NULL )
	{
		if(tmp->info==data)     
		{
			tmp->prev->link=tmp->link;
			tmp->link->prev=tmp->prev;
			free(tmp);
			return start;
		}
		tmp=tmp->link;
	}
	
	if(tmp->info==data)
	{
		tmp->prev->link=NULL;
		free(tmp);
		return start;
	}
	printf("Element %d not found\n",data);
	return start;
}

struct node *reverse2(struct node *start)
{
	struct node *p1,*p2;
	p1=start;
	p2=p1->link;
	p1->link=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->link;
		p2->link=p1;
		p1=p2;
		p2=p2->prev; 
	}
	start=p1;
	printf("List reversed\n");
	return start;
}
//SLL
struct node *create_list3(struct node *start);
void display3(struct node *start);
void count(struct node *start);
void search_list(struct node *start,int data);
struct node *addatbeg3(struct node *start,int data);
struct node *addatend3(struct node *start,int data);
struct node *addafter3(struct node *start,int data,int item);
struct node *addbefore3(struct node *start,int data,int item );
struct node *addatpos3(struct node *start,int data,int pos);
struct node *del3_sll(struct node *start,int data);
struct node *reverse3(struct node *start);

singly_list()
{
	struct node *start=NULL;	
	int choice,data,item,pos;
		
	do
	{
		system("cls");
		printf("1.Create List\n");
		printf("2.display2\n");
		printf("3.Count\n");
		printf("4.Search\n");
		printf("5.Add to empty list / Add at beginning\n");
		printf("6.Add at end\n");
		printf("7.Add after node\n");
		printf("8.Add before node\n");
		printf("9.Add at position\n");
		printf("10.Delete\n");
		printf("11.reverse2\n");
		printf("12.Quit\n\n");
		printf("13.back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			start=create_list3(start);
			break;
		 case 2:
			display3(start);
			break;
		 case 3:
			count(start);
			break;
		 case 4:
			printf("Enter the element to be searched : ");
			scanf("%d",&data);
			search_list(start,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatbeg3(start,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatend3(start,data);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert3 : ");
			scanf("%d",&item);
			start=addafter3(start,data,item);
			break;
		 case 8:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert3 : ");
			scanf("%d",&item);
			start=addbefore3(start,data,item);
			break;
		 case 9:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the position at which to insert3 : ");
			scanf("%d",&pos);
			start=addatpos3(start,data,pos);
			break;
		 case 10:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			start=del3_sll(start, data);	
			break;
		 case 11:
			start=reverse3(start);
			break;
		 case 12:
			 exit(1);
		 case 13:
		 	  return linked_list();
		 default:
			 printf("Wrong choice\n");
		}
	}while(choice!=12);
}

struct node *create_list3(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;

	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=addatbeg3(start,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=addatend3(start,data);	
	}
	printf("list created\n");
	system("PAUSE");
	return start;
}

void display3(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	system("PAUSE");
	printf("\n\n");
}

void count(struct node *start)
{
	struct node *p;
	int cnt=0;
	p=start;
	while(p!=NULL)
	{
		p=p->link;
		cnt++;
	}
	printf("Number of elements are %d\n",cnt);
}

void search_list(struct node *start,int item)
{
	struct node *p=start;
	int pos=1;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			printf("Item %d found at position %d\n",item,pos);
			return;
		}
		p=p->link;
		pos++;
	}
	printf("Item %d not found in list\n",item);
}

struct node *addatbeg3(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}

struct node *addatend3(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}

struct node *addafter3(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("%d not present in the list\n",item);
	return start;
}

struct node *addbefore3(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	if(start==NULL )
	{
		printf("List is empty\n");
		return start;
	}	
	
	if(item==start->info)
	{
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->link=start;
		start=tmp;
		return start;
	}	
	p=start;
	while(p->link!=NULL) 
	{
		if(p->link->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("%d not present in the list\n",item);
	return start;
}

struct node *addatpos3(struct node *start,int data,int pos)
{
	struct node *tmp,*p;
	int i;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	if(pos==1)
	{
		tmp->link=start; 
		start=tmp;
		return start;
	}
	p=start;
	for(i=1; i<pos-1 && p!=NULL; i++)
		p=p->link;
	if(p==NULL)
		printf("There are less than %d elements\n",pos);
	else
	{
		tmp->link=p->link;
		p->link=tmp;
	}	
	return start;
}

struct node *del3_sll(struct node *start,int data)
{
	struct node *tmp,*p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	
	if(start->info==data)
	{
		tmp=start;
		start=start->link;  
		free(tmp);
		return start;
	}
	
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==data)   
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return start;
		}
		p=p->link;
	}
	printf("Element %d not found\n",data);
	return start;
}

struct node *reverse3(struct node *start)
{
	struct node *prev, *ptr, *link;
	prev=NULL;
   	ptr=start;
	while(ptr!=NULL)
	{
		link=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=link;
	}
	start=prev;
	return start;
}
linked_list()
{
	int choice;
	system("cls");
	system("color 13");
	printf("HIT '1' FOR SLL\n");
	printf("HIT '2' FOR DLL\n");
	printf("HIT '3' FOR CLL\n");
	printf("HIT '4' FOR MAIN MENU\n");
	printf("HIT '5' FOR EXIT\n");
	
	while(1)
	{
		printf("Enter the choice:- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				singly_list();
				break;
			case 2:
				doubly_list();
				break;
			case 3:
				circular_list();
				break;
			case 4:
				return main();
				break;
			case 5:
				exit(0);
			
			default :
				 printf("Wrong choice\n");
		}
	}
	
}
