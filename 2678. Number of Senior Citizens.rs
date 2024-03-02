impl Solution {
    pub fn count_seniors(details: Vec<String>) -> i32 {
        let mut ans = 0;
        for detail in details.iter() {
            let age = &detail[11..13];
            let age: i32 = age.parse().unwrap();
            if (age > 60) {
                ans += 1;
            }
        }
        return ans;
    }
}