import Tkinter as tk
import os
from subprocess import PIPE, check_output

top = tk.Tk();

def go():
	string = E1.get()
	os.system('./generator ' + string + ' > tmp.txt')
	#os.system('cat tmp.txt')
	#tmp = Popen(args='cat tmp.txt | ./read',stdout=PIPE,shell=True)
	i_result = check_output('cat tmp.txt',shell=True)
	T1.config(text=i_result)
	result = check_output('cat tmp.txt | ./read',shell=True)
	os.system('rm tmp.txt')
	print("result: " +result)
	T2.config(text=result)

def close_window():
	top.destroy();

B1 = tk.Button(top, text="Close",command=close_window)
B2 = tk.Button(top, text="Go",command=go)
E1 = tk.Entry(top,bd=5)
T1 = tk.Label(top)
T2 = tk.Label(top)
B1.pack()
B2.pack()
E1.pack()
T1.pack()
T2.pack()

top.mainloop()
