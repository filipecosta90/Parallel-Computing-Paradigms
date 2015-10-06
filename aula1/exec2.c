#include <stdio.h>
#include <omp.h>

int main (){
#pragma omp parallel
#pragma omp master
/* 
 * ao utilizarmos pgrama omp master, o ciclo for só corre no master 
 * nao paralelizamos nada!
 * */
  for ( int i = 0; i<100; i++ ){
    int id = omp_get_thread_num();
    printf("%d:i%d\t",id,i);
  }
}
