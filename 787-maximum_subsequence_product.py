from sys import stdin, stdout

n = int(input())
while n != 0:
    mx = 0
    dp = 0
    for v in [int(x) for x in stdin.readline().rstrip().split()]:
        dp = max(dp + v, v)
        mx = max(mx, dp)
    if mx > 0:
        print("The maximum winning streak is " + str(mx) + ".")
    else :
        print("Losing streak.")
    n = int(input())





