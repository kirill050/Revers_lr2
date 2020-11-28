#include <iostream>
#include <cstdlib>

void random_filling(int *arr, int size){
    int module;
    std::cout << "Choose the module:";
    std::cin >> module;
    if (!arr)
        return;
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % module;
    }
}

void hand_filling(int *arr, int size){
    int copy_size = size;
    if (!arr)
        return;
    while (size){
        std::cin >> arr[copy_size - size];
        size--;
    }
}

int *sort_2_stadia(int *arr, int *sub_arr1, int *sub_arr2, int size1, int size2){
    int *temp = new int[size1 + size2];
    for (int i = 0; i < size1; ++i)
        temp[i] = sub_arr1[i];
    for (int i = size1; i < size1 + size2; ++i)
        temp[i] = sub_arr2[(size2 - 1) - (i - size1)];
    int i = 0, j = size1 + size2 - 1, k = 0;

    for(; true;){
        if (temp[j] >= temp[i]){
            arr[k] = temp[i];
            i++;
            check_is_done: k++;
            if (k >= (size1 + size2)){
                break;
            }
        } else {
            arr[k] = temp[j];
            j--;
            goto check_is_done;
        }
    }
    return arr;
}

int *sort_1_stadia(int *arr, int size){
    if (size == 1){
        return arr;
    } else if (size == 2){
        if (arr[1] < arr[0]) {
            int buf = arr[0];
            arr[0] = arr[1];
            arr[1] = buf;
        }
        return arr;
    }
    int *sub_arr1 = new int[size / 2];
    for (int i = 0; i < (size / 2); ++i)
        sub_arr1[i] = arr[i];
    int *sub_arr2 = new int[(size / 2) + (size % 2)];
    for (int i = (size / 2); i < size; ++i)
        sub_arr2[i - (size/2)] = arr[i];

    sub_arr1 = sort_1_stadia(sub_arr1, size / 2);
    sub_arr2 = sort_1_stadia(sub_arr2, (size / 2) + (size % 2));
    arr = sort_2_stadia(arr, sub_arr1, sub_arr2, size / 2, (size / 2) + (size % 2));
    return arr;
}


int main() {

    std::cout << "Input size of array:";
    int arr_size = 0;
    std::cin >> arr_size;
    int *arr = new int[arr_size];

    std::cout << "Choose the method of filling:" << std::endl;
    std::cout << "1.Random filling" << std::endl;
    std::cout << "2.Hand filling" << std::endl;

    int choice = 0;
    std::cin >> choice;

    if (choice == 3)
        goto final;
    else if (choice == 1){
        random_filling(arr, arr_size);
    } else if (choice == 2){
        hand_filling(arr, arr_size);
    }

    int action;
    for(; true;) {
        std::cout << "Choose action:" << std::endl;
        std::cout << "1.Sort array" << std::endl;
        std::cout << "2.Print array" << std::endl;
        std::cout << "3.Exit" << std::endl;
        std::cin >> action;

        switch (action){
            case 1:
                arr = sort_1_stadia(arr, arr_size);
                break;
            case 2:
                for (int i = 0; i < arr_size; ++i)
                    std::cout << arr[i] << ",";
                break;
            case 3:
                goto final;
                break;
            default:
                break;
        }
    }


    final: delete[](arr);
    return 0;
}


