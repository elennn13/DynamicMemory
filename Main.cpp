#include <iostream>


//Вывод массива в консоль
template <typename T>
void print_arr(T arr[], const int length) {
    std::cout << "{ ";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << ", ";
    std::cout << "\b\b }\n";
}


int main(){
    setlocale(LC_ALL, "ru");
    int n;


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
    std::cout << " Введите размер массива -> ";
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


    return 0;
}