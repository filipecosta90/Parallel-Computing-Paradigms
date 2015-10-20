#include <mpi.h>
#include <stdio.h>

int main( int argc, char *argv[]) {
  int rank, msg;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank( MPI_COMM_WORLD, &rank ); /* Process 0 sends and Process 1 receives */
  if (rank == 0) {
    msg = 123456;
    MPI_Send( &msg, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    printf( "%d :: Sending %d\n", rank, msg);

  }
  else if ( rank == 3 ){
    MPI_Recv( &msg, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &status ); 
    printf( "%d :: Received %d\n", rank, msg);
  }
  else {
    MPI_Recv( &msg, 1, MPI_INT, rank -1 , 0, MPI_COMM_WORLD, &status ); 
    MPI_Send( &msg, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
    printf( "%d :: Received %d\n", rank , msg);
  }
  MPI_Finalize(); 
  return 0;
}
