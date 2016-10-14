/*	==================== rowMinimum ====================
	Determines the minimum of the data in a row.
	   Pre   given pointer to the row
	   Post  returns the minimum for that row 
*/
int rowMinimum (int* rowPtr) 
{

//	Local Declarations
	int rowMin = INT_MAX;

//	Statements
	for (int column = 1; column <= *rowPtr; column++) 
	     rowMin = smaller (rowMin, *(rowPtr + column)); 
	return rowMin;
}	// rowMinimum
