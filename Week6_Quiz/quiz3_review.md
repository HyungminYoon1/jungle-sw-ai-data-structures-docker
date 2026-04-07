# 문제
3. 다음 코드를 실행했을 때 printf 출력 값이 2 3 4 5 6 이 되도록 func 함수를 완성하시오.

#include <stdio.h>

void func(/*....*/) {
    // ....
}

int main() {

    int arr[5] = {1, 2, 3, 4, 5};

    func(arr, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


---

# 답변

void func(int arr[], int count) {

    for (int i = 0; i < count; i++) {
        arr[i] = arr[i] + 1;
    }
}

---

# 정답

void func(int arr[], int count) {
    for (int i = 0; i < count; i++) {
        arr[i]++;
    }
}

