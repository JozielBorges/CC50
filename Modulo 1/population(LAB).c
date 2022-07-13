#include <stdio.h>
#include <cs50.h>

int main(void)
{
      int start,end,years=0,population;
      // TODO: Solicite o valor inicial ao usuário
      do{
            start = get_int("Start size: ");
      }
      while(start <9);
     // TODO: Solicite o valor final ao usuário
     do{
            end = get_int("End size: ");
     }while(end < start);

     // TODO: Calcule o número de anos até o limite
      population = start;
       while(population < end){
              population += (population/3) - (population/4);
              years++;
       }
     // TODO: Imprima o número de anos
     printf("Years: %i\n",years);

}