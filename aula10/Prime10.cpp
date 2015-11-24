#include <mpi.h>
#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "PrimeCalc.cpp"
#include "PrimeServer.cpp"

void generate(int min, int max, int* buf) {
  int j=0;
  for(int i=min; i<max; i+=2) {
    buf[j++]=i;
  }
}

int main( int argc, char *argv[]) {

  int rank;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank( MPI_COMM_WORLD, &rank ); 
  int number_processes;
  MPI_Comm_size ( MPI_COMM_WORLD, &number_processes );
  int MAXP = 1000000;
  int SMAXP = 1000;
  int pack=MAXP/10;

  if (rank==0) {

    int *ar = new int[pack/2];
    PrimeServer *ps1 = new PrimeServer();
    ps1->minitFilter(1,SMAXP/3,SMAXP);

    for(int i=0; i<10; i++)
    {
      generate(i*pack, (i+1)*pack, ar);
      ps1->mprocess(ar,pack/2);
      // send ar to pid 1
    }
  }
  else if ( rank == 1 ) {

    PrimeServer *ps2 = new PrimeServer();
    ps2->minitFilter(SMAXP/3+1,2*SMAXP/3,SMAXP);

    int *ar = new int[pack/2];
    for(int i=0; i<10; i++)
    {
      // receive pack ar from pid 0
      ps2->mprocess(ar,pack/2);
      // send ar to pid 2
    }

  } else {

    PrimeServer *ps3 = new PrimeServer();
    ps3->minitFilter(2*SMAXP/3+1,SMAXP,SMAXP);

    int *ar = new int[pack/2];
    for(int i=0; i<10; i++)
    {
      // receive pack ar from pid 1
      ps3->mprocess(ar,pack/2);
      // send ar to pid 0
    }



  }

  MPI_Finalize(); 
  return 0;
}
