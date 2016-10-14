/*	Sample of top-down development using stubs.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

//	 Function Declarations 
	int initialize (void);
	int process    (void);
	int endOfJob   (void);

int main (void)
{
// Statements 
	printf("Begin program \n\n");

	initialize ();
	process ();
	endOfJob ();
	return 0;
}	// main 

/* ================= initialize ================== 
	Stub for initialize. 
*/
int initialize (void) 
{
	// Statements 
	printf("In initialize: \n");
	return 0;
}	// initialize 
/* =================== process ===================
	Stub for process 
*/
int process (void) 
{
	// Statements 
	printf("In process: \n");
	return 0 ;
}	// process 
/* ================== endOfJob ================== 
	Stub for endOfJob 
*/ 
int endOfJob (void) 
{
	// Statements 
	printf("In endOfJob: \n");
	return 0 ;
}	// endOfJob 

/*	Results:
Begin program 
In initialize: 
In process:  
In endOfJob:
*/