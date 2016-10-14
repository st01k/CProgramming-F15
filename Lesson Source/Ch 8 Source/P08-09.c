/*	================== selectionSort ===================
	Sorts by selecting smallest element in unsorted  
	portion of array and exchanging it with element at   
	the beginning of the unsorted list.
	   Pre   list must contain at least one item 
	         last contains index to last element in list 
	   Post  list rearranged smallest to largest
*/
void selectionSort (int list[], int last)
{
//	Local Declarations
	int smallest;
	int tempData;

//	Statements
	// Outer Loop
	for (int current = 0; current < last; current++)
	    {
	     smallest = current;
	     // Inner Loop: One sort pass each loop
	     for (int walk = current + 1; 
	              walk <= last;
	              walk++)
	         if (list[walk] < list[smallest])
	             smallest = walk;
	    // Smallest selected: exchange with current
	    tempData       = list[current];
	    list[current]  = list[smallest];
	    list[smallest] = tempData;
	    } // for current
	return;
}	// selectionSort
