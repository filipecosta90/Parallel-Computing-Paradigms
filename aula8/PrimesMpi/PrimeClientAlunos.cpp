#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include"PrimeCalc.cpp"
#include"PrimeServer.cpp"


void generate(int min, int max, int* buf) {
  int j=0;
  for(int i=min; i<max; i+=2) {
    buf[j++]=i;
  }
}

int main(int argc, char **argv) {
  int nprocesses; 
  int myrank; 

  MPI_Init (&argc, &argv); 

  MPI_Comm_size (MPI_COMM_WORLD, &nprocesses); 
  MPI_Comm_rank (MPI_COMM_WORLD, &myrank); 

  if (nprocesses !=1)  { 
    if (myrank==0) printf ("1 and only 1 processes required.\n"); 
    MPI_Finalize ();
  }
  else {
    switch(myrank) {
      case 0:
        int MAXP = 1000000;
        int SMAXP = 1000;

        PrimeServer *ps1 = new PrimeServer();
        PrimeServer *ps2 = new PrimeServer();
        PrimeServer *ps3 = new PrimeServer();

        ps1->minitFilter(1,SMAXP/3,SMAXP);
        ps2->minitFilter(SMAXP/3+1,2*SMAXP/3,SMAXP);
        ps3->minitFilter(2*SMAXP/3+1,SMAXP,SMAXP);

        int pack=MAXP/10;
        int *ar = new int[pack/2];
        for(int i=0; i<10; i++) {
          generate(i*pack, (i+1)*pack, ar);
          ps1->mprocess(ar,pack/2);
          ps2->mprocess(ar,pack/2);
          ps3->mprocess(ar,pack/2); 
        }	
        ps3->end();

        break;
    }
  }
  MPI_Finalize ();
  return(1);   
}
