/* ==================== buildTable ====================
	  Create backbone of the table by creating an array of
	pointers, each pointing to an array of integers.
	   Pre   nothing
	   Post  returns pointer to the table
*/
int** buildTable (void) 
{
//	Local Declarations
	int   rowNum;
	int   colNum;
	int** table;
	int   row;

//	Statements
	printf("\nEnter the number of rows in the table: "); 
	scanf ("%d", &rowNum); 
	table = (int**) calloc(rowNum + 1, sizeof(int*)); 
	for (row = 0; row < rowNum; row++) 
	    {
	     printf("Enter number of integers in row %d: ", 
	             row + 1);
	     scanf ("%d", &colNum); 
	     table[row] = (int*)calloc(colNum + 1, 
	                               sizeof(int));
	     table[row] [0] = colNum; 
	    } // for
	table[row] = NULL;
	return table;
}	// buildTable
