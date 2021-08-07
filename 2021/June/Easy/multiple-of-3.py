#!/usr/bin/env python

import sys
import math

input = sys.stdin.readline
print = sys.stdout.write


if __name__ == '__main__':
    for _ in range(int(input())):
        n = input().strip()
        best = math.inf
        if int(n) % 3 == 0:
            best = min(best, int(n))
        for i in range(len(n) + 1):
            for d in range(10):
                nn = int(n[:i] + str(d) + n[i:])
                if nn % 3 == 0:
                    best = min(best, nn)
        print(f"{best}\n")
