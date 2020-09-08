#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct GEM{
  int weight;
  int price;
};

long long answer;
int N,K;
int bag[300001];
GEM gem[300001];

bool Comp(GEM a, GEM b)
{
  if(a.weight <= b.weight)
  {
    if(a.weight == b.weight)
    {
      if(a.price > b.price)
      {
        return true;
      }
      return false;
    }
    return true;
  }
  return false;
}

void input()
{
  cin >> N >> K;
  for(int i = 0; i < N; i++)
  {
    int Weight, Price;
    cin >> Weight >> Price;
    gem[i].weight = Weight;
    gem[i].price = Price;
  }
  for(int i = 0; i < K; i++)
  {
    cin >> bag[i];
  }
}

void solution()
{
  int index = 0;
  sort(bag, bag + K);
  sort(gem, gem + N, Comp);
  priority_queue<int> pq;
  for(int i = 0; i < K; i++)
  {
    while(index < N)
    {
      int gem_weight = gem[index].weight;
      int gem_price = gem[index].price;
      if(gem_weight <= bag[i])
      {
        pq.push(gem_price);
        index++;
      }
      else
        break;
    }
    if (pq.empty() == false)
    {
      answer = answer + pq.top();
      pq.pop();
    }
  }
  cout << answer << endl;
}

int main()
{
  input();
  solution();
  return 0;
}