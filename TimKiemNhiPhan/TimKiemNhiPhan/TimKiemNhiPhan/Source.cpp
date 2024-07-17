#include <iostream>
using namespace std;

int binary_search(int A[], int n, int key) {
	int left = 0;            // vị trí phần tử đầu tiên trong mảng
	int right = n - 1;       // vị trí phần tử cuối cùng trong mảng

	while (left <= right) {
		int mid = left + (right - left) / 2;  // vị trí giữa mảng

		if (A[mid] == key) {
			return mid;  // tìm thấy key tại vị trí mid
		}
		else if (key < A[mid]) {
			right = mid - 1;  // tìm kiếm trong nửa trái của mảng
		}
		else {
			left = mid + 1;  // tìm kiếm trong nửa phải của mảng
		}
	}

	return -1;  // không tìm thấy key trong mảng
}

int main() {
	int A[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int n = sizeof(A) / sizeof(A[0]);
	int key = 7;

	int result = binary_search(A, n, key);
	if (result != -1) {
		cout << "Phan tu " << key << " duoc tim thay tai vi tri " << result << "." << endl;
	}
	else {
		cout << "Phan tu " << key << " khong co trong mang." << endl;
	}

	system("pause");  // Tạm dừng chương trình trước khi kết thúc
	return 0;
}
