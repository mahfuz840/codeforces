#include<stdio.h>
#include<map>

using namespace std;

void quicksort(int defence[], int gold[], int low, int high);
void my_swap(int* a, int* b);
int partitioner(int defence[], int gold[], int low, int high);

int main()
{
    int s, b, spaceship[100001], defence[100001], gold[100001];
    int x, y;
    long int sum = 0;

    scanf("%d %d", &s, &b);
    for(int i = 0; i < s; i++)
    {
        scanf("%d", &spaceship[i]);
    }

    for(int i = 0; i < b; i++)
        scanf("%d %d", &defence[i], &gold[i]);

    quicksort(defence, gold, 0, b-1);

    for(int i = 0; i < s; i++)
    {
        sum = 0;
        for(int j = 0; j < b; j++)
        {
            if(spaceship[i] >= defence[j])
                sum += gold[j];
            else
                break;
        }
        printf("%ld ", sum);
    }
}

void quicksort(int defence[], int gold[], int low, int high)
{
    if(low < high)
    {
        int pivot = partitioner(defence, gold, low, high);
        // printf("%d\n", pivot);

        quicksort(defence, gold, low, pivot - 1);
        quicksort(defence, gold, pivot +1, high);

        // printf("in quicksort\n");
    }
}

int partitioner(int defence[], int gold[], int low, int high)
{
    int i = (low - 1);
    int pivot = defence[high];

    for(int j = low; j < high; j++)
    {
        if(defence[j] <= pivot)
        {
            i++;
            my_swap(&defence[i], &defence[j]);
            my_swap(&gold[i], &gold[j]);
        }
    }

        my_swap(&defence[i+1], &defence[high]);
        my_swap(&gold[i+1], &gold[high]);

        return (i + 1);
}

void my_swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
