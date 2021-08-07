#!/usr/bin/env python

import sys

input = sys.stdin.readline
print = sys.stdout.write


if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        x = list(map(int, input().strip().split()))
        y = list(map(int, input().strip().split()))
        a = b = 0
        for j, (zi, i) in enumerate(sorted(((xi + yi, i) for i, (xi, yi) in enumerate(zip(x, y))), reverse=True)):
            if j & 1:
                b += y[i]
            else:
                a += x[i]
        print(f"{a - b}\n")
