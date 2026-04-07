# 문제
1. C언어로 정수 배열 arr에 저장된 원소들의 순서를 거꾸로 뒤집어 출력하는 프로그램을 작성하시오 .

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};

    // 코드 작성

    printf("\n");
    return 0;
}



---

# 답변

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

---

# 정답
    for (int i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

