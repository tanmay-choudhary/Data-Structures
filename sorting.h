Insertionsort()
{
    int arr[MAX],temp,i,n,j,k;
    printf("enter the no.of elements in array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
   {
       k=arr[i];
    for(j=i-1 ;j>=0 && k<arr[j];j--)
        arr[j+1]=arr[j];
        arr[j+1]=k;
    }
    printf("sorted list is\n");
for(i=0;i<n;i++)
    printf("%d\n",arr[i]);
}

////////////////////////////////*********************************///////////////////////////////////////
///////////////////////////////*********************************///////////////////////////////////////

Selectionsort()
{
    int arr[MAX],temp,i,n,j,min;
    printf("enter the no.of elements in array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n-1;i++)
       {
           min=i;
    for(j=i+1;j<n;j++)
    {
        if(arr[min]>arr[j])
        min=j;
    }
    if(i!=min)
    {
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }}
     printf("the sorted order of no. is\n");
    for(i=0;i<n;i++)
        printf("%d\n",arr[i]);
        printf("\n");


}
//////////////////////////////////////////************************************************//////////////////////////////
/////////////////////////////////////////************************************************//////////////////////////////
Bubblesort()
{
    int arr[MAX],temp,i,n,j,k;
    printf("enter the no.of elements in array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }


for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
    if(arr[j]>arr[j+1])
    {

        temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
    }
}}
printf("sorted list is\n");
for(i=0;i<n;i++)
    printf("%d\n",arr[i]);
    }
/////////////////////////////////////////************************************************//////////////////////////////////
/////////////////////////////////////////***********************************************//////////////////////////////////
int partion_quick(int arr[],int low,int up);
Quicksort()
{
    int i,j,n;
    int arr[MAX];
    int quick(int arr[],int low,int up);
    int partion(int arr[],int low,int up);
    printf("enter the no of elements:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d\n",&arr[i]);
    }
    quick(arr,0,n-1);
printf("the sorted list is:\n");
for(i=0;i<n;i++)
    printf("%d\n",arr[i]);
}
int quick(int arr[],int low,int up)
{
    int piv;
    if(low>=up)
        return 0;
    piv=partion_quick(arr,low,up);
    quick(arr,low,piv-1);
    quick(arr,piv+1,up);
}
int partion_quick(int arr[],int low,int up)
{
    int temp,i,j,pivot;
    i=low+1;
    j=up;
    pivot=arr[low];
    while(i<=j)
    {
        while(arr[i]<pivot && (i<j))
            i++;
        while(arr[j]>pivot)
            j--;
            if(i<j)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            else
                i++;
    }
    arr[low]=arr[j];
    arr[j]=pivot;
    return j;
}
///////////////////////////////////////////////////**********************************************///////////////////////////
///////////////////////////////////////////////////*********************************************///////////////////////////

/* Program of sorting using merge sort through recursion*/
void merge_sort( int arr[], int low, int up );
void merge( int arr[], int temp[], int low1, int up1, int low2, int up2 );
void copy(int arr[], int temp[], int low, int up );

Mergesort()
{
	int i, n, arr[MAX];
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	merge_sort( arr, 0, n-1);

	printf("\nSorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void merge_sort(int arr[], int low, int up)
{
	int mid;
	int temp[MAX];
	if(low<up)
	{
		mid = (low+up)/2;
		merge_sort( arr, low , mid );  
		merge_sort( arr, mid+1, up ); 
		merge( arr, temp, low, mid, mid+1, up ); 
		copy(arr,temp,low, up);	
	}
}


void merge( int arr[], int temp[], int low1, int up1, int low2, int up2 )
{
	int i = low1;
	int j = low2 ;
	int k = low1 ;

	while( (i <= up1) && (j <=up2) )
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++] ;
		else
			temp[k++] = arr[j++] ;
	}
	while( i <= up1 )
		temp[k++]=arr[i++];
	while( j <= up2 )
		temp[k++]=arr[j++];
}

void copy(int arr[], int temp[], int low, int up )
{
	int i;
	for(i=low; i<=up; i++)
		arr[i]=temp[i];
}
////////////////////////////////////*******************************************************////////////////////////////////
///////////////////////////////////*******************************************************////////////////////////////////

/*Program of sorting through heapsort*/



void heap_sort(int arr[], int size);
void buildHeap(int arr[], int size);
int del_root(int arr[], int *size);
void restoreDown(int arr[], int i, int size );
void display_arr(int arr[], int n);

Heapsort()
{
	int i;
	int arr[MAX],n;
	
	printf("Enter number of elements : ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("Enter element %d : ",i);
		scanf("%d",&arr[i]);
	}
	
	printf("Entered list is :\n");
	display_arr(arr,n);

	heap_sort(arr,n);

	printf("Sorted list is :\n");
	display_arr(arr,n);

}

void heap_sort(int arr[], int size)
{
	int max;
	buildHeap(arr, size);
	printf("Heap is : ");
	display_arr(arr,size);
		
	while(size>1)
	{
		max = del_root(arr,&size);
		arr[size+1]=max;
	}
}

void buildHeap(int arr[], int size)
{
	int i;
	for(i=size/2; i>=1; i--)
		restoreDown(arr,i,size);
}

int del_root(int arr[], int *size)
{
	int max = arr[1];
	arr[1] = arr[*size];
	(*size)--;
	restoreDown(arr,1,*size);
	return max;
}

void restoreDown(int arr[], int i, int size )
{
	int left=2*i, right=left+1;
	
	int num=arr[i];
	
	while(right<=size)
	{
		if( num>=arr[left] && num>=arr[right] )
		{
			arr[i] = num;
			return;
		}
		else if(arr[left] > arr[right])
		{
			arr[i] = arr[left]; 
			i = left;
		}
		else
		{
			arr[i] = arr[right];
			i = right;
		}
		left = 2 * i;
		right = left + 1;
	}	

	if(left == size && num < arr[left] ) 
	{
		arr[i]=arr[left];
		i = left;
	}
	arr[i]=num;
}
void display_arr(int arr[], int n)
{       
	int i;
	for(i=1;i<=n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
}
sort()
{
	int a;
	system("cls");
	printf("HIT 1 FOR BUBBLE SORT\n");
	printf("HIT 2 FOR SELECTION SORT\n");
	printf("HIT 3 FOR INSERTION SORT\n");
	printf("HIT 4 FOR QUICK SORT\n");
	printf("HIT 5 FOR MERGE SORT\n");
	printf("HIT 6 FOR HEAP SORT\n");
	printf("HIT 7 FOR MAIN MENU\n");
	printf("HIT 8 FOR EXIT\n");
	while(1)
	{
		printf("enter the choice \n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				system("cls");
				Bubblesort();
				system("PAUSE");
				return sort();
			case 2:
				system("cls");
				Selectionsort();
				system("PAUSE");
				return sort();
			case 3:
				system("cls");
				Insertionsort();
				system("PAUSE");
				return sort();
			case 4:
				system("cls");
				Quicksort();
				system("PAUSE");
				return sort();
   			case 5:
   				system("cls");
   				Mergesort();
   				system("PAUSE");
   				return sort();
   			case 6:
   				system("cls");
   				Heapsort();
   				system("PAUSE");
   				return sort();
   			case 7:
   				return main();
   			case 8:
   				exit(0);
   			default:
   				printf("choice not available**TRY AGAIN**");
   				
   					
 			
		}
	}
}









