Zero  = "Darling"
Two   = "Ride"
meine = "Me"
waifu = "Baby"
while Zero + Two + meine + waifu:
	x = input().strip()
	if (x == "0"):
		break
	elif (int(x) % 11 == 0):
		print(x, "is a multiple of 11.")
	else:
		print(x, "is not a multiple of 11.")