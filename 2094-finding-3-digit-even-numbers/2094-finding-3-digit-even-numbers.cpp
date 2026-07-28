class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int count[10] = {0};
        for (int d : digits) count[d]++;
        vector<int> result;
        for (int num = 100; num <= 998; num += 2) {
            int need[10] = {0};
            need[num / 100]++;
            need[(num / 10) % 10]++;
            need[num % 10]++;
            bool ok = true;
            for (int i = 0; i < 10; i++) {
                if (need[i] > count[i]) { ok = false; break; }
            }
            if (ok) result.push_back(num);
        }
        return result;
    }
};