#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;

void input()
{
  cin >> N >> K;
}

void solution()
{
  for(int a = 0; a <= N; a++)
  {
    int b = N-a;
    if(a*b < K)
      continue;
    vector<int> count(b+1);
    for(int i = 0; i < a; i++)
    {
      int temp = min(b, K);
      count[temp]+=1;
      K -= temp;
    }
    for(int i = b; i >= 0; i--)
    {
      for(int j = 0; j < count[i]; j++)
      {
        cout << 'A';
      }
      if(i > 0)
        cout << 'B';
    }
    cout << endl;
    return;
  }
  cout << -1 << endl;
}

int main()
{
  input();
  solution();
  return 0;
}