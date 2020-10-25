import subprocess, psutil
import statics as dg

# output checker
def outputChecker(expected, obtained):
	return expected == obtained

# elemenator
def isElemenator(line):
	for i in range(len(dg.elemenator)):
		if line[i] != dg.elemenator[i]:
			return False
	return True

# styling...
def styleWrite():
	return '\n====================================================================================\n'

def giveTestWrite(tc):
	return 'Test #' + str(tc) + ' '

# writes data as per indentation_string
def writeIndent(data, indentation_string):
	res = ''
	line = ''
	space = len(indentation_string)

	for ch in data:
		if ch == '\n':
			for i in range(space):
				res += ' '
			res += line + '\n'
			line = ''
		else:
			line += ch

	for i in range(space):
		res += ' '		
	res += line

	return res.rstrip()

def checkIfProcessRunning(processName):
    for proc in psutil.process_iter():
        try:
            if processName.lower() in proc.name().lower():
                return True
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            pass
    return False;


# clearing debug file
dfile = open(dg.path + 'debug.txt', 'w')
dfile.write('')
dfile.close()

TestCase = 1

print('Compiling File 1.cpp...')
cmd = ['g++', dg.path + '1.cpp', '-std=c++14', '-I' + dg.path + 'Lib', '-o', dg.path + '1']
subprocess.call(cmd)
print('Compilation Information...')
input() # to hold the screen

pifile = open(dg.path + 'ParsedInput.txt', 'r')
pofile = open(dg.path + 'ParsedOutput.txt', 'r')
inputs = ''
wholeSummary = ''

for line in pifile.readlines():

	if isElemenator(line):
		ifile = open(dg.path + 'in.txt', 'w')
		ofile = open(dg.path + 'out.txt', 'r')
		dfile = open(dg.path + 'debug.txt', 'a')


		dfile.write(styleWrite())
		dfile.write(giveTestWrite(TestCase) + ": ")
		
		print(styleWrite(), end = ' ')
		print(giveTestWrite(TestCase), end = ' ')

		

		for char in inputs:
			ifile.write(char)
		ifile.close()

		

		dfile.write(styleWrite() + 'Your Debugs: ' + styleWrite())
		dfile.close()
		print('Running File...')
		cmd = [dg.path + '1.exe']
		subprocess.call(cmd)
		while checkIfProcessRunning(dg.path + '1.exe'):
			timepass = True


		dfile = open(dg.path + 'debug.txt', 'a')
		print('input : ')
		print(writeIndent(inputs, giveTestWrite(TestCase) + ' input :   '))
		dfile.write('\n' + styleWrite() + 'TestData Information: ' + styleWrite())
		dfile.write('\nTestCase :\n' + writeIndent(inputs, 'TestCase :   ') + '\n')
		


		expected = ''
		obtained = ''


		while True:
			opline = pofile.readline()
			
			if isElemenator(opline):
				break
			expected += str(opline)


		for opline in ofile.readlines():
				obtained += str(opline)

		expected = expected.strip()
		obtained = obtained.strip()

		isPassed = outputChecker(expected, obtained)
		if isPassed:
			dfile.write('Passed' + '\n')
			print(' Passed', end = ' ')
			wholeSummary += str(TestCase) + '. Passed\n'
		else:
			dfile.write('Failed\n')
			dfile.write('Expected : \n')
			dfile.write(writeIndent(expected, 'Expected :   ') + '\n')
			dfile.write('Obtained : \n')
			dfile.write(writeIndent(obtained, 'Obtained :   ') + '\n')

			print('Failed')
			print('Expected : ')
			print(writeIndent(expected, 'Expected :   '))
			print('Obtained : \n')
			print(writeIndent(obtained, 'Obtained :   '))

			wholeSummary += str(TestCase) + '. Failed\n'

		
		inputs = ''
		TestCase += 1


		ifile.close()
		ofile.close()
		dfile.close()

	else:
		
		inputs += line


dfile = open(dg.path + 'debug.txt', 'a')
dfile.write(styleWrite() + wholeSummary + styleWrite())
print(styleWrite() + wholeSummary + styleWrite(), end = ' ')


pifile.close()
pofile.close()
dfile.close()