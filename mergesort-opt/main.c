#include <stdio.h>

//ROBSON MARIANO EUZÉBIO DE OLIVEIRA GRR20204458

void mergeSort(int [], int, int, int);
void partition(int [],int, int);
void insertion_sort(int [],int, int);

void partition(int list[],int low,int high)
{
    int mid;

    if(low < high)
    {

        if ((high - low) <= 10)
            insertion_sort(list, low, high);

        else {

            mid = (low + high) / 2;
            partition(list, low, mid);
            partition(list, mid + 1, high);
            if(list[mid] <= list[mid+1]) return;
            mergeSort(list, low, mid, high);
        }

    }
}

void mergeSort(int list[],int low,int mid,int high)
{
    int i,j,k;
    int *aux;

    aux = (int *) malloc(sizeof(int) * high+1);

    for(i=mid+1; i > low; i--) aux[i-1] = list[i-1];
    for(j=mid; j < high; j++) aux[high+mid-j] = list[j+1];

    for(k=low; k<=high; k++)
    {
        if(aux[j] < aux[i])
            list[k] = aux[j--];
        else
            list[k] = aux[i++];
    }
}

void insertion_sort(int list[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        double tmp = list[i];
        int j = i;
        while ((j > l) && (list[j - 1] > tmp))
        {
            list[j] = list[j - 1];
            j--;
        }
        list[j] = tmp;
    }
}

int main()
{
    int list[50];
    int i, size;

    printf("Digite o total de elementos a serem inseridos:");
    scanf("%d", &size);
    printf("Digite os elementos:\n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &list[i]);
    }
    partition(list, 0, size - 1);
    printf("Array ordenado com o mergesort otimizado:\n");
    for(i = 0;i < size; i++)
    {
        printf("%d   ",list[i]);
    }

    return 0;
}