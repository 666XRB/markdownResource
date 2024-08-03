#include <stdio.h>

#define MAXSIZE 100

typedef int KeyType;
typedef struct {
    KeyType key;
    // InfoType otherinfo; // Other fields as per your design
} RedType;
typedef struct {
    RedType r[MAXSIZE + 1]; // r[0] is not used
    int length;
} SqList;

// Function prototypes
void simpleSelectionSort(SqList *L);
void directInsertionSort(SqList *L);
void bubbleSort(SqList *L);
void binaryInsertionSort(SqList *L);
void shellSort(SqList *L);
void quickSortRecursive(SqList *L, int low, int high);
void quickSortIterative(SqList *L, int low, int high);
void heapSort(SqList *L);

// Function to swap two elements in the array
void swap(RedType *a, RedType *b) {
    RedType temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the array
void printList(SqList L) {
    printf("Sorted List: ");
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.r[i].key);
    }
    printf("\n");
}

// Main function
int main() {
    SqList L;
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    L.length = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &L.r[i].key);
    }

    // Example usage: Simple Selection Sort
    simpleSelectionSort(&L);
    printList(L);

    // You can uncomment and use other sorting algorithms as needed

    return 0;
}

// Simple Selection Sort
void simpleSelectionSort(SqList *L) {
    int i, j, min;
    for (i = 1; i < L->length; i++) {
        min = i;
        for (j = i + 1; j <= L->length; j++) {
            if (L->r[j].key < L->r[min].key) {
                min = j;
            }
        }
        if (min != i) {
            swap(&L->r[min], &L->r[i]);
            printList(*L);
        }
    }
}

// Direct Insertion Sort
void directInsertionSort(SqList *L) {
    int i, j;
    for (i = 2; i <= L->length; i++) {
        if (L->r[i].key < L->r[i - 1].key) {
            L->r[0] = L->r[i]; // Sentinel
            for (j = i - 1; L->r[0].key < L->r[j].key; j--) {
                L->r[j + 1] = L->r[j];
            }
            L->r[j + 1] = L->r[0];
            printList(*L);
        }
    }
}

// Bubble Sort
void bubbleSort(SqList *L) {
    int i, j;
    for (i = 1; i < L->length; i++) {
        for (j = L->length; j > i; j--) {
            if (L->r[j].key < L->r[j - 1].key) {
                swap(&L->r[j], &L->r[j - 1]);
                printList(*L);
            }
        }
    }
}

// Binary Insertion Sort
void binaryInsertionSort(SqList *L) {
    int i, j, low, high, mid;
    for (i = 2; i <= L->length; i++) {
        L->r[0] = L->r[i];
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (L->r[0].key < L->r[mid].key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= high + 1; j--) {
            L->r[j + 1] = L->r[j];
        }
        L->r[high + 1] = L->r[0];
        printList(*L);
    }
}

// Shell Sort
void shellSort(SqList *L) {
    int i, j, increment;
    RedType temp;
    increment = L->length;
    do {
        increment = increment / 3 + 1;
        for (i = increment + 1; i <= L->length; i++) {
            if (L->r[i].key < L->r[i - increment].key) {
                L->r[0] = L->r[i];
                for (j = i - increment; j > 0 && L->r[0].key < L->r[j].key; j -= increment) {
                    L->r[j + increment] = L->r[j];
                }
                L->r[j + increment] = L->r[0];
                printList(*L);
            }
        }
    } while (increment > 1);
}

// Quick Sort - Recursive
void quickSortRecursive(SqList *L, int low, int high) {
    if (low < high) {
        int pivotpos = partition(L, low, high);
        quickSortRecursive(L, low, pivotpos - 1);
        quickSortRecursive(L, pivotpos + 1, high);
    }
}

int partition(SqList *L, int low, int high) {
    RedType pivot = L->r[low];
    while (low < high) {
        while (low < high && L->r[high].key >= pivot.key) {
            high--;
        }
        L->r[low] = L->r[high];
        while (low < high && L->r[low].key <= pivot.key) {
            low++;
        }
        L->r[high] = L->r[low];
    }
    L->r[low] = pivot;
    return low;
}

// Quick Sort - Iterative
void quickSortIterative(SqList *L, int low, int high) {
    int stack[100], top = -1;
    stack[++top] = low;
    stack[++top] = high;
    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];
        int pivotpos = partition(L, low, high);
        if (pivotpos - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivotpos - 1;
        }
        if (pivotpos + 1 < high) {
            stack[++top] = pivotpos + 1;
            stack[++top] = high;
        }
    }
}

// Heap Sort
void heapSort(SqList *L) {
    buildMaxHeap(L);
    int i;
    for (i = L->length; i > 1; i--) {
        swap(&L->r[1], &L->r[i]);
        L->length--;
        adjustDown(L, 1);
        printList(*L);
    }
}

void buildMaxHeap(SqList *L) {
    int i;
    for (i = L->length / 2; i > 0; i--) {
        adjustDown(L, i);
    }
}

void adjustDown(SqList *L, int k) {
    int i;
    L->r[0] = L->r[k];
    for (i = 2 * k; i <= L->length; i *= 2) {
        if (i < L->length && L->r[i].key < L->r[i + 1].key) {
            i++;
        }
        if (L->r[0].key >= L->r[i].key) {
            break;
        }
        L->r[k] = L->r[i];
        k = i;
    }
    L->r[k] = L->r[0];
}
