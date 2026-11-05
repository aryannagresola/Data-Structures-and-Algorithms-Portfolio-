#include <iostream>
#include "DFS.h"

template <typename T>
void test_DFS(){
    auto G = create_reference_graph<unsigned>();

    std::cout << "GRAPH:" << std::endl;
    std::cout << G << std::endl;

    std::cout << "DFS Order of vertices:" << std::endl;

    auto dfs_visit_order = depth_first_search(G, 1);

    for (auto v : dfs_visit_order){
        std::cout << v << std::endl;
    }
}

int main(){
    using T = unsigned;
    test_DFS<T>();

    return 0;
}



