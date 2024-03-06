impl Solution {
    pub fn circular_game_losers(n: i32, k: i32) -> Vec<i32> {
        let n = n as usize;
        let k = k as usize;
        let mut a = vec![false; n];
        let (mut x, mut d) = (0 as usize, k);
        a[0] = true;
        loop {
            x = (x + d) % n;
            d += k;
            if (a[x] == true) {
                break;
            }
            a[x] = true;
        }
        a.iter().enumerate().filter(|(i,&x)| !x).map(|(i,&x)| (i+1) as i32).collect::<Vec<i32>>()
    }
}