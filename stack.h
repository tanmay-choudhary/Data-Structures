
int stack_arr[MAX];
int top = -1;

void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();

array_stack()
{
	int choice,item;
	while(1)
	{
		system("cls");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display the top element\n");
		printf("4.Display all stack elements\n");
		printf("5.Quit\n");
		printf("6.back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1 :
			printf("Enter the item to be pushed : ");
			scanf("%d",&item);
			push(item);
			printf("element is pushed\n");
			system("PAUSE");
			break;
		 case 2:
			item = pop();
			printf("Popped item is : %d\n",item );
			system("PAUSE");
			break;
		 case 3:
			printf("Item at the top is : %d\n", peek() );
			system("PAUSE");
			break;
		 case 4:
			display();
			system("PAUSE");
			break;
		 case 5:
		 	exit(0);
		case 6:
			return stack_driver();
		 default:
			printf("Wrong choice\n");
			system("PAUSE");
		}
	}
}

void push(int item)
{
	if( isFull() )
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top+1;
	stack_arr[top] = item;
}

int pop()
{
	int item;
	if( isEmpty() )
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	item = stack_arr[top];
	top = top-1;
	return item;
}

int peek()
{
	if( isEmpty() )
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return stack_arr[top];
}

int isEmpty()
{
	if( top == -1 )
		return 1;
	else
		return 0;
}

int isFull()
{
	if( top == MAX-1 )
		return 1;
	else
		return 0;
}

void display()
{
	int i;
	if( isEmpty() )
	{
		printf("Stack is empty\n");
		return;
	}
    printf("Stack elements :\n\n");
	for(i=top;i>=0;i--)
		printf(" %d\n", stack_arr[i] );
	printf("\n");
}
///////////////////////**************************************************************************************///////////////


struct stack_node
{
	int info;
	struct stack_node *link;
}*top_list=NULL;

void list_push(int item);
int list_pop();
int list_peek();
int isEmpty2();
void dispstack_list();

stack_list()
{
	int choice,item;
	while(1)
	{      	system("cls");
		printf("1.list_push\n");
		printf("2.list_pop\n");
		printf("3.dispstack_list item at the top_list\n");
		printf("4.dispstack_list all items of the stack\n");
		printf("5.Quit\n");
		printf("6.back\n");
		printf("Enter your choice : ") ;
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			printf("Enter the item to be pushed : ");
			scanf("%d",&item);
			list_push(item);
			printf("element is pushed");
			system("PAUSE");
			break;
		case 2:
			item=list_pop();
			printf("Popped item is : %d\n",item);
			system("PAUSE");
			break;
		case 3:
			printf("Item at the top_list is %d\n",list_peek());
			system("PAUSE");
			break;
		case 4:
			dispstack_list();
			system("PAUSE");
			break;
		case 5:
		    exit(1);
		case 6:
			return stack_driver();
		default :
			printf("Wrong choice\n");
			system("PAUSE");
		}
	}
}

void list_push(int item)
{
	struct stack_node *tmp;
	tmp=(struct stack_node *)malloc(sizeof(struct stack_node));
	if(tmp==NULL)
	{
		printf("Stack Overflow\n");
		return;
	}
	tmp->info=item;
	tmp->link=top_list;
	top_list=tmp;
}

int list_pop()
{
	struct stack_node *tmp;
	int item;
	if( isEmpty2() )
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	tmp=top_list;
	item=tmp->info;
	top_list=top_list->link;
	free(tmp);
	return item;
}

int list_peek()
{
	if( isEmpty2() )
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return top_list->info;
}

int isEmpty2()
{
	if(top_list == NULL)
		return 1;
	else
		return 0;
}


void dispstack_list()
{       
	struct stack_node *ptr;
	ptr=top_list;
	if(isEmpty2())
	{	
		printf("Stack is empty\n");
		return;
	}
	printf("Stack elements :\n\n");
	while(ptr!=NULL)
	{
		printf(" %d\n",ptr->info);
		ptr=ptr->link;
	}
	printf("\n");
}
///////////////////////////////////*****************************************************//////////////////////////////////

int push5(int);
int push6(int);
int pop5();
int pop6();
int display5(int);
int display6(int);
int isempty5();
int isempty6();
int isfull5();
int isfull6();
int top5=-1;
int max=10;
int top6=10;
int a[10];
stacks2()
{
    int k,item;
while(1)
{
	system("cls");
printf("1.push5 in stack 1\n2.pop5 in stack 1\n3.display5 stack 1\n4.push5 in stack 2.\n5.pop5 in stack 2\n6.display5 stack 2\n7.exit\n");
printf("8.back\n");
scanf("%d",&k);
switch(k)
{
case 1:
printf("enter the element\n");
scanf("%d",&item);
push5(item);
printf("element is pushed");
system("PAUSE");
break;

case 2:
    if(isempty5())
    {
        printf("stack is empty\n");
        break;
    }
printf("element removed is %d\n",pop5());
system("PAUSE");
break;

case 3:

display5(top5);
system("PAUSE");
break;

case 4:

printf("enter the element\n");
scanf("%d",&item);
push6(item);
printf("element pushed\n");
system("PAUSE");
break;

case 5:

 if(isempty6())
    {
        printf("stack is empty\n");
        break;
    }
printf("element removed is %d\n",pop6());
system("PAUSE");
break;
case 6:

display6(top6);
system("PAUSE");
break;

case 7:
   exit(1);
case 8:
	return stack_driver();
default :
	printf("choice not available**TRY AGAIN**\n");
   
}
}
}
int push5(int item)
{
if(!isfull5())
{
top5++;
a[top5]=item;
return 0;
}
else
{
printf("stack1 is full\n");
return 0;
}
}
int isfull5()
{
if(top5==top6-1)
return 1;
else
return 0;
}
int isempty5()
{
if(top5==-1)
return 1;
else
return 0;
}
int pop5()
{
int i;
if(!isempty5())
{i=a[top5];
top5--;
return i;
}
}
int display5(int i)
{
    if(isempty5())
    {
        printf("stack1 is empty\n");
        return 1;
    }
int j;
for(j=i;j>=0;j--)
printf("%d\n",a[j]);
}
 int isfull6()
 {
 if(top6==top5+1)
 return 1;
 else
 return 0;
 }


 int push6(int item)
{
if(!isfull6())
{
top6--;
a[top6]=item;
return 0;
}
else
{
printf("stack2 is full\n");
return 1;
}
}


int isempty6()
{
int item;
if(top6==max)
return 1;
else
return 0;
}


int display6(int i)
{
    if(isempty6())
    {
        printf("stack2 is empty\n");
        return 0;
    }
int j;
for(j=i;j<max;j++)
printf("%d\n",a[j]);
}
int pop6()
{
int i;
if(!isempty6())
{i=a[top6];
top6++;
return i;
printf("\n\n%d\n\n",i);
}
}
int stack_driver()
{
	int choice;
	system("cls");
	system("color 3e");
	printf("HIT 1 FOR STACK(ARRAY)\n");
	printf("HIT 2 FOR STACK(LINKED LIST)\n");
	printf("HIT 3 FOR 2 STACKS ------> 1 ARRAY\n");
	printf("HIT 4 FOR MAIN MENU \n");
	printf("HIT 5 FOR EXIT\n\n");
	while(1)
	{
		printf("Enter the choice:- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				array_stack();
				break;
			case 2:
				stack_list();
				break;
			case 3:
				stacks2();
				break;
			case 4:
				return main();
				break;
			case 5:
				exit(0);
			default :
				printf("wrong choice\n\n");
		}
	}
}
