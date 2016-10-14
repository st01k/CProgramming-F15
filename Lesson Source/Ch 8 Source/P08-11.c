/*	================== insertionSort ==================
	Sort list using Insertion Sort. The list is divided  
	into sorted and unsorted lists. With each pass, first  
	element in unsorted list is inserted into sorted list.
	   Pre  list must contain at least one element 
	        last contains index to last element in list
	   Post list has been rearranged 
*/
void insertionSort (int list[], int last) 
{
//	Statements
//	Local Declarations
	int  walk;
	int  temp;
	bool located;

//	Statements
	// Outer loop
	for (int current = 1; current <= last; current++)
	   {
	    // Inner loop: Select and move one element
	    located = false;
	    temp = list[current];
	    for (walk = current - 1; walk >= 0 && !located;)
	       if (temp < list[walk])
	          {
	           list[walk + 1] = list[walk];
	           walk--;
	          } // if
	       else
	           located = true;
	    list [walk + 1] = temp;
	   } // for
	return;
}	// insertionSort
