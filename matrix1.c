#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// compile like:  gcc -Wall -O2 -DNROWS=10000 matrix1.c -o matrix1


#define NCOLS 100

void get_walltime(double *wct) {
	struct timeval tp;
	gettimeofday(&tp,NULL);
	*wct = (double)(tp.tv_sec+tp.tv_usec/1000000.0);
}

int main() {

double *table;
double ts,te;
double sum=0.;


	table = (double *)malloc(NROWS*NCOLS*sizeof(double));
	if (table==NULL) {
	printf("alloc error!\n");
	exit(1);
	}

	
	for (int i = 0; i < NROWS * NCOLS; i++){
		table[i] = 2.;
	}

	
	get_walltime(&ts);
	
	for ( int i = 0; i < NROWS; i++){
	
		for ( int j = 0; j < NCOLS; j++){
	
			sum += table[i*NCOLS +j];

		}
  	}

  
	get_walltime(&te);
	
	double time = te - ts;
	
	printf ( " Time took = %lf\n" , time ); 
		
	printf("sum= %f\n",sum);
	


  free(table);

  return 0;
}
