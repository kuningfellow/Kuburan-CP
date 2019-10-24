rides = int(input())

while (rides > 0):
	rides -= 1
	
	zero_two = input().split()
	
	print((int(zero_two[0]) - int(zero_two[1]) + 5) // 6)