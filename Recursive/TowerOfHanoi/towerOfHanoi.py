def towerOfHanoi(n,CurrPeg,InterPeg,DestPeg):
	"Generates the moves to solve hanoi problem with n pegs"
	if n==1:
		print(CurrPeg+'->'+DestPeg)
	else:
		towerOfHanoi(n-1,CurrPeg,DestPeg,InterPeg) #1st recursive call
		print(CurrPeg+'->'+DestPeg)
		towerOfHanoi(n-1,InterPeg,CurrPeg,DestPeg) #2nd recursive call

CurrPeg=input("Enter the current peg name: ")
InterPeg=input("Enter the intermediate peg name: ")
DestPeg=input("Enter the destination peg name: ")

numDisks=int(input("Enter the number of disks: "))

print("The moves are: ")
towerOfHanoi(numDisks,CurrPeg,InterPeg,DestPeg)

#print(towerOfHanoi.__doc__)
