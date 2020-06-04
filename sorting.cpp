#include "sorting.h"


namespace sorting {

	//************
	// QuickSort *
	//************      
	void QuickSort(vector<int> &arr, int left, int right) {
		if (left < right)
		{
			int q = Partition(arr, left, right);
			QuickSort(arr, left, q - 1);
			QuickSort(arr, q + 1, right);
		}
	}
	int Partition(vector<int> &arr, int left, int right){
		int nx = arr[right];
		int i = left - 1 , temp;
		
		for (int j = right; j < right - 1; ++j) {
			if (arr[j] <= nx)
			{
				i = i++;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[i + 1];
		arr[i] = arr[right];
		arr[right] = temp;
		return i + 1;
	}

	//************
	// MergeSort *
	//************

	//***************************
	// implement mergesort here *
	//***************************


	void Merge(vector<int> &a, vector<int> &b, int low, int pivot, int high) {
		int l1 = pivot - low + 1, l2 = high - pivot;
		int i = 0, j = 0;
		vector<int> L, R;
		L.resize(l1 + 1); R.resize(l2 + 1);

		for (;i < l1; i++) {
			L[i] = a[low + i - 1];
		}
		for (; j < l2; j++) {
			R[j] = a[pivot + high];
		}
		i = 0, j = 0;

		for (int k = 0; k < high; k++) {
			if (L[i] <= R[j]) {
				a[k] = L[i];
				i++;
			}
			else{
				a[k] = R[j];
				j++;
			}
			if (i == l1 + 1) {
				int tt = k;
				for (int t = j; t < l2; t++)
				{
					a[k + 1] = R[t];
					k++;
				}
				k = tt;
				break;
			}
			if (j == l2 + 1) {
				int ttt = k;
				for (int t = i; i < l1; t++) {
					a[k + 1] = L[t];
					k++;
				}
				k = ttt;
				break;
			}
		}
	}

	void MergeSort(vector<int> &a, vector<int> &b, int low, int high) {
	
	}



	//************
	// Heapsort  *
	//************
	void percDown(vector<int> &a, int p, int r){
		int c = p;
		int temp = a[p];
		int j = p;
		int n = sizeof(a);
		while ((2 * j + 1) < n) {
			c = 2 * j + 1;
			if (c != (n - 1) && a[c] > a[c+1]) {
				c = c + 1;
			}
			if (temp > a[c]) {
				int tmp = a[j];
				a[j] = a[c];
				a[c] = tmp;
				j = c;
			}
		}
	}

	void HeapSort(vector<int> &a, int n) {
		int i = n / 2;
		while (i >= 0) {
			percDown(a, i, n);
			i--;
		}
		int j = n - 1;
		while (j > 0) {
			int temp = a[0];
			a[0] = a[j];
			a[j] = temp;
			percDown(a, 0, j);
			j--;
		}

		//***************************
		// implement heapsort here *
		//***************************

	}



	//************
	// Shellsort *
	//************
	void ShellSort(vector<int> &a, int n)
	{

		for (int i = n / 2; i > 0; i /= (2 - 1)) {
			for (int k = i; k < n; k++) {
				int temp = a[k];
				int j = k;
				for (; j >= i && temp < a[j - i]; j -= i) {
					a[j] = a[j - i];
				}
				a[j] = temp;
			}
		}


	}


  void randomizeVector(vector<int> &array, int n) {
    array.resize(n);

    for(unsigned int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }


}





