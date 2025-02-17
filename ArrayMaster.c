#include <stdio.h>

void createArr(int* arr, int size);
void display(int* arr, int size);
void userInput(int* n);
void operation(int n);
void incrementAndInsertElement();
void insertElementAtSpecificIndex();
void deleteElementAtSpecificIndex();

int main ()
{
	int n;
	
	do
	{
		userInput(&n);
		
			if (n == 0)
			{
				printf("Program Terminated.\n");
				break;
			}
			
		operation(n);
		
	} while (n!=0);
	
	
	return 0;
}
void createArr(int* arr, int size)
{
	for (int i = 0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}
}
void display(int* arr, int size)
{
	for (int i = 0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
}
void userInput(int* n)
{
	int ans;
	printf("Enter the array operation you'd like to use: \n");
	printf("[1]: incrementAndInsertElement\n");
	printf("[2]: insertElementAtSpecificINdex\n");
	printf("[3]: deleteElementAtSpecificIndex\n");
	printf("[0]: Terminate Program\n");
	printf("Enter here: ");
	scanf("%d", &ans);
	
	*n = ans;
}
void operation(int n)
{
	switch (n)
	{
		case 1:
			incrementAndInsertElement();
			break;
		
		case 2:
			insertElementAtSpecificIndex();
			break;
		
		case 3:
			deleteElementAtSpecificIndex();
			break;
			
	}
}
void incrementAndInsertElement()
{
	int size, el;
	
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	
	int arr[size+1];
	
	printf("Enter the elements below: \n");
	
	createArr(arr, size);
	// create arr up to size-1 only (hence parameter is size)! Assume that this is the original array.
	// but we have allocated an extra space in (size+1), to update that array later
	// refer to line 84!
	
		// arr[size] will still be correct later on because the last index of arr[size+1] is "size"
		// Ex: size = 5+1
		// index: 0 1 2 3 4 _(to be added)
	
	printf("Array before update: ");
	display(arr, size);
	
	printf("\nEnter the value to be added: ");
	scanf("%d", &el);
	
	arr[size] = el;
	// OR: *(arr+size) = el;
	// NOTE: size is the index of the last element since size got (+1)!
	
	printf("Updated array: ");
	display(arr, ++size);
	
	// this time pre-increment size (size+1) to indicate that you are already done
	// adding the value of the last element!
}
void insertElementAtSpecificIndex()
{
	// NOTE: increment size then right shift elements from index;
	int size, el, index;
	
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	
	int arr[size+1];
	
	printf("Enter the elements of the array: ");
	createArr(arr, size);
	//NOTE: refer to line 93 - 94!
	
	printf("Array before update: ");
	display(arr, size);
	
	printf("\nEnter the element to be added: ");
	scanf("%d", &el);
	
	printf("At what index?: ");
	scanf("%d", &index);

	for (int i = size; i>index; i--)
	{
		// i = size since we're going to shift the value of arr[i-1] to arr[i] vice versa
		// Ex: 1 2 3 4 5 _ add 10 at index 2
		// Is: 1 _ 2 3 4 5
		
		arr[i] = arr[i-1];
	}
	
	*(arr+index) = el;
	
	printf("Updated array: ");
	display(arr, ++size);
}
void deleteElementAtSpecificIndex()
{
	int size, index;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	
	int arr[size];
	printf("Enter the elements of the array: ");
	createArr(arr, size);
	
	printf("Enter the index to be deleted: ");
	scanf("%d", &index);
	
	printf("Array before update: ");
	display(arr, size);
	
	for (int i = index; i<size; i++)
	{
		arr[i] = arr[i+1];
	}
	size--;

	printf("\nArray after update: ");
	display(arr, size);
}

