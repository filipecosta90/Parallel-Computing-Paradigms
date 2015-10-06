#include <stdio.h>
#include <omp.h>

int main (){
#pragma omp parallel
#pragma omp single
/* 
 * ao utilizarmos prgama omp single, o ciclo for só corre numa das threads aleatoriamente 
 * nao paralelizamos nada!
 * */
  for ( int i = 0; i<100; i++ ){
    int id = omp_get_thread_num();
    printf("%d:i%d\t",id,i);
  }
}
