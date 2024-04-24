impl Solution {
    pub fn split_words_by_separator(words: Vec<String>, separator: char) -> Vec<String> {
        words
        .iter()
        .flat_map(|w: &String| w.split(separator))
        .filter(|s: &&str| s.len() > 0)
        .map(|s: &str| (*s).to_string())
        .collect::<Vec<String>>()

        // let mut ans: Vec<String> = vec![];
        // for st in words.into_iter() {
        //     let w: Vec<&str> = st.split(separator).collect();
        //     for &s in w.iter() {
        //         if s.len() > 0 {
        //             ans.push(s.to_string())
        //         }
        //     }
        // }
        // ans
    }
}