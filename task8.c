/*
 * Task 7 example which implements y = 0.5x + x^2cos(floor(x/4)-32); for x in [0,N] in one custom instruction.
 *
 *
*/
#include <stdlib.h>
#include <sys/alt_stdio.h>
#include <sys/alt_alarm.h>
#include <sys/times.h>
#include <alt_types.h>
#include <unistd.h>
#include <system.h>
#include <stdio.h>
#define ALT_CI_COMPLEXEXPRESSION_0(A) __builtin_custom_fnf(ALT_CI_COMPLEXEXPRESSION_0_N,(A))
#define ALT_CI_FP_ADD_0(A,B) __builtin_custom_fnff(ALT_CI_FP_ADD_0_N,(A),(B))

// Test case 1
//#define step 5
//#define N 52

// Test case 2
// #define step 0.1
// #define N 2551

//Test case 3
#define step 0.001
#define N 255001

// Generates the vector x and stores it in the memory
void generateVector(float x[N])
{
	int i;
	x[0] = 0;
	for (i=1; i<N; i++)
		x[i] = ALT_CI_FP_ADD_0(x[i-1],step);
}


float sumVector(float x[])
{
	int i = 1;
	float sum = 0;
	for( ; i < N; i++)
		sum = ALT_CI_FP_ADD_0(ALT_CI_COMPLEXEXPRESSION_0(x[i]),sum);
	return sum;
}


int main()
{
	// Define input vector
	 float x[N];
	 // Returned result
	 float y;
	 generateVector(x);
	 // The following is used for timing
	 clock_t exec_t1, exec_t2;  //measures number of clock cycles
	 exec_t1 = times(NULL); // get system time before starting the process
	 y = sumVector(x);
	 exec_t2 = times(NULL); // get system time after finishing the process
	 float exec_time = (float)(exec_t2 - exec_t1);
	 printf("Execution time = %f ticks. \t Result = %f", exec_time, y);
	 return 0 ;
}
