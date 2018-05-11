#include <bits/stdc++.h>

using namespace std;

void quickSort(int array[], int low, int high) {
      int i = low, j = high;
      int pivot = array[(low + high) / 2];
      // partition 
      while (i <= j) {
            while (array[i] < pivot)
                  i++;
            while (array[j] > pivot)
                  j--;
            if (i <= j) {
                 swap(array[i], array[j]); // swap the position of two elements, to ajust the array
                  i++;
                  j--;
            }
      }
      // recursion 
      if (low < j) quickSort(array, low, j);
      if (i < high) quickSort(array, i, high);
}

int main(){
    int N;
    cout << "Quantos numeros possui o vetor a ser ordenado:" << endl;
    cin >> N;
    int array[N];
    cout << "Digite os numeros do vetor, separados por um espaço:" << endl;
    for(int i=0; i < N; i++)
        cin >> array[i];
    quickSort(array, 0, N-1);
    for (int i = 0; i < N-1; i++)
        cout << array[i] << " ";
    cout << array[N-1] << endl;
}