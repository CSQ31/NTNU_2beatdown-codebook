/**
 * Author: Unknown
 * Date: 2025-09-19
 * Source: cp algo
 * Description: SAM, convert string problems to DAG path problems
 * Time: $O(26N)$
 * Status: stress-tested
 */
const int MAXN = 3e5+5;
int len[MAXN],suf[MAXN],cnt[MAXN],ch[26][MAXN];
int ndcnt = 0,last = 0;
//cnt(v) stores v's endpos size
int extend(int c){

    int cur = ++ndcnt;
    cnt[last] = 1;
    len[cur] = len[last] + 1;

    int p = last;
    while(p != -1 && !ch[c][p])ch[c][p] = cur,p = suf[p];
    
    if(p == -1)suf[cur] = 0;
    else{
        int q = ch[c][p];
        if(len[p]+1 == len[q])suf[cur] = q;
        else{
            int clone = ++ndcnt;
            len[clone] = len[p] + 1;
            suf[clone] = suf[q];
            for(int i=0;i<26;i++)ch[i][clone] = ch[i][q];

            while(p != -1 && ch[c][p] == q){
                ch[c][p] = clone;
                p = suf[p];
            }
            suf[q] = suf[cur] = clone;
        }
    }
    return last = cur;
}
int main()
{
    string s;cin>>s;
    suf[0] = -1;
    for(char c:s)extend(c-'a');
}