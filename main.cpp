#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol527;



string toString(vector<string> input)
{
  string result = "[";
  for (auto e : input)
  {
    result += e;
    result += ",";
  }
  /* remove the last comma */
  if (result.size() > 1)
    result.pop_back();
  result += "]";
  return result;
}

/*
Input: [“like”, “god”, “internal”, “me”, “internet”, “interval”, “intension”,
“face”, “intrusion”]
Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
*/
tuple<vector<string>, vector<string>> testFixture1()
{
  return make_tuple<vector<string>, vector<string>>(
      {"like", "god", "internal", "me", "internet", "interval",
       "intension", "face", "intrusion"},
      {"l2e", "god", "internal", "me", "i6t",
       "interval", "inte4n", "f2e", "intr4n"});
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << toString(get<1>(f)) << endl;
  auto dict = get<0>(f);
  auto result = Solution::wa(get<0>(f));
  cout << "result: " << toString(result) << endl;
}

main()
{
  test1();
  return 0;
}