#include<stdio.h>
#include<string.h>
int count = 0;          //���� �����ϴ� ĳ������ ���� �����ϱ� ���� count ������ �����ߴ�.
int temp = 0;           //�޴� 3������ ���� �����ϴ� ĳ���� ������ ���������ϴµ� for���� ���ǽ��� ����� ���� ������ ����.
                        //�� ó������ for���� count ���� ���ȴµ� �̷��� �ȴٸ� �߰��� ĳ���͸� �����Ұ�� count ���� ���� �� �����Ƿ� �߰��ϴ� ������ ���� for���� ������ �ǹǷ� temp ������ ī���ý�Ű�� �����ϴ� ������ ������ ���� �ʴ´�.
struct character {     //����ü ����. �̸��� ���� name, ������ ���� level, ������ ���� job, �׸��� �޴� 2������ ������ ĳ���ͱ��� ����ϸ� �ȵǹǷ� �̰��� üũ���ֱ� ���� check �� �������.
	char name[30];
	int level;
	char job[30];
	int check;
};
struct character ch[100];

int op1()
{
	printf("[>] ��    �� : ");
	scanf("%s", ch[count].name);    //�̸��� �Է¹ް� ����ü�� ����
	printf("[>] LEVEL : ");
	scanf("%d", &ch[count].level);  //������ �Է¹ް� ����ü�� ����
	printf("[>] ��    �� : ");
	scanf("%s", ch[count].job);     //������ �Է¹ް� ����ü�� ����
	printf("[>] %d��° ĳ���� ���� �Ϸ�\n\n",count+1);
	for(int i=0; i<44; i++)
        printf("-");
    printf("\n");
    ch[count].check = 1;    //�����ϴ� ĳ���ʹ� ch[count].check �� 1 �� ǥ���ߴ�.
    count++;                //ĳ���ͼ��� �ϳ� �þ����Ƿ� count+1 �� ���־���.
    temp++;
    return 0;
}
int op2()
{
    int select;
    printf("[>] ������ ĳ������ ��ȣ : ");
    scanf("%d",&select);

    if(select <= count && select > 0)   //�����ϴ� ĳ���� ��ȣ����, �������� üũ�ϴ� �κ��̴�.
    {
        ch[select-1].check = 0;          //����ü ��� �� check �� ĳ���Ͱ� �����ϴ� ĳ�������� ������ ĳ�������� üũ�ϴ� �����. �����ϴ� ĳ���ʹ� check ����� 1 ��, ������ ĳ���ʹ� check ����� 0 ���� �����ߴ�.
        count--;                        //�����ϴ� ĳ���� ���� ��� count �����̴�. ĳ���Ͱ� ���������Ƿ� count-1 �� ���ش�.
        printf("[>] ���� �Ϸ�.\n\n");
    }
    else
        printf("[>]��ȿ�� ���� �Է����ּ���.\n");
}
int op3()
{
    int c = 1;
    for(int i=0; i<temp; i++)
    {
        if(ch[i].check == 1)    //������ ĳ���ʹ� ����ϸ� �ȵȴ�. ���� ch[i].check==1 �� �����ϴ� ĳ���Ͷ�� ���̴�.
        {
            printf("[>] %d��° ĳ����\n[>] ��   �� : %s\n[>] LEVEL : %d\n[>] ��  �� : %s",c, ch[i].name, ch[i].level, ch[i].job);
            c++;        //��� ��, 1 2 3 ... ��° ĳ���Ͷ�� ����ϱ� ���ؼ� �����ϴ� ĳ���� �϶��� c+1 �Ͽ���.
            printf("\n\n");
        }
    }
}
int op4()
{
    int select;
    char op;
    printf("������ ĳ������ ��ȣ�� �Է��ϼ���.\n[>] ");
    scanf(" %d",&select);
    printf("[>] ��    �� : %s\n[>] LEVEL : %d\n[>]��   �� : %s\n\n",ch[select-1].name, ch[select-1].level, ch[select-1].job);
    while(1)
    {
        printf("�� ĳ������ ������ �����Ͻý��ϱ�?\n���� ������ ���ϸ� Y, �ƴϸ� N�� �����ּ���.\n[>] ");
        scanf(" %c",&op);
        if(op=='Y') //������ ���Ѵٸ�~
        {
            int x;
            printf("��    �� ������ ���Ͻø� 1\nLEVEL ������ ���Ͻø� 2\n��    �� ������ ���Ͻø� 3\n[>] ");
            scanf(" %d",&x);    //� ���� ������ �� �����.
            if(x == 1)  //�̸��� �����ϰ� ������~
            {
                char changename[10];
                printf("�ٲ� �̸��� �Է����ּ���\n[>] ");
                scanf(" %s",changename);
                strncpy(ch[select-1].name, changename, sizeof(changename)+2); //�Է¹��� �ٲ� �̸��� ���� �̸��� ���ڿ� ���̸�ŭ �����Ѵ�.
                printf("[*] ��ȯ�Ϸ�\n\n");
                break;
            }
            else if(x == 2)
            {
                int changelevel;
                printf("�ٲ� LEVEL�� �Է����ּ���\n[>] ");
                scanf(" %d",&changelevel);
                ch[select-1].level = changelevel;
                printf("[*] ��ȯ�Ϸ�\n\n");
                break;
            }
            else if(x == 3)
            {
                char changejob[10];
                printf("�ٲ� ������ �Է����ּ���\n[>] ");
                scanf(" %s",changejob);
                strncpy(ch[select-1].job, changejob, sizeof(changejob)+2);    //�Է¹޴� �ٲ� ������ ���� ������ ���ڿ� ���̸�ŭ �����Ѵ�.
                printf("[*] ��ȯ�Ϸ�\n\n");
                break;
            }
        }
        else if(op == 'N')
        {
            printf("\n");   //����� N �̶�� while �� Ż���ϰ� �ٽ� �޴��� ���
            break;
        }
        else
            printf("�ٽ� �Է��� �ּ���\n\n");
    }
    return 0;
}
int menu(void)  //�޴����� ����ϴ� �Լ�.
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

	return op;  //� �޴��� ������ ��, �Է¹��� ��ȣ�� main �Լ��� ��ȯ�Ѵ�.
}
int main()
{
	while (1)
	{
		int op;
		op = menu();    //menu �Լ����� ��ȯ���� ��ɿ� ���� ����� �����Ѵ�.

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
