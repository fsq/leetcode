impl Solution {
    pub fn can_make_subsequence(a: String, b: String) -> bool {
        let a = a.as_bytes();
        let b = b.as_bytes();
        let (mut i, mut j) = (0, 0);
        while i<a.len() && j<b.len() {
            if (a[i]==b[j] || ((a[i]-b'a'+1)%26+b'a'==b[j])) {
                j += 1;
            }
            i += 1;
        }
        j == b.len()
    }
}