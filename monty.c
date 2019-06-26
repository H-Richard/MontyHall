#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randommod3(){
    int n = (int) (rand() % 3);
    return n;
}

int monty(int guess, int change){
    int target = randommod3();

    if(change == 0){
        printf("guess: %d target: %d\n", guess, target);
        if(guess == target){
            return 1;
        }
        return 0;
    }

    int open = randommod3();

    //Opens a new door
    while(open == target){
        open = randommod3();
    }
    if(change){
        int guess2;
        if(guess == 0){
            if(open == 1){
                guess2 = 2;
            }
            else{
                guess2 = 1;
            }
        }
        else if(guess == 1){
            if(open == 0){
                guess2 = 2;
            }
            else{
                guess2 = 0;
            }
        }
        else if(guess == 2){
            if(open == 0){
                guess2 = 1;
            }
            else
            {
                guess2 = 0;
            }
        }
        printf("guess: %d target: %d changing guess to %d\n", guess, target, guess2);
        if(guess2 == target){
            return 1;
        }
        return 0;
    }
    
}


int main(){
    srand(time( NULL ));
    int change;
    int range;
    printf("1 to switch, 0 to stay ");
    scanf("%d", &change);
    printf("enter the number of simulations ");
    scanf("%d", &range);
    int wins = 0;
    double percentage;
    for(int i = 1;i <= range;i++){
        int guess = randommod3();
        wins += monty(guess, change);
        percentage = ((float)wins)/i;
        printf("win percentage: %lf | wins: %d | games: %d\n", percentage , wins, i);
    }
    
    return 0;
}

