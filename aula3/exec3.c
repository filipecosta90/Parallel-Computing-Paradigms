#include <stdio.h>
#include "omp.h"

int main (){

  int result[100];
#pragma omp for parallel schedule ( dynamic, 1 )
  for ( int i = 0; i < 100; i++ ) {
    result[i] = sin (i );
  }

}
