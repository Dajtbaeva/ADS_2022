class Solution {
public:
    struct MinHeap {
        vector<pair<int, int> > heap;
        MinHeap(){}

        int parent(int i) {
            return (i - 1) / 2;
        }
        int left(int i) {
            return 2 * i + 1;
        }
        int right(int i) {
            return 2 * i + 2;
        }
        bool comp(pair<int, int> p1, pair<int, int> p2){
            int cnt1 = pow(p1.first, 2) + pow(p1.second, 2);
            int cnt2 = pow(p1.first, 2) + pow(p1.second, 2);
            return cnt1 < cnt2;
        }

        void insert(pair<int, int> p) {
            heap.push_back(p);
            int i = heap.size() - 1;
            while (i > 0 && comp(heap[i], heap[parent(i)])) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }
        
        pair<int, int> extractMin() {
            // if (heap.empty()) throw std::runtime_error("heap is empty");
            if (heap.size() == 1) {
                pair<int, int> root = heap[0];
                heap.pop_back();
                return root;
            }
            pair<int, int> root = heap[0];
            heap[0] = heap[heap.size() - 1];
            heap.pop_back();
            heapify(0);
            return root;
        }
        void heapify(int i) {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if (l < heap.size() && comp(heap[l], heap[smallest]))
                smallest = l;
            if (r < heap.size() && comp(heap[r], heap[smallest]))
                smallest = r;
            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                heapify(smallest);
            }
        }
        bool empty() {
            return heap.size() == 0;
        }
        int size() {
            return heap.size();
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        MinHeap mh;
        for(int i = 0; i < points.size(); i++){
            mh.insert({points[i][0], points[i][1]});
        }
        vector<vector<int> > res;
        while(k--) {
            vector<int> v;
            pair<int, int> p = mh.extractMin();
            int a = p.first;
            int b = p.second;
            v.push_back(a);
            v.push_back(b);
            res.push_back(v);
        }
        return res;
    }
};  