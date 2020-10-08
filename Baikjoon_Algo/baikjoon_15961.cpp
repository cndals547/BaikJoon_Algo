#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int N, d, k, c;
int arr[3000000];
int sushi[3001];
int answer, count;
deque<int> dq;

void input()
{
  cin >> N >> d >> k >> c;
  for(int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }
}

void solution()
{
  for(int i = 0; i < k; i++)
  {
    dq.push_back(arr[i]);
    if(!sushi[arr[i]]++)
    {
      count++;
    }
    answer = max(answer, count);
  }
  for(int i = 0; i < N-1; i++)
  {
    dq.pop_front();
    if(!(--sushi[arr[i]]))
        count--;
    dq.push_back(arr[(i+k)%N]);
    if(!sushi[arr[(i+k)%N]]++)
    {
      count++;
    }
    if(!sushi[c])
      answer = max(answer, count+1);
    else
      answer = max(answer, count);
  }
  cout << answer << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  input();
  solution();
  return 0;
}