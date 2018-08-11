#include <bits/stdc++.h>
// https://www.nowcoder.com/question/next?pid=8537290&qid=141067&tid=17473994
using namespace std;
#define M(a, b) memset(a,b,sizeof(a))
typedef long long LL;
// memset(a,0x3f,sizeof(a))
//memset(a,0xcf,sizeof(a))
const int maxn = 3002;

//
// 第一行输入数组序列长度n，第二行输入数组序列。
// 对于 50%的数据,  1 <= n <= 10000;
//对于 100%的数据, 1 <= n <= 500000;
//时间限制：3秒
//
//空间限制：131072K
// 注意内存限制， 定义一个二维数组 m_min[500000][500000] 会内存溢出
// 131072K 能放 33554432 个int 数，但 二维数组需要存 891896832 个数
int main() {

    cout << 32768 * 1024 / sizeof(int) << endl;
    cout << 131072 * 1024 / sizeof(int) << endl; // 33554432

    cout << 500000 * 500000 << endl;              // 891896832

    int n;
    cin >> n;
    int nums[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    int cur_min;
    int ans = nums[1] << 1;
    for (int i = 1; i <= n; i++) {
        cur_min = nums[i]; // 以当前的数为最小值，两端扩展遍历法 
        int sum = nums[i];
        for (int j = i - 1; j >= 1; j--) {
            if (nums[j] >= cur_min) {
                sum += nums[j];
            } else {
                break;
            }
        }

        for (int j = i + 1; j <= n; j++) {
            if (nums[j] >= cur_min) {
                sum += nums[j];
            } else {
                break;
            }
        }
        ans = max(ans, cur_min * sum);
    }
    cout << ans << endl;
    return 0;
}