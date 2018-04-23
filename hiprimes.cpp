#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int val(string prime);
int digitSum(string prime);

int main(int argc, char* argv[])
{
  if(argc <= 1)
  {
    cerr << "Enter output file in command line" << endl;
    return -1;
  }

  ofstream out(argv[1]);

  char digits[4] = {'2', '3', '5', '7'};

  string prime;
  prime.push_back(digits[0]);
  prime.push_back(digits[3]);
  out << val(prime) << " : " << digitSum(prime);
  // while(true)
  // {
  //
  // }

  return 0;
}

int val(string prime)
{
  return atoi(prime.c_str());
}

int digitSum(string prime)
{
  int sum = 0;
  for(int i = 0; i < prime.size(); i++)
  {
    sum += prime[i] - '0';
  }
  return sum;
}
