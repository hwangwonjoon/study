#include<stdio.h>
#include<conio.h>
int mystrlen(char* ptr)
{
	int count = 0;
	while (*ptr++ != '\0')
		count++;
	return count;
}
int main()
{
	char str[256] = { 0, };
	scanf("%s", str);
	printf("%d", mystrlen(str));
}
