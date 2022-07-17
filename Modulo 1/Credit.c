#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Has some bugs :/

int main(void){
    long creditCard, aux, aux2;
    int creditCardMap[16],aux3[16],countAux,digits,initialDigits,initialDigits1;

    creditCard = get_long("Credit card:");
    aux = creditCard;
    int count=0;
    while(aux >0){ //Get each number from the credit card.

        aux2 = aux % 10;
        aux = aux / 10;
        if(aux >9 && aux <100){ //take the 2 initial digits;
            initialDigits = aux;
            initialDigits1 = aux /10;
        }
        creditCardMap[count] = aux2;
        count++;

    }
    digits = count;

    count =1;
    for(int i=1; i < 16; i++){ //Transfer the numbers to another brand new vector
        creditCardMap[i] = creditCardMap[i] *2;
        if(i==1){
            aux3[i-1] =creditCardMap[i];
        }else if(i>1){
            aux3[count] =creditCardMap[i];
            count++;
        }
       i = i+1;
    }
    count =0;
    countAux=0;

    do{ //divide the numbers and sum them;
        if(aux3[countAux] >9){
            aux = aux3[countAux];
            aux3[countAux] = aux3[countAux] %10;
            aux3[countAux+1] = aux /10;
        }
        count++;
        countAux++;
    }while(count <=16);

    count=0;
    aux2 =0;
    do{
        aux2 = aux2+aux3[count];
        count++;

    }while(count <=10);

    for(int i=0; i < 16; i++){
        aux2 += creditCardMap[i];

       i = i+1;
    }


    if(digits==15 && initialDigits1 ==3){
        printf("AMEX\n");
    }else if(digits ==16 && initialDigits1==5){
        printf("MASTERCARD\n");
    }else if (digits >=13 && digits<=16 && initialDigits1 ==4){
        printf("VISA\n");
    }else{
        printf("INVALID\n");
    }


    return 0;
}