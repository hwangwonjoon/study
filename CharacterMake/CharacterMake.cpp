#include<stdio.h>
#include<string.h>
int count = 0;          //현재 존재하는 캐릭터의 수를 저장하기 위해 count 변수를 선언했다.
int temp = 0;           //메뉴 3번에서 현재 존재하는 캐릭터 정보를 출력해줘야하는데 for문의 조건식을 만들기 위해 선언한 변수.
                        //맨 처음에는 for문을 count 까지 돌렸는데 이렇게 된다면 중간에 캐릭터를 삭제할경우 count 값이 변할 수 있으므로 추가하는 개수에 맞춰 for문을 돌리면 되므로 temp 변수에 카운팅시키면 삭제하는 과정에 영향을 받지 않는다.
struct character {     //구조체 선언. 이름을 담을 name, 레벨을 담을 level, 직업을 담을 job, 그리고 메뉴 2번에서 삭제된 캐릭터까지 출력하면 안되므로 이것을 체크해주기 위한 check 를 만들었다.
	char name[30];
	int level;
	char job[30];
	int check;
};
struct character ch[100];

int op1()
{
	printf("[>] 이    름 : ");
	scanf("%s", ch[count].name);    //이름을 입력받고 구조체에 저장
	printf("[>] LEVEL : ");
	scanf("%d", &ch[count].level);  //레벨을 입력받고 구조체에 저장
	printf("[>] 직    업 : ");
	scanf("%s", ch[count].job);     //직업을 입력받고 구조체에 저장
	printf("[>] %d번째 캐릭터 생성 완료\n\n",count+1);
	for(int i=0; i<44; i++)
        printf("-");
    printf("\n");
    ch[count].check = 1;    //존재하는 캐릭터는 ch[count].check 를 1 로 표시했다.
    count++;                //캐릭터수가 하나 늘었으므로 count+1 을 해주었다.
    temp++;
    return 0;
}
int op2()
{
    int select;
    printf("[>] 삭제할 캐릭터의 번호 : ");
    scanf("%d",&select);

    if(select <= count && select > 0)   //존재하는 캐릭터 번호인지, 음수인지 체크하는 부분이다.
    {
        ch[select-1].check = 0;          //구조체 멤버 중 check 는 캐릭터가 존재하는 캐릭터인지 삭제된 캐릭터인지 체크하는 멤버다. 존재하는 캐릭터는 check 멤버를 1 로, 삭제된 캐릭터는 check 멤버를 0 으로 설정했다.
        count--;                        //존재하는 캐릭터 수를 담는 count 변수이다. 캐릭터가 삭제됐으므로 count-1 을 해준다.
        printf("[>] 삭제 완료.\n\n");
    }
    else
        printf("[>]유효한 값을 입력해주세요.\n");
}
int op3()
{
    int c = 1;
    for(int i=0; i<temp; i++)
    {
        if(ch[i].check == 1)    //삭제된 캐릭터는 출력하면 안된다. 따라서 ch[i].check==1 는 존재하는 캐릭터라는 것이다.
        {
            printf("[>] %d번째 캐릭터\n[>] 이   름 : %s\n[>] LEVEL : %d\n[>] 직  업 : %s",c, ch[i].name, ch[i].level, ch[i].job);
            c++;        //출력 시, 1 2 3 ... 번째 캐릭터라고 출력하기 위해서 존재하는 캐릭터 일때만 c+1 하였다.
            printf("\n\n");
        }
    }
}
int op4()
{
    int select;
    char op;
    printf("수정할 캐릭터의 번호를 입력하세요.\n[>] ");
    scanf(" %d",&select);
    printf("[>] 이    름 : %s\n[>] LEVEL : %d\n[>]작   업 : %s\n\n",ch[select-1].name, ch[select-1].level, ch[select-1].job);
    while(1)
    {
        printf("위 캐릭터의 정보를 수정하시습니까?\n내용 수정을 원하면 Y, 아니면 N을 눌러주세요.\n[>] ");
        scanf(" %c",&op);
        if(op=='Y') //수정을 원한다면~
        {
            int x;
            printf("이    름 수정을 원하시면 1\nLEVEL 수정을 원하시면 2\n직    업 수정을 원하시면 3\n[>] ");
            scanf(" %d",&x);    //어떤 것을 수정할 지 물어본다.
            if(x == 1)  //이름을 수정하고 싶으면~
            {
                char changename[10];
                printf("바꿀 이름을 입력해주세요\n[>] ");
                scanf(" %s",changename);
                strncpy(ch[select-1].name, changename, sizeof(changename)+2); //입력받은 바꿀 이름을 기존 이름에 문자열 길이만큼 복사한다.
                printf("[*] 변환완료\n\n");
                break;
            }
            else if(x == 2)
            {
                int changelevel;
                printf("바꿀 LEVEL을 입력해주세요\n[>] ");
                scanf(" %d",&changelevel);
                ch[select-1].level = changelevel;
                printf("[*] 변환완료\n\n");
                break;
            }
            else if(x == 3)
            {
                char changejob[10];
                printf("바꿀 직업을 입력해주세요\n[>] ");
                scanf(" %s",changejob);
                strncpy(ch[select-1].job, changejob, sizeof(changejob)+2);    //입력받는 바꿀 직업을 기존 직업에 문자열 길이만큼 복사한다.
                printf("[*] 변환완료\n\n");
                break;
            }
        }
        else if(op == 'N')
        {
            printf("\n");   //대답이 N 이라면 while 문 탈출하고 다시 메뉴판 출력
            break;
        }
        else
            printf("다시 입력해 주세요\n\n");
    }
    return 0;
}
int menu(void)  //메뉴판을 출력하는 함수.
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
	printf("\n\n\t    1. 캐릭터 생     성");
	printf("\n\t    2. 캐릭터 삭     제");
	printf("\n\t    3. 캐릭터 정보 출력");
	printf("\n\t    4. 캐릭터 정보 수정");
	printf("\n\t    5. 종            료");
	printf("\n\n\n");
	for (int i = 0; i < 44; i++)
		printf("-");
	printf("\n\n[>] 메뉴 선택 : ");
	scanf("%d", &op);
	printf("\n\n");
	for (int i = 0; i < 44; i++)
		printf("-");
	printf("\n\n");

	return op;  //어떤 메뉴를 선택할 지, 입력받은 번호를 main 함수로 반환한다.
}
int main()
{
	while (1)
	{
		int op;
		op = menu();    //menu 함수에서 반환받은 명령에 따라 기능을 수행한다.

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
            printf("[>] 사용해주셔서 감사합니다.\n\n");
            break;
        }
        else
            printf("[>] 유효한 값을 입력해주세요.\n\n");
	}
	return 0;
}
