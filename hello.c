#include <stdio.h>
#include <stdlib.h>


void printBoard(char board[])
{
    printf(" %c | %c | %c \n",board[0],board[1],board[2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n",board[3],board[4],board[5]);
    printf("-----------\n");
    printf(" %c | %c | %c \n",board[6],board[7],board[8]);
}

void checkDraw(char board[])
{
    for(int i=0;i<9;i++)
    {
        if(board[i]==' ')
        {
            return;
        }

    }
    printf("Draw");
    exit(0);
}

int inputSymbol(char board[],int pno)
{

    int temp;
    printf("player %d enter position: ",pno);
    scanf("%i",&temp);
    temp--;
    if(temp>=9 || temp<1)
    {
        printf("please enter 1-9\n");
        temp = inputSymbol(board,pno);
    }
    return temp;

}

void checkWin(char board[],char symbol,int pno)
{

    if((board[0]==symbol && board[1]==symbol && board[2]==symbol)||(board[3]==symbol && board[4]==symbol && board[5]==symbol)||(board[6]==symbol && board[7]==symbol && board[8]==symbol))
    {
        printf("player %d won!\n",pno);
        exit(0);
        
    }else if((board[0]==symbol && board[3]==symbol && board[6]==symbol)||(board[1]==symbol && board[4]==symbol && board[7]==symbol)||(board[2]==symbol && board[5]==symbol && board[8]==symbol))
    {
        printf("player %d won!\n",pno);
        exit(0);
    }else if((board[0]==symbol && board[4]==symbol && board[8]==symbol)||(board[2]==symbol && board[4]==symbol && board[6]==symbol))
    {
       printf("player %d won!\n",pno);
        exit(0);
    }
}

int main()
{
    char board[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int temp;

    while(1)
    {
        printBoard(board);
        checkWin(board,'X',1);
        checkWin(board,'O',2);
        checkDraw(board);
        temp= inputSymbol(board,1);
        board[temp]='X';
        printBoard(board);
        checkWin(board,'X',1);
        checkWin(board,'O',2);
        checkDraw(board);
        temp=inputSymbol(board,2);
        board[temp]='O';

    }
}