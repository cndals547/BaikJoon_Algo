#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, arr[10001], answer;

void solution()
{
  cin >> N;
  for(int i = 1; i <= N; i++)
  {
    int pre_count;
    int max_temp = 0;
    cin >> arr[i] >> pre_count;
    while(pre_count--)
    {
      int pre_num;
      cin >> pre_num;
      max_temp = max(max_temp, arr[pre_num]);
    }
    arr[i] += max_temp;
    if(answer < arr[i])
      answer = arr[i];
  }
  cout << answer << endl;
}

int main()
{
  solution();
  return 0;
}