#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int d[3001] = { 0 };
    
    for (int i = 2; i * i < 3001; i++)
        if (!d[i])
            for (int j = i + i; j < 3001; j += i)
                d[j]++;
    
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        int a = nums[i];
        for (int j = i + 1; j < nums.size(); j++) {
            int b = nums[j];
            for (int k = j + 1; k < nums.size(); k++) {
                int c = nums[k];
                if (!d[a + b + c])
                    answer++;
            }
        }    
    }    

    return answer;
}
