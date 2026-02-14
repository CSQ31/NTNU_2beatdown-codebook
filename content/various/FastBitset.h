/**
 * Author: SQ
 * Date: 2026-02-14
 * License: CC0
 * Source: me
 * Description: Simulates bitset with 64 bit integers arrays
 * To shift the biset by x, first take bit[x%64] then shift the array by x/64
 * Status: tested
 */
#pragma once

typedef unsigned long long ull;
const int N = 3e5+100;
ull bit[64][N/64];
void add(int x){
    for(int j=0;j<64;j++){
            bit[j][(x+j)/64] |= 1ULL << (x+j)%64;
    }
}
