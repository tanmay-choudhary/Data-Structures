/*Program to check nesting of parentheses using ex_stack*/
#include<string.h>
#include<math.h>
#define BLANK ' '
#define TAB '\t'
int ex_top=-1;
int ex_stack[MAX];
int check(char* );
void ex_push(char);
char ex_pop();
int ex_match(char a,char b);
validity()
{
	char exp[MAX];
	int valid;
	printf("Enter an algebraic expression : ");
	fflush(stdin);
	gets(exp);
	fflush(stdin);
	valid=check(exp);
	if(valid==1)
		printf("Valid expression\n");
	else
		printf("Invalid expression\n");
}
int check(char exp[] )
{
	int i;
	char temp;
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			ex_push(exp[i]);
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
			if(ex_top==-1)    /*ex_stack empty*/
			{
				printf("Right parentheses are more than left parentheses\n");
				return 0;
			}
			else
			{
				temp=ex_pop();
				if(!ex_match(temp, exp[i]))
				{
					printf("Mismatched parentheses are : "); 
					printf("%c and %c\n",temp,exp[i]);	
					return 0;
				}
			}
	}
	if(ex_top==-1) /*ex_stack empty*/
	{
		printf("Balanced Parentheses\n"); 
		return 1;
	}
	else 
	{
		printf("Left parentheses more than right parentheses\n");	
		return 0;
	}
}/*End of main()*/
int ex_match(char a,char b)
{
	if(a=='[' && b==']')
		return 1;
	if(a=='{' && b=='}')
		return 1;	
	if(a=='(' && b==')')
		return 1;
	return 0;
}/*End of ex_match()*/

void ex_push(char item)
{
	if(ex_top==(MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	ex_top=ex_top+1;
	ex_stack[ex_top]=item;
}/*End of ex_push()*/

char ex_pop()
{
	if(ex_top==-1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return(ex_stack[ex_top--]);
}/*End of ex_pop()*/
/////////////////////////*********************************************************////////////////////////////////////
////////////////////////**********************************************************///////////////////////////////////

/*Program for conversion of infix to postfix and evaluation of postfix.
It will evaluate only single digit numbers*/


void postfix_push(long int symbol);
long int postfix_pop();
void infix_to_postfix();
long int eval_post();
int priority(char symbol);
int postfix_isEmpty();
int white_space(char );

char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;

infix_postfix()
{
	long int value;
	top=-1;
	printf("Enter infix : ");
	fflush(stdin);
	gets(infix);
	infix_to_postfix();
	printf("Postfix : %s\n",postfix);
	value=eval_post();
	printf("Value of expression : %ld\n",value);
}

void infix_to_postfix()
{
	unsigned int i,p=0;
	char next;
	char symbol;	
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(!white_space(symbol))
		{
			switch(symbol)
			{
			case '(':
				postfix_push(symbol);
				break;
			case ')':
				while((next=postfix_pop())!='(')
					postfix[p++] = next;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				while( !postfix_isEmpty( ) &&  priority(stack[top])>= priority(symbol) )
					postfix[p++]=postfix_pop();
				postfix_push(symbol);
				break;
			default:
			     postfix[p++]=symbol;
			}
		}
	}
	while(!postfix_isEmpty( )) 
		postfix[p++]=postfix_pop();
	postfix[p]='\0'; /*End postfix with'\0' to make it a string*/
}/*End of infix_to_postfix()*/

/*This function returns the priority of the operator*/
int priority(char symbol)
{
	switch(symbol)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	default :
		return 0;
	}
}/*End of priority()*/

void postfix_push(long int symbol)
{
	if(top>MAX)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	stack[++top]=symbol;
}/*End of postfix_push()*/

long int postfix_pop()
{
	if( postfix_isEmpty() )
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return (stack[top--]);
}/*End of postfix_pop()*/
int postfix_isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}/*End of postfix_isEmpty()*/

int white_space(char symbol)
{
	if( symbol == BLANK || symbol == TAB )
		return 1;
	else
		return 0;
}/*End of white_space()*/

long int eval_post()
{
	long int a,b,temp,result;
	unsigned int i;
	
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]<='9' && postfix[i]>='0')
			postfix_push(postfix[i]-'0');
		else
		{
			a=postfix_pop();
			b=postfix_pop();
			switch(postfix[i])
			{
			case '+':
				temp=b+a; break;
			case '-':
				temp=b-a;break;
			case '*':
				temp=b*a;break;
			case '/':
				temp=b/a;break;
			case '%':
				temp=b%a;break;
			case '^':
				temp=pow(b,a);
			}
			postfix_push(temp);
		}
	}
	result=postfix_pop();
	return result;
}/*End of eval_post */
int stack_apps()
{
	int a;
	system("cls");
	printf("HIT 1 FOR EXP..VALIDITY\n");
	printf("HIT 2 FOR INFIX TO POSTFIX\n");
	printf("HIT 3 FOR BACK\n");
	printf("HIT 4 FOR QUIT\n");
	while(1)
	{
		printf("enter the choice\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				validity();
				system("PAUSE");
				return stack_apps();
			case 2:
				infix_postfix();
				system("PAUSE");
				return stack_apps();
			case 3:
				return stack_apps();
			case 4:
				exit(1);
			default:
				printf("choice not available**TRY AGAIN**\n");
				system("PAUSE");
		}
	}
}
