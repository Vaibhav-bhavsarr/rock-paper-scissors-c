#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int pscore = 0, cscore = 0;
    srand(time(NULL));

    char name[15];
    int player, computer, i = 0;
    printf("Enter Player name : ");
    scanf("%s", name);
    while (i < 3)
    {
        printf("\nRound Number %d\n", i + 1);
        printf("************ %s's turn ************\n", name);
        printf(" 1.Scissor\n 2.Paper\n 3.Rock\n");
        scanf("%d", &player);
        switch (player)
        {
        case 1:
            printf(" %s : Scissor\n", name);
            player = 1;
            break;
        case 2:
            printf("%s : Paper\n", name);
            player = 2;
            break;
        case 3:
            printf("%s : Rock\n", name);
            player = 3;
            break;

        default:
            printf("Wrong input you lost your turn\n");
        }
        computer = rand() % 3;
        switch (computer)
        {
        case 0:
            printf("Computer : Scissor\n");
            computer = 0;
            break;
        case 1:
            printf("Computer : Paper\n");
            computer = 1;
            break;
        case 2:
            printf("Computer : Rock\n");
            computer = 2;
            break;
        default:
            printf("Wrong input you lost your turn\n");
        }
        if (computer == 0 && player == 1 || computer == 1 && player == 2 || computer == 2 && player == 3)
        {
            pscore++;
            cscore++;
            printf("Tie Both Got %d point\n", pscore);
        }
        if (player == 1 && computer == 1 || player == 2 && computer == 2 || player == 3 && computer == 0)
        {
            pscore++;
            printf("%s got %d point\n", name, pscore);
        }
        else if (computer == 0 && player == 2 || computer == 2 && player == 1 || computer == 1 && player == 3)
        {
            cscore++;
            printf("computer got %d point\n", cscore);
        }
        i++;
    }

    printf("\nPlayer = %d\t Computer = %d\n", pscore, cscore);
    if (cscore > pscore)
        printf("\n\n**********Computer Wins**********");
    else if (cscore == pscore)
        printf("\n**********Tie**********");
    else
        printf("\n**********%s Wins**********", name);
}