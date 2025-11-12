/**
 * Author: DF
 * Date: 2025-11-12
 * License: 
 * Description: modified rho if p is not prime.\\ for number <= 1e12, it's simpler to sieve primes and factorize the number yourself.
 * Time: Unknown but good! need to factorize p-1
 * Status: Stress-tested
 * Details: 
 */

#include "../contest/random.h"
#include "ModMulLL.h";
#include "Factor.h"
#include "MillerRabin.h"

ll primitive_root(ll p) {
    if (p == 2) return 1;
    ull rho = p-1;
    auto pf = factor(rho); // should be one of vi, v<ll>, v<ull>
    sort(all(pf)); pf.erase(unique(all(pf)), pf.end());
    while ( 1 ) {
        ll g = rnd(1,p);
        bool ok = 1;
        for (auto f : pf) {
            if (modpow(g, rho/f, p) == 1) { ok = 0; break; }
        }
        if (ok) return g;
    }
}
