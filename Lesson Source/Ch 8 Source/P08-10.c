/*	==================== bubbleSort ====================
	Sort list using bubble sort. Adjacent elements are 
	compared and exchanged until list is ordered.
	   Pre  the list must contain at least one item 
	        last contains index to last element in list
	   Post list rearranged in sequence low to high
*/
void bubbleSort (int list [], int last)
{
//	Local Declarations
	int temp;

//	Statements
	// Outer loop
	for(int current = 0; current < last; current++)
	   {
	    // Inner loop: Bubble up one element each pass
	    for (int walker = last;
	             walker > current;
	             walker--)
	        if (list[walker]  < list[walker - 1])
	           {
	            temp             = list[walker];
	            list[walker]     = list[walker - 1];
	            list[walker - 1] = temp;
	           } // if
	   } // for current
	return;
}	// bubbleSort
