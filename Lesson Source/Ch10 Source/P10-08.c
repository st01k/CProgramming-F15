/*	================== processTable ====================
	Process the table to create the statistics.
	   Pre   table
	   Post  row statistics (min, max, and average) 
*/
void processTable (int** table)
{
//	Local Declarations 
int   row = 0;
int   rowMin;
int   rowMax;
float rowAve;

//	Statements
	while (table[row] != NULL)
	  {
	   rowMin = rowMinimum (table[row]);
	   rowMax = rowMaximum (table[row]);
	   rowAve = rowAverage (table[row]);
	   printf("\nThe statistics for row %d ", row + 1);
	   printf("\nThe minimum: %5d",    rowMin); 
	   printf("\nThe maximum: %5d",    rowMax); 
	   printf("\nThe average: %8.2f ", rowAve);
	   row++;
	  } // while
	return;
}	// processTable
