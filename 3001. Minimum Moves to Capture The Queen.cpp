class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a==e && !(c==e && d>=min(b,f) && d<=max(b,f))) return 1;
        if (b==f && !(d==f && c>=min(a,e) && c<=max(a,e))) return 1;

        if (abs(c-e) == abs(d-f)) {
            if (!(abs(a-e)==abs(b-f) && a>=min(c,e) && a<=max(c,e) && b>=min(d,f) && b<=max(d,f)))
                return 1;
        }

        return 2;
    }
};