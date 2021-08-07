#!/usr/bin/env python

import sys

input = sys.stdin.readline
print = sys.stdout.write


if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().strip().split()))
        s = set()
        index = []
        for i, ai in enumerate(a):
            if ai not in s:
                s.add(ai)
                index.append(i)
        print(f"{len(index)}\n")
        for i in index:
            print(f"{i + 1} ")
        print("\n")
