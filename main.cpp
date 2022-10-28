#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

// 맵을 만들어서 0으로 초기화한다. 1은 경계중인 지역이다.
// 매 루프마다 유저위치는 1씩 증가하면서 그 위치가 1이면 걸렸으니까 리턴, 아니면 끝까지가서 리턴한다.
// 루프 한번 돌 때 마다 1씩 더해주면서 시간과 비교한다.
// 근무시간중이면 해당 위치의 맵 데이터를 1로 바꾸고 쉬는 시간이면 0으로 바꾼다
//

// scope_rows는 2차원 배열 scope의 행 길이, scope_cols는 2차원 배열 scope의 열 길이입니다.
// times_rows는 2차원 배열 times의 행 길이, times_cols는 2차원 배열 times의 열 길이입니다.
int solution(int distance, int** scope, size_t scope_rows, size_t scope_cols, int** times, size_t times_rows, size_t times_cols) 
{
    int* EnemyState = (int*)malloc(sizeof(int) * times_rows);
    int* map = (int*)malloc(sizeof(int) * distance);
    // 0이면 길, 1이면 경계지역
    for (int i = 0; i < distance; i++)
    {
        map[i] = 0;
    }
    int UserPosition = -1;
    for (int i = 0; i < times_rows; i++)
    {
        EnemyState[i] = 0;
    }


    while (1)
    {
        for (int i = 0; i < times_rows; i++)
        {
            if (EnemyState[i] >= times[i][0] + times[i][1])
            {
                EnemyState[i] = 0;
            }
            if (EnemyState[i] < times[i][0])
            {
                if (scope[i][0] >= scope[i][1])
                {
                    for (int j = scope[i][1]; j <= scope[i][0]; j++)
                    {
                        map[j - 1] = 1;
                    }
                }
                else if (scope[i][1] >= scope[i][0])
                {
                    for (int j = scope[i][0]; j <= scope[i][1]; j++)
                    {
                        map[j - 1] = 1;
                    }
                }
            }
            else if (EnemyState[i] < times[i][0] + times[i][1])
            {
                if (scope[i][0] >= scope[i][1])
                {
                    for (int j = scope[i][1]; j <= scope[i][0]; j++)
                    {
                        map[j - 1] = 0;
                    }
                }
                else if (scope[i][1] >= scope[i][0])
                {
                    for (int j = scope[i][0]; j <= scope[i][1]; j++)
                    {
                        map[j - 1] = 0;
                    }
                }
            }
            EnemyState[i]++;
        }

        UserPosition++;
        for (int i = 0; i < distance; i++)
        {
            cout << map[i] << " ";
        }
        cout << endl;
        cout << UserPosition << endl;
        if (map[UserPosition] == 1 || UserPosition == distance - 1)
        {
            break;
        }
    }

    int answer = UserPosition+1;
    return answer;
}

int main()
{
    int* scope[3];
    int sss[3][2] = {{7,8},{4,6},{11,10}};
    for (int i = 0; i < 3; i++)
    {
        scope[i] = sss[i];
    }
    int* times[3];
    int ttt[3][2] = { {2,2},{2,4},{3,3} };
    for (int i = 0; i < 3; i++)
    {
        times[i] = ttt[i];
    }
    solution(12, scope, 3, 2, times, 3, 2);
}