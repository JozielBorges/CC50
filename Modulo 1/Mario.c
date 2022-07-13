#include <cs50.h>
#include <stdio.h>
int main(void){
    int height=0, counter=0;
    do{
        height = get_int("Height: ");
    }while(height <= 0 || height >8);
    for(int i = 0; i < height; i++){
        counter++;
         for(int j = 0; j < counter; j++){
            if(j==0){
                for(int a = 0; a < height-counter; a++){
                    printf(" ");
                }
            }
            printf("#");
        }
        printf("\n");
    }
}