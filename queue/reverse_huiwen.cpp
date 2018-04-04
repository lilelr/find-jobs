
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// https://www.nowcoder.com/test/question/0147cbd790724bc9ae0b779aaf7c5b50?pid=2811407&tid=14864388
// 双端队列前后遍历+回文判断

bool is_huiwen(vector<int> &nums) {
    if (nums.size() == 1) {
        return true;
    }
    int i = 0;
    int j = nums.size() - 1;
    for (; i <= j; i++, j--) {
        if (nums[i] != nums[j]) {
            return false;
        }
    }
    return true;
}

int dfs(vector<int> nums, int n, int cnt) {
    if (is_huiwen(nums)) {
        return cnt;
    }
    int res = n;
    for (int i = 0; i < n - 1; i++) {

        vector<int> copy(n - 1, 0);
        for (int j = 0; j < i; j++) {
            copy[j] = nums[j];
        }
        copy[i] = nums[i] + nums[i + 1];
        int j = i + 1;
        for (int k = i + 2; k < n; k++) {
            copy[j] = nums[k];
            j++;
        }

        res = min(res, dfs(copy, n - 1, cnt + 1));
    }
    return res;
}

void dfs_main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int res = dfs(nums, n, 0);
        cout << res << endl;


    }
}

int main() {
    int n;
    deque<int> deque1;
    int start, end;
    int res;

    while (cin >> n) {
        res = 0;
        deque1.clear();
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            deque1.push_back(temp);
        }

        while (deque1.size() > 1) {
            start = deque1.front();
            end = deque1.back();
            if (start == end) {
                deque1.pop_front();
                deque1.pop_back();
            } else {
                res++;
                int sum;
                if (start < end) {
                    sum = start;
                    deque1.pop_front();
                    sum += deque1.front();
                    deque1.pop_front();
                    deque1.push_front(sum);
                } else {
                    sum = end;
                    deque1.pop_back();
                    sum += deque1.back();
                    deque1.pop_back();
                    deque1.push_back(sum);
                }
            }
        }
        cout << res << endl;
    }

}