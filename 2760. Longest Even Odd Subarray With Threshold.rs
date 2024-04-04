impl Solution {
    pub fn longest_alternating_subarray(a: Vec<i32>, threshold: i32) -> i32 {
        let mut ans = 0 as usize;
        let mut l = 0;
        let mut r = 0;
        while l<a.len() {
            if a[l]%2 == 0 && a[l]<=threshold {
                r = l + 1;
                while r<a.len() && a[r]<=threshold && a[r]%2!=a[r-1]%2 {
                    r += 1;
                }
                ans = ans.max(r-l);
                l = r;
            } else {
                l += 1;
            }
        }
        ans as i32
    }
}