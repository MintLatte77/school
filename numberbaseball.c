#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int targetsetting(time){
    int target, target1 = 0, target2 = 0, target3 = 0;
    srand(time);
    while(target1 == target2 || target2==target3 || target3 == target1){
        target1 = (rand() % 9)+1;
        target2 = (rand() % 9)+1;
        target3 = (rand() % 9)+1;
    }
    target = target1 * 100 + target2 * 10 + target3;
    return target;
}
main(){
    int target, target1 = 0, target2 = 0, target3 = 0, number = 0, number1 = 0, number2 = 0, number3 = 0, ball = 0, strike = 0, state = 0, try;
    target = targetsetting(time(NULL));
    target1 = target / 100;
    target2 = target % 100 / 10;
    target3 = target % 10;
    printf("숫자 야구!!\n숫자를 입력하여 타겟 숫자를 맞춰 보세요! : ");
    scanf("%d", &number);
    try = 1;
    if(number != target){
        while(state == 0){
            ball = 0;
            strike = 0; 
            number1 = number / 100;
            number2 = number % 100 / 10;
            number3 = number % 10;
            if (number1 == target1){
                strike = strike + 1;
            }
            else if(number1 == target2 || number1 == target3){
                ball = ball + 1;
            }
            
            if (number2 == target2){
                strike = strike + 1;
            }
            else if(number2 == target1 || number2 == target3){
                ball = ball + 1;
            }
            
            if (number3 == target3){
                strike = strike + 1;
            }
            else if(number3 == target1 || number3 == target2){
                ball = ball + 1;
            }
            
            if(strike == 0 && ball == 0){
                printf("%d : OUT\n", number);
                scanf("%d", &number);
                try = try + 1;
            }
            else if(strike != 3){
                printf("%d : %dB %dS\n", number, ball, strike);
                scanf("%d", &number);
                try = try+ 1;
            }
            else{
                state = 1;
            }
        }
    }
    printf("%d : 3S | %d번 만에 타겟 숫자를 맞췄어요!", number, try);
}