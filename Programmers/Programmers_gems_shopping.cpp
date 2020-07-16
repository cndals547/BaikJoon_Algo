#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if ((a.second - a.first) == (b.second - b.first))
	{
		return a.first < b.first;
	}
	else
	{
		return (a.second - a.first) < (b.second - b.first);
	}
}

vector<int> solution(vector<string> gems)
{
	vector<int> answer;
	vector<int> gems_vec;
	vector<pair<int, int>> gem_leng;
	set<string> gem_list;
	map<string, int> gems_map;
	map<string, int> gems_it;
	for (int i = 0; i < gems.size(); i++)
	{
		gem_list.insert(gems[i]);
	}
	
	int gem_count = gem_list.size();
	for (int i = 0; i < gems.size(); i++)
	{
		if (!gems_map.empty())
		{
			if (gems_map.find(gems[i]) != gems_map.end())
			{
				gems_map.erase(gems[i]);
			}
		}
		gems_map.insert({ gems[i], i });
		if (gems_map.size() == gem_count)
		{
			for (auto it = gems_map.begin(); it != gems_map.end(); it++)
			{
				gems_vec.push_back(it->second);
			}
			sort(gems_vec.begin(), gems_vec.end());
			gem_leng.push_back({ gems_vec[0], gems_vec[gems_vec.size() - 1] });
			gems_vec.clear();
		}
	}
	
	sort(gem_leng.begin(), gem_leng.end(), comp);
	answer.push_back(gem_leng[0].first + 1);
	answer.push_back(gem_leng[0].second + 1);
	return answer;
}