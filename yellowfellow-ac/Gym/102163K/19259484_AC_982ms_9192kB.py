rides = int(input())

while (rides > 0):
	rides -= 1
	
	franxx = input().split()
	franxx[1] = int(franxx[1])
	lis = input().split()
	ans = 0
	tmp = 0
	j = 0
	for i, x in enumerate(lis):
		tmp += int(x)
		while (j <= i and tmp >= franxx[1]):
			tmp -= int(lis[j])
			j += 1
		if (tmp < franxx[1]):
			ans += i - j + 1
	
	print(ans)