#include <stdio.h>
#include <omp.h>

int main (){
#pragma omp parallel
#pragma omp for ordered
  for ( int i = 0; i<100; i++ ){
#pragma omp ordered
    int id = omp_get_thread_num();
    printf("%d:i%d\t",id,i);
  }
}
