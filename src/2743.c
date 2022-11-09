#include <stdio.h>
#include <string.h> // strlen 함수를 위한 헤더

int main()
{
    char word[101];                      // 최대 길이 : 100
    scanf("%s", &word);                  // 단어 입력 받기
    printf("%d", (int)strlen(word)); // strlen(word) : 단어의 길이를 size_t 형으로 반환히는 함수
                                         // 출력을 용이하게 하기 위해 int형으로 캐스팅
    return 0;
}
