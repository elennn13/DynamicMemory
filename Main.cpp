#include <iostream>
#include <cstdlib>
#include <ctime>
//Заполнение массива случайными числами
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
    srand(time(NULL));
        for (int i = 0; i < length; i++)
            arr[i] = rand() % (right - left) + left;

}


//Вывод массива в консоль
template <typename T>
void print_arr(T arr[], const int length) {
    std::cout << "{ ";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << ", ";
    std::cout << "\b\b }\n";
}


//Задача1  Создайте функцию, к.я принимает динамический массив, его длину и число. Длина переданного массива должна увеличиться на переданное значение.
template <typename T>
void arr_app(T*& arr, int& length, int num);
//Задача2
template <typename T>
void arr_pop(T*& arr, int& length, int num);


int main(){
    setlocale(LC_ALL, "ru");
    int n,m;


    //Выделение динамической памяти под переменные
    /*int* pointer = new int;//выделения динамической памяти типа int и сохранение ее адреса в указателе
    *pointer = 7;//запись в выделенную раннее динамическую память числа 7
    std::cout << "pointer = " << pointer << std::endl;
    std::cout << "*pointer = " << *pointer << std::endl;

    delete pointer; //Освобождение памяти, на которую направлен указатель

    pointer = new int;//перенаправление указателя на новую область динамической памяти
    *pointer = 15;
    std::cout << "pointer = " << pointer << std::endl;
    std::cout << "*pointer = " << *pointer << std::endl;

    //Утечка памяти -  это явление, когда в динамической памяти оставются элементы
    //у которых потерялась связь с указателями. Влечет за собой засорение оперативной 
    //памяти устройства.
    */


    //Динамические массивы
    /*std::cout << " Введите размер массива -> ";
    int dsize;
    std::cin >> dsize;
    int* darr = new int[5];

    std::cout << "Ввод данных в массив:\n";
    for (int i = 0; i < dsize; i++) {
        std::cout << " Введите " << i+1 << "-у число -> ";
        std::cin >> darr[i];
    }
    std::cout << "Итоговый массив:\n";
    print_arr(darr, dsize);

    delete[] darr;
*/


    //Двумерные динамические массивы
    int rows = 5, cols = 6;
    // int* mx = new int[rows][cols];// НЕ РАБОТАЕТ
    
    //Выделение памяти
    int** mx = new int* [rows];
    for (int i = 0; i < rows; i++)
        mx[i] = new int[cols];

    //Освобождение памяти 
    for (int i = 0; i < rows; i++)
        delete[] mx[i];
    delete[] mx;

    //Области применения динамической памяти. 
    // 1. Создание массива размер которого может 
    // быть на этапе выполнения программы;
    // 2. Создание массива размер которого должен иметь возможность измениться;
    // 3. Создание связных динамических структур данных;
    // 4. Выделение памяти для объектов в случае их крайней необходимости.

    // Задача 1. Увеличение размера массива.
/*
    std::cout << "Задача1. \nВведите размер массива -> ";
    int size1;
    std::cin >> size1;
    int* arr1 = new int[size1];
    fill_arr(arr1, size1, 10, 21);
    std::cout << "Изначальный массив:\n";
    print_arr(arr1, size1);
    std::cout << "Введите количество новых элементов -> ";
    std::cin >> n;

    arr_app(arr1, size1, n);
    std::cout << "Итоговый массив:\n";
    print_arr(arr1, size1);
*/
// Задача 2. Уменьшение размера массива
    std::cout << "Задача2. \nВведите размер массива -> ";
  
    int size2;
    std::cin >> size2;
    int* arr2 = new int[size2];
    fill_arr(arr2, size2, 10, 21);
    std::cout << "Изначальный массив:\n";
    print_arr(arr2, size2);
    std::cout << "Введите количество элементов для удаления -> ";
    std::cin >> m;

    arr_pop(arr2, size2, m);// 
    std::cout << "Итоговый массив:\n";
    print_arr(arr2, size2);
    return 0;
}



template <typename T>
void arr_app(T*& arr, int& length, int num) {
    //Шаг 0. Проверка на количество элементов для увеличения размера массива
    if (num <= 0)
        return;
   //Шаг 1. Создание нового динамического массива, нужного размера
    T* tmp = new T[length + num]{};

   //Шаг 2. Копирование значений старого массива в элементы нового массива.
    for (int i = 0; i < length; i++)
        tmp[i] = arr[i];

    //Шаг 3. Удаление старого массива
    delete[] arr;

    //Шаг 4. Перенаправление указателя на новый массив.
    arr = tmp;

    //Шаг 5. Увеличение переменной, отвечающей за размер массива
    length += num;

}


template <typename T>
void arr_pop(T*& arr, int& length, int num) {
    if (length <= 0)
        return;

    if (num >= length) {
        delete[] arr;
        arr = nullptr;
        return;
    }
    T* tmp = new T[length - num];
    for(int i = 0; i < length - num; i++)
        tmp[i] = arr[i];
    delete[] arr;
    arr = tmp;
    length -= num;
}