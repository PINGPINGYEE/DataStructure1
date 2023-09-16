	
[실습] 두 가지 방법으로 Stack 구현

1.스택을 다음과 같은 방법으로 구현

   [1] 구조체 배열 사용 [2] 동적 배열 사용

#define MAX 10



2. 난수(1~100) 를 발생시켜서 난수가 짝수이면 push, 홀수이면 pop을 실행하고 실행 내용을 출력

#include <stdlib.h>

#include <time.h>


int main(){

  srand(time(NULL));

  int rand_num = rand() % 100 + 1;

} 

 

3. 앞의 2를 30회 실행하고 실행 결과를 2가지 구현 방법에 대하여 비교 평가
