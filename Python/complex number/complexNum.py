class Complex:
	def __init__(self, myReal, myImg):
		self.real = myReal
		self.img = myImg

	def add(self, real, imaginary):
		self.real = int(self.real) + int(real)
		self.img = int(self.img) + int(imaginary)
		if self.img < 0:
			print str(self.real) + str(self.img) + "i"
		else:
			print str(self.real) + "+" + str(self.img) + "i"

	def multiply(self, real, imaginary):
		tempReal = self.real
		tempImg = self.img
		self.real = (int(tempReal) * int(real)) - (int(tempImg) * int(imaginary))
		self.img = (int(tempReal) * int(imaginary)) + (int(tempImg) * int(real))
		if self.img < 0:
                        print str(self.real) + str(self.img) + "i"
                else:
                        print str(self.real) + "+" + str(self.img) + "i"

	def printComplex(self):
		if self.img < 0:
                        print str(self.real) + str(self.img) + "i"
                else:
                        print str(self.real) + "+" + str(self.img) + "i"


num1 = Complex(2, 1)
num2 = Complex(3, 4)

num1.printComplex()
print "Expected output: 2+1i"
num2.printComplex()
print "Expected output: 3+4i"

num1.add(3, -4)
print "Expected output: 5-3i"
num2.multiply(2, 1)
print "Expected output: 2+11i"
num1.multiply(-2, -3)
print "Expected output: -19-9i"
num2.multiply(0, 4)
print "Expected output: -44+8i"
num1.multiply(-3, 0)
print "Expected output: 57+27i"

num3 = Complex(4, 0)
num3.printComplex()
print "Expected output: 4+0i"
num3.add(2, 0)
print "Expected output: 6+0i"
num3.multiply(0, 2)
print "Expected output: 0+12i"
num3.add(-4, 0)
print "Expected output: -4+12i"
