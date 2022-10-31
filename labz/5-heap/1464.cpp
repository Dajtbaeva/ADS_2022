1464. Maximum Product of Two Elements in an Array
https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 


class Solution {
public:
    
struct MaxHeap {
  vector<int> heap;

  int parent(int i) {
    return (i - 1) / 2;
  }
  int left(int i) {
    return 2 * i + 1;
  }
  int right(int i) {
    return 2 * i + 2;
  }
  void insert(int value) {
    this->heap.push_back(value);
    int i = this->heap.size() - 1;
    while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
      swap(this->heap[parent(i)], this->heap[i]);
      i = parent(i);
    }
  }
  int extractMax() {
    if (this->heap.size() == 0) return INT_MAX;
    if (this->heap.size() == 1) {
      int root = this->heap[0];
      this->heap.pop_back();
      return root;
    }
    int root = this->heap[0];
    this->heap[0] = this->heap[this->heap.size() - 1];
    this->heap.pop_back();
    this->heapify(0);
    return root;
  }
  void heapify(int i) {
    int l = this->left(i);
    int r = this->right(i);
    int biggest = i;
    if (l < this->heap.size() && this->heap[l] > this->heap[biggest])
      biggest = l;
    if (r < this->heap.size() && this->heap[r] > this->heap[biggest])
      biggest = r;
    if (biggest != i) {
      swap(this->heap[i], this->heap[biggest]);
      this->heapify(biggest);
    }
  }
};
    
    int maxProduct(vector<int>& nums) {
        MaxHeap mh;
        for(int i = 0; i < nums.size(); i++){
            mh.insert(nums[i]);
        }
        int res = (mh.extractMax() - 1) * (mh.extractMax() - 1);
        return res;
    }
};



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int res = (nums[0] - 1) * (nums[1] - 1);
        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> q;
        int i = 0;
        while(i < nums.size()){
            q.push(nums[i++]);
        }
        int a = q.top();
        q.pop();
        return (a - 1) * (q.top() - 1);
    }
};