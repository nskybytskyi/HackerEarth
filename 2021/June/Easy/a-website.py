#!/usr/bin/env python

import sys

input = sys.stdin.readline
print = sys.stdout.write


if __name__ == '__main__':
    for _ in range(int(input())):
        index = {}
        g = {}
        for _ in range(int(input())):
            u, v = input().strip().split()
            if u != v:
                if u not in index:
                    index[u] = len(index)
                if v not in index:
                    index[v] = len(index)
                g[index[u]] = index[v]

        n = len(index)
        cost = len(g)
        u = [False] * n

        for i in range(n):
            if not u[i]:
                c = set()
                v = i
                while v in g and not u[v]:
                    u[v] = True
                    c.add(v)
                    v = g[v]
                if v in c:
                    u[v] = True
                    cost += 1

        print(f"{cost}\n")
