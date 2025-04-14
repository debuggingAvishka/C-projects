#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void printcentered(const char *text,int width){
    int len = strlen(text);
    
    int spaces = (width-len)/2;
    for(int i=0;i<spaces;i++){
        printf("-");
    }
    printf("%s",text);
    for(int i=0;i<spaces;i++){
        printf("-");
    }
    printf("\n\n");
}
int game(char you , char computer){
    int result;
    if(you == computer){
        result= -1;
    }
    else if((you =='s' && computer=='p')||(you =='p' && computer=='z')||(you=='z' && computer=='s')){
        result = 0;
    }
    else if((you=='p' && computer=='s')||(you=='z' && computer=='p')||(you=='s' && computer=='z')){
        result = 1;
    }
    return result;
}
int main(){
    int consolewidth =120;
    char you,computer,resultf,playagain;
    srand(time(NULL));

        printcentered(" Welcome to STONE PAPER SCISSORS!! ",consolewidth);
        printf("Select any one option:\n");
        printf("\n\t1.PLAY\n\t2.EXIT\n");

        int choice;
        scanf("%d",&choice);

    
    switch(choice){
        case(1):{
            do{
               int n = rand()%100;
            if(n<33){
                computer = 's';
            }
            else if(n>33 && n<66){
                computer ='p';
            }
            else{
                computer='z';
            }

            printcentered(" Let's Play! ",consolewidth);
            printf("Instructions:\n\tEnter s for STONE, p for PAPER and z for SCISSOR\n\n");
            scanf(" %c",&you);
           
            resultf = game(you ,computer);
           
            if(resultf == -1){
                printcentered(" GAME DRAW!! ",consolewidth);
            }
            else if(resultf ==1){
                printcentered(" YOU WON!! ",consolewidth);
            }
            else if(resultf == 0){
                printcentered(" YOU LOST!! ",consolewidth);
            }
            printf("(Your Choice %c ,Computer's Choice %c)\n",you , computer);
            printf("Do you want to play again?(y for Yes//n for No): \n");
            scanf(" %c",&playagain);

            }while(playagain == 'y' || playagain == 'Y');

            break;
        }
        case(2):{
            printcentered(" Bye,See you later! ",consolewidth);
            break;
        }
        default:{
           printf("Invalid choice! Please restart the program.\n");
        }
    }
return 0;
}
