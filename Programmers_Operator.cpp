#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long long calculate(vector<string> Case, string expression)
{
    long long cal = 0;
    vector<string> change_expression;
    int flag = 0;
    string temp = "";
    for(int i = 0; i < expression.size(); i++)
    {
        if(expression[i] == '-' || expression[i] == '+' || expression[i] == '*')
        {
            string op;
            op.push_back(expression[i]);
            change_expression.push_back(temp);
            change_expression.push_back(op);
            temp = "";
            op.clear();
            continue;
        }
        temp += expression[i];
    }
    change_expression.push_back(temp);
    for(int i = 0; i < Case.size(); i++)
    {
      for(int j = 0; j < change_expression.size(); j++)
      {
        if(change_expression[j] == Case[i])
        {
          long long num1 = atoll(change_expression[j-1].c_str());
          long long num2 = atoll(change_expression[j+1].c_str());
          if(Case[i] == "*")
          {
            change_expression.insert(change_expression.begin() + j-1, to_string(num1 * num2));
          }
          else if(Case[i] == "-")
          {
            change_expression.insert(change_expression.begin() + j-1, to_string(num1 - num2));
          }
          else if(Case[i] == "+")
          {
            change_expression.insert(change_expression.begin() + j-1, to_string(num1 + num2));
          }
          for(int k = 0; k < 3; k++)
          {
            change_expression.erase(change_expression.begin() + j);
          }
          j--;
        }
      }
    }
    return abs(atoll(change_expression[0].c_str()));
}

long long solution(string expression) 
{
    long long answer = 0;
    vector<vector<string>> op_list;
    op_list.push_back({ "+","-","*" });
    op_list.push_back({ "+","*","-" });
    op_list.push_back({ "-","+","*" });
    op_list.push_back({ "-","*","+" });
    op_list.push_back({ "*","+","-" });
    op_list.push_back({ "*","-","+" });
    for(int i = 0; i < op_list.size(); i++)
    {
      long long cal = calculate(op_list[i], expression);
      if(answer < cal)
        answer = cal;
    }
    return answer;
}