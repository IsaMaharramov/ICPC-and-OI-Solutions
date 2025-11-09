n=int(input())
l=1; r=10**51; best=100
while l<=r:
	mid=(l+r)//2
	if mid*(mid+1)//2>=n:
		best=mid
		r=mid-1
	else:
		l=mid+1
print(2*n-best)	