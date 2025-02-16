#include <stdio.h>
#include <string.h>
#include <ctype.h>

void question(int* n);
void functionIdentifier(int n);
void reverseString();
void reverseStringPointers();
void countVowels();
void countConsonant();
void isPalindrome();
void isSubsequent();

int main ()
{
	int n;
	do
	{
		question(&n);
		
		if (n == 0)
		{
			printf("Program Terminated.");
			break;
		}
		
		functionIdentifier(n);
		
	} while (n!=0);
	
	return 0;
}
void question(int* n)
{
	int ans;
	printf("\nChoose the function you'd like to implement on the strings: \n");
	printf("[1]: reverseString\n");
	printf("[2]: reverseStringPointers\n");
	printf("[3]: countVowels\n");
	printf("[4]: countConsonant\n");
	printf("[5]: isPalindrome\n");
	printf("[6]: isSubsequent\n");
	printf("[0]: End.\n");
	
	scanf("%d", &ans);
	while (getchar() != '\n');
	*n = ans;
}
void functionIdentifier(int n)
{
	switch (n)
	{
		case 1:
			reverseString();
			break;
		
		case 2:
			reverseStringPointers();
			break;
		
		case 3: 
			countVowels();
			break;
		
		case 4: 
			countConsonant();
 			break;		 	
		
		case 5: 
			isPalindrome();
			break;
		
		case 6:
			isSubsequent();
			break;
	}	
}
void reverseString()
{
	char str[20];
	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);
	
	str[strcspn(str, "\n")] = '\0';
	size_t len = strlen(str);
	printf("The reverse of the word %s is: ", str);
	for (int i = 0; i<len/2; i++)
	{
		char temp;
		temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
	}
	printf("%s\n", str);
}
void reverseStringPointers()
{
	char str[20];
	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);
	
	str[strcspn(str, "\n")] = '\0';
	size_t len = strlen (str);
	
	printf("The reverse of the word %s using pointer format is: ", str);
	for (int i = 0; i<len/2; i++)
	{
		int temp;
		temp = *(str+i);
		*(str+i) = *(str+len-1-i);
		*(str+len-1-i) = temp;
	}
	printf("%s", str);
}
void countVowels()
{
	char str[20];
	int ctr = 0;
	
	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);
	
	str[strcspn(str, "\n")] = '\0';
	size_t len = strlen(str);
	
	for (int i = 0; i<len; i++)
	{
		char c = tolower(str[i]);
		if (c == 'a' || c == 'e' | c == 'i' || c == 'o' || c == 'u')
		{
			ctr++;
		}
	}
	printf("The word %s has %d vowels letters\n", str, ctr);
}
void countConsonant()
{
	char str[20];
	int ctr = 0;
	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);
	
	str[strcspn(str, "\n")] = '\0';
	size_t len = strlen(str);
	
	for (int i = 0; i<len; i++)
	{
		char c = tolower(str[i]);
		if (isalpha(c) && c!= 'a' && c!= 'e' && c!= 'i' && c!= 'o' && c!= 'u')
		{
			ctr++;
		}
	}
	printf("The word %s has %d consonant letters\n", str, ctr);	
}
void isPalindrome()
{
	char str[20];
	int isPalindrome = 1;
	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);
	
	str[strcspn(str, "\n")] = '\0';
	
	size_t len = strlen(str);
	
	for(int i = 0; i<len/2; i++)
	{	
		if (tolower(str[i]) != tolower(str[len-1-i]))
		{
			isPalindrome = 0;
			break;
		}
	}
	
	if (!isPalindrome)
		printf("The word %s is not a Palindrome!", str);
	else
		printf("The word %s is a Palindrome!", str);
}
void isSubsequent()
{
	char str1[20], str2[20];
	int isSubsequent = 0;
	printf("Enter main string: ");
	fgets(str1, sizeof(str1), stdin);
	printf("Enter subsequent string: ");
	fgets(str2, sizeof(str2), stdin);
	
	str1[strcspn(str1, "\n")] = '\0';
	str2[strcspn(str2, "\n")] = '\0';
	
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	
	int i=0, j=0;
	for (i; i<len1; i++)
	{
		if (str1[i] == str2[j])
		{
			j++;
			if (j == len2)
			{
				isSubsequent = 1;
				break;
			}
		}
	}
	if(isSubsequent == 1)
		printf("%s is a subsequent of %s", str2, str1);
	else
		printf("%s is not a subsequent of %s", str2, str1);
}

