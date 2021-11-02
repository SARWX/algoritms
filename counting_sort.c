#include <stdio.h>
#include <stdlib.h>

#define SIZE 15 // мы предполагаем, что у нас есть 15 элементов в массиве

void counting_sort(int*, int*, int, int, int); //прототип функции, которая выполняет сортировку.

void main()
{
  int given_array[SIZE]={100,82,87,91,87,97,91,90,82,80,97,100,99,80,88}; //пример.

  int max=100; //наибольшее число в массиве, в данном случае 100.
  int min=80;  //наименьшее число в массиве, в данном случае 80.

  int sorted_array[SIZE];
  printf("\n");

 counting_sort(given_array, sorted_array, SIZE, max, min);
}

void counting_sort(int given_array[], int sorted_array[], int size, int max, int min)
{
  int length=max-min;
  int* counting_array = (int*)calloc((length + 1), sizeof(int));
  int k=0;


  for(int i=0;i<=length;i++)
  {
     counting_array[i]=0; //инициализируем ячейки массива нулями
  }

//подсчитываем количество вхождений каждого элемента исходного массива, складываем эти числа в массив.
  for(int j=0; j<size; j++)
   {
     counting_array[given_array[j]-min]+=1;
   }

//строим отсортированный массив
   while(k<size)
   {
     for(int i=0; i<=length; i++)
       {
          for(int l=0; l<counting_array[i]; l++)
            { sorted_array[k]=i+min;
              k++;
            }
       }
   }

   //отображаем отсортированный массив
   for(int i=0; i<size; i++)
    printf("%d ", sorted_array[i]);
    printf("\n");
}
