#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

map<char, pair<int, int>> key_map;

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    char right = '#', left = '*';
    int index = 1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            char a = index + '0';
            key_map[a] = {i, j};
            index++;
        }
    }
    key_map['*'] = {3,0};
    key_map['0'] = {3,1};
    key_map['#'] = {3,2};
    for(int i = 0; i < numbers.size(); i++)
    {
        if(key_map[numbers[i]+'0'].second == 0)
        {
            answer += 'L';
            left = numbers[i] + '0';
        }
        else if(key_map[numbers[i]+'0'].second == 2)
        {
            answer += 'R';
            right = numbers[i]+ '0';
        }
        else
        {
            int left_length = abs(key_map[left].first - key_map[numbers[i]+'0'].first) + abs(key_map[left].second - key_map[numbers[i]+'0'].second);
            int right_length = abs(key_map[right].first - key_map[numbers[i]+'0'].first) + abs(key_map[right].second - key_map[numbers[i]+'0'].second);
            if(left_length == right_length)
            {
                if(hand == "right")
                {
                    answer += 'R';
                    right = numbers[i] + '0';
                }
                else
                {
                    answer += 'L';
                    left = numbers[i] + '0';
                }
            }
            else if(left_length > right_length)
            {
                answer += 'R';
                right = numbers[i] + '0';
            }
            else if(left_length < right_length)
            {
                answer += 'L';
                left = numbers[i] + '0';
            }
        }
    }
    return answer;
}