# 문제
2. 다음 C 코드의 문제점을 찾아 해결하고, printf 출력 결과를 적으시오. 

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *arr = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        arr[i] = i * i;
    }

    printf("%d\n", arr[3]); // 결과 기입

    // start of code

    ….
    // end of code

    return 0;
}


---

# 답변

    // start of code
    free(arr);
    // end of code

출력결과: 9

---

# 정답

출력 결과: 9
핵심 문제점: free(arr); 누락

