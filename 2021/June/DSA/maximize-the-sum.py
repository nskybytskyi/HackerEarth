#!/usr/bin/env python

import sys

input = sys.stdin.readline  # strip
print = sys.stdout.write    # \n

from collections import defaultdict

if __name__ == '__main__':
    for _ in range(int(input())):
        n, k = map(int, input().strip().split())
        a = list(map(int, input().strip().split()))
        f = defaultdict(int)
        for ai in a:
            f[ai] += ai
        b = list(sorted(list(filter(lambda value: value > 0, f.values())), reverse=True))
        print(f"{sum(b[:k])}\n")
