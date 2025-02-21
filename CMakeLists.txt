cmake_minimum_required(VERSION 3.17)
project(template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_SYSROOT /Library/Developer/CommandLineTools/SDKs/MacOSX14.sdk)

add_executable(template main.cpp)

add_executable(djset_base djset/base/main.cpp)
add_executable(djset_rank djset/rank/main.cpp)

add_executable(merge_sort merge_sort/base/main.cpp)

add_executable(num_dp num_dp/base/main.cpp)

add_executable(dijkstra dijkstra/base/main.cpp)

add_executable(bit_single_add bit/bit_single_add/main.cpp)
add_executable(bit_interval_add bit/bit_interval_add/main.cpp)
add_executable(bit_single_max bit/bit_single_max/main.cpp)


add_executable(trie trie/base/main.cpp)
add_executable(trie01 trie/trie01.cpp)

add_executable(comb_base comb/base/main.cpp)

add_executable(comb_complicated comb/complicated/main.cpp)

add_executable(queue_monotonous queue/monotonous/main.cpp)

add_executable(segment segment/base/main.cpp)
add_executable(segment_interval_add segment/interval_add/main.cpp)
add_executable(segment_interval_max segment/interval_max/main.cpp)
add_executable(segment_interval_add_x2 segment/interval_add_x2/main.cpp)

add_executable(lcp lcp/base/main.cpp)

add_executable(gcd gcd/base/main.cpp)


add_executable(subset subset/base/main.cpp)

add_executable(quick_power quick_power/base/main.cpp)
add_executable(quick_power_matrix quick_power/matrix/main.cpp)

add_executable(rand rand/base/main.cpp)

add_executable(lower_bound lower_bound/base/main.cpp)

add_executable(quick_sort quick_sort/base/main.cpp)

add_executable(heap_sort heap_sort/base/main.cpp)

add_executable(binary_graph binary_graph/base/main.cpp)

add_executable(kmp kmp/base/main.cpp)
add_executable(z_kmp kmp/z-kmp/main.cpp)

add_executable(next_higher_k next_higher_k/base/main.cpp)

add_executable(manacher manacher/base/main.cpp)

add_executable(lca_tarjan lca/tarjan/main.cpp)

add_executable(ors_ors ors/ors/main.cpp)

add_executable(binary_lifting binary_lifting/tree/main.cpp)
add_executable(binary_lifting2 binary_lifting/tree/main2.cpp)

add_executable(rmq rmq/base/main.cpp)

add_executable(lca_dfs lca/binary_lifting/dfs.cpp)

add_executable(p4648 luogu/p4648.cpp)

add_executable(scan_line scan_line/line.cpp)

add_executable(eratosthenes prime_filter/eratosthenes.cpp)

add_executable(cantor cantor/main.cpp)
add_executable(reverse cantor/reverse.cpp)
add_executable(main main.cpp)
add_executable(ek network_flow/maximum_flow/ek.cpp)
add_executable(dinic network_flow/maximum_flow/dinic.cpp)