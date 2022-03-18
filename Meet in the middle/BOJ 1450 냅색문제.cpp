#include <bits/stdc++.h>
using namespace std;

int n, c, divSize, bucketIndex;
vector<int> arr;
vector<int> divCount;
vector<bool> choiced;
vector<vector<long long>> subset;

long long sumSubset(vector<bool> &choiced) {
    long long sum = 0;
    
    for (int i = 0; i < choiced.size(); ++i) {
        if (choiced[i]) {
            sum += arr[i];
        }
    }

    return sum;
}

void setSumSubset(vector<bool> &choiced, int index, int size) {
    if (index == size) {
        subset[bucketIndex].push_back(sumSubset(choiced));
        return;
    }

    setSumSubset(choiced, index + 1, size);
    choiced[index] = true;
    setSumSubset(choiced, index + 1, size);
    choiced[index] = false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    
    arr.resize(n);
    choiced.resize(n);
    divSize = 2;    // 분할할 개수. 문제에서는 2개로 나누면 충분해보인다.
    divCount.resize(divSize);
    subset.resize(divSize);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    for (int i = 0, remains = n - (n / divSize) * divSize; 
         i < divSize; 
         ++i, --remains ) {    // 예: 29는 15와 14로 나눈다.
        
        divCount[i] = n / divSize;
        
        if (remains > 0) {
            ++divCount[i];
        }
    }
    
    int sumDivCount = 0;
    for (int i = 0; i < divSize; ++i) {
        bucketIndex = i;
        
        if (i == 0) {
            setSumSubset(choiced, 0, divCount[i]);
        }
        else if (i == divSize - 1) {
            if (divCount[i - 1] != n) {
                setSumSubset(choiced, sumDivCount, n);
            }
        }
        else {
            setSumSubset(choiced, sumDivCount, sumDivCount + divCount[i]);
        }
        
        sumDivCount += divCount[i];
    }

    for (int i = 0; i < divSize; ++i) {
        sort(subset[i].begin(), subset[i].end());
    }
    
    // 아래는 divSize = 2 일 때, 계산 과정
    int answer = 0;
    for (int i = 0; i < subset[0].size(); ++i) {
        if (subset[0][i] > c) {
            continue;
        }

        if (subset[1].empty()) {
            ++answer;
            continue;
        }
        
        long long b = c - subset[0][i];
        auto p = upper_bound(subset[1].begin(), subset[1].end(), b) - subset[1].begin();
        answer += p;
    }
    
    cout << answer;
}
