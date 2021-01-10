#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"linkedlist.h"
#include"queue.h"
#include"stack.h"
#include"tree.h"
#include"sorting.h"
#include"searching.h"
#include"app_stack.h"
#include"vector.h"
int counter=0;
int main()
{
	
	system("cls");
	int a;
	printf("HIT 1 FOR LINKED LIST\n");
	printf("HIT 2 FOR QUEUE \n");
	printf("HIT 3 FOR STACK\n");
	printf("HIT 4 FOR STACK APPLICATIONS\n");
	printf("HIT 5 FOR TREES \n");
	printf("HIT 6 FOR SORTING\n");
	printf("HIT 7 FOR SEACHING\n");
	printf("HIT 8 FOR EXIT\n");
	while(1)
	{
	printf("enter the choice:- ");
	scanf("%d",&a);
	  switch(a)
	  {
	  	case 1:
	  		linked_list();
	  		break;
	  	case 2:
	  		queue_driver();
	  		break;
	  	case 3:
	  		stack_driver();
	  		break;
	  	case 4:
	  		stack_apps();
	  		break;
	  	case 5:
	  		tree();
	  		break;
	  	case 6:
	  		sort();
	  		break;
	  	case 7:
	  		searching();
	  		break;
	  	case 8:
	  		vectorq();
	  		system("PAUSE");
	  		return main();
	  	case 9:
	  		exit(1);
	  	default:
	  		printf("Wrong choice**TRY AGAIN**\n");
	  		system("PAUSE");
	  }
	}
}
