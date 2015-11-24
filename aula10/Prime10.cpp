#include <mpi.h>
#include <stdio.h>
#include <mpi.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "PrimeCalc.cpp"
#include "PrimeServer.cpp"
#include "PrimeClientAlunos.cpp"

int main( int argc, char *argv[]) {
  int rank, msg;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank( MPI_COMM_WORLD, &rank ); /* Process 0 sends and Process 1 receives */
  int number_processes;
  MPI_Comm_size ( MPI_COMM_WORLD, &number_processes );

  if (rank==0) {
    msg = 123456;
    MPI_Send( &msg, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    printf( "%d :: Sending %d\n", rank, msg);
    PrimeServer *ps1 = new PrimeServer();
    ps1->minitFilter(1,SMAXP/3,SMAXP);

    int *ar = new int[pack/2];
    for(int i=0; i<10; i++)
    {
      generate(i*pack, (i+1)*pack, ar);
      ps1->mprocess(ar,pack/2);
      // send ar to pid 1
    }
  }
  else if ( rank == 1 ) {
    MPI_Recv( &msg, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, &status ); 
    printf( "%d :: Received %d\n", rank, msg);

    PrimeServer *ps2 = new PrimeServer();
    ps2->minitFilter(SMAXP/3+1,2*SMAXP/3,SMAXP);

    int *ar = new int[pack/2];

    for(int i=0; i<10; i++)
    {
      // receive pack ar from pid 0
      ps2->mprocess(ar,pack/2);
      // send ar to pid 2
      //
    }

  } else {
    MPI_Recv( &msg, 1, MPI_INT, rank -1 , 0, MPI_COMM_WORLD, &status ); 
    MPI_Send( &msg, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);

  }

  MPI_Finalize(); 
  return 0;
}
