# Description     : Code that will impress u ;)
# Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
# Date            : ur my date uwu
# HEADERS ================================================================


# ========================================================================
# MAIN 
# ========================================================================

def bin(past, len):
	left = past + "0"
	right = past + "1"

	if len > 1:
		bin(left, len-1)
		bin(right, len-1)
	else:
		print(left)
		print(right)



def main():
	bin("", 4)

if __name__ == '__main__':
	print("\nSTART ----------------------------------------")
	main()

	print("\nEND ------------------------------------------")