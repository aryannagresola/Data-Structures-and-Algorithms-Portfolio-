#ifndef SORTINGALGO_H
#define SORTINGALGO_H

// shell sort:
template <typename T>
void shellSort(T arr[], int size){
    for(int interval = size / 2; interval >= 1; interval = interval / 2){
        for(int i = interval; i < size; i++){
            T temp = arr[i];
            int j = i;

            while(j >= interval && arr[j - interval] > temp){
                arr[j] = arr[j - interval];
                j = j - interval;
            }
            arr[j] = temp;
        }
    }
}

// merge sort:
template <typename T>
void merge(T arr[], int left, int middle, int right){
    T temp[100];
    int i = left;
    int j = middle + 1;
    int k = 0;

    while(i <= middle && j <= right){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }while(i <= middle){
        temp[k] = arr[i];
        i++;
        k++;
    }while(j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(i = left, k = 0; i <= right; i++, k++){
        arr[i] = temp[k];
    }
}

template <typename T> // this the function that split array in half
void mergeSort(T arr[], int left, int right){
    if(left < right){
        int middle = (left + right) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// quick sort:
template <typename T> // function that splits array
int arrPartition(T arr[], int low, int high){
    T pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;

            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    T temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

template <typename T>
void quickSort(T arr[], int low, int high){
    if(low < high){
        int pivot = arrPartition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

#endif

