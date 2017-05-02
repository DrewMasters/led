import Tkinter as tk
import os
from subprocess import PIPE, check_output

top = tk.Tk();

def go():
	#get user provided string from entry E1
	string = E1.get()
	#input that string into led screen generator program and store
	#result in tmp.txt
	os.system('./generator "' + string + '" > tmp.txt')
	#get led screen result from generator and write
	#to label T1
	i_result = check_output('cat tmp.txt',shell=True)
	T1.config(text=i_result)
	#pipe led screen stored in tmp.txt into reader program
	#get result and write to label T2
	result = check_output('cat tmp.txt | ./read',shell=True)
	T2.config(text=result)
	#remove the tmp file that holds the led screen
	os.system('rm tmp.txt')

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
