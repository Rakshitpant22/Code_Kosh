
Given an integer array nums and an integer k, return the k most frequent elements.You may return the answer in any order.Example 1 :

    Input : nums = [ 1, 1, 1, 2, 2, 3 ],
            k = 2 Output : [1, 2] vector<int> topKFrequent(vector<int> & nums, int k)
{
  priority_queue<pair<int, int>> pq;
  unordered_map<int, int> mpp;
  for (auto it : nums)
  {
    mpp[it]++;
  }

  for (auto it : mpp)
  {
    pq.push({it.second, it.first});
  }
  vector<int> ans;
  while (k--)
  {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  return ans;
} 

IMP CONCEPT :

    Given an array of strings words and
    an integer k,
   return the k most frequent strings.Return the answer sorted by the frequency from highest to lowest.Sort the words with the same frequency by their lexicographical order.

     Input : words = [ "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" ],
     k = 4 Output : [ "the", "is", "sunny", "day" ] Explanation : "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

class Solution {
public:


class cmp{
       public:    
  operator()(pair<int, string> a, pair<int, string> b) const
{
  if (a.first < b.first)
  return true;
  else if (a.first == b.first && a.second > b.second)
  return true;
  return false;
}
};


vector<string> topKFrequent(vector<string> &words, int k)
{
  int n = words.size();
  unordered_map<string, int> mpp;
  for (auto it : words)
  {
    mpp[it]++;
  }
  priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
  for (auto it : mpp)
  {
    pq.push({it.second, it.first});
  }
  vector<string> ans;
  while (k--)
  {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  return ans;
}
};

  static bool comparator(pair<string,int> p1, pair<string,int> p2)
    {
        if(p1.second>p2.second || (p1.second==p2.second && p1.first<p2.first))
            return true;
        return false;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m1;
        
        for(int i=0; i<words.size(); i++)
            m1[words[i]]++;
        
        vector<pair<string,int>> v1;
        for(auto it=m1.begin(); it!=m1.end(); it++)
            v1.push_back({it->first,it->second});
        
        sort(v1.begin(),v1.end(),comparator);
        
        vector<string> ans;
        for(int i=0; i<k; i++)
        {
            ans.push_back(v1[i].first);
        }
        
        return ans;
    }