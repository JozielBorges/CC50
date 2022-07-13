#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,string argv[]){

    if(argc != 2){
        printf("Uso: ./ chave de substituição");
        return 1;
    }
    if(strlen(argv[1]) != 26){
        printf("A chave deve conter 26 caracteres.");
        return 1;
    }

    for(int i=0, n = strlen(argv[1]); i<n;i++){
        if(!isalpha(argv[1][i])){
            printf("A chave deve conter 26 caracteres(letras).");
            return 1;
        }

        if(argv[1][i] == argv[1][i+1]){
            printf("A chave não deve conter caracteres repetidos.");
            return 1;
        }
    }

    string text = get_string("Plaintext: ");
    string ciphertext = text;

    for(int i =0, n = strlen(text);i <n; i++){
        if(isalpha(text[i])){
            if(islower(text[i])){
                ciphertext[i] = (text[i] - 'a');
            }else{
                ciphertext[i] = (text[i] - 'A')+26;
            }

            for(int j =0, m = strlen(argv[1]); j<m;j++){
                if(ciphertext[i]>=26){
                    if(ciphertext[i]-26 == j){
                        ciphertext[i] = toupper(argv[1][j]);
                    }
                }else{
                    if(ciphertext[i] == j){
                        ciphertext[i] = tolower(argv[1][j]);
                    }
                }
            }
        }
    }
    printf("ciphertext: %s\n",ciphertext);
    return 0;
}