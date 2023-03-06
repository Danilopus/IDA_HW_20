#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
//#include <array>

//----------- Service functions prototypes -------------------------
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);
//----------- INTEGER Input filtrers -------------------------------
int Get_Int_SA();				// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();			// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
int Get_Int_PG();				// peek&get вариант проверки ввода INTEGER	
//----------- DOUBLE Input filtrers --------------------------------
double Get_Dbl_SA();		// String-analysis вариант фильтра DOUBLE.
double Get_Dbl_Positive();	// String-analysis вариант фильтра DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get вариант проверки ввода DOUBLE	


// Homework 20 -----------------------------------------------------

//Task 1
void show_arr(int arr[], int Size)
{
	Array_Console_Out(arr, Size);
}

//Task 2
template <typename ANY> int search_index(ANY arr[], int Size, ANY Value_to_Search, int begin = 0)
{
	if (begin < Size)
		for (int i = begin; i < Size; i++)
		{
			if (arr[i] == Value_to_Search) return i;
		}
	else std::cout << "\nStart position error\n";		
	return -1;
}
template <typename ANY> void search_index_demo(ANY arr[], int Size, int begin = 0)
{
	std::cout << "\nEnter a value to search first index\n";
	int Value_to_Search = Get_Int_SA();		
	std::cout << "First index (search from 0-th position) -> " << search_index(arr, Size, Value_to_Search);	
	std::cout << "\n\nEnter a position to start searching first index\n";
	begin = Get_Int_SA();
	std::cout << "First index (search from " << begin <<"-th position) -> " << search_index(arr, Size, Value_to_Search, begin);
}

//Task 3
template <typename ANY> int  search_last_index(ANY arr[], int Size, ANY Value_to_Search)
{
	for (int i = Size; i >= 0; i--)
		{
			if (arr[i] == Value_to_Search) return i;
		}
	return -1;
}
template <typename ANY> int  search_last_index(ANY arr[], int Size, ANY Value_to_Search, int begin, int end)
{
	if (begin < Size && begin < end)
		for (int i = end; i >= begin; i--)
		{
			if (arr[i] == Value_to_Search) return i;
		}
	else std::cout << "\nStart/end position error\n";
	return -1;
}
template <typename ANY> void search_last_index_demo(ANY arr[], int Size)
{
	std::cout << "\nEnter a value to search last index\n";
	int Value_to_Search = Get_Int_SA();
	std::cout << "Last index (search from 0 to 99 position) -> " << search_last_index(arr, Size, Value_to_Search);
	std::cout << "\n\nEnter a position to start searching last index\n";
	int begin = Get_Int_SA();
	std::cout << "\nEnter a position to end searching last index\n";
	int end = Get_Int_SA();
	std::cout << "\nLast index (search from " << begin << " to " << end <<" position) -> " << search_last_index(arr, Size, Value_to_Search, begin, end);
}

//Task 4
template <typename ANY> ANY arr_min(ANY arr[], int Size)
{
	ANY Temp_for_Min = arr[0];
	for (int i = 1; i < Size; i++)
	{
		if (arr[i] < Temp_for_Min) Temp_for_Min = arr[i];		
	}
	return Temp_for_Min;
}

//Task 5
template <typename ANY> ANY arr_max(ANY arr[], int Size)
{
	ANY temp_var = arr[0];
	for (int i = 1; i < Size; i++)
	{
		if (arr[i] > temp_var) temp_var = arr[i];
	}
	return temp_var;
}

//Task 6
template <typename ANY> double mean_value(ANY arr[], int Size)
{
	ANY temp_var = 0;
	for (int i = 1; i < Size; i++)
	{
		temp_var += arr[i];
	}
	return double(temp_var)/Size;
}

//Task 7
template <typename ANY> void range(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	if (Range_min < Range_max)
	{
		std::cout << "\n[";
		for (int i = 1; i < Size; i++)
		{
			if (arr[i] > Range_min && arr[i] < Range_max)
				std::cout << arr[i] << ", ";
			
		}
		std::cout << "\b\b]\n";
	}
	else std::cout << "\nRange error\n";
}
template <typename ANY> void range_demo(ANY arr[], int Size)
{
	std::cout << "\nEnter begin value of a range\n";
	int begin = Get_Int_SA();
	std::cout << "\nEnter end value of a range\n";
	int end = Get_Int_SA();
	std::cout << "\nElements of array in range [" << begin << ".." << end << "]:\n"; 
	range(arr, Size, begin, end);

}

//Task 8
template <typename ANY> int counter(ANY arr[], int Size, ANY Value_to_Count)
{
	int Counter = 0;
	for (int i = 0; i < Size; i++)
		{
		if (arr[i] == Value_to_Count)
			Counter++;
		}	
	return Counter;
}
template <typename ANY> void counter_demo(ANY arr[], int Size)
{
	std::cout << "\nEnter a value to count\n";
	int Value_to_Count = Get_Int_SA();	
	std::cout << "\nCounts "<< counter(arr, Size, Value_to_Count) << " times";
}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("mode con cols=110 lines=40"); // ??? текст основного меню не входит в окно консоли по умолчанию. При небольшом увеличении окна (lines < 85) пропадает полоса прокрутки, что не здорово. Как ee оставить и не делать (lines > 85)?
	//  START MENU -------------------------------------------------
	std::string Name_of_Work = { "Home Work 20: Functions and Arrays consolidation of knowledge" };
	std::string Menu_Element_1 = { "show_arr()" };
	std::string Menu_Element_2 = { "search_index()" };
	std::string Menu_Element_3 = { "search_last_index()" };
	std::string Menu_Element_4 = { "arr_min()" };
	std::string Menu_Element_5 = { "arr_max()" };
	std::string Menu_Element_6 = { "mean_value()" };
	std::string Menu_Element_7 = { "range()" };
	std::string Menu_Element_8 = { "counter()" };

	// -------------------------------------------------------------
	
	int const Size = 100;
	int Random_Array[Size];
	srand(time(NULL));
	Fill_Array_with_Random(Random_Array, Size, -100, 100);	

	do {		
		system("cls");
		std::cout << "\n\t***\t***\t" << Name_of_Work << "\t***\t***\n\n\t\n\nArray[100] with random [-100..100] is ready to use\n\nChoose an opion: \n";		
		std::cout << "\n 1. " << Menu_Element_1;
		std::cout << "\n 2. " << Menu_Element_2;
		std::cout << "\n 3. " << Menu_Element_3;
		std::cout << "\n 4. " << Menu_Element_4;
		std::cout << "\n 5. " << Menu_Element_5;
		std::cout << "\n 6. " << Menu_Element_6;
		std::cout << "\n 7. " << Menu_Element_7;
		std::cout << "\n 8. " << Menu_Element_8;

		std::cout << "\n\n 0. Exit\n";
		int choice = 0;
		std::cout << "\nYour choice: ";
		choice = Get_Int_Positive();		
		std::cout << "\n";
		// User choice handling
		if (choice == 0) { std::cout << "\nGood By"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0; }
		else if (choice == 1) show_arr(Random_Array, Size);
		else if (choice == 2) search_index_demo(Random_Array, Size);
		else if (choice == 3) search_last_index_demo(Random_Array, Size);
		else if (choice == 4) std::cout << "\nMinimum element -> " << arr_min(Random_Array, Size);
		else if (choice == 5) std::cout << "\nMaximum element -> " << arr_max(Random_Array, Size);
		else if (choice == 6) std::cout << "\nAverage of all elements -> " << mean_value(Random_Array, Size);
		else if (choice == 7) range_demo(Random_Array, Size);
		else if (choice == 8) counter_demo(Random_Array, Size);


			
		else { std::cout << "\nSuch choice does not exist yet\n"; Sleep(1000); }
		std::cout << "\n\n";
		system("pause");
		} while (true);
	return 0;
}

//----------- Service functions ------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); // заклинание средней силы против неудачного чтения getline
	std::cin.clear(); // заклинание малой силы против неудачного чтения getline
	getline(std::cin, a);
	//std::cout << "\nFunction: working with " << a << "\n"; для отладки
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	//std::cin.ignore(1024, '\n');
	getline(std::cin, a);
	if (a != "") // оказывается getline считывает пустую строку которую stoi уже не берет
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Incorrect input: INTEGER overflow. Decrease input\n";
			}
		}
		else
		{
			std::cout << "Incorrect symbols: positive INTEGER expected. Try again...\n";
			return Get_Int_Positive();
		}
		//return Get_Int_Positive();
	}
	else
		std::cout << "Input Error: NULL input\n";
	return Get_Int_Positive();
}
int Get_Int_PG()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! Repeat please...\n";
	}
	return a;
}
double Get_Dbl_SA(){
	std::string a;
	std::cin.sync();
	getline(std::cin, a);
	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
	if ((a.find_first_not_of("-.0123456789") == -1))
	{
		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
		{
			if (a[i] == '-')
			{
				std::cout << "\nInput Error: Minus misstanding\n";
				return Get_Dbl_SA();
			}

		}
		bool Dot_Flag = 0;
		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
		{
			if (a[i] == '.')
			{
				if (Dot_Flag == 1)
				{
					std::cout << "\nInput Error: Dot misstandig\n";
					return Get_Dbl_SA();
				}
				Dot_Flag = 1;
			}

		}		 	
				try{
					return stod(a);
				}
				catch (std::out_of_range) {
					std::cout << "Data type overflow\n";
					return Get_Dbl_SA();					
				}						
	}
	else {		
		std::cout << "Incorrect symbols: REAL expected.\nUse dot instead of coma. Example 50.64\n";
		return Get_Dbl_SA();
	}
}
double Get_Dbl_Positive(){
	std::string a, dot = "."; // = "";
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{
		if ((a.find_first_not_of(".0123456789") == -1))
		{
			bool One_Dot_already = false;
			for (int i = 0; i < a.size(); i++)
			{
				//std::cout << "\na[" << i << "] ->" << a[i]<< " == " <<dot[0];
				//std::cout << "\nflag -> " << One_Dot_already;
				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
				{
					std::cout << "dot placement error\n";
					return Get_Dbl_Positive();
				}
				if (a[i] == dot[0])	One_Dot_already = true;
			}
			try
			{
				//std::cout << "trying stod: " << a;
				//system("pause");
				return stod(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Incorrect input: Data type [DOUBLE] overflow. Decrease input\n";
				return Get_Dbl_Positive();
			}
		}
		else
		{
			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
			std::cout << "Incorrect symbols: positive REAL expected.\nUse dot instead of coma. Example 50.64\n";
			return Get_Dbl_Positive();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input\n";
		return Get_Dbl_Positive();
	}
	return Get_Dbl_Positive();
}
double Get_Dbl_PG()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! Repeat please...\n";
	}
	return a;
}
int Get_Random(int Range_min=-999, int Range_max=999)
{
	if (Range_min > Range_max) 
	{ 
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min=-9999.0, double Range_max=9999.0)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);		
	}
}
