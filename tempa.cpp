//
//(Minimum) Assignment Problem by Hungarian Algorithm
//taken from Knuth's Stanford Graphbase
//
#include <bits/stdc++.h>
using namespace std;

#define INF (0x7FFFFFFF)

#define size1 (20)
#define size2 (20)

#define verbose (0)

long long Array[size1][size2];
char Result[size1][size2];  // used as boolean

void initArray()
{
long long i,j;

for (i=0;i<size1;++i)
	for (j=0;j<size2;++j)
		Array[i][j]=99999999;
}

void hungarian(long long n)
{
long long i,j;

unsigned long long m=n;
long long k;
long long l;
long long s;
long long col_mate[size1]={0};
long long row_mate[size2]={0};
long long parent_row[size2]={0};
long long unchosen_row[size1]={0};
long long t;
long long q;
long long row_dec[size1]={0};
long long col_inc[size2]={0};
long long slack[size2]={0};
long long slack_row[size2]={0};
long long unmatched;
long long cost=0;

for (i=0;i<size1;++i)
	for (j=0;j<size2;++j)
		Result[i][j]=false;

// Begin subtract column minima in order to start with lots of zeroes 12
// printf("Using heuristic\n");
for (l=0;l<n;l++)
{
	s=Array[0][l];
	for (k=1;k<n;k++)
		if (Array[k][l]<s)
			s=Array[k][l];
	cost+=s;
	if (s!=0)
		for (k=0;k<n;k++)
			Array[k][l]-=s;
}
// End subtract column minima in order to start with lots of zeroes 12

// Begin initial state 16
t=0;
for (l=0;l<n;l++)
{
	row_mate[l]= -1;
	parent_row[l]= -1;
	col_inc[l]=0;
	slack[l]=INF;
}
for (k=0;k<m;k++)
{
	s=Array[k][0];
	for (l=1;l<n;l++)
		if (Array[k][l]<s)
			s=Array[k][l];
	row_dec[k]=s;
	for (l=0;l<n;l++)
		if (s==Array[k][l] && row_mate[l]<0)
		{
			col_mate[k]=l;
			row_mate[l]=k;
			if (verbose)
				printf("matching col %d==row %d\n",l,k);
			goto row_done;
		}
	col_mate[k]= -1;
	if (verbose)
		printf("node %d: unmatched row %d\n",t,k);
	unchosen_row[t++]=k;
row_done:
	;
}
// End initial state 16
 
// Begin Hungarian algorithm 18
if (t==0)
	goto done;
unmatched=t;
while (1)
{
	if (verbose)
		printf("Matched %d rows.\n",m-t);
	q=0;
	while (1)
	{
		while (q<t)
		{
			// Begin explore node q of the forest 19
			{
				k=unchosen_row[q];
				s=row_dec[k];
				for (l=0;l<n;l++)
					if (slack[l])
					{
						long long del;
						del=Array[k][l]-s+col_inc[l];
						if (del<slack[l])
						{
							if (del==0)
							{
								if (row_mate[l]<0)
									goto breakthru;
								slack[l]=0;
								parent_row[l]=k;
								if (verbose)
									printf("node %d: row %d==col %d--row %d\n",
										t,row_mate[l],l,k);
								unchosen_row[t++]=row_mate[l];
							}
							else
							{
								slack[l]=del;
								slack_row[l]=k;
							}
					}
				}
			}
			// End explore node q of the forest 19
			q++;
		}
 
		// Begin introduce a new zero into the matrix 21
		s=INF;
		for (l=0;l<n;l++)
			if (slack[l] && slack[l]<s)
				s=slack[l];
		for (q=0;q<t;q++)
			row_dec[unchosen_row[q]]+=s;
		for (l=0;l<n;l++)
			if (slack[l])
			{
				slack[l]-=s;
				if (slack[l]==0)
				{
					// Begin look at a new zero 22
					k=slack_row[l];
					if (verbose)
						printf(
							"Decreasing uncovered elements by %d produces zero at [%d,%d]\n",
							s,k,l);
					if (row_mate[l]<0)
					{
						for (j=l+1;j<n;j++)
							if (slack[j]==0)
								col_inc[j]+=s;
						goto breakthru;
					}
					else
					{
						parent_row[l]=k;
						if (verbose)
							printf("node %d: row %d==col %d--row %d\n",t,row_mate[l],l,k);
						unchosen_row[t++]=row_mate[l];
					}
					// End look at a new zero 22
				}
			}
			else
				col_inc[l]+=s;
		// End introduce a new zero into the matrix 21
	}
breakthru:
	// Begin update the matching 20
	if (verbose)
		printf("Breakthrough at node %d of %d!\n",q,t);
	while (1)
	{
		j=col_mate[k];
		col_mate[k]=l;
		row_mate[l]=k;
		if (verbose)
			printf("rematching col %d==row %d\n",l,k);
		if (j<0)
			break;
		k=parent_row[j];
		l=j;
	}
	// End update the matching 20
	if (--unmatched==0)
		goto done;
	// Begin get ready for another stage 17
	t=0;
	for (l=0;l<n;l++)
	{
		parent_row[l]= -1;
		slack[l]=INF;
	}
	for (k=0;k<m;k++)
		if (col_mate[k]<0)
		{
			if (verbose)
				printf("node %d: unmatched row %d\n",t,k);
			unchosen_row[t++]=k;
		}
	// End get ready for another stage 17
}
done:

// Begin doublecheck the solution 23
for (k=0;k<m;k++)
	for (l=0;l<n;l++)
		if (Array[k][l]<row_dec[k]-col_inc[l])
			exit(0);
for (k=0;k<m;k++)
{
	l=col_mate[k];
	if (l<0 || Array[k][l]!=row_dec[k]-col_inc[l])
		exit(0);
}
k=0;
for (l=0;l<n;l++)
	if (col_inc[l])
		k++;
if (k>m)
	exit(0);
// End doublecheck the solution 23
// End Hungarian algorithm 18

for (i=0;i<m;++i)
{
	Result[i][col_mate[i]]=true;
 /*TRACE("%d - %d\n", i, col_mate[i]);*/
}
for (k=0;k<m;++k)
{
	for (l=0;l<n;++l)
	{
		/*TRACE("%d ",Array[k][l]-row_dec[k]+col_inc[l]);*/
		Array[k][l]=Array[k][l]-row_dec[k]+col_inc[l];
	}
	/*TRACE("\n");*/
}
for (i=0;i<m;i++)
	cost+=row_dec[i];
for (i=0;i<n;i++)
	cost-=col_inc[i];
printf("%lld\n",cost);
}

main()
{
	long long y,x,i;

	initArray();
	long long n;
	cin>>n;
	pair<long long , long long> a[n+9] , b[n+9];
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i].first>>a[i].second;
	for(long long i = 0 ; i < n ; i++)
		cin>>b[i].first>>b[i].second;
	for(long long i = 0 ; i < n ; i ++)
		for(long long j = 0 ; j < n; j++){
			long long dst = abs(a[i].first - b[i].first) + abs(b[i].second - a[i].second);
			Array[i][j] = dst;
		}
	hungarian(n);

// for (y=0;y<size1;++y)
// 	for (x=0;x<size2;++x)
// 		if (Result[y][x])
// 			printf("%d and %d are connected in the assignment\n",y,x);
}