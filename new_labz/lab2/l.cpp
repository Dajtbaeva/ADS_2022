# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};
// 10
// 5 1 2 -10 5 3 9 -5 10 10 -> 5 3 9 -5 10 10 = 32


int findMaxSum(int n, Node *head) {
  Node * cur = head;
    int ans = -9999;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += cur->val; 
        ans = max(ans, sum); 
        if(sum < 0){ 
            sum = 0;
        }
        cur = cur->next;
    }
    return ans;

  // int cur_sum = head -> val;
  // int sumi = cur_sum;
  // head = head -> next;
  // while(head){
  //   cur_sum = max(head -> val, cur_sum + head -> val); // Updating current sum if the current element adds more sum value
  //   sumi = max(sumi, cur_sum); // Updating maxSum
  //   head = head -> next;
  // }
  // return sumi;
}

int main(){
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}