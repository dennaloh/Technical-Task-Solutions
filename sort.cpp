#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct caseInsensitiveCmp
{
  bool operator()(string x, string y) const
  {
    if (isupper(x[0]))
      x[0] = tolower(x[0]);
    if (isupper(y[0]))
      y[0] = tolower(y[0]);

    if (x < y)
      return true;
    return false;
  }
};

int main()
{
  string typedInStr;
  string str =
      "print happy against monkey need different effect sheep paper horse parallel journey kind account opinion lock knowledge look weather join market space married who nerve responsible payment again while rhythm prison opposite special why authority rest school operation river year shake than shame push when question road waiting Zoo respect that ring then very theory water tomorrow wheel umbrella the view walk twist unit voice waste together week weight yesterday tooth you young Zibra will yellow brain verse Xray cloud adjustment between where connection branch care needle about with addition cart button control desire Xman cloth balance";
  while (true)
  {
    cout << "Input: ";
    getline(cin, typedInStr);
    if (typedInStr == str)
      break;
    else
      cout << "Invalid string!\n";
  }
  vector<string> inputList;
  string result = "";
  string word = "";
  for (size_t i = 0; i < str.length(); i++)
  {
    char c = str[i];
    if (c == ' ')
    {
      inputList.push_back(word);
      word = "";
    }
    else if (i == str.length() - 1)
    {
      word += c;
      inputList.push_back(word);
    }
    else
      word += c;
  }

  sort(inputList.begin(), inputList.end(), caseInsensitiveCmp());

  for (string inputWord : inputList)
    result += inputWord + " ";
  result.pop_back();
  cout << "Result: ";
  cout << result;

  return 0;
}
