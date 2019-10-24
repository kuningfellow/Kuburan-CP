rides = int(input())

while (rides > 0):
	rides -= 1
	darling = input().split()
	n = int(darling[0])
	k = int(darling[1])
	m = int(darling[2])
	ans = 1
	while (n > 0):
		if (n % 2 == 1):
			ans = ans * k % m
		k = k * k % m
		n //= 2
	print(ans)