#include <stdio.h>

int main(void) {

    int arr[5] = {1, 2, 3, 4, 5};

    // 코드 작성
    int len = 5;
    int count = len/2;

    for (int i = 0; i < count; i++) {
        int temp = arr[i];
        arr[i] = arr[len-1-i];
        arr[len-1-i] = temp;
    }

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;

}

