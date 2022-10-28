#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

// ���� ���� 0���� �ʱ�ȭ�Ѵ�. 1�� ������� �����̴�.
// �� �������� ������ġ�� 1�� �����ϸ鼭 �� ��ġ�� 1�̸� �ɷ����ϱ� ����, �ƴϸ� ���������� �����Ѵ�.
// ���� �ѹ� �� �� ���� 1�� �����ָ鼭 �ð��� ���Ѵ�.
// �ٹ��ð����̸� �ش� ��ġ�� �� �����͸� 1�� �ٲٰ� ���� �ð��̸� 0���� �ٲ۴�
//

// scope_rows�� 2���� �迭 scope�� �� ����, scope_cols�� 2���� �迭 scope�� �� �����Դϴ�.
// times_rows�� 2���� �迭 times�� �� ����, times_cols�� 2���� �迭 times�� �� �����Դϴ�.
int solution(int distance, int** scope, size_t scope_rows, size_t scope_cols, int** times, size_t times_rows, size_t times_cols) 
{
    int* EnemyState = (int*)malloc(sizeof(int) * times_rows);
    int* map = (int*)malloc(sizeof(int) * distance);
    // 0�̸� ��, 1�̸� �������
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