#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void){
    string text = get_string("Text: ");

    int words=0 , phrase=0, letters=0;

    float grade;

    for(int i =0, n = strlen(text); i <n; i++){
        if(toupper(text[i]) >= 65 && toupper(text[i]) <=90){ // if has letters then change then to uppercase
            letters++;
        }else if(text[i] == ' '){
            words++;
        }else if(text[i] =='.' || text[i] =='?' || text[i] =='!'){
            phrase++;
        }
    }
    words++; //Temp fix xD

    grade = 0.0588 * ((letters*100)/words) - 0.296 * ((phrase*100)/words) - 15.8;

    if((int)grade >= 16){
        printf("Grade 16+\n");
    }else if((int)grade <1){
        printf("Before Grade 1\n");
    }else{
        printf("Grade %i\n",(int)grade);
    }

    return 0;
}