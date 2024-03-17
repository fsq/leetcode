impl Solution {
    pub fn is_fascinating(n: i32) -> bool {
        let mut d = [0; 10];
        n.to_string().as_bytes().iter().for_each(|x| d[(x-b'0') as usize] += 1);
        (n*2).to_string().as_bytes().iter().for_each(|x| d[(x-b'0') as usize] += 1);
        (n*3).to_string().as_bytes().iter().for_each(|x| d[(x-b'0') as usize] += 1);
        if d[0] > 0 {
            return false;
        }
        d[1..=9].iter().all(|&x| x==1)
    }
}