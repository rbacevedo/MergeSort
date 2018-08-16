#include <iostream>
#include <vector>

//This is where most of the work is
void merge(std::vector<int> & list, std::vector<int> list_copy, size_t beginning_index, size_t middle_index, size_t ending_index)
{
	/*Copy both halves into a helper vector*/
	//Copying the entire vector until the particular ending index
	for (size_t i = 0; i <= ending_index; ++i)
	{
		list_copy.push_back(list[i]);
	}

	size_t copy_list_Left = beginning_index;//first index of the copy_list the is going to be evaluated
	size_t copy_list_Right = middle_index + 1;//Want to check everything after the middle point
	size_t current_index = beginning_index;//Want to change the original vector

	/*Iterate through the copy list. Compare the left and the right half,
	copying back the smaller element from the two halves into the original vector.*/
	//comparing both the copy of the list and the original list elements to sort them appropiately
	
	while (copy_list_Left <= middle_index && copy_list_Right <= ending_index)
	{
		if (list_copy[copy_list_Left] <= list_copy[copy_list_Right])
		{
			//changing the element of the list
			list[current_index] = list_copy[copy_list_Left];
			++copy_list_Left;
		}
		else
		{
			list[current_index] = list_copy[copy_list_Right];
			++copy_list_Right;
		}
		++current_index;
	}
	
	//Copy the rest of the left side of the array into the target array*/
	//We have to do this because we are changing directly the array from left to right until the middle
	//If there are values from the left that are greater than the values that are on the right we
	//have to include them after the last changed value
	int remaining = middle_index - copy_list_Left;
	for (int i = 0; i <= remaining; ++i)
	{
		list[current_index + i] = list_copy[copy_list_Left + i];
	}
}


void mergesort(std::vector<int> & list, std::vector<int> list_copy, size_t beginning_index, size_t ending_index)
{
	if (beginning_index < ending_index)
	{
		//remember that every single time there is a recursive call the parameter values change accordingly in the new stack frame
		size_t middle_index = (beginning_index + ending_index) / 2;
		//recursive leap of faith
		mergesort(list, list_copy, beginning_index, middle_index);//Sort left half
		mergesort(list, list_copy, middle_index + 1, ending_index);//Sort right half
		merge(list, list_copy, beginning_index, middle_index, ending_index);//Merge them
	}
}


//helper merge sort
void mergeSort(std::vector<int> & list)
{
	std::vector<int> list_copy;
	mergesort(list, list_copy, 0, list.size()-1);
}

int main()
{
	std::vector<int> list = { 9,8,5,6,7,10, 50,41 };
	mergeSort(list);
	system("pause");
	return 0;
}