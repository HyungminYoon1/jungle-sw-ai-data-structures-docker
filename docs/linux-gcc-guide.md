# Linux에서 C 파일 빌드, 실행, 디버깅하기

이 문서는 이 저장소에서 C 문제 파일을 Linux 환경에서 컴파일하고 실행하는 가장 기본적인 방법을 정리합니다.

## 언제 이 문서를 보면 좋은가

- `gcc` 명령이 무엇을 하는지 헷갈릴 때
- VS Code의 `Run` 또는 `Debug` 버튼이 내부적으로 무엇을 하는지 알고 싶을 때
- `.c` 파일을 직접 빌드하고 실행해 보고 싶을 때
- `printf`, `NULL`, 실행 파일 경로 같은 기본 오류를 빠르게 점검하고 싶을 때

## 가장 짧은 사용법

예를 들어 BST 문제 파일 하나를 직접 실행해 보려면:

```bash
cd Data-Structures/Binary_Search_Tree
gcc Q1_F_BST.c -o Q1_F_BST
./Q1_F_BST
```

의미는 다음과 같습니다.

- `gcc`: C 컴파일러를 실행합니다.
- `Q1_F_BST.c`: 입력 소스 파일입니다.
- `-o Q1_F_BST`: 출력 실행 파일 이름을 `Q1_F_BST`로 지정합니다.
- `./Q1_F_BST`: 현재 폴더의 실행 파일을 실행합니다.

## 이 저장소에서 자주 쓰는 패턴

### Binary Search Tree 문제 실행

```bash
cd Data-Structures/Binary_Search_Tree
gcc Q5_F_BST.c -o Q5_F_BST
./Q5_F_BST
```

### Binary Tree 문제 실행

```bash
cd Data-Structures/Binary_Tree
gcc Q1_E_BT.c -o Q1_E_BT
./Q1_E_BT
```

### Week6 Quiz 코드 실행

```bash
cd Week6_Quiz
gcc quiz3_code.c -o quiz3_code
./quiz3_code
```

## 추천 컴파일 옵션

처음에는 아래처럼 경고를 함께 보는 습관이 좋습니다.

```bash
gcc -Wall -Wextra -std=c11 Q5_F_BST.c -o Q5_F_BST
```

옵션 의미:

- `-Wall`: 자주 놓치는 경고를 보여줍니다.
- `-Wextra`: 추가 경고를 더 보여줍니다.
- `-std=c11`: C11 표준 기준으로 컴파일합니다.

실습 중에는 코드가 "돌아가기만" 해도 통과한 것처럼 보일 수 있지만, 경고가 실제 버그를 미리 알려주는 경우가 많습니다.

## VS Code의 Run, Debug 버튼은 무엇을 하는가

이 저장소에서는 VS Code 설정이 이미 들어 있어서, `Run` 또는 `Debug`를 누르면 내부적으로 빌드가 자동 실행될 수 있습니다.

관련 설정은 다음 파일에 있습니다.

- [.vscode/tasks.json](/workspaces/jungle-sw-ai-data-structures-docker/.vscode/tasks.json)
- [.vscode/launch.json](/workspaces/jungle-sw-ai-data-structures-docker/.vscode/launch.json)

핵심 동작은 이렇습니다.

1. 활성 파일을 `gcc` 또는 `gcc-13`으로 컴파일합니다.
2. 실행 파일을 현재 파일과 같은 폴더에 생성합니다.
3. `Debug`를 시작하면 생성된 실행 파일을 gdb로 실행합니다.

즉, 버튼만 눌렀더라도 뒤에서는 `gcc`가 실행되고 있을 가능성이 큽니다.

## 자주 만나는 오류와 점검 포인트

### `printf`에 빨간 줄이 뜰 때

대부분 `#include <stdio.h>`가 빠진 경우입니다.

```c
#include <stdio.h>
```

### `NULL`이 정의되지 않았다고 나올 때

문맥에 따라 아래 헤더 중 하나가 필요합니다.

```c
#include <stddef.h>
```

또는 `stdio.h`, `stdlib.h`를 이미 포함하면 해결되는 경우도 많습니다.

### `No such file or directory`

보통 아래 둘 중 하나입니다.

- 현재 폴더가 다릅니다.
- 실행 파일 이름이 다릅니다.

예를 들어 `gcc Q1_F_BST.c -o Q1_F_BST`로 만들었다면 실행은:

```bash
./Q1_F_BST
```

입니다.

### `implicit declaration of function 'printf'`

거의 항상 `stdio.h` 누락입니다.

### `malloc`, `free` 관련 경고

보통 `stdlib.h` 누락입니다.

```c
#include <stdlib.h>
```

## 실습용 체크리스트

문제를 풀고 나면 아래를 확인해 보세요.

- 컴파일이 되는가
- 경고가 없는가
- 빈 구조에서 정상 동작하는가
- 원소 1개일 때도 정상 동작하는가
- 경계값이나 중복 입력을 확인했는가

## 추천 학습 흐름

1. 문제 PDF를 읽고 요구사항을 먼저 정리합니다.
2. 빈 함수만 채웁니다.
3. `gcc`로 직접 컴파일합니다.
4. 실행해서 입력을 넣어 봅니다.
5. 마지막에 `Run/Debug`로도 다시 확인합니다.

터미널에서 직접 빌드해 보면 에러 메시지를 더 명확하게 읽는 연습이 되고, IDE 버튼은 빠른 반복 확인에 유리합니다. 두 방법을 함께 쓰는 것이 가장 효율적입니다.
