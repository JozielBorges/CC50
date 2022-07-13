#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    int changes=0;
    float coin;
    do{
        coin = get_float("Troca devida: ");
    }while(coin <=0);

    int cents = round(coin *100);

    while(cents !=0){
        if((cents -25) >= 25 || (cents - 25) ==0){
            cents = cents - 25;
            changes++;
        }else if((cents - 10) >= 10 || (cents - 10) ==0){
            cents = cents - 10;
            changes++;
        }else if((cents - 5) >= 5|| (cents - 5) ==0){
            cents = cents - 5;
            changes++;
        }else if((cents - 1) >= 1|| (cents - 1) ==0){
            cents = cents - 1;
            changes++;
        }
    }

    printf("Trocas: %i \nDinheiro: %f",changes,coin);
}