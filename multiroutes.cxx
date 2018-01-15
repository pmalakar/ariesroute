/*
 * Author: Preeti Malakar
 *
 * Test code for testing libroute
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#include "route.h"

int main (int argc, char *argv[]) {

	int myrank, commsize, source, destination;
	
	MPI_Init( &argc, &argv);

	MPI_Comm_rank (MPI_COMM_WORLD, &myrank);
	MPI_Comm_size (MPI_COMM_WORLD, &commsize);

  const char *fname = argv[1];
	FILE *fp = fopen(fname, "r");
  if(fp==NULL) exit(1);

  while(fscanf(fp, "%d %d", &source, &destination) > 0) {
		if (myrank == 0) //source)
		{
			printf ("Route from %d - %d\n", source, destination);
			//puts("************\n");
		
			char *path = new char[512];
			//path[0] = '\0';

	//		puts(path);			

			getRoute (source, destination) ; //, path);
//			printf("Path from %d - %d : %s\n", source, destination, path);
	

//printf ("Hop %d: [%d-%d] %d (%d %d %d %d %d %d) -> %d (%d %d %d %d %d %d)\n", hopnum, srcRank, destRank, child, childCoords[0], childCoords[1], childCoords[2], childCoords[3], childCoords[4], childCoords[5], parent, intmdtCoords[0], intmdtCoords[1], intmdtCoords[2], intmdtCoords[3], intmdtCoords[4], intmdtCoords[5]); 

			//puts("************\n");
			fflush(stdout);
		}
  }

	fclose(fp);

	MPI_Finalize();

	return 0;
}
