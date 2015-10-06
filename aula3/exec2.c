#include <math.h>
#define size 100000
#include "omp.h"

double a[size], b[size];
void main() {
  //init
#pragma omp parallel 
  {
#pragma omp for 
    for(int i=0;i<size; i++) {
      a[i] = 1.0/((double) (size-i));
      b[i] = a[i] * a[i];
    }
    // computedot
    double dot = 0;
#pragma omp for reduction (+:dot)
    for(int i=0;i<size; i++) {
      dot += a[i]*b[i];
    }
  }
#pragma omp master
  printf("Dot is %18.16f\n",dot); 
}
