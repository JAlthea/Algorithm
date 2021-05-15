#include <string>
#include <vector>
#include <cstring>  //for use memset
#include <algorithm>
using namespace std;

const int ALPHABETS = 26;
int lowerToNumber(char key) { return key - 'a'; }
struct Trie {
    int count;
    Trie* node[ALPHABETS];
    
    Trie() : count(1) {
        memset(node, 0, sizeof(node));
    }
    
    ~Trie() {
        for (int i=0; i<ALPHABETS; i++)
            if (node[i])
                delete node[i];
    }
    
    void insert(const char* key) {
        if (*key) 
        {
            int next = lowerToNumber(*key);
            if (node[next] == NULL)
                node[next] = new Trie();
            else
                node[next] -> count++;
            
            node[next] -> insert(key + 1);
        }
    }
    
    int find(const char* key) {
        if (*key == '?')    //문제에서 찾으려고 하는 키워드에 무조건 ?가 들어간다. 종료 조건1
        {
            int sumCount = 0;
            for (int i=0; i<ALPHABETS; i++)
                if (node[i] != NULL)
                    sumCount += node[i] -> count;
            return sumCount;
        }
        
        int next = lowerToNumber(*key);
        if (node[next] == NULL) //종료 조건2
            return 0;
        return node[next] -> find(key + 1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    Trie *root[10001] = { 0 };  //단어의 길이마다 다르게 저장하기 위함
    Trie *reroot[10001] = { 0 };
    int wordsSize = words.size();
    int queriesSize = queries.size();
    vector<int> answer(queriesSize, 0);
    
    for (auto &word : words)    //Insert
    {
        int wordSize = word.size();
        const char *c = word.c_str();
        
        if (root[wordSize] == NULL)
            root[wordSize] = new Trie();
        root[wordSize] -> insert(c);
        
        string rString = word;
        reverse(rString.begin(), rString.end());
        
        const char *rc = rString.c_str();
        if (reroot[wordSize] == NULL)
            reroot[wordSize] = new Trie();
        reroot[wordSize] -> insert(rc);
    }
    
    for (int i=0; i<queriesSize; i++)   //Find
    {
        int querySize = queries[i].size();
        if (queries[i][querySize - 1] == '?')   //words
        {
            const char *c = queries[i].c_str();
 
            if (root[querySize] != NULL)
                answer[i] = root[querySize] -> find(c);
        }
        else    //back_words
        {
            string re = queries[i];
            reverse(re.begin(), re.end());
            const char *rc = re.c_str();
            
            if (reroot[querySize] != NULL)
                answer[i] = reroot[querySize] -> find(rc);
        }
    }
    
    return answer;
}
