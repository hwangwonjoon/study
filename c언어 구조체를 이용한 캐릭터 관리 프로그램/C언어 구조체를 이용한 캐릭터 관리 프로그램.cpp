#include<stdio.h>
#include<string.h>
int count = 0;  //�����ϴ� ĳ���� ���� ī���� �ϱ� ���� ����.

struct character {
	char name[30];
	int level;
	char job[30];
};
struct character ch[100];   //����ü ����

int op1()
{
	printf("[>] ��    �� : ");
	scanf("%s", ch[count].name);    //�̸��� �Է¹ް� ����ü�� ����
	printf("[>] LEVEL : ");
	scanf("%d", &ch[count].level);  //������ �Է¹ް� ����ü�� ����
	printf("[>] ��    �� : ");
	scanf("%s", ch[count].job);     //������ �Է¹ް� ����ü�� ����
	printf("[>] %d��° ĳ���� ���� �Ϸ�\n\n",count+1);
    count++;    //���� �����ϴ� ĳ���� ���� ī�����ϴ� ���� count (������ ĳ���ʹ� ī���� X)

	for(int i=0; i<44; i++)
        printf("-");
    printf("\n");

    return 0;
}
int op2()
{
    int select;
    printf("[>] ������ ĳ������ ��ȣ : ");
    scanf("%d",&select);

    if(select <= count && select > 0)       //��ȿ�� �������� Ȯ��. �� �κ��� ������ ��Ű�� �κ�
    {
        for(int i=select; i<count; i++)     //���� ��� A B C D �̷��� �ִµ� C�� ������ ���, ��ĭ�� ������ ������� ������ A B D �� ���� ĳ���Ͱ� ������ ���̴�. �̰��� ǥ���� �κ��̴�.
        {
            strcpy(ch[i-1].name, ch[i].name);   //�̸� ����� ��ĭ�� �ű��.
            strcpy(ch[i-1].job, ch[i].job);     //���� ����� ��ĭ�� �ű��.
            ch[i-1].level = ch[i].level;        //���� ����� ��ĭ�� �ű��.
        }
        count--;                //���������ϱ� ī��Ʈ �ϳ��� ����� �Ѵ�.
         printf("[>] ���� �Ϸ�.\n\n");
    }
    else
        printf("[>]��ȿ�� ���� �Է����ּ���.\n");
}
int op3()
{
    int c = 1;
    for(int i=0; i<count; i++)  //�տ��� ���� ������ �ִ� �ϴ��� ��ĭ�� ������� ������ ���ӵǾ� ���� ���̴�. �׷��� ĳ���� ����ŭ for ���� �����Ű�� �ȴ�.
    {
            printf("[>] %d��° ĳ����\n[>] ��   �� : %s\n[>] LEVEL : %d\n[>] ��  �� : %s\n\n",c, ch[i].name, ch[i].level, ch[i].job);
            c++;
    }
}
int op4()
{
    int select;
    char op[3];
    printf("������ ĳ������ ��ȣ�� �Է��ϼ���.\n[>] ");
    scanf(" %d",&select);
    if(select<=0 || select >count)  //������ ĳ���� ��ȣ�� ��ȿ�� �������� üũ�ϴ� �κ�.
    {
        printf("��ȿ�� ���� �Է����ּ���\n\n");
        return 0;
    }
    printf("[>] ��    �� : %s\n[>] LEVEL : %d\n[>]��   �� : %s\n\n",ch[select-1].name, ch[select-1].level, ch[select-1].job);
    while(1)    //�տ��� select ������ ���� ��ȿ�� ���̶�� ���� ����.
    {
        printf("�� ĳ������ ������ �����Ͻý��ϱ�?\n���� ������ ���ϸ� Y, �ƴϸ� N�� �����ּ���.\n[>] ");
        scanf(" %s",op);
        if(strcmp(op,"Y")==0) //������ ���Ѵٸ�
        {
            int x;
            printf("��    �� ������ ���Ͻø� 1\nLEVEL ������ ���Ͻø� 2\n��    �� ������ ���Ͻø� 3\n[>] ");
            scanf(" %d",&x);
            if(x == 1)
            {
                char changename[10];
                printf("�ٲ� �̸��� �Է����ּ���\n[>] ");
                scanf(" %s",changename);
                strcpy(ch[select-1].name, changename);  //���ο� �̸��� ������ �̸��� �����.
                printf("[*] ��ȯ�Ϸ�\n\n");
                break;
            }
            else if(x == 2)
            {
                int changelevel;
                printf("�ٲ� LEVEL�� �Է����ּ���\n[>] ");
                scanf(" %d",&changelevel);
                ch[select-1].level = changelevel;   //���ο� ������ ������ ������ �����.
                printf("[*] ��ȯ�Ϸ�\n\n");
                break;
            }
            else if(x == 3)
            {
                char changejob[10];
                printf("�ٲ� ������ �Է����ּ���\n[>] ");
                scanf(" %s",changejob);
                strcpy(ch[select-1].job, changejob);    //���ο� ������ ������ ������ �����.
                printf("[*] ��ȯ�Ϸ�\n\n");
                break;
            }
        }
        else if(strcmp(op,"N")==0)  //N �� ������ �ٽ� �޴������� �̵�
        {
            printf("\n");
            return 0;
        }
        else
            printf("�ٽ� �Է��� �ּ���\n\n");
    }
    return 0;
}
int menu(void)  //�޴� ����ϴ� �κ�.
{
	int op;
	for (int i = 0; i < 44; i++)
		printf("-");
	printf("\n");
	for (int i = 0; i < 18; i++)
		printf("-");
	printf("M E N U");
	for (int i = 0; i < 19; i++)
		printf("-");
	printf("\n");
	for (int i = 0; i < 44; i++)
		printf("-");
	printf("\n\n\t    1. ĳ���� ��     ��");
	printf("\n\t    2. ĳ���� ��     ��");
	printf("\n\t    3. ĳ���� ���� ���");
	printf("\n\t    4. ĳ���� ���� ����");
	printf("\n\t    5. ��            ��");
	printf("\n\n\n");
	for (int i = 0; i < 44; i++)
		printf("-");
	printf("\n\n[>] �޴� ���� : ");
	scanf("%d", &op);
	printf("\n\n");
	for (int i = 0; i < 44; i++)
		printf("-");
	printf("\n\n");

	return op;
}
int main()
{
	while (1)
	{
		int op;
		op = menu();    //menu()�Լ����� � �޴��� ���� ��ų�� ��ȯ ������ �޾ƿ´�.

		if (op == 1)
			op1();
        else if (op == 2)
			op2();
        else if(op == 3)
            op3();
        else if(op == 4)
            op4();
        else if(op == 5)
        {
            printf("[>] ������ּż� �����մϴ�.\n\n");
            break;
        }
        else
            printf("[>] ��ȿ�� ���� �Է����ּ���.\n\n");
	}
	return 0;
}
