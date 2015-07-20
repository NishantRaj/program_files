test = int(raw_input())
for x in range(test):
	s_max , inp = raw_input().split()
	s_max = int(s_max)
	print s_max
	inp = str(inp)
	counter = int(inp[0]);
	ans = 0
	temp = 0
	for j in range(1 , s_max + 1):
		if counter <= j and inp[j] != '0':
			temp = abs(counter - j)
			counter += temp + int(inp[j])
			ans += temp
		else:
			counter += int(inp[j]) 
	print "Case #" + str(x+1) +": " + str(ans)  