#include<stdio.h>
#include<conio.h>
#include<windows.h>
int board[4][4] = { 0, };
int temp[4][4] = { 0, };
int x = 1, y = 1;
int count = 0;
int winner;
void line();
void start();

int check()
{
    if ((temp[1][1] == 1 && temp[1][2] == 1 && temp[1][3] == 1) || (temp[2][1] == 1 && temp[2][2] == 1 && temp[2][3] == 1) || (temp[3][1] == 1 && temp[3][2] == 1 && temp[3][3] == 1))
    {
        winner = 1;
        return 1;
    }
    else if ((temp[1][1] == 1 && temp[2][1] == 1 && temp[3][1] == 1) || (temp[1][2] == 1 && temp[2][2] == 1 && temp[3][2] == 1) || (temp[1][3] == 1 && temp[2][3] == 1 && temp[3][3] == 1))
    {
        winner = 1;
        return 1;
    }
    else if ((temp[1][1] == 1 && temp[2][2] == 1 && temp[3][3] == 1) || (temp[1][3] == 1 && temp[2][2] == 1 && temp[3][1] == 1))
    {
        winner = 1;
        return 1;
    }
    else if ((temp[1][1] == 2 && temp[1][2] == 2 && temp[1][3] == 2) || (temp[2][1] == 2 && temp[2][2] == 2 && temp[2][3] == 2) || (temp[3][1] == 2 && temp[3][2] == 2 && temp[3][3] == 2))
    {
        winner = 2;
        return 1;
    }
    else if ((temp[1][1] == 2 && temp[2][1] == 2 && temp[3][1] == 2) || (temp[1][2] == 2 && temp[2][2] == 2 && temp[3][2] == 2) || (temp[1][3] == 2 && temp[2][3] == 2 && temp[3][3] == 2))
    {
        winner = 2;
        return 1;
    }
    else if ((temp[1][1] == 2 && temp[2][2] == 2 && temp[3][3] == 2) || (temp[1][3] == 2 && temp[2][2] == 2 && temp[3][1] == 2))
    {
        winner = 2;
        return 1;
    }
    if (count == 9)
        return 9;
    else
        return 0;
}
void PRINTBOARD()
{
    if (count % 2 == 0)
    {
        line();
        printf("1P : ■   / 2P : ●\n\n1P 차례입니다.\n");
    }
    else if (count % 2 == 1)
    {
        line();
        printf("1P : ■   / 2P : ●\n\n2P 차례입니다.\n");
    }

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (board[i][j] == 3)
                printf("☆ ");
            else if (board[i][j] == 0)
                printf("□ ");
            else if (board[i][j] == 1)
                printf("■ ");
            else if (board[i][j] == 2)
                printf("● ");
        }
        printf("\n");
    }
}
void PRINTTEMP()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (temp[i][j] == 0)
                printf("□ ");
            else if (temp[i][j] == 1)
                printf("■ ");
            else if (temp[i][j] == 2)
                printf("● ");
        }
        printf("\n");
    }
}
void DRAW()
{
    system("cls");
    printf("\n\n승부가 나지 않았습니다!!\n새로운 게임을 시작합니다.");
    Sleep(3000);
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            temp[i][j] = 0;
            board[i][j] = 0;
        }
    }
    x = 1;
    y = 1;
    count = 0;
    system("cls");
    start();
}
void line()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 20; j++)
            printf("=");
        printf("\n");
    }
}
void start()
{
    while (1)
    {
        int k;
        char op;
        board[x][y] = 3;
        PRINTBOARD();
        if (k = check())
        {
            if (k == 9)
            {
                DRAW();
                break;
            }
            system("cls");
            printf("\n\n축하합니다!!\n%dP 가 이겼습니다!!\n\n", winner);
            break;
        }
        op = getch();
        if (op == 13)
        {
            if (count % 2 == 0)
            {
                if (temp[x][y] != 0)
                {
                    printf("선택할 수 없는 위치입니다.\n\n");
                    Sleep(1000);
                    system("cls");
                    continue;
                }
                temp[x][y] = 1;
                board[x][y] = 1;
                count++;
            }
            else if (count % 2 == 1)
            {
                if (temp[x][y] != 0)
                {
                    printf("선택할 수 없는 위치입니다.\n\n");
                    Sleep(1000);
                    system("cls");
                    continue;
                }
                temp[x][y] = 2;
                board[x][y] = 2;
                count++;
            }
        }
        else if (op == 'w')
        {
            if (x >= 2)
            {
                board[x][y] = temp[x][y];
                x--;
                board[x][y] = 3;
            }
        }
        else if (op == 's')
        {
            if (x <= 2)
            {
                board[x][y] = temp[x][y];
                x++;
                board[x][y] = 3;
            }
        }
        else if (op == 'a')
        {
            if (y >= 2)
            {

                board[x][y] = temp[x][y];
                y--;
                board[x][y] = 3;
            }
        }
        else if (op == 'd')
        {
            if (y <= 2)
            {
                board[x][y] = temp[x][y];
                y++;
                board[x][y] = 3;
            }
        }
        system("cls");
    }
}
int main()
{
    while (1)
    {
        int op;

        system("cls");
        printf("1. 게임 시작\n\n2. 게임 방법\n\n3. 조작 방법\n\n[>] : ");
        scanf(" %d", &op);

        if (op == 1)
            break;
        else if (op == 2)
        {
            system("cls");
            printf("\n- player 1 과 player 2 이 번갈아 말을 둘 수 있습니다.");
            printf("\n\n- 가로, 세로, 대각선 중 한 줄을 자기 모양으로\n  먼저 채우는 사람이 이깁니다.");
            printf("\n\n- 둘 중 한 명이 이길 때까지 게임이 진행됩니다.");
            Sleep(5000);
        }
        else if (op == 3)
        {
            system("cls");
            printf("\n - 위로 이동 : w\n - 아래로 이동 : s\n - 왼쪽으로 이동: a\n - 오른쪽으로 이동 : d");
            printf("\n\n - ENTER 키 : 말 두기");
            Sleep(3500);
        }
        else
        {
            printf("\n올바른 숫자를 입력하세요.");
            Sleep(1000);
        }
    }
    system("cls");
    start();
}
