class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>>pq; // min heap 
        // step1 : put all elements in the min heap
        for(auto i : nums){
            pq.push(i) ;
        }
        while(pq.size() >k){
            pq.pop() ;
        }
        return pq.top() ;
    }
};