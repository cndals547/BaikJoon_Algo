#include <iostream>
#include <vector>

using namespace std;

bool visit[200000];
int priority[200000];
int hang[200000];
vector<int> edge[200000];

void visited(int n)
{
    if(visit[n])
        return;
    if(!visit[priority[n]])
    {
        hang[priority[n]] = n;
        return;
    }
    
    visit[n] = true;
    visited(hang[n]);
    for(int i:edge[n])
    {
        visited(i);
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) 
{
    bool answer = true;
    for(auto &it : path)
    {
        edge[it[0]].push_back(it[1]);
        edge[it[1]].push_back(it[0]);
    }
    
    for(auto &it : order)
        priority[it[1]] = it[0];
    
    if(priority[0])
        return false;
    
    visit[0] = true;
    for(int i:edge[0])
        visited(i);
    
    for(int i = 0; i < n; i++)
    {
        if(!visit[i])
            return false;
    }
    return true;
}