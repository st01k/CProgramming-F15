/*	==================== rowMaximum ====================
	Calculates the maximum of the data in a row.
	   Pre   given pointer to the row 
	   Post  returns the maximum for that row
*/
int rowMaximum (int* rowPtr) 
{
//	Local Declarations
	int rowMax = INT_MIN;

//	Statements
	for (int column = 1; column <= *rowPtr; column++) 
	     rowMax = larger  (rowMax, *(rowPtr + column)); 
	return rowMax;
}	// rowMaximum
