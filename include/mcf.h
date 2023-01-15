//
// Created by linux on 1/15/23.
//

#ifndef GA_PRIORITY_DELIVER_MCF_H
#define GA_PRIORITY_DELIVER_MCF_H

#include <cstdint>
#include "vector"
#include "climits"

struct MinCostFlow {
private:
    static constexpr int64_t inf = LLONG_MAX;
    struct Edge {
        int from, to, capacity, cost, flow;
    };
    std::vector<std::vector<int>> adj;
    std::vector<int64_t> distance;
    std::vector<int> parent;
    std::vector<bool> in_queue;
    std::vector<Edge> edges;

    int num_vertex;
public:
    MinCostFlow(int _num_vertex);
    void add_edge(int u, int v, int cap, int cost);
    bool spfa(int source, int sink);
    std::pair<int64_t, int64_t> min_cost_flow(int source, int sink);
};

#endif //GA_PRIORITY_DELIVER_MCF_H
