#include <omp.h> 
#include <stdio.h> 
#include <stdlib.h>

int main(){
  int data;
  int flag=0;
  #pragma omp parallel 
  {
    if (omp_get_thread_num()==0) {
      /* Write to the data buffer that will be read by thread */
      data = 42;
      /* Set flag to release thread 1 */
      flag = 1;
    #pragma omp flush(flag,data)
    }
    else{
      if(omp_get_thread_num()==1) {
        /* Loop until we see the update to the flag */ 
        while (flag < 1){
          #pragma omp flush(flag,data)
        }
        #pragma omp flush(data)
        printf("flag = %d\ndata = %d\n", flag, data); }
    }
  }
}
