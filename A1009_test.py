#coding:utf-8
import numpy as np 
import subprocess
import os

def gen(n):
	assert 2<=n and n<=100
	a_list = np.random.choice(range(-1000,1000), n)
	a_list_sort = sorted(a_list)
	max2 = a_list_sort[-2]
	min2 = a_list_sort[1]
	sum2 = sum(map(lambda x:x*x, a_list))
	input_standard = '%d\n' %(n) + ' '.join(map(str, a_list)) + '\n'
	output_standard = '%d\n%d\n%d\n' %(max2,min2,sum2)
	return input_standard, output_standard

def check(n, i, exe = './a.out'):
	pid = os.fork()
	print('begin %d, n %d, i%d' % (pid,n,i))
	input_standard, output_standard = gen(n)
	# echo -e "5\n100 40 -30 30 1\n" | ./a.out
	proc =subprocess.Popen(exe, stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)  
	proc.stdin.write(input_standard)  
	proc.wait()
	lines = proc.stdout.readlines()  
	output_real = ''.join(lines).strip()
	success =  output_standard.strip() == output_real
	if not success:
		print(input_standard, output_standard, output_real)

	print('end %d, n %d, i %d' % (pid,n,i))
	return success

if __name__ == '__main__':
	for n in range(2,4):
		for i in range(2):
			check(n, i)