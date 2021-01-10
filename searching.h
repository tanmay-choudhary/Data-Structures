int BinarySearch(int arr[], int size, int item);

Binary()
{
	int i, size, item, arr[MAX], index;
	
	printf("Enter the number of elements : ");
	scanf("%d",&size);
	printf("Enter the elements (in sorted order) : \n");
	for(i=0; i<size; i++)
		scanf("%d", &arr[i] );

	printf("Enter the item to be searched : ");
	scanf("%d", &item);
	
	index = BinarySearch(arr, size, item);
	
	if(index==-1)
		printf("%d not found in array\n", item);
	else
		printf("%d found at position %d\n", item, index);
}

int BinarySearch(int arr[], int size, int item)
{
	int low=0, up=size-1, mid;
	while(low<=up)
	{
		mid = (low+up)/2;
		if(item>arr[mid])
			low = mid+1;	
		else if(item<arr[mid])
			up = mid-1;	
			return mid;
	}
	return -1;
}
////////////////////////////////////////////*************************************************////////////////////////////
////////////////////////////////////////////*************************************************/////////////////////////////


int LinearSearch(int arr[], int n, int item);
Linear()
{
	int i, n, item, arr[MAX], index;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("Enter the elements : \n");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i] );

	printf("Enter the item to be searched : ");
	scanf("%d", &item);
	
	index = LinearSearch(arr, n, item);
	
	if(index == -1)
		printf("%d not found in array\n", item);
	else
		printf("%d found at position %d\n", item, index);
}
int LinearSearch(int arr[], int n, int item)
{
	int i=0;
	while(i<n && item!=arr[i])
			i++;
	if(i < n) 
		return i;
	else
		return -1;
}
int searching()
{
	int a;
	system("cls");
	printf("HIT 1 FOR SEQUENTIAL SEARCH\n");
	printf("HIT 2 FOR BINARY SEARCH\n");
	printf("HIT 3 FOR MAIN MENU\n");
	printf("HIT 4 FOR QUIT \n ");
	printf("enter the choice:-");
	scanf("%d",&a);
  while(1)
  {
  		switch(a)
	{
		case 1:
			Linear();
			system("PAUSE");
			return searching();
		case 2:
			Binary();
			system("PAUSE");
			return searching();
		case 3:
			return main();
		case 4:
			exit(1);
		default:
			printf("choice not available**TRY AGAIN**\n");
			system("PAUSE");
		
	}
  }
  

}



