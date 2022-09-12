import matplotlib.pyplot as plt

if __name__ == '__main__':
	lambdas = [1, 4, 10]
	data = [[float(prob) for prob in line.split()[:-1]] for line in input().split('|')[:-1]]
	
	for i, y in enumerate(data):
		x = [z for z in range(len(y))]
		plt.plot(x, y, label=f'λ = {lambdas[i]}')
		
	plt.legend();
	plt.xlabel('Number of packets')
	plt.ylabel('Probability')
	plt.show()
