# path : C:\Users\ *** \AppData\Roaming\Sublime Text 3\Packages\CFCompiler\cfcompiler

import sublime, os, sublime_plugin
import statics as dg

class CfcompilerCommand(sublime_plugin.TextCommand):
	"""docstring for CfcompilerCommnad"""
	def run(self, edit):
		dire = os.path.dirname(self.view.file_name())

		path = dg.path
		str1 = '    freopen("debug.txt", "w", stderr);\n'
		str2 = '    freopen("debug.txt", "a", stderr);\n'

		
		# changing debug to appending mode...
		f = open(path + '1.cpp', 'r')
		myfile = ''
		for line in f.readlines():
			if line == str1:
				line = str2
			myfile += line
		f.close()

		f = open(path + '1.cpp', 'w')
		f.write(myfile)
		f.close()

		cmd = dire[0] + ': && ' + 'cd ' + dire + ' && ' + 'python ' + path + '\\Lib\\DGCompiler.py'
		os.system(cmd)


		# changing debug to overwrriting mode...
		f = open(path + '1.cpp', 'r')
		myfile = ''
		for line in f.readlines():
			if line == str2:
				line = str1
			myfile += line
		f.close()

		f = open(path + '1.cpp', 'w')
		f.write(myfile)
		f.close()