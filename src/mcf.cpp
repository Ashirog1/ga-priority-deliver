//
// Created by linux on 1/15/23.
//

//
// Created by linux on 1/15/23.
//

#ifndef GA_PRIORITY_DELIVER_MCF_H
#define GA_PRIORITY_DELIVER_MCMF_H

#include "vector"
#include "climits"
#include "queue"

#include "../include/mcf.h"

MinCostFlow::MinCostFlow(int _num_vertex) {
    this->num_vertex = _num_vertex;
    adj = std::vector<std::vector<int>>(num_vertex + 1);
    distance = std::vector<int64_t>(num_vertex + 1);
    parent = std::vector<int>(num_vertex + 1);
    in_queue = std::vector<bool>(num_vertex + 1);
}

void MinCostFlow::add_edge(int u, int v, int cap, int cost) {
    Edge e1 = {u, v, cap, cost, 0};
    Edge e2 = {v, u, 0, -cost, 0};
    adj[u].push_back(edges.size());
    edges.push_back(e1);
    adj[v].push_back(edges.size());
    edges.push_back(e2);
}

bool MinCostFlow::spfa(int source, int sink) {
    /*
     * find shortest path from source to sink
     */
    for (int v = 1; v <= num_vertex; ++v)
        distance[v] = inf;
    distance[source] = 0;
    std::queue<int> queue;
    queue.push(source);
    while (not queue.empty()) {
        int u = queue.front(); queue.pop();
        in_queue[u] = false;
        for (int i : adj[u]) {
            int v = edges[i].to;
            if (edges[i].flow < edges[i].capacity && distance[v] > distance[u] + edges[i].cost) {
                distance[v] = distance[u] + edges[i].cost;
                parent[v] = i;
                if (not in_queue[v]) {
                    in_queue[v] = true;
                    queue.push(v);
                }
            }
        }
    }

    return distance[T] != inf;
}

std::pair<int64_t, int64_t> MinCostFlow::min_cost_flow(int source, int sink) {
    /*
     * implementation classical min cost flow
     * return: {min_cost, flow}
     */
    int64_t min_cost = 0;
    int64_t flow = 0;
    while (spfa(source, sink)) {
        int flow_passed = INT_MAX;

        /*
         * find index of edge from shortest path between source and sink
         */
        std::vector<int> path;
        for (int v = sink; v != source;) {
            int id = parent[v];
            path.push_back(id);
            v = edges[id].from;
        }

        /*
         * find maximum flow can be passed in the path from source to sink
         */
        for (int id : path) {
            flow_passed = std::min(flow_passed, edges[id].capacity - edges[id].flow);
        }

        flow += flow_passed;
        min_cost += (int64_t)flow_passed * distance[sink];

        for (int id : path) {
            edges[id].flow += flow_passed;
            edges[id ^ 1].flow -= flow_passed;
        }
    }
    return {min_cost, flow};
}

#endif //GA_PRIORITY_DELIVER_MCF_H
