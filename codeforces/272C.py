import sys
a,b = map(int,sys.stdin.readline().split())
MOD = 1000000007
res = b * (b - 1) *(b * a * (a + 1)//2 + a)//2
res = res%MOD
print res