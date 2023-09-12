#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace DIJK {
    const auto INF = INT_MAX;
    vector<int> dijkstra(vector<vector<pair<int, int> > > g, int s) {
        int n = g.size();
        vector<int> dis(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<>> pq;

        dis[s] = 0;
        pq.emplace(0, s);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dis[u]) {
                continue;
            }

            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK2 {
    vector<int> dijkstra(vector<vector<pair<int, int> > > g, int s) {
        int n = g.size();
        vector<int> dis(n);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

        pq.emplace(0, s);
        dis[s] = 0;
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dis[u]) {
                continue;
            }

            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_2 {
    vector<int> dijkstra(vector<vector<pair<int, int> > > g, int s) {
        int n = g.size();
        vector<int> dis(n);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

        dis[s] = 0;
        pq.emplace(0, s);
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dis[u]) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_3 {
    vector<int> dijkstra(vector<vector<pair<int, int > > > g, int s) {
        int n = g.size();
        vector<int> dis(n);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

        dis[s] = 0;
        pq.emplace(0, s);

        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dis[u]) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }

        return dis;
    }
}

namespace DIJK_4 {
    vector<int> dijkstra(vector<vector<pair<int, int> > > g, int s) {
        int n = g.size();
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        vector<int> dis(n);
        dis[s] = 0;
        pq.emplace(0, s);

        while (pq.size()) {
            auto [d, u] = pq.top();
             pq.pop();
             if (dis[u] < d) {
                 continue;
             }
             for (auto [v, w] : g[u]) {
                 if (d + w < dis[v]) {
                     dis[v] = d + w;
                     pq.emplace(dis[v], v);
                 }
             }
        }
        return dis;
    }
}

namespace DIJK_5 {
    vector<int> dijkstra(vector<vector<pair<int, int> > > g, int s) {
        int n = g.size();
        vector<int> dis(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}


namespace DIJK_6 {
    vector<int> dijkstra(vector<vector<pair<int, int> > > g, int s) {
        int n = g.size();
        vector<int> dis(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_7 {
    vector<int> dijkstra(vector<vector<pair<int, int> > >g, int s) {
        int n = g.size();
        vector<int> dis(n);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        dis[n] = 0;
        pq.emplace(0, s);
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;

    }
}

namespace DIJK_8 {
    vector<int> dijkstra(vector<vector<pair<int, int> > > g, int s) {
        int n = g.size();
        vector<int> dis(n);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        pq.emplace(0, s);
        dis[s] = 0;
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < v) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_9 {
    vector<int> dijkstra(vector<vector<pair<int, int> > >& g, int s) {
        int n = g.size();
        vector<int> dis(n);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        dis[s] = 0;
        pq.emplace(s, 0);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_10 {
    vector<int> dijkstra(vector<vector<pair<int, int> > >& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        dis[s] = 0;
        pq.emplace(0, s);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_11 {
    vector<int> dijkstra(vector<vector<pair<int, int> > >& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_12 {
    vector<int> dijkstra(vector<vector<pair<int, int> > >& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty() ) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u] ) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_13 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
        vector<int> dis(n, INT_MAX);
        pq.emplace(0, s);
        dis[s] = 0;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v] ) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_14 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_15 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }

        }
        return dis;
    }
}

namespace DIJK_16 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_17 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_18 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_19 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_20 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_21 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_22 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_23 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d ) {
                continue;
            }
            for (auto [v, w] : g[u] ) {
                if (d + w < dis[v] ) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_24 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v] , v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_25 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_26 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_27 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_28 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_29 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_30 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_31 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_32 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_33 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, 0x3f3f3f3f);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_34 {
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, 0x3f3f3f3f);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_35 {
    const int inf = 1e9;
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_36 {
    const int inf = 1e9;
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto& [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_37 {
    const int inf = 1e9;
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dis(n, inf);
        dis[s] = 0;
        pq.emplace(0, s);
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto& [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] =  d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }

}

namespace DIJK_38 {
    const int inf = 1e9;
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto& [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

namespace DIJK_39 {
    const int inf = 1e9;
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
        int n = g.size();
        vector<int> dis(n, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            for (auto& [v, w] : g[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis;
    }
}

vector<vector<pair<int, int> > > get(int n, vector<vector<int> > edges) {
    vector<vector<pair<int, int>>> g(n);
    for (auto e : edges) {
        int x = e[0], y = e[1], c = e[2];
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }
    return g;
}
void test() {
    using DIJK_39::dijkstra;
    // ans : [0, 3, 1, 4, 5, 6]
    vector<vector<int> > edges = {
            {0, 1, 4},
            {0, 2, 1},
            {1, 2, 2},
            {1, 3, 1},
            {1, 4, 3},
            {3, 4, 1},
            {3, 5, 2}
    };
    auto g = get(6, edges);
    auto dis = dijkstra(g, 0);
    for (auto e : dis) {
        cout << e << " ";
    }
    cout << "\n";
}

int main() {
    test();
    return 0;
}
