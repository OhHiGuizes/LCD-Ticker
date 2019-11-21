import serial

s = serial.Serial("/dev/ttyACM0")
def main():
	with open("ticker.txt", "rt") as f:
		s.read_until(b'Ready!')
		b = f.read(1)
		s.write(bytes(b, encoding='utf8'))
		while True:
			if(s.read_until(b'OK!')):
				c = f.read(1)
				if(not c):
					break
				else:
					s.write(bytes(c, encoding='utf8'))

	
if __name__ == "__main__":
	main()
