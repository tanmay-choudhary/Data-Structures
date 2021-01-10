
#define MAX 500

int arr[MAX];
int front=-1;
int rear=-1;

void display_queue( );
void insert2_queue(int );
int del2_queue();
int peek2_queue();
int isempty2_queue();
int isfull_queue();

circular_queue()
{
	int choice,item;
	while(1)
	{
		printf("1.insert2_queue\n");
		printf("2.Delete\n");
		printf("3.peek2_queue\n");
		printf("4.display_queue\n");
		printf("5.Quit\n");
		printf("6.back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
			printf("Input the element for insertion : ");
			scanf("%d",&item);
			insert2_queue(item);
			break;
		case 2 :
			printf("Element deleted is : %d\n",del2_queue());
			break;
		case 3:
			printf("Element at the front is  : %d\n",peek2_queue());
			break;
		case 4:
			display_queue();
			break;
		case 5:
			exit(1);
		case 6:
			return queue_driver();
		default:
			printf("Wrong choice\n");
		}
	}
}

void insert2_queue(int item)
{
	if( isfull_queue() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front == -1 )  
		front=0;
	
	if(rear==MAX-1)
		rear=0;
	else
		rear=rear+1;
	arr[rear]=item ;
}

int del2_queue()
{
	int item;
	if( isempty2_queue() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	item=arr[front];
	if(front==rear) 
	{
		front=-1;
		rear=-1;
	}
	else if(front==MAX-1)
		front=0;
	else
		front=front+1;
	return item;
}

int isempty2_queue()
{
	if(front==-1)
		return 1;
	else
		return 0;
}

int isfull_queue()
{
	if((front==0 && rear==MAX-1) || (front==rear+1))
		return 1;
	else
		return 0;
}

int peek2_queue()
{
	if( isempty2_queue() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return arr[front];
}

void display_queue()
{
	int i;
	if(isempty2_queue())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	i=front;
	if( front<=rear )
	{
		while(i<=rear)
			printf("%d ",arr[i++]);
	}
	else
	{
		while(i<=MAX-1)
			printf("%d ",arr[i++]);
		i=0;
		while(i<=rear)
			printf("%d ",arr[i++]);
	}
	printf("\n");
}
////////////////////////********************************************************************************////////////////////
void insert_frontEnd(int item);
void insert_rearEnd(int item);
int delete_frontEnd();
int delete_rearEnd();
void display1_queue();
int isEmpty1_queue();
int isFull1_queue();

dqueue()
{
	int choice,item;
	while(1)
	{
		printf("1.insert2_queue at the front end\n");
		printf("2.insert2_queue at the rear end\n");
		printf("3.Delete from front end\n");
		printf("4.Delete from rear end\n");
		printf("5.display1_queue\n");
		printf("6.Quit\n");
		printf("7.back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert_frontEnd(item);
			break;
		case 2:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert_rearEnd(item);
			break;
		 case 3:
			printf("Element deleted from front end is : %d\n",delete_frontEnd());
			break;
		 case 4:
			printf("Element deleted from rear end is : %d\n",delete_rearEnd());
			break;
		 case 5:
			display1_queue();
			break;
		 case 6:
			exit(1);
		case 7:
			return queue_driver();
		 default:
			printf("Wrong choice\n");
		}
		printf("front = %d, rear =%d\n", front , rear);
		display1_queue();
	}
}

void insert_frontEnd(int item)
{
	if( isFull1_queue() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if( front==-1 )
	{
		front=0;
		rear=0;
	}
	else if(front==0)
		front=MAX-1;
	else
		front=front-1;
	arr[front]=item ;
}

void insert_rearEnd(int item)
{
	if( isFull1_queue() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1) 
	{
		front=0;
		rear=0;
	}
	else if(rear==MAX-1)  
		rear=0;
	else
		rear=rear+1;
	arr[rear]=item ;
}

int delete_frontEnd()
{
	int item;
	if( isEmpty1_queue() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	item=arr[front];
	if(front==rear) 
	{
		front=-1;
		rear=-1;
	}
	else
		if(front==MAX-1)
			front=0;
		else
			front=front+1;
	return item;
}

int delete_rearEnd()
{
	int item;
	if( isEmpty1_queue() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	item=arr[rear];
	
	if(front==rear) 
	{
		front=-1;
		rear=-1;
	}
	else if(rear==0)
		rear=MAX-1;
	else
		rear=rear-1;
	return item;
}

int isFull1_queue()
{
	if ( (front==0 && rear==MAX-1) || (front==rear+1) )
		return 1;
	else
		return 0;
}

int isEmpty1_queue()
{
	if( front == -1)
		return 1;
	else
		return 0;
}

void display1_queue()
{
	int i;
	if( isEmpty1_queue() )
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	i=front;
	if( front<=rear )
	{
		while(i<=rear)
			printf("%d ",arr[i++]);
	}
	else
	{
		while(i<=MAX-1)
			printf("%d ",arr[i++]);
		i=0;
		while(i<=rear)
			printf("%d ",arr[i++]);
	}
	printf("\n");
}
/////////////////////////////****************************************************************************///////////////////
struct node_queue
{
	int info;
	struct node_queue *link;
}*rear1=NULL;

void queue_insert3(int);
int queue_del3();
void queue_display3();
int queue_isEmpty3();
int queue_peek3();

CLL_queue()
{
	int choice,item;
	while(1)
	{
		printf("1.queue_insert3\n");
		printf("2.Delete\n");
		printf("3.queue_peek3\n");
		printf("4.queue_display3\n");
		printf("5.Quit\n");
		printf("6.back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the element for insertion : ");
			scanf("%d",&item);
			queue_insert3(item);
			break;
		 case 2:
			printf("Deleted element is %d\n",queue_del3());	
			break;
		 case 3:
			printf("Item at the front of queue is %d\n",queue_peek3());
			break;
		 case 4:
			queue_display3();
			break;
		 case 5:
		 	exit(0);
		case 6:
			return queue_driver();
		 default:
			printf("Wrong choice\n");
		}
	}
}

void queue_insert3(int item)
{
	struct node_queue *tmp;
	tmp=(struct node_queue *)malloc(sizeof(struct node_queue));
	tmp->info=item;
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	
	if( queue_isEmpty3() ) 
	{
		rear1=tmp;
		tmp->link=rear1;
	}
	else
	{
		tmp->link=rear1->link;
		rear1->link=tmp;
		rear1=tmp;
	}
}

queue_del3()
{
	int item;
	struct node_queue *tmp;
	if( queue_isEmpty3() )
	{
		printf("Queue underflow\n");
		exit(1);
	}
	if(rear1->link==rear1) 
	{
		tmp=rear1;
		rear1=NULL;
	}
	else
	{
		tmp=rear1->link;
		rear1->link=rear1->link->link;
	}
	item=tmp->info;
	free(tmp);
	return item;
}

int queue_peek3()
{
	if( queue_isEmpty3() )
	{
		printf("Queue underflow\n");
		exit(1);
	}
	return rear1->link->info;
}

int queue_isEmpty3()
{
	if( rear1 == NULL )
		return 1;
	else
		return 0;
}


void queue_display3()
{
	struct node_queue *p;
	if(queue_isEmpty3())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue is :\n");
	p=rear1->link;
	do
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=rear1->link);
	printf("\n");
}
///////////****************************************************************************************///////////////////////
void insert4(int item);
int del4();
int peek4();
void display4();
int isFull4();
int isEmpty4();

que_array()
{
	int choice,item;
	while(1)
	{
		printf("1.insert4\n");
		printf("2.Delete\n");
		printf("3.display4 element at the front\n");
		printf("4.display4 all elements of the queue\n");
		printf("5.Quit\n");
		printf("6.back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert4(item);
			break;
		case 2:
			item=del4();
			printf("Deleted element is  %d\n",item);
			break;
		case 3:
			printf("Element at the front is %d\n",peek4());
			break;
		case 4:
			display4();
			break;
		case 5:
			exit(1);
		case 6:
			return queue_driver();
		default:
			printf("Wrong choice\n");
		}
	}
}

void insert4(int item)
{
	if( isFull4() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if( front == -1 )  
		front=0;
	rear=rear+1;
	arr[rear]=item ;
}

int del4()
{
	int item;
	if( isEmpty4() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	item=arr[front];
	front=front+1;
	return item;
}

int peek4()
{
	if( isEmpty4() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return arr[front];
}

int isEmpty4()
{
	if( front==-1 || front==rear+1 )
		return 1;
	else
		return 0;
}

int isFull4()
{
	if( rear==MAX-1 )
		return 1;
	else
		return 0;
}

void display4()
{
	int i;
	if ( isEmpty4() )
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue is :\n\n");
	for(i=front;i<=rear;i++)
		printf("%d  ",arr[i]);
	printf("\n\n");
}
int queue_driver()
{
	int a;
	system("cls");
	system("color 5e");
	printf("HIT 1 FOR QUEUE(ARRAY)\n");
	printf("HIT 2 FOR QUEUE(CIRCULAR LINKED LIST)\n");
	printf("HIT 3 FOR DEQUEUE\n");
	printf("HIT 4 FOR CIRCULAR QUEUE\n");
	printf("HIT 5 FOR MAIN MENU\n");
	printf("HIT 6 for EXIT\n");
	while(1)
	{
		printf("enter the choice:- ");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				system("cls");
				que_array();
				break;
			case 2:
				system("cls");
				CLL_queue();
				break;
			case 3:
				system("cls");
				dqueue();
				break;
			case 4:
				system("cls");
				circular_queue();
				break;
			case 5:
				return main();
				break;
			case 6:
				exit(0);
			default:
				printf("choice not available **TRY AGAIN**\n\n");
		}
	}
}

