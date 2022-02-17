#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <string>
#include <queue>
using namespace sol527;
using namespace std;

/*takeaways
  - the key is to get the abbreviation right first;
    especially the edge case where you should just
    return the original string instead of continuing
    with the next longer prefix
  - pre-populate the abbreviations with the prefix
    length 1
  - for each word if its abbreviation has duplicates
    with other words adjust them all by going to the
    next longer prefix. Continue as many rounds as
    it needs until there is no duplicates or the
    original words are returned



*/
vector<string> Solution::wa(vector<string> &dict)
{

  auto abb = [](string s, int prefix)
  {
    const int n = s.size();
    /*
      - don't overthink this
      - 1 for the last character, and 1 for the length should
        be sufficient as the length can hold 1 to 9 which means
        the word should be long enough before the length
        becomes 2 digits
    */
    if (n <= prefix + 1 + 1)
      return s;
    return string(s.substr(0, prefix) + to_string(n - prefix - 1) + s.back());
  };

  const int n = dict.size();
  auto result = vector<string>(n);
  auto prefix = vector<int>(n, 1);
  /*
    - pre-populate the abbreviations
      with the first char as the prefix
  */
  for (auto i = 0; i < n; i++)
    result[i] = abb(dict[i], prefix[i]);

  for (int i = 0; i < n; i++)
  {
    /*
       - we don't know how many rounds it will
         take to find the next different
         abbreviations - use while loop
    */
    while (true)
    {
      auto found = false;
      for (int j = i + 1; j < n; j++)
        if (result[j] == result[i])
        {
          /* try next prefix  */
          result[j] = abb(dict[j], ++prefix[j]);
          if (!found)
            found = true;
        }
      /*
        - until there is no duplicates
        - i is fine now as there is no
          more duplicates for i
          - if any j's have duplicates
            down the road the prefix
            length will have to be
            increased to fix the problem
      */
      if (!found)
        break;
      /* try next prefix */
      result[i] = abb(dict[i], ++prefix[i]);
    }
  }

  return result;
}