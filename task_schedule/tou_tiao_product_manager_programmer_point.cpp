#include <bits/stdc++.h>
// https://www.nowcoder.com/question/next?pid=8537279&qid=141057&tid=17430446
using namespace std;
#define M(a, b) memset(a,b,sizeof(a))
const int MAXN = 305;
typedef long long LL;

const int maxn = 3002;
int n, m, p;
struct Task {
    int pm_index; // 产品所属pm
    int raise_time; // 提出时间
    int priority; // 优先级
    int period;  // 时长
    int task_index; // 任务序号
    int pm_task_index;
    int end_time; // 终止时间

//    bool operator < (const task& b) const{
//        return raise_time <= b.raise_time;
//    }
};

// sort according to the raise_time of task
struct compare_task {

    bool operator()(const Task &a, const Task &b) {
        return a.raise_time > b.raise_time; // 提出时间早的排在前面
    }
};

struct compare_task_inner {

    bool operator()(const Task &a, const Task &b) {
        if (a.priority != b.priority) { // high priority first
            return a.priority < b.priority;
        } else {
            if (a.period != b.period) { // short period first
                return a.period > b.period;
            } else {
                return a.raise_time > b.raise_time; // early raise_time first
            }
        }
    }
};

struct Manager {
    priority_queue<Task, vector<Task>, compare_task> m_pq;


    int most_desired_task(int start_time, Task &desired_task) {
        priority_queue<Task, vector<Task>, compare_task_inner> cache_pq; // transfer

//        while (!m_pq.empty()){
//            auto temp = m_pq.top();
//            m_pq.pop();
//            printf("%d %d %d\n",temp.pm_index, temp.raise_time,temp.priority);
//
//        }

        while (!m_pq.empty() && m_pq.top().raise_time <= start_time) {
            cache_pq.push(m_pq.top());
            m_pq.pop();
        }
//        printf("m_pq.size():%d | cache_pq.size(): %d \n",m_pq.size(), cache_pq.size());

        if (cache_pq.empty()) {
            // no task's raise_time earlier than start_time
            if (m_pq.empty()) {
                return 0;
            } else {
                desired_task = m_pq.top();
                m_pq.pop();
            }
        } else {
            // choose the first task of cache_pq
            desired_task = cache_pq.top();
            cache_pq.pop();
        }
        while (!cache_pq.empty()) {
            // transfer the remain tasks to m_pq
            m_pq.push(cache_pq.top());
            cache_pq.pop();
        }

//        printf("m_pq.size():%d | cache_pq.size(): %d \n",m_pq.size(), cache_pq.size());
        return 1;


    }
};


struct Programmer {
    int next_work_time;

    Programmer(int t) : next_work_time(t) {

    }
};

int work_time;
int select_task(vector<Manager> &pms, Task &picked_task) {
    auto cmp = [](const Task &a, const Task &b) {
        if (a.raise_time == b.raise_time || (a.raise_time <= work_time && b.raise_time <= work_time)) {
            //  short period, first index
            if (a.period != b.period) {
                return a.period > b.period;
            } else {
                return a.pm_index > b.pm_index;
            }
        }

        if (a.raise_time > work_time && b.raise_time > work_time) { // choose which raise first
            return a.raise_time > b.raise_time;
        }
        if (a.raise_time > work_time) {
            return true;
        }
        if (b.raise_time > work_time) {
            return false;
        }
        return false;
    };

    priority_queue<Task, vector<Task>, decltype(cmp)> m_pq(cmp);

    for (int i = 1; i <= n; i++) {
//        printf("pm: %d\n",i);
//        printf("pm.m_pq.size(): %d\n",pms[i].m_pq.size());

        Manager& cur_manager = pms[i]; // 注意一定要结构体引用，写成 Manager cur_manager = pms[i] 则会造成复制 pms[i] 给临时变量 cur_manager, 从而无法真正修改 pms[i] 的值
        Task desired_task;
        int ret = cur_manager.most_desired_task(work_time, desired_task);

        if (ret == 1) {
            m_pq.push(desired_task);
        }
//        printf("pm.m_pq.size(): %d\n",pms[i].m_pq.size());

    }

    if (m_pq.empty()) {
        return 0;
    }
    picked_task = m_pq.top();
    m_pq.pop();
//    printf("%d")

//    for(int i=1;i<=n;i++){
//        printf("desired begins %d pms[i].m_pq.size(): %d\n",i,pms[i].m_pq.size());
//    }
    while (!m_pq.empty()) {
        Task tmp = m_pq.top();
        m_pq.pop();
        pms[tmp.pm_index].m_pq.push(tmp); // restore
    }

//    for(int i=1;i<=n;i++){
//        printf("desired finished %d pms[i].m_pq.size(): %d\n",i,pms[i].m_pq.size());
//    }
    return 1;
}

int a, b, c, d;


int main() {
    cin >> n >> m >> p;
    vector<Manager> pms(n + 1);
    vector<Task> save_tasks(p + 1);


    for (int i = 1; i <= p; i++) {
        cin >> a >> b >> c >> d;
        Task new_t;
        new_t.pm_index = a;
        new_t.raise_time = b;
        new_t.priority = c;
        new_t.period = d;
        new_t.task_index = i;

        pms[a].m_pq.push(new_t);

    }

//    for(int i=1;i<=n;i++){
//        printf("pms[i].m_pq.size() %d\n",pms[i].m_pq.size());
//    }

    auto cmp = [](const Programmer &a, const Programmer &b) {
        return a.next_work_time >  b.next_work_time; // who finished first, first out
    };

    priority_queue<Programmer, vector<Programmer>, decltype(cmp)> losers_pq(cmp); // records the order of programmer

    for (int i = 1; i <= m; i++) {
        Programmer new_p(0);
        losers_pq.push(new_p);
    }

    while (true) {
        Programmer cur_p = losers_pq.top();
        losers_pq.pop();
        Task pt;
        work_time = cur_p.next_work_time;
//        for(int i=1;i<=n;i++){
//            printf("select begins pms[i].m_pq.size() %d\n",pms[i].m_pq.size());
//        }

        int ret = select_task(pms,  pt);



        if (ret == 0) { // no task is picked, game over
            break;
        }
//        for(int i=1;i<=n;i++){
//           printf("select finished %d pms[i].m_pq.size(): %d\n",i,pms[i].m_pq.size());
//        }
//        printf("pt.raise_time %d, cur_p.next_work_time %d pt.period %d \n ",pt.raise_time,cur_p.next_work_time,pt.period);
        pt.end_time = max(pt.raise_time, cur_p.next_work_time) + pt.period;
//        printf("picked_task.end_time %d\n",pt.end_time);
        save_tasks[pt.task_index] = pt; // 保存结果
        cur_p.next_work_time = pt.end_time;
        losers_pq.push(cur_p);
    }

    for (int i = 1; i <= p; i++) {
        cout << save_tasks[i].end_time << endl;
    }

    return 0;

}