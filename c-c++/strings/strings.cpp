#include <iostream>
#include <string>
using namespace std;
/* s2 contains all characters in s1 */
string twoStrings(string s1, string s2) {
  for (auto c : s1) 
    if (s2.find(c) == string::npos)
      return "NO";
  return "YES";
}  

int main() {
  string s2 {"hello"};
  string s1 {"eel"};
  cout << twoStrings(s2,s1) << &endl;
  return 0;
}
