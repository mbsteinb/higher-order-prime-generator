#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int val(string num);
int digitSum(string num);
string nextNum(string num, char* digits, int dSize);

int main(int argc, char* argv[])
{
  if(argc <= 1)
  {
    cerr << "Enter output file in command line" << endl;
    return -1;
  }

  ofstream out(argv[1]);

  char digits[4] = {'2', '3', '5', '7'};
  int dSize = 4;

  out << "Order 1:\t23" << endl;

  string num = "23";
  int lastOrder = 23;
  int order = 1;
  while(order <= 10)
  {
    num = nextNum(num, digits, dSize);

    int dSum = digitSum(num);
    if(dSum != lastOrder)
    {
      if(dSum > lastOrder)
        break;
      continue;
    }

    int v = val(num);

    bool prime = true;
    for(int i = 2; i < v-1; i++)
    {
      if(v%i == 0)
      {
        prime = false;
        break;
      }
    }

    if(prime)
    {
      out << "Order " << ++order << ":\t" << num << endl;
      lastOrder = v;
      cout << order << endl;
    }
  }

  return 0;
}

int val(string num)
{
  return atoi(num.c_str());
}

int digitSum(string num)
{
  int sum = 0;
  for(int i = 0; i < num.size(); i++)
  {
    sum += num[i] - '0';
  }
  return sum;
}

string nextNum(string num, char* digits, int dSize)
{
  for(int i = num.size()-1; i >= 0; i--)
  {
    if(num[i] != digits[dSize-1])
    {
      for(int j = 0; j < dSize-1; j++)
      {
        if(num[i] == digits[j])
        {
          num[i] = digits[j+1];
          for(int k = i+1; k < num.size(); k++)
            num[k] = digits[0];
          return num;
        }
      }
    }
  }

  string nextNum;
  for(int i = 0; i < num.size()+1; i++)
  {
    nextNum.push_back(digits[0]);
  }
  return nextNum;
}
