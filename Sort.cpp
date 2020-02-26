#include <iostream>
#include <algorithm>
using namespace std;

void swapI(int list[], int first, int second){
    int temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

int partition(int list[], int first, int last){
    int pivot;
    int index, smallIndex;
    swapI(list, first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;
    for (index = first +1; index <= last; index++){
        if (list[index] < pivot){
            smallIndex++;
            swapI(list, smallIndex, index);
        }
    }
    swapI(list, first, smallIndex);

    return smallIndex;
}

void quickSort(int list[], int first, int last){
    int pivotLocation;
    if (first < last){
        pivotLocation = partition(list, first, last);
        quickSort(list, first, pivotLocation - 1);
        quickSort(list, pivotLocation + 1, last);
    }
}

int main(){

    int x[6] = {5,4,2,1,3,6};
    quickSort(x, 0, 6);
    for (int i = 0; i < 6; i++)
        cout << x[i] << " ";

    return 0;
}
