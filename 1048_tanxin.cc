#include <stdio.h>

#define MaxInput 101
#define DEBUG
/*
 * Wrong Method
 *  TestCase:6 4 2 1 3 5 7
 *  result shoule be : 74
 *  this result is : 76
 */
typedef struct Store {
  int weight;
  struct Store* next;
}Store;

void TransStoreList(Store* head) {
  if (head == NULL) return;
  Store* tmp = head;
  while (tmp != NULL) {
    printf("%d ", tmp->weight);
    tmp = tmp->next;
  }
  printf("\n");
}

int MinMergeCost(Store* head, int len) {
  if (head == NULL) return 0;
  if (len == 1) return 0;
  int tmp_cost = 0;
  int total_cost = 0;
  while (len > 1) {
    Store* pos = head;
    Store* min_pos = head;
    int min_cost = pos->weight + pos->next->weight;
    pos = pos->next;
    while(pos->next != NULL) {
      tmp_cost = pos->weight + pos->next->weight;
      if (tmp_cost < min_cost) {
        min_cost = tmp_cost;
        min_pos = pos;
      }
      pos = pos->next;
    }
    total_cost += min_cost;
    min_pos->weight += min_pos->next->weight;
    Store* tmp = min_pos->next;
    min_pos->next = tmp->next;
    delete tmp;
    --len;
#ifdef DEBUG
    TransStoreList(head);
#endif
  }
  return total_cost;
}
int main(int argc, char** argv) {
  int input_num = 0;
  scanf("%d", &input_num);
  Store* head = NULL;
  Store* last_store = NULL;
  int tmp_weight;
  for (int i = 0; i < input_num; ++i) {
    scanf("%d", &tmp_weight);
    Store * tmp = new Store;
    tmp->weight = tmp_weight;
    tmp->next = NULL;
    if (head == NULL) {
      last_store = head = tmp;
    } else {
      last_store->next = tmp;
      last_store = tmp;
    }
  }
#ifdef DEBUG
  TransStoreList(head);
#endif
  printf("%d", MinMergeCost(head, input_num));
  return 0;
}
