/*Program to construct a binary tree from inorder and preorder*/
#include<stdio.h>
#include<stdlib.h>

int tree();
struct treenode
{
	int info;
	struct treenode *lchild;
	struct treenode *rchild;
	int balance;
}*root=NULL;

struct listnode
{
	struct listnode *prev;
	int info;
	struct listnode *next;
}*pre=NULL, *in=NULL,*post=NULL;

void tree_display(struct treenode *ptr,int level);
struct listnode *addtoempty(struct listnode *start,int data);
struct listnode *addatend(struct listnode *start,int data);
struct listnode *create_list(struct listnode *start, int n);
struct treenode *construct(struct listnode *inptr,struct listnode *preptr, int num);
void inorder(struct treenode *ptr);
void postorder(struct treenode *ptr);
void preorder(struct treenode *ptr);

in_pre()
{
	int n;
	
	printf("Enter the number of nodes  :  ");
	scanf("%d",&n);

	printf("Enter inorder\n");
	in = create_list(in, n);

	printf("Enter preorder\n");
	pre=create_list(pre, n);

	root = construct(in,pre,n);

	printf("Inorder : ");  inorder(root);
	printf("\nPostorder : ");  postorder(root);
	printf("\nPreorder : "); preorder(root);
	printf("\n\nTree is : \n");
	tree_display(root,0);
	printf("\n");
}

struct treenode *construct(struct listnode *inptr,struct listnode *preptr, int num )
{
	struct treenode *temp;
	struct listnode *q;

	int i,j;
	if(num==0)
		return NULL;
	
	temp=(struct treenode *)malloc(sizeof(struct treenode));
	temp->info=preptr->info;
	temp->lchild = NULL;
	temp->rchild = NULL;

	if(num==1)/*if only one treenode in tree */
		return temp;
	
	q = inptr;	
	for(i=0; q->info != preptr->info; i++)
		q = q->next;
	
	/*Now q points to root treenode in inorder list and 
	 and number of nodes in its left subtree is i*/
	 
	/*For left subtree*/
	temp->lchild = construct(inptr, preptr->next, i);
	
	/*For right subtree*/
	for(j=1;j<=i+1;j++)
		preptr=preptr->next;
	temp->rchild = construct(q->next, preptr, num-i-1);
	 
	return temp;
}/*End of construct()*/

void tree_display(struct treenode *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		tree_display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		tree_display(ptr->lchild, level+1);
	}
}/*End of display()*/

struct listnode *create_list(struct listnode *start, int n)
{
	int i, data;
	start=NULL;
	for(i=1;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		if(start==NULL)
			start=addtoempty(start,data);
		else
			start=addatend(start,data);	
	}
	return start;
}/*End of create_list()*/

struct listnode *addtoempty(struct listnode *start,int data)
{
	struct listnode *tmp;
	tmp=(struct listnode*)malloc(sizeof(struct listnode));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}/*End of addtoempty( )*/
struct listnode *addatend(struct listnode *start,int data)
{
	struct listnode *tmp,*p;
	tmp=(struct listnode*)malloc(sizeof(struct listnode));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}/*End of addatend( )*/

void inorder(struct treenode *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}/*End of inorder( )*/
void postorder(struct treenode *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ",ptr->info);
	}
}/*End of postorder( )*/

void preorder(struct treenode *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		printf("%d  ",ptr->info);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}/*End of preorder( )*/


////////////////////////////********************************************************************///////////////////////////


/*P6.2 Program for constructing a binary tree from inorder and postorder */


void tree_display(struct treenode *ptr,int level);
struct listnode *tree_addtoempty(struct listnode *start,int data);
struct listnode *tree_addatend(struct listnode *start,int data);
struct listnode *tree_create_list(struct listnode *start, int n);
struct treenode *tree_construct(struct listnode *inptr,struct listnode *postptr, int num);
in_post()
{
	int n;

	printf("Enter the number of nodes  :  ");
	scanf("%d",&n);

	printf("Enter inorder\n");
	in = tree_create_list(in,n);

	printf("Enter postorder\n");
	post = tree_create_list(post,n);

	root = tree_construct(in,post,n);

	printf("Inorder : ");  inorder(root);
	printf("\nPostorder : ");  postorder(root);
	printf("\nPreorder : "); preorder(root);
	printf("\n\nTree is : \n");
	tree_display(root,0);
	printf("\n");
}/*End of main()*/

struct treenode *tree_construct(struct listnode *inptr,struct listnode *postptr, int num)
{
	struct treenode *temp;
	struct listnode *q, *ptr;

	int i,j;
	if(num==0)
		return NULL;
	
	ptr=postptr;
	for(i=1;i<num;i++)
		ptr = ptr->next;

	/*Now ptr points to last treenode of postorder which is root*/
	
	temp=(struct treenode *)malloc(sizeof(struct treenode));
	temp->info=ptr->info;
	temp->lchild = NULL;
	temp->rchild = NULL;

	if(num==1)/*if only one treenode in tree */
		return temp;
		
	q=inptr;
	for(i=0; q->info!=ptr->info; i++ )
		q = q->next;

	/*Now i denotes the number of nodes in left subtree
	and q points to root treenode in inorder list*/	
	
	/*For left subtree*/
	temp->lchild = tree_construct(inptr, postptr, i);
			
	/*For right subtree*/
	for(j=1;j<=i;j++)
		postptr = postptr->next;
	temp->rchild = tree_construct(q->next, postptr, num-i-1);
		
	return temp;
}/*End of tree_construct()*/

struct listnode *tree_create_list(struct listnode *start, int n)
{
	int i,data;
	start=NULL;
	for(i=1;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		if(start==NULL)
			start=tree_addtoempty(start,data);
		else
			start=tree_addatend(start,data);	
	}
	return start;
}/*End of tree_create_list()*/

struct listnode *tree_addtoempty(struct listnode *start,int data)
{
	struct listnode *tmp;
	tmp=(struct listnode*)malloc(sizeof(struct listnode));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}/*End of tree_addtoempty( )*/

struct listnode *tree_addatend(struct listnode *start,int data)
{
	struct listnode *tmp,*p;
	tmp=(struct listnode*)malloc(sizeof(struct listnode));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}/*End of tree_addatend( )*/

///////////////////////////////////////////*********************************************///////////////////////////////////
//////////////////////////////////////////*********************************************///////////////////////////////////


/*P6.3 Recursive operations in Binary Search Tree*/

struct treenode *search(struct treenode *ptr, int skey);
struct treenode *insert_bst(struct treenode *ptr, int ikey);
struct treenode *del(struct treenode *ptr, int dkey);
struct treenode *Min(struct treenode *ptr);
struct treenode *Max(struct treenode *ptr);
int height(struct treenode *ptr);

BST()
{
	struct treenode *ptr;
	int choice,k;

	while(1)
	{
		system("cls");
		printf("\n");
		printf("1.Search\n");
		printf("2.insert_bst\n");
		printf("3.Delete\n");
		printf("4.Preorder Traversal\n");
		printf("5.Inorder Traversal\n");
		printf("6.Postorder Traversal\n");
		printf("7.Height of tree\n");
		printf("8.Find minimum and maximum\n");
		printf("9.Quit\n");
		printf("10.back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1: 
			printf("Enter the key to be searched : ");
			scanf("%d",&k);
			ptr = search(root, k);
			if(ptr!=NULL)
				printf("Key found\n");
				system("PAUSE");
			break;
		case 2:
			printf("Enter the key to be inserted : ");
			scanf("%d",&k);
			root = insert_bst(root, k);
			printf("key is inserted\n");
			system("PAUSE");
			break;
		case 3:
			printf("Enter the key to be deleted : ");
			scanf("%d",&k);
			root = del(root,k);
			printf("%d is deleted\n",k);
			system("PAUSE");
			break;
		 case 4:
			preorder(root);
			system("PAUSE");
			break;
		 case 5:
			inorder(root);
			system("PAUSE");
			break;
		 case 6:
			postorder(root);
			system("PAUSE");
			break;
		 case 7:
			 printf("Height of tree is %d\n", height(root));
			 system("PAUSE");
			 break;
		 case 8:
			ptr = Min(root);
			if(ptr!=NULL)
				printf("Minimum key is %d\n", ptr->info );
			ptr = Max(root); 	
			if(ptr!=NULL)
				printf("Maximum key is %d\n", ptr->info );
				system("PAUSE");
			break;
		 case 9:
			exit(1);
		  case 10:
		  	return tree();
		 default:
			printf("Wrong choice\n");
			system("PAUSE");
		}
	}
}

struct treenode *search(struct treenode *ptr, int skey)
{
	if(ptr==NULL) 
	{	
		printf("key not found\n");
		return NULL;
	}
	else if(skey < ptr->info)
		return search(ptr->lchild, skey);	
	else if(skey > ptr->info)
		return search(ptr->rchild, skey);
	else 
		return ptr;
}

struct treenode *insert_bst(struct treenode *ptr, int ikey )
{
	if(ptr==NULL)	
	{
		ptr = (struct treenode *) malloc(sizeof(struct treenode));
		ptr->info = ikey;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
	}
	else if(ikey < ptr->info)
		ptr->lchild = insert_bst(ptr->lchild, ikey);
	else if(ikey > ptr->info)	
		ptr->rchild = insert_bst(ptr->rchild, ikey);  
	else
		printf("Duplicate key\n");
	return ptr;
}

struct treenode *del(struct treenode *ptr, int dkey)
{
	struct treenode *tmp, *succ;

	if( ptr == NULL)
	{
		printf("dkey not found\n");
		return(ptr);
	}
	if( dkey < ptr->info )
		ptr->lchild = del(ptr->lchild, dkey);
	else if( dkey > ptr->info )
		ptr->rchild = del(ptr->rchild, dkey);
	else
	{
	
		if( ptr->lchild!=NULL  &&  ptr->rchild!=NULL ) 
		{
			succ=ptr->rchild;
			while(succ->lchild)
				succ=succ->lchild;
			ptr->info=succ->info;
			ptr->rchild = del(ptr->rchild, succ->info);
		}
		else	
		{
			tmp = ptr;
			if( ptr->lchild != NULL ) 
				ptr = ptr->lchild;
			else if( ptr->rchild != NULL) 
				ptr = ptr->rchild;
			else
				ptr = NULL;
			free(tmp);
		}						
	}
	return ptr; 
}

struct treenode *Min(struct treenode *ptr)
{
	if(ptr==NULL)
		return NULL;
	else if(ptr->lchild==NULL)
        return ptr;
	else 
		return Min(ptr->lchild);
}

struct treenode *Max(struct treenode *ptr)
{
	if(ptr==NULL) 
		return NULL;
	else if(ptr->rchild==NULL)
        return ptr;
	else 
		return Max(ptr->rchild);
}
int height(struct treenode *ptr)
{
	int h_left, h_right; 

	if (ptr == NULL)
		return 0; 

	h_left =  height(ptr->lchild); 
	h_right = height(ptr->rchild); 

	if (h_left > h_right) 
		return 1 + h_left; 
	else 
		return 1 + h_right; 
}

//////////////////////////////////***************************************************************///////////////////////
/////////////////////////////*****////////////////////////////////////////////////////////////////*/***************///////
//avl


/*Program of AVL tree*/

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
struct treenode *RotateLeft(struct treenode *pptr);
struct treenode *RotateRight(struct treenode *pptr);

struct treenode *avl_insert(struct treenode *pptr, int ikey);
struct treenode *insert_left_check(struct treenode *pptr, int *ptaller);
struct treenode *insert_right_check(struct treenode *pptr, int *ptaller);
struct treenode *insert_LeftBalance(struct treenode *pptr);
struct treenode *insert_RightBalance(struct treenode *pptr);

struct treenode *avl_del(struct treenode *pptr, int dkey);
struct treenode *del_left_check(struct treenode *pptr, int *pshorter);
struct treenode *del_right_check(struct treenode *pptr, int *pshorter);
struct treenode *del_LeftBalance(struct treenode *pptr,int *pshorter);
struct treenode *del_RightBalance(struct treenode *pptr,int *pshorter);
avl()
{
	int choice,key;


	while(1)
	{
		system("cls");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Quit\n");
		printf("5.Back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the key to be inserted : ");
			scanf("%d",&key);
			root = avl_insert(root,key);
			printf("key is inseted\n");
			system("PAUSE");
			break;
		 case 2:
			printf("Enter the key to be deleted : ");
			scanf("%d",&key);
			root = avl_del(root,key);
			system("PAUSE");
			break;
		 case 3:
			inorder(root);
			system("PAUSE");
			break;
		 case 4:
			exit(1);
		 case 5:
		 	return tree();
		 default:
			printf("Wrong choice\n");
		}
	}
}

struct treenode *avl_insert(struct treenode *pptr, int ikey)
{
	static int taller;
	if(pptr==NULL)	/*Base case*/
	{
		pptr = (struct treenode *) malloc(sizeof(struct treenode));
		pptr->info = ikey;
		pptr->lchild = NULL;
		pptr->rchild = NULL;
		pptr->balance = 0;
		taller = TRUE;
	}
	else if(ikey < pptr->info)	/*Insertion in left subtree*/
	{
		pptr->lchild = avl_insert(pptr->lchild, ikey);
		if(taller==TRUE)
			pptr = insert_left_check( pptr, &taller );
	}
	else if(ikey > pptr->info)	/*Insertion in right subtree */
	{
		pptr->rchild = avl_insert(pptr->rchild, ikey);  
		if(taller==TRUE)
			pptr = insert_right_check(pptr, &taller);
	}
	else  /*Base Case*/
	{
		printf("Duplicate key\n");
		taller = FALSE;
	}
	return pptr;
}/*End of avl_insert( )*/

struct treenode *insert_left_check(struct treenode *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: /* Case L_A : was balanced */  
		pptr->balance = 1;	/* now left heavy */
		break;
	 case -1: /* Case L_B: was right heavy */ 
		pptr->balance = 0;	/* now balanced */
		*ptaller = FALSE;
			break;
	 case 1: /* Case L_C: was left heavy */   
		pptr = insert_LeftBalance(pptr);	/* Left Balancing */
		*ptaller = FALSE;
	}
	return pptr;
}/*End of insert_left_check( )*/

struct treenode *insert_right_check(struct treenode *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: /* Case R_A : was balanced */	
		pptr->balance = -1;	/* now right heavy */
		break;
	 case 1: /* Case R_B : was left heavy */  
		pptr->balance = 0;	/* now balanced */ 
		*ptaller = FALSE;
		break;
	 case -1: /* Case R_C: Right heavy */   
		pptr = insert_RightBalance(pptr);	/* Right Balancing */
		*ptaller = FALSE;
	}
	return pptr;
}/*End of insert_right_check( )*/

struct treenode *insert_LeftBalance(struct treenode *pptr)
{
	struct treenode *aptr, *bptr;

	aptr = pptr->lchild;
	if(aptr->balance == 1)  /* Case L_C1 : Insertion in AL */ 
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else		/* Case L_C2 : Insertion in AR */
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
		case -1:			/* Case L_C2a : Insertion in BR */   
			pptr->balance = 0;
			aptr->balance = 1;
			break;
		case 1:					/* Case L_C2b : Insertion in BL */
			pptr->balance = -1;
			aptr->balance = 0;
			break;
		case 0:					/* Case L_C2c : B is the newly inserted treenode */ 
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}/*End of insert_LeftBalance( )*/

struct treenode *insert_RightBalance(struct treenode *pptr)
{
	struct treenode *aptr, *bptr;

	aptr = pptr->rchild;
	if(aptr->balance == -1) /* Case R_C1 : Insertion in AR */ 
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else		/* Case R_C2 : Insertion in AL */
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
		case -1:	/* Case R_C2a : Insertion in BR */
			pptr->balance = 1;  
			aptr->balance = 0;
			break;
		case 1:		/* Case R_C2b : Insertion in BL */
			pptr->balance = 0;
			aptr->balance = -1;
			break;
		case 0:		/* Case R_C2c : B is the newly inserted treenode */
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}/*End of insert_RightBalance( )*/

struct treenode *RotateLeft(struct treenode *pptr)
{
	struct treenode *aptr;
	aptr = pptr->rchild;	/*A is right child of P*/
	pptr->rchild = aptr->lchild; /*Left child of A becomes right child of P */
	aptr->lchild = pptr;  /*P becomes left child of A*/ 
	return aptr;  /*A is the new root of the subtree initially rooted at P*/
}/*End of RotateLeft( )*/

struct treenode *RotateRight(struct treenode *pptr)
{
	struct treenode *aptr;
	aptr = pptr->lchild;	/*A is left child of P */
	pptr->lchild = aptr->rchild; /*Right child of A becomes left child of P*/  
	aptr->rchild = pptr;			/*P becomes right child of A*/
	return aptr; /*A is the new root of the subtree initially rooted at P*/
}/*End of RotateRight( )*/

struct treenode *avl_del(struct treenode *pptr, int dkey)
{
	struct treenode *tmp, *succ;
	static int shorter;

	if( pptr == NULL) /*Base Case*/
	{
		printf("Key not present \n");
		shorter = FALSE;
		return(pptr);
	}
	if( dkey < pptr->info )
	{
		pptr->lchild = avl_del(pptr->lchild, dkey);
		if(shorter == TRUE)
			pptr = del_left_check(pptr, &shorter);
	}
	else if( dkey > pptr->info )
	{
		pptr->rchild = avl_del(pptr->rchild, dkey);
		if(shorter==TRUE)
			pptr = del_right_check(pptr, &shorter);
	}
	else /* dkey == pptr->info, Base Case*/
	{
		/*pptr has 2 children*/
		if( pptr->lchild!=NULL  &&  pptr->rchild!=NULL )  
		{
			succ = pptr->rchild;
			while(succ->lchild)
				succ = succ->lchild;
			pptr->info = succ->info;
			pptr->rchild = avl_del(pptr->rchild, succ->info);
			if( shorter == TRUE )
				pptr = del_right_check(pptr, &shorter);
		}
		else	
		{
			tmp = pptr;
			if( pptr->lchild != NULL ) /*only left child*/
				pptr = pptr->lchild;
			else if( pptr->rchild != NULL) /*only right child*/
				pptr = pptr->rchild;
			else	/* no children */
				pptr = NULL;
			free(tmp);
			shorter = TRUE;
		}						
	}
	return pptr; 
}/*End of avl_del( )*/

struct treenode *del_left_check(struct treenode *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0: /* Case L_A : was balanced */       
			pptr->balance = -1;	/* now right heavy */ 
			*pshorter = FALSE;
			break;
		case 1: /* Case L_B : was left heavy */	 
			pptr->balance = 0;	/* now balanced */
			break;            
		case -1: /* Case L_C : was right heavy */   
			pptr = del_RightBalance(pptr, pshorter); /*Right Balancing*/
	}
	return pptr;
}/*End of del_left_check( )*/

struct treenode *del_right_check(struct treenode *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0:		/* Case R_A : was balanced */		
			pptr->balance = 1;	/* now left heavy */
			*pshorter = FALSE;
			break;
		case -1: /* Case R_B : was right heavy */	
			pptr->balance = 0;	/* now balanced */
			break;
		case 1: /* Case R_C : was left heavy */	
			pptr = del_LeftBalance(pptr, pshorter );  /*Left Balancing*/
	}
	return pptr;
}/*End of del_right_check( )*/

struct treenode *del_LeftBalance(struct treenode *pptr,int *pshorter)
{
	struct treenode *aptr, *bptr;
	aptr = pptr->lchild;
	if( aptr->balance == 0)  /* Case R_C1 */
	{
		pptr->balance = 1;
		aptr->balance = -1;
		*pshorter = FALSE;
		pptr = RotateRight(pptr);
	}
	else if(aptr->balance == 1 ) /* Case R_C2 */
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else						/* Case R_C3 */
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
			case 0:					/* Case R_C3a */
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:					/* Case R_C3b */
				pptr->balance = -1;		
				aptr->balance = 0;
				break;
			case -1:			/* Case R_C3c */
				pptr->balance = 0;	
				aptr->balance = 1;
		}
		bptr->balance = 0;			
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}/*End of del_LeftBalance( )*/

struct treenode *del_RightBalance(struct treenode *pptr,int *pshorter)
{
	struct treenode *aptr, *bptr;

	aptr = pptr->rchild;
	if (aptr->balance == 0)	/* Case L_C1 */ 
	{
		pptr->balance = -1;
		aptr->balance = 1;
		*pshorter = FALSE;
		pptr = RotateLeft(pptr);			
	}
	else if(aptr->balance == -1 )	/* Case L_C2 */ 
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);			
	}
	else							/* Case L_C3 */
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
			case 0:					/* Case L_C3a */
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:					/* Case L_C3b */ 
				pptr->balance = 0;
				aptr->balance = -1;
				break;
			case -1:				/* Case L_C3c */
				pptr->balance = 1;
				aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}/*End of del_RightBalance( )*/
//////////////////////////////////////////////***************************************************************//////////////
////////////////////////////////////////////******************************************************************////////////

/*Insertion, Deletion and Traversal in fully in-threaded Binary Search Tree*/



typedef enum {false,true} boolean;
struct thread_node *in_succ(struct thread_node *p);
struct thread_node *in_pred(struct thread_node *p);
struct thread_node *thread_insert(struct thread_node *root, int ikey);
struct thread_node *thread_del(struct thread_node *root, int dkey);
struct thread_node *case_a(struct thread_node *root, struct thread_node *par,struct thread_node *ptr);
struct thread_node *case_b(struct thread_node *root,struct thread_node *par,struct thread_node *ptr);
struct thread_node *case_c(struct thread_node *root, struct thread_node *par,struct thread_node *ptr);

void thread_inorder( struct thread_node *root);
void thread_preorder( struct thread_node *root);

struct thread_node
{
	struct thread_node *left;
	boolean lthread;
	int info;
	boolean rthread;
	struct thread_node *right;
};
	
intheaded()
{
	system("cls");
	int choice,num;
	struct thread_node *root=NULL;
	
	while(1)
	{
		system("cls");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Preorder Traversal\n");
		printf("5.Quit\n");
		printf("6.BACK\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			root = thread_insert(root,num);
			printf("KEY is inserted \n");
			system("PAUSE");
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			root = thread_del(root,num);
			system("PAUSE");
			break;
		 case 3:
			thread_inorder(root);
			system("PAUSE");
			break;
		 case 4:
			thread_preorder(root);
			system("PAUSE");
			break;
		 case 5:
			 exit(1);
		  case 6:
		  	return tree();
		 default:
			printf("Wrong choice\n");
			system("PAUSE");
		}/*End of switch */
	}/*End of while */
}/*End of main( )*/

struct thread_node *thread_insert(struct thread_node *root, int ikey)
{       
	struct thread_node *tmp,*par,*ptr;

	int found=0;
	
	ptr = root;
	par = NULL;

	while( ptr!=NULL )
	{
		if( ikey == ptr->info)
		{
			found =1;
			break;
		}
		par = ptr;
		if(ikey < ptr->info)
		{
			if(ptr->lthread == false)
				ptr = ptr->left;	
			else 
				break;
		}
		else 
		{
			if(ptr->rthread == false)
				ptr = ptr->right;
			else 
				break;
		}
	}
	
	if(found)
		printf("Duplicate key");
	else
	{
        
		tmp=(struct thread_node *)malloc(sizeof(struct thread_node));
		tmp->info=ikey;
		tmp->lthread = true;
		tmp->rthread = true;
		if(par==NULL)
		{
			root=tmp;
			tmp->left=NULL;
			tmp->right=NULL;
		}
		else if( ikey < par->info )
		{
			tmp->left=par->left;
			tmp->right=par;
			par->lthread=false;
			par->left=tmp;
		}
		else
		{
			tmp->left=par;
			tmp->right=par->right;
			par->rthread=false;
			par->right=tmp;
		}	
	}
	return root;
}/*End of thread_insert( )*/

struct thread_node *thread_del(struct thread_node *root, int dkey)
{
	struct thread_node *par,*ptr;
	
	int found=0;

	ptr = root;
	par = NULL;
	
	while( ptr!=NULL)
	{
		if( dkey == ptr->info)
		{
			found =1;
			break;
		}
		par = ptr;
		if(dkey < ptr->info)
		{
			if(ptr->lthread == false)
				ptr = ptr->left;	
			else 
				break;
		}
		else 
		{
			if(ptr->rthread == false)
				ptr = ptr->right;
			else 
				break;
		}
	}

	if(found==0)
		printf("dkey not present in tree");
	else if(ptr->lthread==false && ptr->rthread==false)/*2 children*/
		root = case_c(root,par,ptr);	
	else if(ptr->lthread==false )/*only left child*/
        root = case_b(root, par,ptr);
	else if(ptr->rthread==false)/*only right child*/
        root = case_b(root, par,ptr);
	else /*no child*/
		root = case_a(root,par,ptr);
	return root;
}/*End of thread_del( )*/

struct thread_node *case_a(struct thread_node *root, struct thread_node *par,struct thread_node *ptr )
{
	if(par==NULL) /*root thread_node to be deleted*/
		root=NULL;
	else if(ptr==par->left)
	{
		par->lthread=true;
		par->left=ptr->left;
	}
	else
	{
		par->rthread=true;
		par->right=ptr->right;
	}
	free(ptr);
	return root;
}/*End of case_a( )*/

struct thread_node *case_b(struct thread_node *root,struct thread_node *par,struct thread_node *ptr)
{
	struct thread_node *child,*s,*p;

	/*Initialize child*/
	if(ptr->lthread==false) /*thread_node to be deleted has left child */
		child=ptr->left;
	else                /*thread_node to be deleted has right child */
		child=ptr->right;
	
	
	if(par==NULL )   /*thread_node to be deleted is root thread_node*/
		root=child;
	else if( ptr==par->left) /*thread_node is left child of its parent*/
		par->left=child;
	else                     /*thread_node is right child of its parent*/
		par->right=child;
	
	s=in_succ(ptr);
	p=in_pred(ptr);

	if(ptr->lthread==false) /*if ptr has left subtree */
			p->right=s;
	else                         
	{
		if(ptr->rthread==false) /*if ptr has right subtree*/
			s->left=p;
	}

	free(ptr);
	return root;
}/*End of case_b( )*/

struct thread_node *case_c(struct thread_node *root, struct thread_node *par,struct thread_node *ptr)
{
	struct thread_node *succ,*parsucc;

	/*Find thread_inorder successor and its parent*/
	parsucc = ptr;
	succ = ptr->right;
	while(succ->left!=NULL)
	{
		parsucc = succ;
		succ = succ->left;
	}
	
	ptr->info = succ->info;

	if(succ->lthread==true && succ->rthread==true)
		root = case_a(root, parsucc,succ);
	else	
		root = case_b(root, parsucc,succ);
	return root;
}/*End of case_c( )*/

struct thread_node *in_succ(struct thread_node *ptr)
{
	if(ptr->rthread==true)
		return ptr->right; 
	else
	{
		ptr=ptr->right;
		while(ptr->lthread==false)
			ptr=ptr->left;
		return ptr;
	}
}/*End of in_succ( )*/

struct thread_node *in_pred(struct thread_node *ptr)
{
	if(ptr->lthread==true)
		return ptr->left;
	else
	{
		ptr=ptr->left;
		while(ptr->rthread==false)
			ptr=ptr->right;
		return ptr;
	}
}/*End of in_pred( )*/

void thread_inorder( struct thread_node *root)
{
	struct thread_node *ptr;
	if(root == NULL )
	{
		printf("Tree is empty");
		return;
	}

	ptr=root;
	/*Find the leftmost thread_node */
	while(ptr->lthread==false)
		ptr=ptr->left;
	
	while( ptr!=NULL )
	{
		printf("%d ",ptr->info);	
		ptr=in_succ(ptr);
	} 
}/*End of thread_inorder( )*/

void thread_preorder(struct thread_node *root )
{
	struct thread_node *ptr;
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	ptr=root;

	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		if(ptr->lthread==false)
			ptr=ptr->left;
		else if(ptr->rthread==false)
			ptr=ptr->right;
		else
		{
			while(ptr!=NULL && ptr->rthread==true)
				ptr=ptr->right;
			if(ptr!=NULL)
				ptr=ptr->right;
		}
	}
}/*End of thread_preorder( )*/


int tree()
{
	int choice;
	system("cls");
	system("color 2b");
	printf("HIT 1 FOR MAKE A TREE FROM INORDER AND PREORDER\n");
	printf("HIT 2 FOR MAKE A TREE FROM INPRDER AND POSTORDER\n");
	printf("HIT 3 FOR BINARY SEARCH TREE\n");
	printf("HIT 4 FOR AVL TREE\n");
	printf("HIT 5 FOR IN-THREADED TREE\n");
	printf("HIT 6 FOR MAIN MENU\n");
	printf("HIT 7 FOR QUIT PROGRAMME\n");
while(1)
	  {
	  	printf("enter the choice:- ");
	  	scanf("%d",&choice);
	  	switch(choice)
	  	{
	  	    case 1:
	  	    	system("cls");
	  	    	in_pre();
	  	    	system("PAUSE");
	  	    	return tree();
	  	    	break;
	  	    case 2:
	  	   		system("cls");
	  	    	in_post();
	  	    	system("PAUSE");
	  	    	return tree();
	  	    	break;
	  	    case 3:
	  	    	BST();
	  	    	system("PAUSE");
	  	    	break;
	  	    case 4:
	  	    	avl();
	  	    	break;
	  	    case 5:
	  	        intheaded();
	  	        system("PAUSE");
				break; 
	  	    case 6:
	  	    	return main();
	  	    	break;
	  	    case 7:
	  	    	exit(1);	
	  	    default:
	  	    	printf("wrong choice\n");
	  	    	
	  	       }
	  }
}
