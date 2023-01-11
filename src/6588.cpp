#include <stdio.h>

int prime[1000001] = {0,0,1, }; // 전체 수 체크

int main()
{
    int n;

    for (int i = 2; i < 1001; i++) // 에라토스테네스의 체를 사용하여 구간 내의 모든 소수를 판별함.
    {
        for (int j = 2; prime[i] && i * j < 1000001; j++)
            prime[i * j] = 0;
    }

    while (scanf("%d", &n) && n) // 입력 받은 수가 유효하면 반복 -> 입력 받는 한 반복
    {
        for (int i = 3; i * 2 <= n; i += 2) // 2부터 n의 절반이 될 때 까지 짝수만 체크
        {
            if (prime[i] && prime[n - i]) // 비교된 두 소수의 합이 해당 짝수가 될 때
            {
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
            else
            {
                printf("Goldbach's conjecture is wrong.\n");
                break;
            }
        }
    }

    return 0;
}
