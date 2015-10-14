import sys
sys.setrecursionlimit(5000)
x = [None for _ in range(5000)]
def fibo(n):
	if n==0 :
		return 0
	if n==1:
		return 1;
	if n< 5000 and x[n] != None:
		return x[n];
	if n<5000:
		x[n] = fibo(n-2) + fibo(n-1)
		return x[n]
	else :
		return fibo(n-2) + fibo(n-1)
def ans(k , n):
	if k == 0 :
		return n;
	return ans(k-1 , fibo(n))
t = int(input())
fibo(2000)
while t:
	k , n , m = map(int , raw_input().split())
	print ans(k , n)%m