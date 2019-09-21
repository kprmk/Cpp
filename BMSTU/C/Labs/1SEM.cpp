------------------------------------------------------------------------
SORTIROVKI BUBBLEEE

void swap(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void printMass(int mass[], int size)
{
	int i;

	printf("Massiv: ");
	for (i = 0; i < size; ++i)
	{
		printf("%d ", mass[i]);
	}
	printf("\n");
}

int minElement(int mass[], int size)
{
	int i, minIndex = 0;

	for (i = 1; i < size; ++i)
	{
		if (mass[i] < mass[minIndex])
		{
			minIndex = i;
		}
	}

	return minIndex;
}

int maxElement(int mass[], int N)
{
	int i, maxIndex = 0;

	for (i = 1; i < N; ++i)
	{
		if (mass[i] > mass[maxIndex])
		{
			maxIndex = i;
		}
	}

	return maxIndex;
}

void bubbleSort(int mass[], int N)
{
	int i, j, swapDone = 0;
	for (i = N - 1; i > 1; --i)
	{
		for (j = 0; j < i; ++j)
		{
			if (mass[j] > mass[j + 1])
			{
				swap(mass + j, mass + j + 1);
				swapDone = 1;
			}
		}

		if (!swapDone)
			break;
		else
			swapDone = 0;
	}
}

int main()
{
	int mass[NN] = { 2, -5, 3, 4, 0, 9, 18, 25, 7, 2 };
	printMass(mass, NN);

	bubbleSort(mass, NN);
	printMass(mass, NN);

	int min = minElement(mass, NN);
	int max = maxElement(mass, NN);
	printf("Min = %d (index = %d), ", mass[min], min);
	printf("Max = %d (index = %d)\n", mass[max], max);

	getchar();
	return 0;
}

SELECT , HAIR AND GNOMIK

void selectSort_Original(int mass[], int size)
{
	int i, j;

	for (i = 0; i < size - 1; ++i)
	{
		for (j = i + 1; j < size; ++j)
		{
			if (mass[i] > mass[j])
			{
				swap(mass + i, mass + j);
			}
		}
	}
}

void selectSort_MinFunc(int mass[], int size)
{
	int i, minIndex;

	for (int i = 0; i < size - 1; ++i)
	{
		minIndex = minElement(mass + i, size - i);

		if (minIndex)
		{
			swap(mass + i, mass + i + minIndex);
		}
	}
}

void selectSortRecursive_Original(int mass[], int size)
{
	int i;

	if (size < 2)
		return;

	for (i = 1; i < size; ++i)
	{
		if (mass[0] > mass[i])
		{
			swap(mass, mass + i);
		}
	}
	selectSortRecursive_Original(mass + 1, size - 1);
}

void selectSortRecursive_MinFunc(int mass[], int size)
{
	if (size < 2)
		return;

	int minIndex = minElement(mass, size);

	if (minIndex)
		swap(mass, mass + minIndex);

	selectSortRecursive_MinFunc(mass + 1, size - 1);
}

void hairbrushSort(int mass[], int size)
{
	int delta = 2, swapDone = 0;

	// вычислим дельту для индексов
	while (delta < size)
		delta *= 2;
	delta = delta / 2 - 1;

	while (1)
	{
		int i;

		for (i = 0; i + delta < size; ++i)
		{
			if (mass[i] > mass[i + delta])
			{
				swap(mass + i, mass + i + delta);
				++swapDone;
			}
		}
		if (delta > 1)
		{
			delta = (delta + 1) / 2 - 1;
			swapDone = 0;
		}
		else
		{
			if (!swapDone)
				break;
			else
				swapDone = 0;
		}
	}
}

void gnomeSort(int mass[], int size)
{
	int i;

	for (i = 0; i < size - 1; ++i)
	{
		if (mass[i] > mass[i + 1])
		{
			swap(mass + i, mass + i + 1);
			if (i > 0)
				i -= 2;
		}
	}
}
````````````````````````````````````````````````
LIN and BIN SEARCE

void rightShift(int mass[], unsigned left, unsigned right)
{
	for (unsigned i = right; i > left; --i)
	{
		mass[i] = mass[i - 1];
	}
}

void rightCircleShift(int mass[], unsigned left, unsigned right)
{
	int temp = mass[right];
	rightShift(mass, left, right);
	mass[left] = temp;
}

int linearSearch(int mass[], int size, int value)
{
	/*int i;
	for (i = 0; i < size; ++i)
	{
	if (mass[i] >= value)
	return i;
	}
	return size;*/

	int i = 0;
	while (i < size && mass[i++] < value);
	return i;
}

int binarySearch(int mass[], int left, int right, int value)
{
	while (right - left >= 0)
	{
		switch (right - left)
		{
		case 0:
			if (mass[left] <= value)
				return left;
			else
				return left + 1;
		default:
			if (mass[left + (right - left) / 2] == value)
				return left + (right - left) / 2;
			else if (value > mass[left + (right - left) / 2])
				left = left + (right - left) / 2 + 1;
			else
				right = left + (right - left) / 2 - 1;
		}
	}
}

int binarySearchRecursive(int mass[], int left, int right, int value)
{
	switch (right - left)
	{
	case 0:
		if (mass[left] <= value)
			return left;
		else
			return left + 1;
	default:
		if (mass[left + (right - left) / 2] == value)
			return left + (right - left) / 2;
		else if (value > mass[left + (right - left) / 2])
			return binarySearchRecursive(mass, left + (right - left) / 2 + 1, right, value);
		else
			return binarySearchRecursive(mass, left, left + (right - left) / 2 - 1, value);
	}
}

void insertSort(int mass[], int size)
{
	int i, insertIndex;
	for (int i = 1; i < size; ++i)
	{
		insertIndex = linearSearch(mass, i, mass[i]);
		if (insertIndex < i)
		{
			rightCircleShift(mass, insertIndex, i);
		}
	}
}

void insertSortRecurse(int mass[], int fullSize, int sortSize)
{
	if (sortSize > fullSize)
		return;

	int insertIndex = linearSearch(mass, sortSize - 1, mass[sortSize - 1]);

	if (insertIndex < sortSize - 1)
	{
		rightCircleShift(mass, insertIndex, sortSize - 1);
	}

	insertSortRecurse(mass, fullSize, sortSize + 1);
}

MERGG
void rightCycleShift(int mass[], int size)
{
	int i, temp = mass[size - 1];
	for (i = size - 1; i > 0; --i)
	{
		mass[i] = mass[i - 1];
	}
	mass[0] = temp;
}

void threeSort(int mass[])
{
	if (mass[0] > mass[1])
	{
		if (mass[1] >= mass[2])
		{
			swap(mass, mass + 2);
			return;
		}
		else
		{
			swap(mass, mass + 1);
			return;
		}
	}
	else if (mass[0] == mass[1])
	{
		if (mass[1] > mass[2])
		{
			swap(mass, mass + 2);
			return;
		}
	}
	else
	{
		if (mass[1] > mass[2])
		{
			swap(mass + 1, mass + 2);
			return;
		}
	}
}

void mergeBuf(int mass[], int leftSize, int rightSize)
{
	int i, leftI = 0, rightI = leftSize, mergedSize = leftSize + rightSize;
	int *mergedMass = (int*)malloc(mergedSize * sizeof(int));

	for (i = 0; i < mergedSize; ++i)
	{
		if (leftI >= leftSize)
		{
			mergedMass[i] = mass[rightI];
			++rightI;
			continue;
		}

		if (rightI >= mergedSize)
		{
			mergedMass[i] = mass[leftI];
			++leftI;
			continue;
		}

		if (mass[leftI] < mass[rightI])
		{
			mergedMass[i] = mass[leftI];
			++leftI;
		}
		else
		{
			mergedMass[i] = mass[rightI];
			++rightI;
		}
	}

	memcpy(mass, mergedMass, mergedSize * sizeof(int));
	free(mergedMass);
}

void merge(int mass[], int leftSize, int rightSize)
{
	int leftI = 0, rightI = leftSize;

	while (rightI < leftSize + rightSize)
	{
		if (leftI == rightI)
		{
			break;
		}

		if (mass[leftI] < mass[rightI])
		{
			++leftI;
			continue;
		}
		rightCycleShift(mass + leftI, rightI - leftI + 1);
		++leftI;
		++rightI;
	}
}

void mergeSort(int mass[], int size)
{
	if (size <= 1)
		return;
	else if (size == 2)
	{
		if (mass[0] > mass[1])
			swap(mass, mass + 1);

		return;
	}
	else if (size == 3)
	{
		threeSort(mass);
		return;
	}
	else
	{
		int leftSize = (size - 1) / 2 + 1, rightSize = size - leftSize; 
					//int leftSize = size / 2, rightSize = size - leftSize; 
		mergeSort(mass, leftSize);
		mergeSort(mass + leftSize, rightSize);
		// Вариант с дополнительным выделением памяти
		mergeBuf(mass, leftSize, rightSize);
		// Вариант без дополнительного выделения памяти
		//merge(mass, leftSize, rightSize);
	}
}
``````````````````````````````````````````````````````````````````````````
STR _______________________char * s && t__const char * cs && ct__ size_t n

unsigned strLength(char str[])
{
	unsigned i = 0;
	while (str[i++]);
	return i - 1;
}  
size_t strlen(cs)

char* strCopy(char *str_dest, char *str_src)
{
	if (str_src == NULL || str_dest == NULL)
	{
		printf("Error: dest or src is NULL\n");
		return NULL;
	}
	if (strLength(str_dest) < strLength(str_src))
	{
		printf("Error: dest memory is less than src memory\n");
		return NULL;
	}
	//VAR 1
	unsigned i = 0;
	while (str_src[i])
	{
		str_dest[i] = str_src[i];
		++i;
	}
	str_dest[i] = '\0';
	//VAR 2
	unsigned len = strLength(str_src);
	memcpy(str_dest, str_src, (len + 1) * sizeof(char));
	return str_dest;
}    
char *strcpy(s, ct)
char *strncpy(s, ct, n)
                                                      
char* strConcat(char *str1, char *str2)
{
	unsigned len1 = strLength(str1), len2 = strLength(str2);
	char *newstr = (char*)malloc((len1 + len2 + 1) * sizeof(char));

	// VAR 1
	unsigned i = 0;
	while (str1[i])
	{
		newstr[i] = str1[i];
		++i;
	}
	i = 0;
	while (str2[i])
	{
		newstr[len1 + i] = str2[i];
		++i;
	}
	newstr[len1 + i] = '\0';

	// VAR 2
	memcpy(newstr, str1, len1 * sizeof(char));
	memcpy(newstr + len1, str2, (len2 + 1) * sizeof(char));
	return newstr;
}         
char *strcat(s, ct)
char *strncat(s, ct, n)

int strCompare(char *str1, char *str2)
{
	// Вариант 1
	unsigned i = 0;
	while (str1[i])
	{
		if (str1[i] < str2[i])
			return -1;
		if (str1[i] > str2[i])
			return 1;
		++i;
	}

	if (str1[i] == str2[i])
		return 0;
	else
		return -1;
}       
char strcmp(cs, st)
char strncmp(cs, ct)

int strChar(char *str, char c)
{
	unsigned i = 0;
	do
	{
		if (c == str[i])
			return (int)i;
	} while (str[i++]);
	return -1;
}    
(first) char *strchr(cs, c)
(last)  char *strrchr(cs, c)

int strStr(char *str, char* substr)
{
	unsigned i = 0, subI = 0, strPos = 0;

	while (str[i])
	{
		if (!substr[subI])
			break;

		if (str[i] == substr[subI])
		{
			if (!subI)
				strPos = i;
			++subI;
		}
		else
		{
			if (subI > 0)
			{
				subI = 0;
				--i;
			}
		}
		++i;
	}

	if (subI == strLength(substr))
		return strPos;
	else
		return -1;
}
char *strstr(cs, ct)

char* gets_safe(char *buf, unsigned bufsize)
{
	unsigned i = 0;
	char c;

	while ((c = getchar()) != '\n')
	{
		if (i < bufsize - 1)
		{
			buf[i++] = c;
		}
	}
	buf[i] = '\0';
	return buf;
}

char * getstr(char *str, int max)
{
	int i = 0;
	char c;
	while ((c = getchar()) != '\n')
	{
		if (i < max - 1)
		{
			str[i++] = c;
		}
		else
		{
			puts("ERROR");
			while ((c = getchar()) != '\n');
			break;
		}
	}
	str[i] = '\0';
	if (strlen(str) == 0)
		return NULL;
	return str;
}

char * sgets(char* str, int n)
{
	char * f; 
	int i = 0;
	f = fgets(str, n, stdin);
	if (f)
	{
		while (str[i] != '\n' && str[i] != '\0')i++;
		if (str[i] == '\n')
			str[i] = '\0';
		else
			while (getchar() != '\n');
	}
	if (strlen(str) == 0)
		return NULL;
	return f;
}

char* removeChar(char *str, unsigned pos)
{
	unsigned i = pos;
	do
	{
		str[i] = str[i + 1];
	} while (str[i++]);
	return str;
}

char* removeDublicates(char *str)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	unsigned i = 0, pos = 0;

	while (str[i])
	{
		unsigned key = 1, count;

		for (count = 0; count < pos; ++count)
		{
			if (str[count] == str[i])
			{
				key = 0;
				break;
			}
		}
		if (key)
		{
			str[pos++] = str[i];
		}
		++i;
	}
	str[pos] = '\0';
	return str;
}

char* remove_duplicates(char* str)
{
	/*
	Функция удаления повторных вхождений символов в строку
	Простейшие реализации обычно основаны
	на удалении найденных повторных символов,
	что приводит к многократным сдвигам массива
	В данной реализации повторные символы не удаляются,
	а просто пропускаются.
	Зато впервые встреченные символы копируются в начало строки.
	Т.е. в начале строки начинает формироваться ответ,
	по завершении обработки всей строки после него надо будет
	только дописать '\0'.
	Тем самым мы не только избегаем сдвигов,
	но и упрощаем процедуру проверки на дубликаты.
	Уникальных символов заведомо не может быть больше,
	чем всего символов в кодовой таблице (255).
	А строка при этом может быть гораздо длиннее.
	Важно заметить, что в общем случае счётчик символов i
	обгоняет счётчик уникальных символов count,
	но между ними располагаются дублирующиеся элементы,
	поэтому на их место можно смело записывать новые обнаруженные
	уникальные элементы
	*/

	unsigned count = 1, i = 0, j, flag;

	while (str[i])
	{
		flag = 1;
		//проверка на унивальность
		//поиск среди первых (count-1) элементов
		for (j = 0; j < count; j++)
			if (str[j] == str[i])
			{
				flag = 0;
				break;
			}
		//если флаг не сброшен
		if (flag)
			//добавляем символ к числу уникальных			
			str[count++] = str[i];
		i++;
	}
	str[count] = '\0';
	return str;
}

int sumOfDigits(char *str)
{
	unsigned i = 0;
	int sum = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			sum += (str[i] - '0');
		}
		++i;
	}
	return sum;
}

int sumOfDecimals(char *str)
{
	unsigned i = 0;
	int sum = 0, num = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + str[i] - '0';

			if (str[i + 1] < '0' || str[i + 1] > '9')
			{
				sum += num;
				num = 0;
			}
		}
		++i;
	}
	if (num)
		sum += num;
	return sum;
}

char* reverseSubstring(char *str, unsigned left, unsigned right)
{
	while (left < right)
	{
		swap(str + left++, str + right--);
	}
	return str;
}

char* reverseString(char* str)
{
	return reverseSubstring(str, 0, strLength(str) - 1);
}

unsigned wordsCount(char *str)
{
	unsigned i = 0, wordsNum = 0;
	char delimiters[] = "\t\n\"'(){}[]<>+=*\\/.,:;!? ";
	do
	{
		if (strChar(delimiters, str[i]) == -1)
		{
			if (strChar(delimiters, str[i + 1]) != -1)
			{
				++wordsNum;
			}
		}
	} while (str[i++]);

	return wordsNum;
}

unsigned maxWordLen(char *str)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	unsigned i = 0, maxLen = 0, len = 0;
	char delimiters[] = "\t\n(){}[]<>+=*\\/.,:;!? ";
	do
	{
		if (strChar(delimiters, str[i]) == -1)
		{
			++len;
			if (strChar(delimiters, str[i + 1]) != -1)
			{
				if (len > maxLen)
				{
					maxLen = len;
				}
				len = 0;
			}
		}
	} while (str[i++]);

	return maxLen;
}

int MaxWordLen(char * str)  //key == 1 -inword == 0 -outside
{
	char strW[] = "{}[]()1234567890-=/*-+.,@#$%^&	 ";
	int i = 0, a = 0, b = 0, key = 0;
	while (str[i])
	{
		if (!strchr(strW, str[i]))
		{
			if (!key)
			{
				b = i;
				key = 1;
			}
			if (strchr(strW, str[i + 1]))
			{
				if (a < i + 1 - b)
				{
					a = i + 1 - b;
				}
				key = 0;
			}
		}
		i += 1;
	}
	return a;
}

unsigned longest_word(char* str)
{
	/*
	Функция нахождения длины самого длинного слова
	Общие принципы организации - аналогичны подсчёту
	числа слов в строке (см. функцию words_count).
	Проходя по строке,
	будем считать длину каждого очередного слова.
	Если она окажется больше текущей оценки
	максимальной длины - обновляем эту оценку.
	Изначально оценку полагаем равной 0.
	*/

	unsigned inWord = 0, i = 0, length = 0, maxLength = 0;
	char separator[] = " \t,.!?:;";

	do
	{
		if (char_in_string(str[i], separator))
		{
			if (inWord)
				if (length > maxLength)
					maxLength = length;
			inWord = 0;
			length = 0;
		}
		else
		{
			inWord = 1;
			length++;
		}
	} while (str[i++]);
	//при этом символ '\0' тоже будет обработан

	return maxLength;
}

unsigned shortest_word(char* str)
{
	/*
	Функция нахождения длины самого короткого слова
	Общие принципы организации - аналогичны подсчёту
	числа слов в строке (см. функцию words_count).
	Проходя по строке,
	будем считать длину каждого очередного слова.
	Если она окажется меньше текущей оценки
	минимальной длины - обновляем эту оценку
	Изначально оценку полагаем равной 0.
	Если при сравнении этих величин понимаем,
	что оценка до сих пор нулевая
	(т.е. прочитанное слово является первым),
	то его длину принимаем за оценку минимальной длины.
	*/

	unsigned inWord = 0, i = 0, length = 0, minLength = 0;
	char separator[] = " \t,.!?:;";

	do
	{
		if (char_in_string(str[i], separator))
		{
			if (inWord)
				if ((length < minLength) || !minLength)
					minLength = length;
			inWord = 0;
			length = 0;
		}
		else
		{
			inWord = 1;
			length++;
		}
	} while (str[i++]);
	//при этом символ '\0' тоже будет обработан

	return minLength;
}

unsigned minWordLen(char *str)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	unsigned i = 0, minLen = strLength(str), len = 0;
	char delimiters[] = "(){}[]<>+=*\\/.,:;!? ";
	do
	{
		if (strChar(delimiters, str[i]) == -1)
		{
			++len;
			if (strChar(delimiters, str[i + 1]) != -1)
			{
				if (len < minLen)
				{
					minLen = len;
				}
				len = 0;
			}
		}
	} while (str[i++]);

	return minLen;
}

void wordsPrint(char *str)
{
	unsigned i = 0;
	char delimiters[] = "\t\n(){}[]<>+=*\\/.,:;!? ";
	do
	{
		if (strChar(delimiters, str[i]) == -1)
		{
			putchar(str[i]);
			if (strChar(delimiters, str[i + 1]) != -1)
			{
				putchar('\n');
			}
		}
	} while (str[i++]);
}

void wordsReverse(char *str)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	unsigned i = 0, left = -1;
	char delimiters[] = "\t\n(){}[]<>+=*\\/.,:;!? ";
	do
	{
		if (strChar(delimiters, str[i]) == -1)
		{
			if (left == -1)
				left = i;

			if (strChar(delimiters, str[i + 1]) != -1)
			{
				reverseSubstring(str, left, i);
				left = -1;
			}
		}
	} while (str[i++]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MATRIX

#define M 2
#define N 3

int** matrixMemoryAllocation(int **mass, int sizeM, int sizeN)
{
	mass = (int**)malloc(sizeM * sizeof(int*));
	for (int i = 0; i < sizeM; ++i)
	{
		mass[i] = (int*)malloc(sizeN * sizeof(int));
	}
	return mass;
}

int* matrixMemoryAllocationSingle(int *mass, int sizeM, int sizeN)
{
	mass = (int*)malloc(sizeM * sizeN * sizeof(int));
	return mass;
}

int randomNum(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void matrixRandomInitStatic(int mass[][N], int sizeM)
{
	srand(time(NULL));

	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			mass[i][j] = randomNum(-5, 5);
		}
	}
}

void matrixRandomInitDynamic(int **mass, int sizeM, int sizeN)
{
	srand(time(NULL));

	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < sizeN; ++j)
		{
			mass[i][j] = randomNum(-10, 10);
		}
	}
}

void matrixRandomInitSingle(int *mass, int sizeM, int sizeN)
{
	srand(time(NULL));

	for (int i = 0; i < sizeM * sizeN; ++i)
	{
		mass[i] = randomNum(-10, 10);
	}
}

void printMatrixStatic(int mass[][N], int sizeM)
{
	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%3d ", mass[i][j]);
		}
		printf("\n");
	}
}

void printMatrixDynamic(int **mass, int sizeM, int sizeN)
{
	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < sizeN; ++j)
		{
			printf("%3d ", mass[i][j]);
		}
		printf("\n");
	}
}

void printMatrixDynamicSingle(int *mass, int sizeM, int sizeN)
{
	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < sizeN; ++j)
		{
			printf("%3d ", mass[i * sizeN + j]);
		}
		printf("\n");
	}
}

void swap(void *pa, void *pb, unsigned size)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//"unsigned size" ---> using "sizeof(TData)"//
{
	void *temp = malloc(size);
	memcpy(temp, pa, size);
	memcpy(pa, pb, size);
	memcpy(pb, temp, size);
	free(temp);
}

void swapInt(int *pa, int *pb)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;

	//swap(pa, pb, sizeof(int));
}

void swapIntPointer(int **pa, int **pb)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	int *temp = *pa;
	*pa = *pb;
	*pb = temp;

	//swap(pa, pb, sizeof(int*));
}

void swapColumnsInStaticMatrix(int mass[][N], int sizeM, int col1, int col2)
{
	if (col1 < 0 || col1 > N || col2 < 0 || col2 > N)
	{
		printf("Error: incorrect index(es) of swappig columns.");
		return;
	}

	for (unsigned i = 0; i < sizeM; ++i)
	{
		swapInt(*(mass + i) + col1, *(mass + i) + col2);
		//swapInt(&(mass[i][col1]), &(mass[i][col2]));
	}
}

void swapColumnsInDynamicMatrix(int **mass, int sizeM, int sizeN, int col1, int col2)
{
	if (col1 < 0 || col1 > sizeN || col2 < 0 || col2 > sizeN)
	{
		printf("Error: incorrect index(es) of swappig columns.");
		return;
	}

	for (unsigned i = 0; i < sizeM; ++i)
	{
		swapInt(*(mass + i) + col1, *(mass + i) + col2);
		//swapInt(&(mass[i][col1]), &(mass[i][col2]));
	}
}

void swapColumnsInDynamicSingleMatrix(int *mass, int sizeM, int sizeN, int col1, int col2)
{
	if (col1 < 0 || col1 > sizeN || col2 < 0 || col2 > sizeN)
	{
		printf("Error: incorrect index(es) of swappig columns.");
		return;
	}

	for (unsigned i = 0; i < sizeM; ++i)
	{
		swapInt(mass + i * sizeN + col1, mass + i * sizeN + col2);
		//swapInt(&(mass[i * sizeN + col1]), &(mass[i * sizeN + col2]));
	}
}

void swapRowsInStaticMatrix(int mass[][N], int sizeM, int row1, int row2)
{
	if (row1 < 0 || row1 > sizeM || row2 < 0 || row2 > sizeM)
	{
		printf("Error: incorrect index(es) of swappig rows.");
		return;
	}

	for (unsigned j = 0; j < N; ++j)
	{
		swapInt(*(mass + row1) + j, *(mass + row2) + j);
		//swapInt(&(mass[row1][j]), &(mass[row2][j]));
	}
}

void swapRowsInDynamicMatrix(int **mass, int sizeM, int sizeN, int row1, int row2)
{
	if (row1 < 0 || row1 > sizeM || row2 < 0 || row2 > sizeM)
	{
		printf("Error: incorrect index(es) of swappig rows.");
		return;
	}
	for (unsigned j = 0; j < N; ++j)
	{
		swapInt(*(mass + row1) + j, *(mass + row2) + j);
		//swapInt(&(mass[row1][j]), &(mass[row2][j]));
	}
	//swapIntPointer(mass + row1, mass + row2);
}

void swapRowsInDynamicSingleMatrix(int *mass, int sizeM, int sizeN, int row1, int row2)
{
	if (row1 < 0 || row1 > sizeM || row2 < 0 || row2 > sizeM)
	{
		printf("Error: incorrect index(es) of swappig rows.");
		return;
	}

	for (unsigned j = 0; j < sizeN; ++j)
	{
		swapInt(mass + row1 * sizeN + j, mass + row2 * sizeN + j);
		//swapInt(&(mass[row1 * sizeN + j]), &(mass[row2 * sizeN + j]));
	}
}

int** transposeStaticMatrix(int mass[][N], int sizeM)
{
	if (sizeM != N)
	{
		int **transposedMatrix = NULL;
		transposedMatrix = matrixMemoryAllocation(transposedMatrix, N, sizeM);

		for (int i = 0; i < sizeM; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				transposedMatrix[j][i] = mass[i][j];
			}
		}
		return transposedMatrix;
	}

	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			swapInt(&(mass[i][j]), &(mass[j][i]));
		}
	}
	return NULL;
}

int** transposeDynamicMatrix(int **mass, int sizeM, int sizeN)
{
	if (sizeM != sizeN)
	{
		int **transposedMatrix = NULL;
		transposedMatrix = matrixMemoryAllocation(transposedMatrix, sizeN, sizeM);

		for (int i = 0; i < sizeM; ++i)
		{
			for (int j = i + 1; j < sizeN; ++j)
			{
				transposedMatrix[j][i] = mass[i][j];
			}
		}

		return transposedMatrix;
	}

	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = i + 1; j < sizeN; ++j)
		{
			swapInt(&(mass[i][j]), &(mass[j][i]));
		}
	}

	return NULL;
}

int* transposeDynamicSingleMatrix(int *mass, int sizeM, int sizeN)
{
	if (sizeM != sizeN)
	{
		int *transposedMatrix = NULL;
		transposedMatrix = matrixMemoryAllocationSingle(transposedMatrix, sizeN, sizeM);

		for (int i = 0; i < sizeM; ++i)
		{
			for (int j = i + 1; j < sizeN; ++j)
			{
				transposedMatrix[j * sizeM + i] = mass[i * sizeN + j];
			}
		}

		return transposedMatrix;
	}

	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = i + 1; j < sizeN; ++j)
		{
			swapInt(&(mass[i * sizeN + j]), &(mass[j * sizeM + i]));
		}
	}

	return NULL;
}

int** multiplyMatrixes(int **matrix1, int **matrix2, int m1, int n1, int m2, int n2)
{
	if (n1 != m2)
	{
		printf("Error: matrix [%dx%d] can't be multiplied with matrix [%dx%d].\n", m1, n1, m2, n2);
		return NULL;
	}

	int **multiMatr = NULL;
	multiMatr = matrixMemoryAllocation(multiMatr, m1, n2);

	for (int i = 0; i < m1; ++i)
	{
		for (int j = 0; j < n2; ++j)
		{
			multiMatr[i][j] = 0;
			for (int k = 0; k < n1; ++k)
			{
				multiMatr[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return multiMatr;
}

int main()
{
	int **arr1 = NULL, **arr2 = NULL, **arr3 = NULL;

	arr1 = matrixMemoryAllocation(arr1, M, N);
	matrixRandomInitDynamic(arr1, M, N);

	arr2 = matrixMemoryAllocation(arr2, N, 2);
	matrixRandomInitDynamic(arr2, N, 2);

	printMatrixDynamic(arr1, M, N);
	printf("\n\n");
	printMatrixDynamic(arr2, N, 2);
	printf("\n\n");

	arr3 = multiplyMatrixes(arr1, arr2, M, N, N, 2);
	printMatrixDynamic(arr3, M, 2);

	getchar();
	return 0;
}

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 4
#define N 3

int randomNum(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void matrixRandomInitStatic(int mass[][N], int sizeM)
{
	srand(time(NULL));

	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			mass[i][j] = randomNum(-5, 5);
		}
	}
}

void lollyPopPrintLUStr(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (1)
	{
		unsigned key = 0;

		for (int i = left; i <= right; ++i)
		{
			if (i == left)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key == 0)
				break;

			if (i == top)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key < 2)
				break;

			if (i == right)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		for (int i = bottom; i >= top; --i)
		{
			if (key < 3)
				break;

			if (i == bottom)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		if (key < 4)
			break;
	}
}

void lollyPopPrintLDStr(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (1)
	{
		unsigned key = 0;

		for (int i = bottom; i >= top; --i)
		{
			if (i == bottom)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key == 0)
				break;

			if (i == left)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key < 2)
				break;

			if (i == top)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key < 3)
				break;

			if (i == right)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		if (key < 4)
			break;
	}
}

void lollyPopPrintRUStr(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (1)
	{
		unsigned key = 0;

		for (int i = top; i <= bottom; ++i)
		{
			if (i == top)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key == 0)
				break;

			if (i == right)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		for (int i = bottom; i >= top; --i)
		{
			if (key < 2)
				break;

			if (i == bottom)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key < 3)
				break;

			if (i == left)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		if (key < 4)
			break;
	}
}

void lollyPopPrintRDStr(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (left <= right && top <= bottom)
	{
		unsigned key = 0;

		for (int i = right; i >= left; --i)
		{
			if (i == right)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		for (int i = bottom; i >= top; --i)
		{
			if (key == 0)
				break;

			if (i == bottom)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key < 2)
				break;

			if (i == left)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key < 3)
				break;

			if (i == top)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		if (key < 4)
			break;
	}
}

void lollyPopPrintLURev(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (left <= right && top <= bottom)
	{
		unsigned key = 0;

		for (int i = top; i <= bottom; ++i)
		{
			if (i == top)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key == 0)
				break;

			if (i == left)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		for (int i = bottom; i >= top; --i)
		{
			if (key < 2)
				break;

			if (i == bottom)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key < 3)
				break;

			printf(" %d", mass[top][i]);
		}
		++top;
	}
}

void lollyPopPrintLDRev(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (left <= right && top <= bottom)
	{
		unsigned key = 0;

		for (int i = left; i <= right; ++i)
		{
			if (i == left)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		for (int i = bottom; i >= top; --i)
		{
			if (key == 0)
				break;

			if (i == bottom)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key < 2)
				break;

			if (i == right)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key < 3)
				break;

			printf(" %d", mass[i][left]);
		}
		++left;
	}
}

void lollyPopPrintRURev(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (left <= right && top <= bottom)
	{
		unsigned key = 0;

		for (int i = right; i >= left; --i)
		{
			if (i == right)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key == 0)
				break;

			if (i == top)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key < 2)
				break;

			if (i == left)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		for (int i = bottom; i >= top; --i)
		{
			if (key < 3)
				break;

			printf(" %d", mass[i][right]);
		}
		--right;
	}
}

void lollyPopPrintRDRev(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (left <= right && top <= bottom)
	{
		unsigned key = 0;

		for (int i = bottom; i >= top; --i)
		{
			if (i == bottom)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key == 0)
				break;

			if (i == right)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key < 2)
				break;

			if (i == top)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key < 3)
				break;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;
	}
}

void printMatrixStatic(int mass[][N], int sizeM)
{
	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%3d ", mass[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int m[M][N];

	matrixRandomInitStatic(m, M);
	printMatrixStatic(m, M);

	printf("\nMatrix -> straight lollypop from left upper corner:\n");
	lollyPopPrintLUStr(m, M);
	printf("\nMatrix -> straight lollypop from left down corner:\n");
	lollyPopPrintLDStr(m, M);
	printf("\nMatrix -> straight lollypop from right upper corner:\n");
	lollyPopPrintRUStr(m, M);
	printf("\nMatrix -> straight lollypop from right upper corner:\n");
	lollyPopPrintRDStr(m, M);

	printf("\nMatrix -> reverse lollypop from left upper corner:\n");
	lollyPopPrintLURev(m, M);
	printf("\nMatrix -> reverse lollypop from left down corner:\n");
	lollyPopPrintLDRev(m, M);
	printf("\nMatrix -> reverse lollypop from right upper corner:\n");
	lollyPopPrintRURev(m, M);
	printf("\nMatrix -> reverse lollypop from right upper corner:\n");
	lollyPopPrintRDRev(m, M);

	getchar();
	return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
RAZR MATRIX
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *values;
	unsigned *rowIndexes;
	unsigned *colIndexes;
	unsigned rowNum;
	unsigned colNum;
	unsigned maxSize;
} SparseMatrix;

unsigned* rightShift(unsigned *mass, unsigned left, unsigned right)
{
	for (int i = right; i > left; --i)
	{
		mass[i] = mass[i - 1];
	}

	return mass;
}

unsigned* leftShift(unsigned *mass, unsigned left, unsigned right)
{
	for (int i = left; i < right; ++i)
	{
		mass[i] = mass[i + 1];
	}

	return mass;
}

int* rightShift(int *mass, unsigned left, unsigned right)
{
	for (int i = right; i > left; --i)
	{
		mass[i] = mass[i - 1];
	}

	return mass;
}

int* leftShift(int *mass, unsigned left, unsigned right)
{
	for (int i = left; i < right; ++i)
	{
		mass[i] = mass[i + 1];
	}

	return mass;
}

void sparseMatrixInit(SparseMatrix *matr, unsigned rows, unsigned cols, unsigned maxSize)
{
	matr->rowNum = rows;
	matr->colNum = cols;
	matr->maxSize = maxSize;

	matr->values = (int*)malloc(sizeof(int) * maxSize);
	matr->colIndexes = (unsigned*)malloc(sizeof(unsigned) * maxSize);
	matr->rowIndexes = (unsigned*)malloc(sizeof(unsigned) * (rows + 1));

	for (unsigned i = 0; i <= rows; ++i)
	{
		matr->rowIndexes[i] = 0;
	}
}

void sparseMatrixDelete(SparseMatrix *matr)
{
	free(matr->values);
	free(matr->colIndexes);
	free(matr->rowIndexes);
}

int getElement(SparseMatrix *matr, unsigned row, unsigned col)
{
	if (row >= matr->rowNum)
	{
		printf("Error: incorrect row number.\n");
		return 0;
	}

	if (col >= matr->colNum)
	{
		printf("Error: incorrect column number.\n");
		return 0;
	}

	for (unsigned j = matr->rowIndexes[row]; j < matr->rowIndexes[row + 1]; ++j)
	{
		if (col == matr->colIndexes[j])
		{
			return matr->values[j];
		}
	}

	return 0;
}

int setElement(SparseMatrix *matr, unsigned row, unsigned col, int value)
{
	codes toreturn :
	0 - succesefully or set element
	1 - is not right indexes
	2 - no free place

	unsigned i, j;

	if (row >= matr->rowNum)
	{
		printf("Error: incorrect row number.\n");
		return 1;
	}

	if (col >= matr->colNum)
	{
		printf("Error: incorrect column number.\n");
		return 1;
	}

	for (j = matr->rowIndexes[row]; j < matr->rowIndexes[row + 1]; ++j)
	{
		if (col == matr->colIndexes[j])
		{
			// element besides '0'

			if (!value)
			{
				if (matr->values[j])
				{
					leftShift(matr->colIndexes, j, matr->maxSize - 1);
					leftShift(matr->values, j, matr->maxSize - 1);
					for (unsigned k = row + 1; k <= matr->rowNum; ++k)
					{
						matr->rowIndexes[k]--;
					}
				}

				return 0;
			}

			matr->values[j] = value;
			return 0;
		}
	}

	// element is '0'

	if (matr->rowIndexes[matr->rowNum] == matr->maxSize)
	{
		// no place
		return 2;
	}

	if (value)
	{
		for (i = row + 1; i <= matr->rowNum; ++i)
		{
			matr->rowIndexes[i]++;
		}

		for (j = matr->rowIndexes[row]; j < matr->rowIndexes[row + 1] - 1; ++j)
		{
			if (col < matr->colIndexes[j])
			{
				rightShift(matr->colIndexes, j, matr->maxSize - 1);
				rightShift(matr->values, j, matr->maxSize - 1);

				matr->colIndexes[j] = col;
				matr->values[j] = value;

				return 0;
			}
		}

		// if col bigger indexes in this area
		rightShift(matr->colIndexes, j, matr->maxSize - 1);
		rightShift(matr->values, j, matr->maxSize - 1);

		matr->colIndexes[j] = col;
		matr->values[j] = value;
	}

	return 0;
}

void printMatrix(SparseMatrix *matr)
{
	for (unsigned i = 0; i < matr->rowNum; ++i)
	{
		for (unsigned j = 0; j < matr->colNum; ++j)
		{
			printf("%4d", getElement(matr, i, j));
		}
		printf("\n");
	}
}

void printSparseMatrix(SparseMatrix *matr)
{
	for (unsigned i = 0; i < matr->rowNum; ++i)
	{
		for (unsigned j = matr->rowIndexes[i]; j < matr->rowIndexes[i + 1]; ++j)
		{
			printf("[I: %2u, J: %2u] -> %4d\n", i, matr->colIndexes[j], matr->values[j]);
		}
	}
}

void fillMatrixFromFile(SparseMatrix* pMatrix, char* fileName)
{
	/*
	функция инициализации матрицы на основе данных
	в текстовом файле --- init Matrix base on datas in text file (fileName)
	предполагается чтение данных в виде троек чисел --- read 3 numbers
	(row, column, value)
	*/

	FILE* fp;

	//открываем файл на чтение ("r" - read) - open file for READING
	if (!(fp = fopen(fileName, "r")))
	{
		//обработка ситуации, когда это сделать не удалось --- 
		//If it is not succesefully
		printf("Can not open file!\n");
		return;
	}

	unsigned row, column;
	int value;

	do
	{
		//проверяем, удалось ли fscanf прочитать 3 значения, как и задумано
		if (fscanf(fp, "%u %u %d", &row, &column, &value) == 3)
			//если да - можно вызывать set_element --- if "scanf()" is right - setElment
			setElement(pMatrix, row, column, value);
		else
			//если нет - в файле обнаружена ошибка, --- is not right
			//прекращаем его обработку
			break;
	} while (!feof(fp)); --- END OF FILE ---> END OF CYCLE
	//штатное завершение цикла - когда достигнут конец файла
	//не забываем завершить работу с файлом
	fclose(fp); --- END OF WORK WITH FILE
}

void prepareFile(char* fileName)
{_______________________________
	/*
	функция формирует текстовый файл,
	в котором записываются тройки чисел:
	(row, column, value)
	*/

	FILE* fp;
	char buf[50];

	//открываем файл на запись ("w" - write)
	if (!(fp = fopen(fileName, "w")))
	{
		//обработка ситуации, когда это сделать не удалось
		printf("Can not open file!\n");
		return;
	}

	do
	{
		//читаем строку из потока стандартного ввода
		fgets(buf, 50, stdin);
		//и тут же пишем её в открытый файл
		fputs(buf, fp);
	} while (buf[0] != '\n');
	//выходим, кода введённая строка - пустая
	//(сразу идёт символ перевода строки)

	//не забываем завершить работу с файлом
	fclose(fp);
}

int main()
{
	SparseMatrix matrix;

	//prepareFile("matrix.txt");		
	sparseMatrixInit(&matrix, 5, 5, 10);
	fillMatrixFromFile(&matrix, "matrix.txt");

	printSparseMatrix(&matrix);
	printf("\n\n");
	printMatrix(&matrix);

	setElement(&matrix, 1, 1, -13);
	setElement(&matrix, 0, 0, 0);
	setElement(&matrix, 3, 2, 10);
	setElement(&matrix, 2, 4, 10);
	printf("\n\n");
	printMatrix(&matrix);

	setElement(&matrix, 2, 3, 0);
	setElement(&matrix, 2, 4, 10);
	printf("\n\n");
	printMatrix(&matrix);

	sparseMatrixDelete(&matrix);

	getchar();
	return 0;
}

