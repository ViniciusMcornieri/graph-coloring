#include "./seatest/src/seatest.h"
#include "../src/include/linked_list.h"
#include "../src/include/graph.h"

void test_new(){
    linked_list_t *lst = newLinkedList(); 
    assert_int_equal(lst->quantity, 0);
}

void test_push_peek(){
    linked_list_t *lst = newLinkedList();
    int value          = 13;
    int valueb         = 7;
    push(lst, &value);
    push(lst, &valueb);
    int n =*(int *) peek(lst);
    assert_int_equal(n,7);
    assert_int_equal(lst->quantity,2);
}

void test_sum(){
    linked_list_t *lst = newLinkedList();
    int value = 7;    
    push(lst, &value);
    push(lst, &value);
    push(lst, &value);
    push(lst, &value);
    push(lst, &value);    
    assert_int_equal(lst->quantity,5);
    node_t *it = lst->head;
    int totalSum = 0;     
    while(it != NULL){
        totalSum += *(int *)it->data;
        it = it->next;
    }
    assert_int_equal(35,totalSum);
}

void test_fixture_linked_list(){
    test_fixture_start();
    run_test(test_new);
    run_test(test_push_peek);
    run_test(test_sum);
    test_fixture_end();
}

void test_new_graph_adj(){
    graph_t *g = buildGraph("./data/anna.col", ADJ, 0.5);    
    int i, qtt = 0;
    for(i = 0; i<g->vertex_qtt; i++){
         qtt += g->adj[i]->quantity;
    }
    assert_int_equal(qtt, g->edge_qtt);  
}

void test_new_graph_mtx(){
    graph_t *g = buildGraph("./data/anna.col", MTX, 0.5);
 /* int i,j, qtt = 0;
    for(i = 0; i < g->vertex_qtt; i++){
        for(j = 0; j < g->vertex_qtt; j++){
            if (g->mtx[i][j].active == 1) qtt++;
        }
    }
    assert_int_equal(qtt, g->edge_qtt);
    //*/
}


void test_fixture_graph(){
    test_fixture_start();
    run_test(test_new_graph_adj);
    run_test(test_new_graph_mtx);
    test_fixture_end();

}

void all_tests(){
    test_fixture_linked_list();
    test_fixture_graph();
}

int main(void){
    run_tests(all_tests);
    return 0;
}


/*
assert_true
assert_false
assert_int_equal
assert_ulong_equal
assert_string_equal
assert_n_array_equal
assert_bit_set
assert_bit_not_set
assert_bit_mask_matches
assert_fail
assert_float_equal
assert_double_equal
assert_string_contains
assert_string_doesnt_contain
assert_string_starts_with
assert_string_ends_with
*/
