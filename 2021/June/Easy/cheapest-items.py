#!/usr/bin/env python

import sys
import math

input = sys.stdin.readline
print = sys.stdout.write


if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        vp = []
        dp = [0] + [math.inf] * (2 * n)
        for _ in range(n):
            vi, pi = map(int, input().strip().split())
            vi += 1
            for i in range(2 * n, vi - 1, -1):
                dp[i] = min(dp[i], dp[i - vi] + pi)
        print(f"{min(dp[n:])}\n")
