#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> primes;
vector<bool> check;
int answer, low, high, sum;

void check_primes()
{
    check.resize(n + 1, true);
    for(int i = 2; i * i <= n; i++)
    {
        if(!check[i])
            continue;
        for(int j = i * i; j <= n; j += i)
        {
            check[j] = false;
        }
    }
    
    for(int i = 2; i <= n; i++)
    {
        if(check[i])
            primes.push_back(i);
    }
}

void solution()
{
    while(1)
    {
        if(sum >= n)
            sum -= primes[low++];
        else if(high == primes.size())
            break;
        else
            sum += primes[high++];
        if(sum == n)
            answer++;
    }
}

int main()
{
    cin >> n;
    check_primes();
    solution();
    cout << answer << endl;
    return 0;
}