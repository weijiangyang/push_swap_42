#include <stdlib.h>

//insertion sort
void insertionSort(int arr[], int left, int right)
{
	int	i;
	int	tmp;
	int	j;

	i = left + 1;
	while (i <= right)
	{
		tmp = arr[i];
		j = i - 1;
		while (j >= left && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
		i++;
	}
}
void merge(int arr[], int l, int m, int r)
{
	int	len1;
	int	len2;
	int	*left;
	int	*right;
	int	i;
	int	k;
	int	j;

	k = l;
	i = 0;
	j = 0;
	len1 = m - l + 1;
	len2 = r - m;
	left = malloc (len1 * sizeof(int));
	right = malloc (len2 * sizeof(int));
	while (i < len1)
	{
		left[i] = arr[l + i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		right[i] = arr[m + 1 + i];
		i++;
	}		

	i = 0; 
	while (i < len1 && j < len2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];				
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < len1)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < len2)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
	free (left);
	free (right);
}

// Implémentation principale de Timsort
void timSort(int arr[], int n)
{
	int	i;
	const int MIN_RUN = 5;
	int	size;
	int	left;
	int	right;
	
	i = 0;
	size = MIN_RUN;
	left = 0;
	while (i < n)
	{
		if (i + MIN_RUN < n)

			insertionSort(arr, i, i + MIN_RUN - 1);
		else
			insertionSort(arr, i, n - 1);
		i += MIN_RUN;
	}
	while (size < n)
	{
		left = 0;
		while (left < n)
		{
			int mid = left + size - 1;
			if ( left + 2 * size - 1 < n)
				 right = left + 2 * size - 1;
			else 
				 right = n - 1;
			if (mid < right)
				merge(arr, left, mid, right);
			left += 2 * size;
		}
		size *= 2;
	}
}


// Affichage
#include <stdio.h>

void printArray(int arr[], int n) 
{
	int i;

	i = 0;
	while (i < n)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}


int main(void)
{
	int tab[] = {12,31, 54, 14, 25, 4, 6, 29, 19, 15, 82, 91, 38, 58, 22, 43, 63, 9};
	timSort(tab, 18);
	printArray(tab, 18);
	return (0);
}
/*#include <stdio.h>

int main(void)
{
        int tab1[] = {10, 2, 5, 3, 1, 18, 13, 4, 6, 7};
        insertionSort(tab1, 0, 9);
	int tab2[] = {21, 12, 2, 14, 6, 7, 5, 11, 19, 4};
	insertionSort(tab2, 0, 9);
	int	arr[20];

        int     i;
        
        i = 0;
	while (i < 10)
	{
		arr[i] = tab1[i];
		i++;
	}
	int j = 0;
	while (j < 10)
	{
		arr[i + j] = tab2[j];
		j++;
	}
	merge(arr, 0, 9, 19);
	i = 0;
	while (i < 20)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}*/


