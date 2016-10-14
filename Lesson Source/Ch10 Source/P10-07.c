/*	==================== fillTable ====================
	This function fills the array rows with data. 
	   Pre   array of pointers 
	   Post  array filled 
*/
void fillTable (int** table) 
{
//	Local Declarations
	int row = 0;

//	Statements
	printf("\n =============================");
	printf("\n Now we fill the table.\n");
	printf("\n For each row enter the data");
	printf("\n and press return: ");
	printf("\n =============================\n");

	while (table[row] != NULL) 
	   {
	    printf("\n row %d (%d integers) =====> ", 
	            row + 1, table[row][0]);
	    for (int column = 1; 
	             column <= *table[row]; 
	             column++)
	         scanf("%d", table[row] + column); 
	    row++;
	   } // while
	return;
}	// fillTable
