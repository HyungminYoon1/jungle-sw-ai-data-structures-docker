# Data Structures Practice (C)

이 저장소는 자료구조 문제를 C로 구현하며 학습하기 위한 템플릿입니다.

## 학습 목표
- 자료구조의 핵심 연산을 직접 구현하고 동작을 이해하기
- 제공된 스켈레톤 코드의 빈 함수만 완성하며 문제 해결력 키우기
- 간단한 테스트 케이스를 직접 만들어 검증 습관 익히기

## 문제 풀이 순서
권장 순서:
`Linked List -> Stack and Queue -> Binary Tree -> Binary Search Tree`

## 진행 방법
1. 각 폴더의 문제 PDF를 읽고 요구사항을 정리합니다.
2. 해당 `Q*_*.c` 파일의 빈 함수 부분을 구현합니다.
3. 컴파일 후 직접 입력을 넣어 동작을 확인합니다.
4. 엣지 케이스(빈 구조, 원소 1개, 중복/경계값)를 추가로 테스트합니다.

## 컴파일 예시
```bash
cd Data-Structures/Binary_Search_Tree
gcc Q1_F_BST.c -o Q1_F_BST
./Q1_F_BST
```

## 참고
- 기본 보조 함수(예: enqueue/dequeue 등)는 이미 제공된 경우가 많습니다.
- 핵심은 문제에서 요구한 함수의 로직을 정확히 구현하는 것입니다.

## Git 사용(간단)
```bash
git add .
git commit -m "Solve: BST Q1"
git push
```


