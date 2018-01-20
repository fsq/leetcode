class Solution {
public:
    
    // https://leetcode.com/problems/find-k-closest-elements/description/
    // O(k+logn) binary search
    // first consider first k elements [0, k-1]
    // if arr[k] is better than a[0], we move window rightwards by 1
    // until the first i such that arr[i+k] is no better than a[i]
    // thus find the first i s.t. x-arr[i]<=a[i+k]-x
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0, r=arr.size()-k;
        while (l<r) {
            int i = l + ((r-l)>>1);
            if (arr[i]-(x<<1)+arr[i+k]>=0)
                r = i;
            else 
                l = i + 1;
        }
        return vector<int>(arr.begin()+l, arr.begin()+l+k);
    }
};