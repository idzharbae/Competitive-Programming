if __name__ == '__main__' :
	k = int(input())
	s = input()

	sk = bin(k)[2:]

	if len(sk) < len(s):
		print('0')
		exit()

	
