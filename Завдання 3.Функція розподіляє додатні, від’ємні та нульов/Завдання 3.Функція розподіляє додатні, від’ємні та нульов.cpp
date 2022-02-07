/*Завдання 3. Написати функцію, яка отримує покажчик
на статичний масив і його розмір. Функція розподіляє
додатні, від’ємні та нульові елементи в окремі динамічні
масиви.*/

#include <iostream>
using namespace std;

void printArr(int* arr, int size) {        // Функція друку динамічного масиву
    for (int i = 0; i < size; i++)
    {
        cout << "Arr [" << i + 1 << "] = " << arr[i] << endl;
    }
}
void inputArr(int*& arr, int& size) {       //Функція ініціалізації масиву;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter [" << i + 1 << "] element of massive = ";
        cin >> arr[i];
    }
}
void distribution(int* arr, int size) {   //Функція розподілу масиву
    int p = 0, m = 0, z = 0;        //для майбутнього розміру 
    int* arrplus = new int[size];
    int* arrminus = new int[size];      //три нових масиви для розподілу(додатні,мінусові, та нульові.
    int* arrzero = new int[size];
    
    for (int i = 0; i < size; i++)  //цикл для перерахунку елементів 
    {
        if (arr[i] > 0) {
            arrplus[p] = arr[i];        //умвоа при якій записуємо додатні елементи у масив 
            p++;
        }
        if (arr[i] < 0) {
            arrminus[m] = arr[i];   //умова при якій записуємо від'ємні елементи у масив
            m++;
        }
        if (arr[i]==0)
        {
            arrzero[z] = arr[i];    //умова для масива з 0-ми.
            z++;
        }
    }
    cout << "Array with positive numbers :"<<endl;  //виводимо на екран масив з додатніми елементами 
    printArr(arrplus, p);
    cout << "Array with negative numbers :" << endl;//виводимо на екран масив з від'ємними елементами 
    printArr(arrminus, m);
    cout << "Array with zero:" << endl;             //виводимо на екран масив з з 0-ми
    printArr(arrzero, z);
}
int main()
{
    int size = 100;
    cout << "Enter size=";
    cin >> size;
    int* arr = new int[size];

    inputArr(arr, size);        //виклик функції для заповнення масиву
    distribution(arr, size);    //виклик функції для розділення на окремі три масиви 
}


    