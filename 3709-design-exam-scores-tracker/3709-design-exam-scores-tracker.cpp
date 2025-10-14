#include <map>
using namespace std;

class ExamTracker {
public:
    map<int, long long> score;   // time -> score
    map<int, long long> prefix;  // time -> total sum till that time
    bool dirty = false;          // track if prefix needs update

    void record(int time, int val) {
        score[time] = val;
        dirty = true; // prefix outdated
    }

    long long totalScore(int startT, int endT) {
        if (dirty) {  // recompute prefix only if new record added
            long long sum = 0;
            prefix.clear();
            for (auto &[t, s] : score) {
                sum += s;
                prefix[t] = sum;
            }
            dirty = false;
        }

        // find total till endT
        auto itEnd = prefix.upper_bound(endT);
        long long endSum = (itEnd == prefix.begin()) ? 0 : prev(itEnd)->second;

        // find total till startT - 1
        auto itStart = prefix.lower_bound(startT);
        long long startSum = (itStart == prefix.begin()) ? 0 : prev(itStart)->second;

        return endSum - startSum;
    }
};
