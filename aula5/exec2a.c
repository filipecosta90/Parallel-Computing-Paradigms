#include <mpi.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main( int argc, char *argv[]) {
  int rank, msg;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank( MPI_COMM_WORLD, &rank ); /* Process 0 sends and Process 1 receives */
  int number_processes;
  MPI_Comm_size ( MPI_COMM_WORLD, &number_processes );
  if (rank == 0) {
    for ( int p_num = 1; p_num < number_processes; p_num++ ) {
      srand(p_num);
      msg = rand();
      MPI_Send( &msg, 1, MPI_INT, p_num, 0, MPI_COMM_WORLD);
      printf( "%d :: Sending %d to %d \n", rank, msg, p_num);
    }
  }
  else {
    MPI_Recv( &msg, 1, MPI_INT, 0 , 0, MPI_COMM_WORLD, &status ); 
    printf( "%d :: Received %d from master(0)\n", rank , msg);
    msg = rank;
    MPI_Send( &msg, 1, MPI_INT, 0 , 0, MPI_COMM_WORLD);
    printf( "%d :: Sent %d to master(0)\n", rank ,  msg);
  }
  MPI_Finalize(); 
  return 0;
}
