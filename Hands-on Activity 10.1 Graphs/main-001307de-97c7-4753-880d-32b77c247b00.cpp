#include <iostream>
#include "BFS.h"

template <typename T>
void test_BFS(){
    auto G = create_reference_graph<unsigned>();

    std::cout << "GRAPH:" << std::endl;
    std::cout << G << std::endl;

    std::cout << "BFS Order of vertices:" << std::endl;

    auto bfs_visit_order = breadth_first_search(G, 1);

    for (auto v : bfs_visit_order){
        std::cout << v << std::endl;
    }
}

int main(){
    using T = unsigned;

    test_BFS<T>();

    return 0;
}


