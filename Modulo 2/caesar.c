#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,string argv[]){
    if(argc ==2){

        for(int i = 0, n = strlen(argv[1]); i<n;i++ ){
            if(isdigit(argv[1][i] || argv[1][i] <=0)){ // Check if the key is a int, positive;
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
            int key = atoi(argv[1]); // convert the string to int;
            string text = get_string("plaintext: ");
            for(int i =0, n = strlen(text);i <n; i++){
                if(isalpha(text[i])){
                    if(islower(text[i])){
                        text[i] = (text[i] - 'a' + key)%26 + 'a';
                    }else{
                        text[i] = (text[i] - 'A' + key)%26 + 'A';
                    }

                }

            }
            printf("ciphertext: %s\n",text);
            return 0;
    }
    else{
        printf("Usage: ./caesar key\n");
        return 1;
    }
}