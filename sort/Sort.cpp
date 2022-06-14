#include "Sort.h"

void Swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void InsertionSort(int a[],int n,int &ccmp)
{
    for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
			ccmp ++;
		}
		a[k + 1] = key;
		ccmp ++;
	}
}
void ShellSort(int a[],int n,int &ccmp)
{
    for (int interval = n / 2; interval > 0; interval /= 2)
	{
		for (int i = interval; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
			{
				a[j] = a[j - interval];
				ccmp++;
			}	
			a[j] = temp;
			ccmp++;
		}
		ccmp++;
	}
}
void CountingSort(int a[],int n,int &ccmp)
{
    int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			ccmp ++;
		}
		ccmp ++;
	}

	int *count = new int[max + 1];
	for (int i = 0; i <= max; i++)
	{
		count[i] = 0;
		ccmp ++;
	}

	for (int i = 0; i < n; i++)
	{
		count[a[i]]++;
		ccmp ++;
	}

	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
		ccmp ++;
	}

	int *temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
		ccmp ++;
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = temp[i];
		ccmp ++;
	}
	
	delete[] count;
	delete[] temp;
}
void FlashSort(int a[],int n,int &ccmp)
{
    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
	{
		l[i] = 0;
		ccmp ++;
	}

	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
		{
			minVal = a[i];
			ccmp ++;
		}
		if (a[i] > a[max])
		{
			max = i;
			ccmp ++;
		}
		ccmp ++;
	}
	if (a[max] == minVal)
	{
		return;
		ccmp ++;
	}
	
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
		ccmp ++;
	}

	for (int i = 1; i < m; i++)
	{
		l[i] += l[i - 1];
		ccmp ++;
	}

	Swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
			ccmp ++;
		}

		flash = a[j];
		if (k < 0) 
		{
			ccmp ++;
			break;
		}

		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
			ccmp ++;
		}
		ccmp ++;
	}

	delete[] l;
	InsertionSort(a, n,ccmp);
}

void InsertionSort(int a[],int n)
{
    for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}
void ShellSort(int a[],int n)
{
    for (int interval = n / 2; interval > 0; interval /= 2)
	{
		for (int i = interval; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
				a[j] = a[j - interval];
			a[j] = temp;
		}
	}
}
void CountingSort(int a[],int n)
{
    int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	int *count = new int[max + 1];
	for (int i = 0; i <= max; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[a[i]]++;

	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];

	int *temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; i < n; i++)
		a[i] = temp[i];
	delete[] count;
	delete[] temp;
}
void FlashSort(int a[],int n)
{
    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	Swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	InsertionSort(a, n);
}