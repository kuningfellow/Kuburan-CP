rides = int(input())

while (rides > 0):
	rides -= 1
	
	darling = input().split()
	
	if (darling[0] == darling[1]):
		print("Iskandar")
	elif (int(darling[0]) < int(darling[1])):
		print("Hamada")
	else:
		print("Bashar")