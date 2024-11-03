#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int sum(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void swapFrom(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int *copy(int *srcArr, int n) {
    int *destArr = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        destArr[i] = srcArr[i];
    }
    return destArr;
}

int findMax(int *arr, int n) {
    if (n <= 0) {
        return -1;
    }
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        maxVal = max(arr[i], maxVal);
    }
    return maxVal;
}

int findMin(int *arr, int n) {
    if (n <= 0) {
        return -1;
    }
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        minVal = min(minVal, arr[i]);
    }
    return minVal;
}

double average(int *arr, int n) {
    if (n <= 0) return 0.0;
    return (double) sum(arr, n) / n;
}

void reverse(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(&arr[i], &arr[n - i - 1]);
    }
}

int *addElement(int *arr, int *size, int element) {
    arr = realloc(arr, (*size + 1) * sizeof(int));
    if (!arr) {
        return NULL;
    }
    arr[*size] = element;
    (*size)++;
    return arr;
}

void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(int *arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int *arr, int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else right = mid - 1;
    }
    return -1;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int partition(int arr[], int low, int high) {
    int rndNum = rand() % (high - low + 1) + low;
    int pivot = arr[rndNum];
    swap(&arr[low], &arr[rndNum]);
    int left = low + 1, right = high;
    while (left < right) {
        while (left < right && arr[left] <= pivot) {
            left++;
        }
        while (left <= right && arr[right] >= pivot) {
            right--;
        }
        if (left < right) {
            swap(&arr[left], &arr[right]);
        }
    }
    swap(&arr[low], &arr[right]);
    return right;
}

void introsort(int arr[], int low, int high, int depthLimit) {
    int size = high - low + 1;
    if (size < 16) {
        insertionSort(arr, low, high);
    } else if (depthLimit == 0) {
        heapSort(arr + low, size);
    } else {
        int pivot = partition(arr, low, high);
        introsort(arr, low, pivot - 1, depthLimit - 1);
        introsort(arr, pivot + 1, high, depthLimit - 1);
    }
}

void sort(int arr[], int n) {
    int depthLimit = 2 * (int) log(n);
    introsort(arr, 0, n - 1, depthLimit);
}

int *map(int *arr, int n, int (*func)(int)) {
    int *res = malloc(n * sizeof(int));
    if (res == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        res[i] = func(arr[i]);
    }
    return res;
}

int *filter(int *arr, int n, bool (*predicate)(int), int *newLen) {
    int *temp = malloc(n * sizeof(int));
    if (temp == NULL) {
        *newLen = 0;
        return NULL;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (predicate(arr[i])) {
            temp[count++] = arr[i];
        }
    }
    int *res = malloc(count * sizeof(int));
    if (res == NULL) {
        *newLen = 0;
        free(temp);
        return NULL;
    }
    for (int i = 0; i < count; i++) {
        res[i] = temp[i];
    }
    free(temp);
    *newLen = count;
    return res;
}

int reduce(int *arr, int n, int (*operation)(int, int), int init) {
    int res = init;
    for (int i = 0; i < n; i++) {
        res = operation(res, arr[i]);
    }
    return res;
}