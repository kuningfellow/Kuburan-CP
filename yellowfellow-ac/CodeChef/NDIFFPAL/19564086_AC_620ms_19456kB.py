rides = int(input())

while (rides > 0):
	rides -= 1
	n = int(input())
	for i in range(n):
		print(chr(i % 26 + ord('a')), end="")
	print("")