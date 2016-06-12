import sys
n = int(input())
arr = map(int , sys.stdin.readline().split())
res = 1
for i in xrange(0,n):
	res = res * arr[i]
ans = str(res)
print(res)
print(ans[0])