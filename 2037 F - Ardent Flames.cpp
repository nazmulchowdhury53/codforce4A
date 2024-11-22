#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

class DamageSolver {
private:
    int n, m_int, k;
    vector<ll> h, x;

    struct Event {
        ll pos;
        int type;
    };

    bool canAchieveDamage(ll mid) {
        vector<Event> events;

        for (int i = 0; i < n; ++i) {
            ll required_damage = (h[i] + mid - 1) / mid;
            if (required_damage > m_int) {
                continue;
            }

            ll delta = m_int - required_damage;
            ll left = x[i] - delta;
            ll right = x[i] + delta;
            events.push_back({left, 1});
            events.push_back({right + 1, -1});
        }

        if (events.empty()) {
            return false;
        }


        sort(events.begin(), events.end(), [](const Event &a, const Event &b) {
            if (a.pos != b.pos) return a.pos < b.pos;
            return a.type > b.type;
        });

        ll cnt = 0;
        for (size_t i = 0; i < events.size(); ++i) {
            cnt += events[i].type;

            if (i + 1 < events.size() && events[i].pos == events[i + 1].pos)
                continue;


            if (cnt >= k) {
                return true;
            }
        }

        return false;
    }

public:
    DamageSolver(int n, int m_int, int k, const vector<ll>& h, const vector<ll>& x)
        : n(n), m_int(m_int), k(k), h(h), x(x) {}

    ll findMinimumDamage() {
        ll low = 1, high = 1e9;
        ll answer = -1;


        while (low <= high) {
            ll mid = (low + high) / 2;
            if (canAchieveDamage(mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m_int, k;
        cin >> n >> m_int >> k;
        vector<ll> h(n), x(n);

        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }


        DamageSolver solver(n, m_int, k, h, x);


        cout << solver.findMinimumDamage() << '\n';
    }

    return 0;
}
