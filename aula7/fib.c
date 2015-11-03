#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>

int fib(int n){
  int i,j;
  if(n<2) return(n);
  i = fib (n-1);
  j = fib (n-2);
  return (i+j);
}

int main(int argc, char *argv[]){
  
  int val, n, rank;
  val=atoi(argv[1]);
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  
  if(rank == 0){
    printf("Valor: %d\n",val);
    n = fib(val);
    MPI_Send(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
  }
  else if (rank == 1){
    MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    printf("Received! Fib %d = %d\n",val,n);
  }
  MPI_Finalize();
  return 0;
}
