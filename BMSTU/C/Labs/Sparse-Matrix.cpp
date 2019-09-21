#include <stdio.h>
#include <stdlib.h>


typedef		//визуально отделим определение типа от структуры
struct	//sparseMatrix		//дескриптор структуры в данном случае является необязательным
{
	unsigned rows, columns;		//число строк и столбцов
	unsigned maxSize;			//максимальноче число ненулевых элементов, определяет размер буферов
	unsigned* rowIndexes;		//указатель для работы с динамическим массивом индексов
	unsigned* columnIndexes;	//указатель для работы с динамическим массивом номеров столбцов
	int* values;				//указатель для работы с динамическим массивом значений элементов
}
sparseMatrix;		//имя типа, которое фиксируется typedef

					//инициализация работы с разреженной матрицей и освобождение динамически распределённой памяти
void matrix_allocation(sparseMatrix* pMatrix, unsigned rows, unsigned columns, unsigned maxSize);
void matrix_free(sparseMatrix* pMatrix);

//установка и чтение элемента в заданной позиции
int set_element(sparseMatrix* pMatrix, unsigned row, unsigned column, int value);
int get_element(sparseMatrix* pMatrix, unsigned row, unsigned column);

//диагностический вывод всей матрицы
void print_matrix(sparseMatrix* pMatrix);		//прямоугольный вид
void print_sparseMatrix(sparseMatrix* pMatrix);	//разреженное представление

												//отказоустойчивый ввод значения типа int с клавиатуры
int input_int(char* caption);

//инициализация разреженной матрицы
void init_from_console(sparseMatrix* pMatrix);				//с клавиатуры
void init_from_file(sparseMatrix* pMatrix, char* fileName);	//из файла

															//подготовка файла для инициализации матрицы
void prepare_file(char* fileName);

int main()
{
	sparseMatrix matrix;

	//готовим работы с матрицей,
	//в том числе выделяем динамическую память
	matrix_allocation(&matrix, 4, 5, 10);

	//инициализация с клавиатуры
	//init_from_console(&matrix);

	//инициализация из файла
	//prepare_file("data.txt");
	init_from_file(&matrix, "data.txt");
	print_matrix(&matrix);
	print_sparseMatrix(&matrix);

	//освобождаем динамически распределённую память
	matrix_free(&matrix);

	getchar();
	return 0;
}

void matrix_allocation(sparseMatrix* pMatrix, unsigned rows, unsigned columns, unsigned maxSize)
{
	/*
	подготовка работы с разреженной матрицей
	*/

	//инициализируем поля структуры
	//значениями аргументов функции
	pMatrix->rows = rows;
	pMatrix->columns = columns;
	pMatrix->maxSize = maxSize;

	//динамически распределяем память под массивы
	pMatrix->rowIndexes = (unsigned*)malloc((rows + 1) * sizeof(unsigned));
	pMatrix->columnIndexes = (unsigned*)malloc(maxSize * sizeof(unsigned));
	pMatrix->values = (int*)malloc(maxSize * sizeof(int));

	//обнуляем элементы массива rowIndexes
	for (unsigned i = 0; i < (rows + 1); i++)
		pMatrix->rowIndexes[i] = 0;
}

void matrix_free(sparseMatrix* pMatrix)
{
	//освобождаем динамически распределённую память
	free(pMatrix->rowIndexes);
	free(pMatrix->columnIndexes);
	free(pMatrix->values);
}

int set_element(sparseMatrix* pMatrix, unsigned row, unsigned column, int value)
{
	/*
	функция установки элемента,
	стоящего в строке row
	в столбце column
	в значение value

	коды возврата:
	0 - успешное обновление или вставка элемента
	1 - некорректные значения индексов
	2 - для вставки элемента нет места
	*/

	unsigned i, j;

	//проверка адекватности введённых индексов строки и столбца
	//выходим с кодом возврата 1
	if ((row > pMatrix->rows) || (column > pMatrix->columns))
		return 1;

	//проверяем самый простой случай:
	//элемент уже есть разреженной матрице
	for (i = pMatrix->rowIndexes[row]; i < pMatrix->rowIndexes[row + 1]; i++)
		if (pMatrix->columnIndexes[i] == column)
		{
			if (value)
			{
				//если нашли такой элемент,
				//а value не равен 0
				//обновляем значение в массиве
				//и выходим с кодом возврата 0
				pMatrix->values[i] = value;
				return 0;
			}

			//попадаем в эту ветку кода,
			//когда value равен 0,
			//т.е. нужно стереть значащий элемент

			//для этого сдвигаем массивы
			//values и columnIndexes влево на 1 позицию
			for (j = i; j < (pMatrix->rowIndexes[pMatrix->rows] - 1); j++)
			{
				pMatrix->values[j] = pMatrix->values[j + 1];
				pMatrix->columnIndexes[j] = pMatrix->columnIndexes[j + 1];
			}

			//и уменьшаем на 1 значения элементов
			//в массиве rowIndexes начиная со следующей строки
			for (j = row + 1; j < (pMatrix->rows + 1); j++)
				pMatrix->rowIndexes[j]--;

			//выходим с кодом возврата 0
			return 0;
		}

	//в эту ветку попадаем, если в разреженном массиве
	//не встречается элемент с заданными индексами

	//проверка тривиального случая
	//0 пытаемся записать поверх 0
	//выходим с кодом возврата 0
	if (!value)
		return 0;

	//проверяем, хватит ли нам размера буфера для
	//размещения ещё одного ненулевого элемента
	//выходим с кодом возврата 2
	if (pMatrix->rowIndexes[pMatrix->rows] == pMatrix->maxSize)
		return 2;

	//если размер буфера позволяет,
	//освобождаем место для нового элемента,
	//выполняя сдвиг вправо существующих элементов
	//массивов values и columnIndexes
	for (j = pMatrix->rowIndexes[pMatrix->rows]; j > i; j--)
	{
		pMatrix->values[j] = pMatrix->values[j - 1];
		pMatrix->columnIndexes[j] = pMatrix->columnIndexes[j - 1];
	}

	//на освободившееся место записываем новый элемент
	pMatrix->values[i] = value;
	pMatrix->columnIndexes[i] = column;

	//и уменьшаем на 1 значения элементов
	//в массиве rowIndexes начиная со следующей строки
	for (j = row + 1; j < (pMatrix->rows + 1); j++)
		pMatrix->rowIndexes[j]++;

	//выходим с кодом возврата 0
	return 0;
}

int get_element(sparseMatrix* pMatrix, unsigned row, unsigned column)
{
	/*
	функция возвращает значение элемента,
	который стоит в матрице на пересечении
	строки row и столбца column
	*/

	//перебираем в массиве columnIndexes
	//только элементыс индексами, которые лежат
	//от pMatrix->rowIndexes[row]
	//до pMatrix->rowIndexes[row + 1]
	for (unsigned i = pMatrix->rowIndexes[row]; i < pMatrix->rowIndexes[row + 1]; i++)
		if (pMatrix->columnIndexes[i] == column)
			return pMatrix->values[i];

	return 0;
}

void print_matrix(sparseMatrix* pMatrix)
{
	/*
	функция распечатывает матрицу в обычном прямоугольном виде
	*/

	unsigned i, j;

	//просто проходим по всем возможным значениям индексов
	//по строкам и по столбцам
	for (i = 0; i < pMatrix->rows; i++)
	{
		for (j = 0; j < pMatrix->columns; j++)
			printf("%4d", get_element(pMatrix, i, j));
		printf("\n");
	}
	printf("\n\n");
}

void print_sparseMatrix(sparseMatrix* pMatrix)
{
	unsigned i;

	//этот массив всегда имеет (rows + 1) элемент
	printf("Row indexes array:\n");
	for (i = 0; i < (pMatrix->rows + 1); i++)
		printf("%4u", pMatrix->rowIndexes[i]);

	//в этом массиве число актуальных элементов определяется
	//значением последнего элемента массива rowIndexes
	printf("\nColumn indexes array:\n");
	for (i = 0; i < pMatrix->rowIndexes[pMatrix->rows]; i++)
		printf("%4u", pMatrix->columnIndexes[i]);

	printf("\nValues array:\n");
	for (i = 0; i < pMatrix->rowIndexes[pMatrix->rows]; i++)
		printf("%4d", pMatrix->values[i]);

	printf("\n\n");
}

int input_int(char* caption)
{
	/*
	функция реализует отказоустойчивый ввод целого числа
	параметр caption - это строка, которая является
	подсказкой для пользователя, что ему необходимо вводить
	*/

	int input;

	//организуем бесконечный цикл
	do
	{
		//выводим предложение ввести некий параметр
		printf("Input %s\n", caption);
		//если успешно прочитано 1 целое число
		if (scanf("%d", &input) == 1)
			//выходим из цикла
			break;
		//в противном случае
		printf("Invalid input!\n");
		//очищаем символы, оставшиеся в буфере ввода
		while (getchar() != '\n');
	} while (1);

	//очищаем символы, оставшиеся в буфере ввода
	while (getchar() != '\n');

	//возвращаем прочитанное с клавиатуры значение
	return input;
}

void init_from_console(sparseMatrix* pMatrix)
{
	/*
	функция реализцет отказоустойчивый ввод
	элементов матрицы
	*/

	int row, column;
	int value;
	char c;

	//организуем бесконечный цикл
	do
	{
		//запрашиваем у пользователя параметры,
		//необходимые для вызова set_element
		row = input_int("row");
		column = input_int("column");
		value = input_int("value");

		//вызываем set_element, при этом обрабатываем
		//код его возврата при помощи switch
		switch (set_element(pMatrix, row, column, value))
		{
		case 1: printf("Index out of range!\n");  break;
		case 2: printf("Buffer overflow!\n"); break;
		default: print_matrix(pMatrix); break;
		}

		//организуем ещё один бесконечный цикл
		do
		{
			printf("Continue? (y/n)\n");
			//читаем ОДИН символ
			c = getchar();
			//в случае положительного ответа пользователя
			//выходим из вложенного цикла, идём на новую
			//итерацию большого цикла
			if (c == 'y' || c == 'Y')
				break;
			//в случае отрицательного ответа пользователя
			//прерываем исполнение функции в целом
			if (c == 'n' || c == 'N')
				return;
			//во всех остальных случаях
			printf("Invalid input!\n");
			//очищаем символы, оставшиеся в буфере ввода
			while (getchar() != '\n');
		} while (1);

	} while (1);
}

void init_from_file(sparseMatrix* pMatrix, char* fileName)
{
	/*
	функция инициализации матрицы на основе данных
	в текстовом файле
	предполагается чтение данных в виде троек чисел
	(row, column, value)
	*/

	FILE* fp;

	//открываем файл на чтение ("r" - read)
	if (!(fp = fopen(fileName, "r")))
	{
		//обработка ситуации, когда это сделать не удалось
		printf("Can not open file!\n");
		return;
	}

	unsigned row, column;
	int value;

	do
	{
		//проверяем, удалось ли fscanf прочитать 3 значения, как и задумано
		if (fscanf(fp, "%u %u %d", &row, &column, &value) == 3)
			//если да - можно вызывать set_element
			set_element(pMatrix, row, column, value);
		else
			//если нет - в файле обнаружена ошибка,
			//прекращаем его обработку
			break;
	} while (!feof(fp));
	//штатное завершение цикла - когда достигнут конец файла

	//не забываем завершить работу с файлом
	fclose(fp);
}

void prepare_file(char* fileName)
{
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
