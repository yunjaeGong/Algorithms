import queue
import sys
import heapq as hq

N, M, K, S = map(int, sys.stdin.readline().strip().split())
Pcost, Qcost = map(int, sys.stdin.readline().strip().split())

Graph = [[] for ii in range(N+1)]
Q = queue.Queue()

zombie = [0 for _ in range(100001)]
danger = [False for _ in range(100001)]

for i in range(K):
    node = int(input())
    zombie[node] = True
    Q.put(node)

for i in range(M):
    u, v = map(int, sys.stdin.readline().strip().split())
    Graph[u].append(v)
    Graph[v].append(u)

# 다익스트라
def dijkstra():
    d = [sys.maxsize for _ in range(100001)]
    d[1] = 0
    pq = []
    hq.heappush(pq, (0, 1)) # weight, Node

    while pq:
        dist, from2 = hq.heappop(pq)
        if d[from2] < dist:
            continue

        for to in Graph[from2]:
            if zombie[to]:
                continue
            cost = Pcost

            if danger[to]:
                cost = Qcost
            if to == N:
                cost = 0
            if d[to] > d[from2] + cost:
                d[to] = d[from2] + cost
                hq.heappush(pq, [d[to], to])
    return d[N]
def findmin(lst):
    min = sys.maxsize
    idx = 0
    for i in range(len(lst)):
        if lst[i][0] < min:
            min = lst[i][0]
            idx = i
    return idx

def dijkstra_n2():
    d = [sys.maxsize for _ in range(100001)]
    d[1] = 0

    djQ = [(0,1)]
    # idx = min(djQ, key=lambda x_: x_[0])
    while djQ:
        dist, from2 = djQ.pop(findmin(djQ))
        if d[from2] < dist:
            continue

        for to in Graph[from2]:
            if zombie[to]:
                continue
            cost = Pcost

            if danger[to]:
                cost = Qcost
            if to == N:
                cost = 0
            if d[to] > d[from2] + cost:
                d[to] = d[from2] + cost
                djQ.append((d[to], to))
    return d[N]

def Danger():
    for i in range(S+1):
        if Q.empty():
            break
        size = Q.qsize()
        for i in range(size):
            to = Q.get()
            if danger[to]:
                continue
            danger[to] = True
            for v in Graph[to]:
                Q.put(v)

Danger()
print(dijkstra())
