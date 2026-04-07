# 문제
5. C언어 코드의 실행 결과를 기입 하시오.

void update(int p) { p = 200;} // 
void update1(int *p) { *p = 100;} //포인터가 지칭하는 값을 100으로 변경 
void update2(int **p) { **p = 1000;} // 최종적으로 그 포인터가 가리키는 정수값 x를 1000으로 변경

int main() {

    int x = 10;
    int *p = &x; // p는 x의 포인터

    update(x); printf("%d\n", x); // 10
    update1(&x); printf("%d\n", x); // 100
    update2(&p); printf("%d\n", x); // 1000
    update1(p); printf("%d\n", x); // 100

}


---

# 답변


---

# 정답


