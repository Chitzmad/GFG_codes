K Most Frequent Words

You have been given an array/list 'WORDS' of 'N' non-empty words, and an integer 'K'. 
Your task is to return the 'K' most frequent words sorted by their frequency from highest to lowest.

Note:

If two words have the same frequency then the lexicographically smallest word should come first in your answer.
Follow up:

Can you solve it in O(N * logK) time and O(N) extra space? 

Sample Input 1:
6 2
i love codingninjas i love coding
Sample Output 1:
i love
Sample Input 2:
8 3
the sky is blue the weather is hot
Sample Output 2:
is the blue
Explanation for Sample Input 2:
“is” and “the” are words with a frequency of 2.
“sky”, “blue”, “weather”, and “hot” are the words with a frequency of 1.

The words with a frequency of 2 are the most frequent words and the lexicographically smallest word from the words with a frequency of 1 is “blue”.

### code begins below ###

#include<unordered_map>
#include<queue>
class compare{
    public:
        bool operator()(const pair<string,int>& a, const pair<string,int>& b){
            if(a.second==b.second){
                return a.first>b.first;
            }
            else{
                return a.second<b.second;
            }
        }
};

vector<string> kMostFreqWords(string words[], int n, int k){
    // Write your code here.
    unordered_map<string,int> hmap;
    for(int i=0;i<n;i++){
        hmap[words[i]]++;
    }
    // for(const auto& word : words){
    //     hmap[word[i]]++;
    // }

    priority_queue<pair<string,int>, vector<pair<string,int>>, compare> pq;

    for(const auto& it: hmap){
        pq.push(it);
    }

    vector<string> res;
    while(k-- && !pq.empty()){
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;

} 
