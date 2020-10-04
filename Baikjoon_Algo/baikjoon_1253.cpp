#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long num[2001];
int Left, Right;
int answer;

int main()
{
  cin >> N;
  for(int i = 1; i <= N; i++)
  {
    cin >> num[i];
  }
  sort(num+1, num+N+1);
  for(int i = 1; i <= N; i++)
  {
    long long find = num[i];
    Left = 1;
    Right = N;
    while(Left < Right)
    {
      if(num[Left] + num[Right] == find)
      {
        if(Left !=i && Right != i)
        {
          answer++;
          break;
        }
        else if(Left == i)
        {
          Left++;
        }
        else if(Right == i)
        {
          Right--;
        }
      }
      else if(num[Left] + num[Right] < find)
      {
        Left++;
      }
      else
      {
        Right--;
      }
    }
  }
  cout << answer << endl;
  return 0;
}