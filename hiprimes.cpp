#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int val(string& num);
int digitSum(string& num);
string nextNum(string num, char* digits, int dSize);
string smallestNum(int val, char* digits, int dSize);

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

  string num = "23";
  int lastOrder = 23;
  int order = 1;
  while(order <= 5)
  {
    int dSum = digitSum(num);
    if(dSum != lastOrder)
    {
      if(dSum > lastOrder)
      {
        cout << "uhoh..." << endl;
        break;
      }
      num = nextNum(num, digits, dSize);
      continue;
    }

    int v = val(num);

    cout << v << " ";

    bool prime = true;
    double root = sqrt(v);
    for(int i = 2; i < root; i++)
    {
      if(v%i == 0)
      {
        prime = false;
        break;
      }
    }

    if(prime)
    {
      out << "Order " << order++ << ":\t" << num << endl;
      lastOrder = v;
      cout << endl << order << '\t' << v << endl;

      num = smallestNum(lastOrder, digits, dSize);
    }
    else
      num = nextNum(num, digits, dSize);
  }

  return 0;
}

int val(string& num)
{
  return atoi(num.c_str());
}

int digitSum(string& num)
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

string smallestNum(int val, char* digits, int dSize)
{
  string num;

  int largestDVal = digits[dSize-1] - '0';
  int remainder = val%largestDVal;
  cout << remainder << endl;

  //Hardcoding stuff :/
  if(remainder == 1) num = "35";
  else if(remainder == 2) num = "2";
  else if(remainder == 3) num = "3";
  else if(remainder == 4) num = "22";
  else if(remainder == 5) num = "5";
  else if(remainder == 6) num = "33";

  int dSum = digitSum(num);
  while(dSum < val)
  {
    num.push_back(digits[dSize-1]);
    dSum += largestDVal;
    cout << dSum << " ";
  }

  cout << endl << num << endl;

  return num;
}
