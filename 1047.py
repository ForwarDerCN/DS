MAXN = 10007
g = [[0 for i in range(MAXN)] for j in range(MAXN)]

global n
n = int(input())
for i in range(n):
    str = input()
    row = str.split(" ")
    for j in range(0, n):
        g[i][j] = int(row[j])

def InsertVex(v):
    global n
    # Down rectangle
    i = n-1
    while i>=v:
        for j in range(n):
            g[i+1][j] = g[i][j]
        i = i-1
    # Right rectangle
    j = n-1
    n = n+1
    while j>=v:
        for i in range(n):
            g[i][j+1] = g[i][j]
        j = j-1
    # New col and row
    for i in range(n):
        g[v][i] = 0
        g[i][v] = 0
    return

def InsertArc(v, w):
    g[v][w] = 1
    g[w][v] = 1
    return

def DeleteVex(v):
    global n
    n = n-1
    # Left down rectangle
    for i in range(v, n):
        for j in range(0, n+1):
            g[i][j] = g[i+1][j]
    # Right up rectangle
    for j in range(v, n):
        for i in range(0, n):
            g[i][j] = g[i][j+1]
    return
        
def DeleteArc(v, w):
    g[v][w] = 0
    g[w][v] = 0
    return

while 1:
    str = input()
    if str == '':
        break
    else:
        op = str.split(" ")
        if op[0] == "IV":
            InsertVex(int(op[1]))
        elif op[0] == "IA":
            InsertArc(int(op[1]), int(op[2]))
        elif op[0] == "DV":
            DeleteVex(int(op[1]))
        elif op[0] == "DA":
            DeleteArc(int(op[1]), int(op[2]))

for i in range(n):
    for j in range(n):
        print(g[i][j], end = ' ')
    print('\n', end = '')
