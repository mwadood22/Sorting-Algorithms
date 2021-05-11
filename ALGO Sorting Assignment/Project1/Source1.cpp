#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<chrono>
#include<Windows.h>
#include<algorithm>
#include<cmath>
using namespace std;
using namespace std::chrono;
void Insertion_Sort(int* arr, int size);
void Bubble_Sort(int* arr, int size);
void Selection_Sort(int* arr, int size);
void Merge_Sort(int* arr, int left, int right);
void Quick_Sort(int* arr, int low, int high);
void Heap_Sort(int* arr, int size, int t);
void Count_Sort(int* arr, int size);
void Radix_Sort(int* arr, int size);
void Bucket_Sort(int* arr, int size);
int main()
{
	int* arr = new int[3000], i = 0, t = 0, num, option = 0, temp = 0, file;
	fstream fio;
	while (option == 0)
	{
		system("cls");
		i = 0, temp = 0;
		cout << "\t\t\t\tWelcome to FASTSORT\n\n\t\t\tPlease use number to operate\n\t\t\t\tPress 1 to select file: 1\n\t\t\t\tPress 0 to exit: 0\nYour choice: ";
		cin >> option;
		if (option == 1)
		{
			cout << "Enter number to choose file:\n1- Sample.txt\n2- RollNumber.txt\n3- Raw.txt\nYour choice: ";
			cin >> file;
			switch (file)
			{
			case 1:
			{
				fio.open("sample.txt");
				while (!fio.eof())
				{
					fio >> arr[i];
					i++;
				}
				fio.close();
				break;
			}
			case 2:
			{
				fio.open("rollnumber.txt");
				while (!fio.eof())
				{
					fio >> arr[i];
					i++;
				}
				fio.close();

				break;
			}
			case 3:
			{
				fio.open("raw.txt");
				while (!fio.eof())
				{
					fio >> arr[i];
					i++;
				}
				fio.close();
				break;
			}
			}
		}
		else if (option == 0)
			goto flag;
		system("cls");
		cout << "Unsorted data in given file: \n";
		for (int j = 0; j < i; j++)
		{
			cout << arr[j] << endl;
		}
		num = i;
		cout << "Press 0 to proceed: ";
		cin >> option;
		system("cls");
		cout << "\t\t\t\tSorting Techniques Menu\n\t\t\tSelect from the Following Sorting Techniques\n";
		cout << "\t\t\t\tInsertion sort: 1\n\t\t\t\tBubble sort: 2\n\t\t\t\tSelection sort: 3\n\t\t\t\tMerge sort: 4\n\t\t\t\tQuick sort: 5\n\t\t\t\tHeap sort: 6\n\t\t\t\tCount sort: 7\n\t\t\t\tRadix sort: 8\n\t\t\t\tBucket sort: 9\n\t\t\t\tYour choice: ";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			auto start = high_resolution_clock::now();
			Insertion_Sort(arr, num);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			break;
		}
		case 2:
		{
			auto start = high_resolution_clock::now();
			Bubble_Sort(arr, num);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			break;
		}
		case 3:
		{
			auto start = high_resolution_clock::now();
			Selection_Sort(arr, num);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			break;
		}
		case 4:
		{
			auto start = high_resolution_clock::now();
			Merge_Sort(arr, 0, num - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			break;
		}
		case 5:
		{
			auto start = high_resolution_clock::now();
			Quick_Sort(arr, 0, num - 1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			break;
		}
		case 6:
		{
			auto start = high_resolution_clock::now();
			Heap_Sort(arr, num, t);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			break;
		}
		case 7:
		{
			auto start = high_resolution_clock::now();
			Count_Sort(arr, num);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			break;
		}
		case 8:
		{
			auto start = high_resolution_clock::now();
			Radix_Sort(arr, num);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			break;
		}
		case 9:
		{
			auto start = high_resolution_clock::now();
			Bucket_Sort(arr, num);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by function: "
				<< duration.count() << " microseconds" << endl;
			break;
		}
		}
		ofstream nio("SortedResultFile.txt");
		while (i > 0)
		{
			i--;
			nio << arr[temp] << endl;
			temp++;
		}
		nio.close();
		cout << "Sorted data as stored in file: \n";
		for (int j = 0; j < num; j++)
			cout << arr[j] << endl;
		cout << "Press 0 to proceed: ";
		cin >> option;
		system("cls");
		cout << "Press 0 to use software again, or any other key to abort: ";
		cin >> option;
	}
flag:
	system("pause");
}
void swap(int* value, int* value1)
{
	int temp = *value;
	*value = *value1;
	*value1 = temp;
}
void Insertion_Sort(int* arr, int size)
{
	int temp, identify;
	for (int i = 1; i < size; i++)
	{
		temp = i;
		while (temp > 0 && arr[temp - 1] > arr[temp])
		{
			identify = arr[temp];
			arr[temp] = arr[temp - 1];
			arr[temp - 1] = identify;
			temp--;
		}
	}
}
void Bubble_Sort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}
void Selection_Sort(int* arr, int size)
{
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		temp = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[temp])
			{
				temp = j;
			}
		}
		swap(&arr[temp], &arr[i]);
	}
}
void merge(int* arr, int left, int mid, int right)
{
	int a, b, c;
	int no_1 = mid - left + 1;
	int no_2 = right - mid;
	int* L_T = new int[no_1];
	int* R_T = new int[no_2];
	for (a = 0; a < no_1; a++)
		L_T[a] = arr[left + a];
	for (b = 0; b < no_2; b++)
		R_T[b] = arr[mid + 1 + b];
	a = 0, b = 0, c = left;
	while (a < no_1 && b < no_2)
	{
		if (L_T[a] <= R_T[b])
		{
			arr[c] = L_T[a];
			a++;
		}
		else
		{
			arr[c] = R_T[b];
			b++;
		}
		c++;
	}
	while (a < no_1)
	{
		arr[c] = L_T[a];
		a++;
		c++;
	}
	while (b < no_2)
	{
		arr[c] = R_T[b];
		b++;
		c++;
	}
}
void Merge_Sort(int* arr, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		Merge_Sort(arr, left, middle);
		Merge_Sort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}
int division(int* arr, int low, int high)
{
	int mid = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= mid)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void Quick_Sort(int* arr, int low, int high)
{
	if (low < high)
	{
		int pivot = division(arr, low, high);
		Quick_Sort(arr, low, pivot - 1);
		Quick_Sort(arr, pivot + 1, high);
	}
}
void heap_adjust(int* arr, int t, int n, int i) {
	int large = i, left = 2 * i + 1, right = 2 * i + 2;
	if (left < n && arr[left] > arr[large])
		large = left;
	if (right < n && arr[right] > arr[large])
		large = right;
	if (large != i)
	{
		t = arr[i];
		arr[i] = arr[large];
		arr[large] = t;
		heap_adjust(arr, t, n, large);
	}
}
void Heap_Sort(int* arr, int size, int n_1) {
	for (int n_2 = size / 2 - 1; n_2 >= 0; n_2--)
		heap_adjust(arr, n_1, size, n_2);
	for (int n_2 = size - 1; n_2 >= 0; n_2--) {
		n_1 = arr[0];
		arr[0] = arr[n_2];
		arr[n_2] = n_1;
		heap_adjust(arr, n_1, n_2, 0);
	}
}
int Find_Max(int *arr, int size)
{
	int maximum = arr[1];
	for (int i = 2; i <= size; i++)
	{
		if (arr[i] > maximum)
			maximum = arr[i];
	}
	return maximum;
}
void Count_Sort(int* arr, int size) {
	int i, j, n;
	int index = 0;
	int min, max;

	min = max = arr[0];
	for (i = 1; i < size; i++) {
		min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
	}
	n = max - min + 1;
	int* arr1 = new int[n];
	for (i = 0; i < n; i++)
	{
		arr1[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		arr1[arr[i] - min]++;
	}
	for (i = min; i <= max; i++)
	{
		for (j = 0; j < arr1[i - min]; j++) arr[index++] = i;
	}

	delete[] arr1;
}
void SORT(int* arr, int size, int num)
{
	int* arr1 = new int[size];
	int i, temp[10] = { 0 };
	for (i = 0; i < size; i++)
	{
		temp[(arr[i] / num) % 10]++;
	}
	for (i = 1; i < 10; i++)
	{
		temp[i] += temp[i - 1];
	}
	for (i = size - 1; i >= 0; i--)
	{
		arr1[temp[(arr[i] / num) % 10] - 1] = arr[i];
		temp[(arr[i] / num) % 10]--;
	}
	for (i = 0; i < size; i++)
		arr[i] = arr1[i];
}
void Radix_Sort(int* arr, int size)
{
	int max = Find_Max(arr, size);
	for (int num = 1; max / num > 0; num *= 10)
	{
		SORT(arr, size, num);
	}
}
void Bucket_Sort(int* arr, int size)
{
	int max, bucket = 10, temp, i, j, k;
	vector <int>arr1[10];
	max = Find_Max(arr, size);

	temp = ceil(float(max + 1) / bucket);
	for (i = 0; i < size; i++) {
		j = floor(arr[i] / temp);
		arr1[j].push_back(arr[i]);
	}
	for (i = 0; i < bucket; i++) {
		sort(arr1[i].begin(), arr1[i].end());
	}
	k = 0;
	for (i = 0; i < bucket; i++) {
		for (j = 0; j < arr1[i].size(); j++) {
			arr[k++] = arr1[i][j];
		}
	}
}
