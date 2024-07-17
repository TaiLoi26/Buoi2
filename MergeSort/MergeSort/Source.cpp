#include <iostream>
using namespace std;

void merge(int A[], int left, int mid, int right) {
	int n1 = mid - left + 1;  // độ dài nửa dãy đầu của A
	int n2 = right - mid;     // độ dài nửa dãy sau của A

	int* L = new int[n1];
	int* R = new int[n2];


	for (int i = 0; i < n1; i++)
		L[i] = A[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = A[mid + 1 + j];


	int i = 0, j = 0;

	int k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}


	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}


	delete[] L;
	delete[] R;
}

void merge_sort(int A[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		
		merge_sort(A, left, mid);
		merge_sort(A, mid + 1, right);

		
		merge(A, left, mid, right);
	}
}

int main() {
	int A[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(A) / sizeof(A[0]);

	cout << "Mang ban dau: ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;

	merge_sort(A, 0, n - 1);

	cout << "Mang da sap xep: ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;

	system("pause");  // Tạm dừng chương trình trước khi kết thúc
	return 0;
}
