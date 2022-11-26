1337. The K Weakest Rows in a Matrix
https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].


class Solution {
public:
    static int comp(pair<int, int> &p1, pair<int, int> &p2){
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int> > v;
        vector<int> res;
        for(int i = 0; i < mat.size(); i++){
            int one = 0;
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 1) one++;
            }
            v.push_back(make_pair(i, one));
        }
        sort(v.begin(), v.end(), comp);
        vector<pair<int, int> > :: iterator it;
        for(it = v.begin(); it != v.end(); it++){
            if(k == 0) break;
            res.push_back((*it).first);
            k--;
        }
        return res;
    }
};


class node{
 public:
    int index;
    int data;
    
    node(int data , int row)
    {
        this->data = data;
        this->index = row;
    }
};

// Since we uses the custom priority queue that's why we have to make our custom comparison code
class compare{
public:
    bool operator()(node* a , node* b)
    {
        if(a->data > b->data)
        {
            return true;
        }
        
        if(a->data == b->data && a->index > b->index)
        {
            return true;
        }
        
        return false;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& nums, int k) {
  
  // Priority queue that stores the corresponding sum of the rows
        priority_queue<node* , vector<node* > , compare> minHeap;
        
        vector<int> helper;
    
    // Inserting the sum in the array 
    // Tip: We can also insert the sum in the min heap in this for loop
    // but that part will increase the time complexity to O(row*col*log(col))
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int sum = 0;
            for(int j = 0 ; j < nums[i].size() ; j++)
            {
                sum += nums[i][j];
            }
            helper.push_back(sum);
        }
        
    // Inserting all sum values in the min-heap with their corresponding indexes
        for(int i = 0 ; i < helper.size() ; i++)
        {
            node* temp = new node(helper[i] , i);
            minHeap.push(temp);
        }
        
        vector<int> ans;
        int i = 0;
    
    // Inserting the indexes in the ans array.
        while(minHeap.size() > 0 && i < k)
        {
            auto temp = minHeap.top();
            minHeap.pop();
            
            ans.push_back(temp->index);
            i++;
        }
        
        return ans;
    }
};