/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var findThePrefixCommonArray = function(a, b) {
    let n = a.length;
    let s1 = new Array(n).fill(false);
    let s2 = new Array(n).fill(false);
    let ans = new Array();
    let cm = 0;
    for (let i=0; i<n; ++i) {
        s1[a[i]] = true;
        if (s2[a[i]]) ++cm;
        s2[b[i]] = true;
        if (s1[b[i]]) ++cm;
        ans.push(cm);
    }
    return ans;

};