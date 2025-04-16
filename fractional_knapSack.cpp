class Solution {
  public:
    static bool cmp(pair<double, int> a, pair<double, int> b) {
        return a.first > b.first;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, int>> ratio_index;

        for (int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            ratio_index.push_back({ratio, i});
        }

        sort(ratio_index.begin(), ratio_index.end(), cmp);

        double ans = 0.0;

        for (int i = 0; i < n && capacity > 0; i++) {
            int idx = ratio_index[i].second;

            if (wt[idx] <= capacity) {
                ans += val[idx];
                capacity -= wt[idx];
            } else {
                ans += ratio_index[i].first * capacity;
                break;
            }
        }

        return ans;
    }
};
