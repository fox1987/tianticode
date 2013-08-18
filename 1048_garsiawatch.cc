#include <stdio.h>

#define MaxInput 101
#define DEBUG
typedef struct Store {
  int weight;
  struct Store* next;
  struct Store* prev;
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
    while(pos->next->next != NULL) {
      if (pos->weight <= pos->next->next->weight) break;
      pos = pos->next;
    }
    int cur_cost = pos->weight + pos->next->weight;
    total_cost += cur_cost;
    Store* tmp = pos->next;
    pos->next = tmp->next;
    if (tmp->next != NULL) {
      tmp->next->prev = pos;
    }
    delete tmp;
    pos->weight = cur_cost;
    while(pos->prev != NULL) {
      if (pos->prev->weight > cur_cost) {
        break;
      } else {
        pos->weight = pos->prev->weight;
        pos->prev->weight = cur_cost;
        pos = pos->prev;
      }
    }
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
    tmp->prev = NULL;
    if (head == NULL) {
      last_store = head = tmp;
    } else {
      last_store->next = tmp;
      tmp->prev = last_store;
      last_store = tmp;
    }
  }
#ifdef DEBUG
  TransStoreList(head);
#endif
  printf("%d", MinMergeCost(head, input_num));
  delete head;
  return 0;
}
