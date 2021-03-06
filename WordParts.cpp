// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
using namespace std;
class WordParts {
public:
  string comp;
  vector <string> dic;
  int m[100];

  int r(int pos)
  {
    int & ret = m[pos];

    if (m[pos] != -1)
      return m[pos];

    if (pos == comp.size())
      return 0;

    ret = 10000;

    for (int i=0; i<dic.size(); i++)
      if (comp.substr(pos, dic[i].size()) == dic[i])
	ret = min(ret, 1 + r(pos+dic[i].size()));

    return ret;
  }

  int partCount(string original, string compound)
  {
    int ret = 0;
    comp = compound;
    memset(m, -1, sizeof(m));

    for (int i=0; i<original.size(); i++)
      {
	if (i != 0)
	  dic.push_back(original.substr(0, i));
	dic.push_back(original.substr(i));
      }

    ret = r(0);

    if (ret > 1000)
      ret = -1;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "ANTIDISESTABLISHMENTARIANISM"; string Arg1 = "ANTIDISIANISMISM"; int Arg2 = 3; verify_case(0, Arg2, partCount(Arg0, Arg1)); }
  void test_case_1() { string Arg0 = "ANTIDISESTABLISHMENTARIANISM"; string Arg1 = "ESTABLISHMENT"; int Arg2 = -1; verify_case(1, Arg2, partCount(Arg0, Arg1)); }
  void test_case_2() { string Arg0 = "TOPCODERDOTCOM"; string Arg1 = "TOMTMODERDOTCOM"; int Arg2 = 5; verify_case(2, Arg2, partCount(Arg0, Arg1)); }
  void test_case_3() { string Arg0 = "HELLO"; string Arg1 = "HELLOHEHELLOLOHELLO"; int Arg2 = 5; verify_case(3, Arg2, partCount(Arg0, Arg1)); }
  void test_case_4() { string Arg0 = "DONTFORGETTHEEMPTYCASE"; string Arg1 = ""; int Arg2 = 0; verify_case(4, Arg2, partCount(Arg0, Arg1)); }
  void test_case_5() { string Arg0 = "BAAABA"; string Arg1 = "BAAABAAA"; int Arg2 = 2; verify_case(5, Arg2, partCount(Arg0, Arg1)); }
  void test_case_6() { string Arg0 = "ABBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABB"; string Arg1 = "BBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABAA"; int Arg2 = 17; verify_case(6, Arg2, partCount(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
WordParts ___test;
___test.run_test(-1);
}
// END CUT HERE 
