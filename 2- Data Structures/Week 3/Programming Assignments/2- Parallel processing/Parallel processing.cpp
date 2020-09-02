#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <functional>
#include <utility>
using namespace std;

class JobQueue
{
private:
    int numberOfWorkers;
    vector<int> Jobs;

    vector<int> assignedWorkers;
    vector<long long> startTime;

    void getInfo()
    {
        int numberOfJobs;
        cin >> numberOfWorkers >> numberOfJobs;
        Jobs.resize(numberOfJobs);
        for (int i = 0; i < numberOfJobs; ++i)
            cin >> Jobs[i];
    }

    void WriteResponse()
    {
        for (int i = 0; i < Jobs.size(); ++i)
        {
            cout << assignedWorkers[i] << " " << startTime[i] << "\n";
        }
    }

    void AssignJobsoptimal()
    {

        assignedWorkers.resize(Jobs.size());
        startTime.resize(Jobs.size());

        auto cmp = [](const pair<int, long long> left, const pair<int, long long> right) {
            if ((left.second) == (right.second))
                return (left.first > right.first);
            else

                return ((left.second) > (right.second));
        };
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp)> worker_finish_time(cmp);

        for (int i = 0; i < Jobs.size(); ++i)
        {
            int duration = Jobs[i];
            int next_worker = 0;
            pair<int, long long> min_worker_finish_time_pair;
            if (worker_finish_time.size() < numberOfWorkers)
            {
                min_worker_finish_time_pair = make_pair(i, 0);
            }
            else
            {
                min_worker_finish_time_pair = worker_finish_time.top();
                worker_finish_time.pop();
            }
            next_worker = min_worker_finish_time_pair.first;

            assignedWorkers[i] = next_worker;
            startTime[i] = min_worker_finish_time_pair.second;
            worker_finish_time.push(make_pair(next_worker, (min_worker_finish_time_pair.second + duration)));
        }
    }

public:
    void Solve()
    {
        getInfo();
        AssignJobsoptimal();
        WriteResponse();
    }
};

int main()
{
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}