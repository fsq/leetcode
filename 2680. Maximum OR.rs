impl Solution {
    pub fn maximum_or(nums: Vec<i32>, k: i32) -> i64 {
        let mut bc: [i32; 50] = [0; 50];
        let mut hb = 0;
        for x in &nums {
            for j in 0..31 {
                if (((x>>j) & 1) > 0) {
                    bc[j] += 1;
                    hb = hb.max(j);
                }
            }
        }

        let mut ans: i64 = 0;
        for &x in nums.iter() {
            if (((x>>hb) & 1) > 0) {
                let mut sum: i64 = 0;
                for j in 0..31 {
                    if ((((x>>j) & 1)>0 && bc[j]>1) || 
                        (((x>>j) & 1)==0 && bc[j]>0)) {
                        sum |= ((1 as i64)<<j);
                    }
                }
                sum |= ((x as i64) << k);
                ans = ans.max(sum);
            }
        }
        return ans;
    }
}