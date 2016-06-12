# remember Array 'M' store index of actual matrix 'P' so for comparing values in GetMinimum function compare the values of array 'P' not of array 'M'
SparseMatrix(n , m){

	for i = 0 to 2^i <= n:
		for j = 0 to 2^j <= m:
			for x = 0 to x + 2^i -1 < n :
				for y = 0 to y + (1<<j) -1 < m:
					if i == 0 and j == 0:
						M[x][y][i][j] = Pair(x , y) # store x, y
					else if i == 0:
						M[x][y][i][j] = GetMinimum(M[x][y][i][j-1], M[x][y+(1<<(j-1))][i][j-1])
					else if j == 0:
						M[x][y][i][j] = GetMinimum(M[x][y][i-1][j], M[x+ (1<<(i-1))][y][i-1][j])
					else 
						M[x][y][i][j] = GetMinimum(M[x][y][i-1][j-1], M[x + (2^(i-1))][y][i-1][j-1], 
							M[x][y+(2^(j-1))][i-1][j-1], M[x + (2^(i-1))][y+(2^(j-1))][i-1][j-1]);
}

RMQ(x, y, x1, y1){
	k = log(x1 - x + 1)
	l = log(y1 - y + 1)
	ans = GetMinimum(M[x][y][k][l], M[x1 - (2^k) + 1][y][k][l], M[x][y1 - (2^l) + 1][k][l], M[x1 - (2^k) + 1][y1 - (2^l) + 1][k][l]);
	return P[ans->x][ans->y] # ans->x represent Row number sored in ans and similarly ans->y represent column store in ans
}