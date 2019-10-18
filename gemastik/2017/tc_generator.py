from random import randint

f = open('tcc1','w')
T = randint(1,10)
f.write(str(T) + '\n')
for tc in range(T):
	N = randint(1,10)
	S = [randint(1,2) for i in range(N)]
	P = [randint(0,2) for i in range(N)]
	C = [ [] for i in range(N) ]
	for i in range(N):
		l = []
		for j in range(P[i]):
			x = randint(1,50)
			while x in l:
				x = randint(1,50)
			l.append(x)
		C[i] = l

	f.write(str(N) + '\n')

	for i in range(N):
		f.write(str(S[i]) + ' ')
	f.write('\n')

	for i in range(N):
		f.write(str(P[i]) + ' ')
		for j in range(P[i]):
			f.write(str(C[i][j]) + ' ')
		f.write('\n')