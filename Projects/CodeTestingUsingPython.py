import subprocess
import os
from subprocess import Popen, PIPE
import psutil
import statics as dg

base_dir = dg.path

def generateTest(T):
	f = open(base_dir + 'in.txt', 'w')

	# Code Starts here
	f.write(str(10 ** 5) + '\n')
	for i in range(10 ** 5):
		f.write(str(t + i) + '\n')

def giveOut():
	f = open(base_dir + 'out.txt', 'r')
	op = f.read()
	return op.strip()

def checkIfProcessRunning(processName):
    for proc in psutil.process_iter():
        try:
            if processName.lower() in proc.name().lower():
                return True
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            pass
    return False;


# Main Code Starts From Here

# print('Compiling Generator.cpp', end='\n')
# cmd = ["g++", base_dir + "3__Generator.cpp", "-std=c++14", "-o", base_dir + "testing_gen"]
# subprocess.call(cmd)

print('Compiling 1.cpp, Good File', end='\n')
cmd = ["g++", base_dir + "1.cpp", "-std=c++14", "-o", base_dir + "good"]
subprocess.call(cmd)

print('Compiling 3.cpp, Testing File', end='\n')
cmd = ["g++", base_dir + "3.cpp", "-std=c++14", "-o", base_dir + "testing"]
subprocess.call(cmd)

print('Compilation Done', end='\n')

t = 1
while t <= 10 ** 9:

	# preparing input file
	generateTest(t)
	t += 10 ** 5
	
	# Correct Answer
	cmd = [base_dir + 'good.exe']
	subprocess.call(cmd)
	
	# Time Pass
	while checkIfProcessRunning('good.exe'):
		i = 0
	
	good_ans = giveOut()
	# print('Expected: ' + good_ans)

	
	# Maybe Incorrect Answer
	cmd = [base_dir + 'testing.exe']
	subprocess.call(cmd)
	
	# Time Pass
	while checkIfProcessRunning('testing.exe'):
		i = 0
	
	ans_got = giveOut()
	# print('Your Output: ' + ans_got)

	
	if good_ans != ans_got:
		print('TestCase Found !!')
		dg.holdScreen()
		break

print('Passed All TestCases.')