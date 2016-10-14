/*	==================== rowAverage ====================
	This function calculates the average of the data in a row.
	   Pre   pointer to the row
	   Post  returns the average for that row 
*/
float  rowAverage (int* rowPtr) 
{
//	Local Declarations
	float  total = 0;
	float  rowAve;

//	Statements
	for (int column = 1; column <= *rowPtr; column++)
	     total += (float)*(rowPtr + column);
	rowAve = total / *rowPtr;
	return rowAve;
}	// rowAverage
