//CODING ASSIGNMENT 1
//FINDING_TARGET_SUM
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.

#include<iostream>
#include<string>

int* find_indices(int size, int array[], int target)
{
	int* result = new int[2]();
	int flag = 0;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			int total = array[i] + array[j];
			
			if (total == target)
			{
				result[0] = i;
				result[1] = j;
				flag = 1;
			}	
			if (flag == 1)
				return result;
		}
	}
	return result;
}

//Function to validate dynamic input array
int* TestDynamicIp(int* target)
{
	int size=0;
	std::cout << "\nEnter the size of dynamic array:";
	std::cin >> size;
	int* array{ new int[size] {} };
	std::cout << "\nEnter the elements of array:";
	for (int i = 0; i < size; i++)
		std::cin >> array[i];
	int* result{};
	*target=0;
	std::cout << "\nEnter target for dynamic array:";
	std::cin >> *target;
	std::cout << "\nArray:";
	for (int i = 0; i < size; i++)
		std::cout << " " << array[i];
	result = find_indices(size, array, *target);
	delete[] array;
	return result;
}

//Function to validate array with same elements that adds  up to same target
int* TestSameNum(int* target)
{
	int array[] = { 1,1,1,1,1,1,1,1,1 };
	int size = sizeof(array) / sizeof(array[0]);
	int* result{};
	*target = 2;
	std::cout << "\nArray:";
	for (int i = 0; i < size; i++)
		std::cout << " " << array[i];
	result = find_indices(size, array, *target);
	return result;
}

//Function to validate array with repetitive elements
int* TestRepetitiveNum(int* target)
{
	int array[] = { 1,-2,5,2,5,16,7,-4};
	int size = sizeof(array) / sizeof(array[0]);
	int* result{};
	*target = 7;
	std::cout << "\nArray:";
	for (int i = 0; i < size; i++)
		std::cout << " " << array[i];
	result = find_indices(size, array, *target);
	return result;
}
//Function to validate array with all postive numbers, true  target
int* TestPositiveNumT(int* target)
{
	int array[]={2,5,7,9,11,15};
	int size = sizeof(array) / sizeof(array[0]);
	int* result{};
	*target = 12;
	std::cout << "\nArray:";
	for (int i = 0; i < size; i++)
		std::cout << " " << array[i];
	result = find_indices(size, array, *target);
	return result;
}

//Function to validate array with all postive numbers, false  target
int* TestPositiveNumF(int *target)
{
	int array[] = { 2,5,7,9,11,15 };
	int size = sizeof(array) / sizeof(array[0]);
	int* result{};
	*target = 10;
	std::cout << "\nArray:";
	for (int i = 0; i < size; i++)
		std::cout << " " << array[i];
	result = find_indices(size, array, *target);
	return result;
}

//Function to validate array with all negative numbers,true target 
int* TestNegativeNumT(int* target)
{
	int array[]= { -5,-2,-9,-10,-22 };
	int size = sizeof(array) / sizeof(array[0]);
	int* result{};
	*target =-32;
	std::cout << "\nArray:";
	for (int i = 0; i < size; i++)
		std::cout << " " << array[i];
	result = find_indices(size, array, *target);
	return result;
}

// Function to validate array with all negative numbers, false target
int* TestNegativeNumF(int *target)
{
	int array[] = { -5,-2,-9,-10,-22 };
	int size = sizeof(array) / sizeof(array[0]);
	int* result{};
	*target = 20;
	std::cout << "\nArray:";
	for (int i = 0; i < size; i++)
		std::cout << " " << array[i];
	result = find_indices(size, array, *target);
	return result;
}

//Function to validate array with postive and numbers, true target
int* TestMixedNumT(int* target)
{
	int array[]={-1,3,5,-6};
	int size = sizeof(array) / sizeof(array[0]);
	int* result{};
	*target = -1;
	std::cout << "\nArray:";
	for (int i = 0; i < size; i++)
		std::cout << " " << array[i];
	result = find_indices(size, array, *target);
	return result;
}

//Function to validate array with postive and numbers and false target
int* TestMixedNumF(int *target)
{
	int array[] = { -1,3,5,-6 };
	int size = sizeof(array) / sizeof(array[0]);
	int* result{};
	*target = 11;
	std::cout << "\nArray:";
	for (int i = 0; i < size; i++)
		std::cout << " " << array[i];
	result = find_indices(size, array, *target);
	return result;
}

//Main function
int main()
{
	int target[9] = {0};
	int* result[9];
	const char* display[9] = { "all positive & true target", "all positive & false target",
		"all negative & true target","all negative & false target ","mixed & true target",
		"mixed & false target", "Repetitive elements array","All Same elements array","Dynamic array" };

	//Function calls to test cases
	std::cout<<"\n---------------------INPUT TEST CASES------------------\n";
	result[0]=TestPositiveNumT(&target[0]);
	result[1] = TestPositiveNumF(&target[1]);
	result[2]=TestNegativeNumT(&target[2]);
	result[3] = TestNegativeNumF(&target[3]);
	result[4]=TestMixedNumT(&target[4]);
	result[5] = TestMixedNumF(&target[5]);
	result[6] = TestRepetitiveNum(&target[6]);
	result[7] = TestSameNum(&target[7]);
	result[8] = TestDynamicIp(&target[8]);

	//Display results 
	std::cout << "\n--------------------RESULTS---------------------------\n";
	for (int i = 0; i < 9; i++)
	{
		std::cout << "\nResult for " << display[i] << " case:\n";
		if (result[i][0] != result[i][1])
			std::cout << "\tThe two indices which adss up to " << target[i] << " are: " << result[i][0] << " and " << result[i][1]<<"\n";
		else
			std::cout << "\tNo two indices adds up to " << target[i] <<"\n";
	}
	
	return 0;
}


