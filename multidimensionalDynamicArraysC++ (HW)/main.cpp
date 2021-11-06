//Задание 1. Написать функцию, добавляющую столбец
//        двухмерному массиву в указанную позицию.
//Задание 2. Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.
//Задание 3. Дана матрица порядка M×N (M строк, N столбцов). Необходимо заполнить ее значениями и написать функцию,
// осуществляющую циклический сдвиг строк и/или столбцов массива указанное количество раз и в указанную сторону.

#include <iostream>

int** allocate(const int rows, const int cols);
void clear(int** matrix, int rows);

void fillrand(int** matrix, const int rows, const int cols, int begin = 1, int end = 100);
void print(int** matrix, const int rows, const int cols);

void push_col_index(int** matrix, const int rows, int& cols, int index  = 3);
void erase_col(int** matrix, int rows, int& cols, int index = 1);

int main()
{
    using namespace std;
    
    int rows;
    cout << "Rows: "; cin >> rows;
    int cols;
    cout << "Cols: "; cin >> cols;
    
    int** matrix = allocate(rows, cols);
    
    fillrand(matrix, rows, cols);
    cout << "\nMatrix: " << endl;
    print(matrix, rows, cols);
    
    cout << "\nAdd new column: " << endl;
    
    push_col_index(matrix, rows, cols);
    print(matrix, rows, cols);
    
    cout << "\nDelete a column: " << endl;
    
    erase_col(matrix, rows, cols);
    print(matrix, rows, cols);
    
    clear(matrix, rows);
    return 0;
}

int** allocate(const int rows, const int cols)
{
    int** matrix = new int*[rows]{};
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}

void clear(int** matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix [i];
    }
    delete [] matrix;
}

void fillrand(int** matrix, const int rows, const int cols, int begin, int end)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = rand() % (end - begin) + begin;
        }
    }
}
void print(int** matrix, const int rows, const int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void push_col_index(int** matrix, const int rows, int& cols, int index)
{
    for (int i = 0; i < rows; ++i)
    {
        int* buffer = new int[cols + 1]{};
        int currentCol = 0;
        for (int j = 0; j < cols; ++j)
        {
            if(j == index)
            {
                buffer[index] = 0;
                currentCol ++;
            }
            buffer[currentCol] = matrix[i][j];
            currentCol ++;
        }
        delete [] matrix[i];
        matrix[i] = buffer;
    }
    cols++;
}
void erase_col(int** matrix, int rows, int& cols, int index)
{
    for (int i = 0; i < rows; ++i)
    {
        int* buffer = new int[cols - 1]{};
        int currentCol = 0;
        for (int j = 0; j < cols; ++j)
        {
            if(j != index)
            {
                buffer[currentCol] = matrix[i][j];
                currentCol ++;
            }
        }
        delete [] matrix[i];
        matrix[i] = buffer;
        
    }
    cols--;
}
