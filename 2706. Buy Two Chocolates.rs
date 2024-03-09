impl Solution {
    pub fn buy_choco(mut prices: Vec<i32>, money: i32) -> i32 {
        prices.sort();
        let c: i32 = prices.iter().take(2).sum();
        if c <= money {
            money - c
        } else {
            money
        }
    }
}