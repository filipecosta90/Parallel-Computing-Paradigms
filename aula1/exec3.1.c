#include <stdio.h>
#include <omp.h>

int main (){
#pragma omp parallel
/* 
 * ao utilizarmos pragma omp for, o ciclo for é paralelizado 
 * */
  for ( int i = 0; i<100; i++ ){
    int id = omp_get_thread_num();
    printf("%d:i%d\t",id,i);
    #pragma omp barrier
  }
}
