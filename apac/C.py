from decimal import Decimal
t=int(raw_input())
for test in xrange(1 , t+1):
	n , m=map(int , raw_input().split())
	li=[int(x) for x in raw_input().split()]
	print "Case #"+str(test)+": "
	for i in xrange(m):
		l , r = map(int , raw_input().split())
		mult = 1;
		for y in xrange(l , r+1):
			mult = mult*(li[y]**(1.0/(r-l+1)));
		print "%0.9f" % mult