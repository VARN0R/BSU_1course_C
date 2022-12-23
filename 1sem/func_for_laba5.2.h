enum class CHOICEARRAY {
	FLOAT = 'f',
	DOUBLE = 'd',
	INT = 'i',
};


enum class CHOICE	{
	MANUAL = 'm',
	RAND = 'n',
};

template <typename T>
void choiceSort (T *Sorted, int max_elements, int &number_of_permutations, int &number_of_comparisons){
	for (int i = 0; i < max_elements; i++){
		T temp = Sorted[0]; // временная переменная для хранения значения перестановки
		for (int j= i + 1; j < max_elements; j++){
			if (Sorted[i] > Sorted[j]){
				temp = Sorted[i];
				Sorted[i] = Sorted[j];
				Sorted[j] = temp;
				number_of_permutations++;
			}
			number_of_comparisons++;
		}
	}
}


template<typename T>
void choicePaste (T *Sorted, int max_elements, int &number_of_permutations, int &number_of_comparisons){
	T buff = 0;	
	for (int i = 1; i < max_elements; i++)
	{
		buff = Sorted[i];
		for (int j = i - 1; j >= 0 && Sorted[j] > buff; j--){
			Sorted[j + 1] = Sorted[j];
			number_of_permutations++;	
			number_of_comparisons++;					
			Sorted[j + 1] = buff;
		} 	
	}
}

//-----------------------------------------------------------------------------------------------
template <typename T>
void manualArray(T *Sorted, T *a, int max_elements) {
	for (int i = 0; i<max_elements; i++){
		T str = 0;
		std::cin >> str;
		Sorted[i] = str;
		a[i] = str;
		std::cout << "[" << i << "]= " << Sorted[i] << std::endl;
	}
}

//------------------------------------------------------------------------------------------------------


template <typename T>
void randArray(T *Sorted, T *a , int max_elements) {
	for (int i = 0; i<max_elements; i++){ 
		T str = 0;
		str = rand()%100;
		Sorted[i]=str;
		a[i]=str;
		std::cout << "[" << i << "]= " << Sorted[i] << std::endl;
	}
}

void randArray(float *Sorted, float *a , int max_elements) {
	for (int i = 0; i<max_elements; i++){ 
		int str = 0;
		str = rand()%1000 / 10.f;
		Sorted[i]=str;
		a[i]=str;
		std::cout << "[" << i << "]= " << Sorted[i] << std::endl;
	}
}


//------------------------------------------------------------------------------------------------------------

