/**
 * Author: SQ
 * Date: 2025-11-12
 * License: 
 * Description: generating all primes smaller than LIM, minp[i] store minimum prime factor of i, could be use for factorize a number.
 * Time: $O(LIM)$
 * Status: Stress-tested
 * Details: 
 */

const int LIM=1e6+5;
int minp[LIM];
vi ps;
void sieve(){
    minp[1] = 1;
    rep(i, 2, LIM) {
        if ( !minp[i] ) ps.pb ( minp[i] = i );
        for ( int p: ps ) {
            if ( p > minp[i] || i*1LL*p >= LIM ) break;
            minp[i*p] = p;
        }
    }
}
