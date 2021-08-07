#!/usr/bin/env python
from functools import lru_cache
from math import gcd
import sys

input = sys.stdin.readline

mod = 10 ** 9 + 7

@lru_cache(None)
def bin_mod_fib(n):
    if n == 0:
        return 0, 1
    p = bin_mod_fib(n >> 1)
    c = (p[0] * (2 * p[1] - p[0])) % mod
    d = (p[0] ** 2 + p[1] ** 2) % mod
    if n & 1:
        return d, (c + d) % mod
    else:
        return c, d

if __name__ == '__main__':
    for _ in range(int(input())):
        n = input().strip()
        m = int(input())
        k = 0
        for d in n:
            k = (10 * k + ord(d) - ord('0')) % m
        print(bin_mod_fib(gcd(k, m))[0])
