
#include <string>
#include <iostream>
#include <vector>

#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;

const int maxn = 3002;
int n, m, p;
struct task {
    int pm_index;
    int raise_time;
    int priority;
    int period;
    int task_index;
    int pm_task_index;
};

struct compare_task {

    bool operator()(const task &a, const task &b) {
        return a.raise_time <= b.raise_time;
    }
};


bool my_compare_task(const task &a, const task &b) {
    return a.raise_time <= b.raise_time;

}

struct coder {
    int finished_time;
    int coder_index;
};

struct compare_coder {
    bool operator()(const coder &l, const coder &r) {
        if (l.finished_time == r.finished_time) {
            return l.coder_index > r.coder_index;
        } else {
            return l.finished_time > r.finished_time;
        }
    }
};

int a, b, c, d;

int main() {
    cin >> n >> m >> p;
    vector<vector<task>> tasks(n + 1, vector<task>());
    int start_time = maxn;
    for (int i = 0; i < p; i++) {
        cin >> a >> b >> c >> d;
        task new_t;
        new_t.pm_index = a;
        new_t.raise_time = b;
        new_t.priority = c;
        new_t.period = d;
        new_t.task_index = i + 1;

        start_time = min(start_time, b); // 记录开始时间
        tasks[a].push_back(new_t); // 加入到对应产品经理的队列中
    }

    for (int i = 1; i <= n; i++) {
        sort(tasks[i].begin(), tasks[i].end(), my_compare_task);
    }
    priority_queue<coder, vector<coder>, compare_coder> pq;
    for (int i = 1; i <= m; i++) {
        coder coder1;
        coder1.coder_index = i;
        coder1.finished_time = start_time; //开始的任务
        pq.push(coder1);
    }

    int cnt = 0;
    vector<int> visited(n + 1, 0);
    vector<int> finished(p + 1, 0);
    while (cnt < n) {

        coder cur_coder = pq.top();
        pq.pop();

        int coder_time = cur_coder.finished_time;
//        task handle_task;
//        handle_task.raise_time=maxn;
        task cur_coder_task; // 当前要处理的task
        int cur_coder_task_index = maxn;
        cur_coder_task.priority = -2;
        for (int i = 1; i <= n; i++) {
            if (tasks[i].size() == 0) {
                if (visited[i] == 0) {
                    cnt++; // 属于 产品经理i的任务已经全部处理完
                    visited[i] = 1;
                }
                continue;
            } else {
                task handle_task;
                handle_task.priority = -1;
                // 遍历当前的产品经理i的可以处理任务
                for (int j = 0; j < tasks[i].size(); j++) {
                    task cur_task = tasks[i][j];
                    if (cur_task.raise_time <= coder_time) {
                        if (cur_task.priority > handle_task.priority) {
                            handle_task = cur_task; // 寻找当前产品经理中优先级最高的
                            handle_task.pm_task_index = j;// 记录它在原始任务队列中的坐标
                            cur_coder_task_index = j;
                        }
                    } else {
                        break;
                    }
                }

                if (handle_task.priority != -1) {
                    if (cur_coder_task.priority == -2) {
                        cur_coder_task = handle_task;
                    } else {
                        if (handle_task.period < cur_coder_task.period) { // 时间短的优先
                            cur_coder_task = handle_task;
                        }
                    }
                }

            }

        }

        if (cnt == n) {
            break;
        }

        // 当前程序员要处理的任务
        cur_coder.finished_time = cur_coder.finished_time + cur_coder_task.period;
        finished[cur_coder_task.task_index] = cur_coder.finished_time; // 记录完成时间
        pq.push(cur_coder);

        tasks[cur_coder_task.pm_index].erase(
                tasks[cur_coder_task.pm_index].begin() + cur_coder_task.pm_task_index); // 从产品经理的待处理任务中删除该任务
    }

    for (int k = 1; k <= p; ++k) {
        cout << finished[k] << endl;
    }

    return 0;

}
