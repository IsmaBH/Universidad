#Implementacion recursiva de la  transformada rapida de fourier
import cmath as cm

def RECURSIVE_FFT(a):
	y = a
	n = len(a)
	if n == 1:
		return a
	#variable auxiliar z
	z = (2*cm.pi*1j)/(n)
	Wn = cm.exp(z)
	W = 1
	a0 = a[0:n:2]
	a1 = a[1:n:2]
	y0 = RECURSIVE_FFT(a0)
	y1 = RECURSIVE_FFT(a1)
	for k in range(0,int(n/2)):
		y[k] = y0[k] + W * y1[k]
		y[k+int(n/2)] = y0[k] - W * y1[k]
		W = W*Wn
	return y

a = [int(x) for x in input().split()]
print(RECURSIVE_FFT(a))