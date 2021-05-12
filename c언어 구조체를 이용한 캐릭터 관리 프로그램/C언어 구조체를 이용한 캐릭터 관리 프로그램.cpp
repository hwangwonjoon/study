#include<stdio.h>
#include<string.h>
int count = 0;  //존재하는 캐릭터 수를 카운팅 하기 위한 변수.

struct character {
	char name[30];
	int level;
	char job[30];
};
struct character ch[100];   //구조체 선언

int op1()
{
	printf("[>] 이    름 : ");
	scanf("%s", ch[count].name);    //이름을 입력받고 구조체에 저장
	printf("[>] LEVEL : ");
	scanf("%d", &ch[count].level);  //레벨을 입력받고 구조체에 저장
	printf("[>] 직    업 : ");
	scanf("%s", ch[count].job);     //직업을 입력받고 구조체에 저장
	printf("[>] %d번째 캐릭터 생성 완료\n\n",count+1);
    count++;    //현재 존재하는 캐릭터 수를 카운팅하는 변수 count (삭제된 캐릭터는 카운팅 X)

	for(int i=0; i<44; i++)
        printf("-");
    printf("\n");

    return 0;
}
int op2()
{
    int select;
    printf("[>] 삭제할 캐릭터의 번호 : ");
    scanf("%d",&select);

    if(select <= count && select > 0)       //유효한 숫자인지 확인. 이 부분은 삭제를 시키는 부분
    {
        for(int i=select; i<count; i++)     //예를 들어 A B C D 이렇게 있는데 C를 삭제할 경우, 한칸씩 앞으로 당겨지기 때문에 A B D 와 같이 캐릭터가 존재할 것이다. 이것을 표현한 부분이다.
        {
            strcpy(ch[i-1].name, ch[i].name);   //이름 멤버를 한칸씩 옮긴다.
            strcpy(ch[i-1].job, ch[i].job);     //직업 멤버를 한칸씩 옮긴다.
            ch[i-1].level = ch[i].level;        //레벨 멤버를 한칸씩 옮긴다.
        }
        count--;                //삭제했으니까 카운트 하나를 빼줘야 한다.
         printf("[>] 삭제 완료.\n\n");
    }
    else
        printf("[>]유효한 값을 입력해주세요.\n");
}
int op3()
{
    int c = 1;
    for(int i=0; i<count; i++)  //앞에서 삭제 과정이 있다 하더라도 한칸씩 당겨지기 때문에 연속되어 있을 것이다. 그래서 캐릭터 수만큼 for 문을 실행시키면 된다.
    {
            printf("[>] %d번째 캐릭터\n[>] 이   름 : %s\n[>] LEVEL : %d\n[>] 직  업 : %s\n\n",c, ch[i].name, ch[i].level, ch[i].job);
            c++;
    }
}
int op4()
{
    int select;
    char op[3];
    printf("수정할 캐릭터의 번호를 입력하세요.\n[>] ");
    scanf(" %d",&select);
    if(select<=0 || select >count)  //수정할 캐릭터 번호가 유효한 숫자인지 체크하는 부분.
    {
        printf("유효한 값을 입력해주세요\n\n");
        return 0;
    }
    printf("[>] 이    름 : %s\n[>] LEVEL : %d\n[>]작   업 : %s\n\n",ch[select-1].name, ch[select-1].level, ch[select-1].job);
    while(1)    //앞에서 select 변수의 값이 유효한 값이라면 수정 진행.
    {
        printf("위 캐릭터의 정보를 수정하시습니까?\n내용 수정을 원하면 Y, 아니면 N을 눌러주세요.\n[>] ");
        scanf(" %s",op);
        if(strcmp(op,"Y")==0) //수정을 원한다면
        {
            int x;
            printf("이    름 수정을 원하시면 1\nLEVEL 수정을 원하시면 2\n직    업 수정을 원하시면 3\n[>] ");
            scanf(" %d",&x);
            if(x == 1)
            {
                char changename[10];
                printf("바꿀 이름을 입력해주세요\n[>] ");
                scanf(" %s",changename);
                strcpy(ch[select-1].name, changename);  //새로운 이름을 기존의 이름에 덮어쓴다.
                printf("[*] 변환완료\n\n");
                break;
            }
            else if(x == 2)
            {
                int changelevel;
                printf("바꿀 LEVEL을 입력해주세요\n[>] ");
                scanf(" %d",&changelevel);
                ch[select-1].level = changelevel;   //새로운 레벨을 기존의 레벨에 덮어쓴다.
                printf("[*] 변환완료\n\n");
                break;
            }
            else if(x == 3)
            {
                char changejob[10];
                printf("바꿀 직업을 입력해주세요\n[>] ");
                scanf(" %s",changejob);
                strcpy(ch[select-1].job, changejob);    //새로운 직업을 기존의 직업에 덮어쓴다.
                printf("[*] 변환완료\n\n");
                break;
            }
        }
        else if(strcmp(op,"N")==0)  //N 을 누르면 다시 메뉴판으로 이동
        {
            printf("\n");
            return 0;
        }
        else
            printf("다시 입력해 주세요\n\n");
    }
    return 0;
}
int menu(void)  //메뉴 출력하는 부분.
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

	return op;
}
int main()
{
	while (1)
	{
		int op;
		op = menu();    //menu()함수에서 어떤 메뉴를 실행 시킬지 반환 값으로 받아온다.

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
