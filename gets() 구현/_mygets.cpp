#include<stdio.h>
void _mygets(char * ptr)
{
	char ch;
	int index = 0;
	ch = getchar();
	while (ch != '\n')
	{
		ptr[index] = ch;
		index++;
		ch = getchar();
	}
	ptr[index] = '\0';
	return;
}
int main()
{
	char str[256] = { 0, };
	_mygets(str);
	printf("%s", str);
	return 0;
}
