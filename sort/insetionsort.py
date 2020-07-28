def insertionsort(n):
	for i in range(len(n)):
		for j in range(i):
			if n[i] < n[j]:
				n[j], n[i] = n[i], n[j]
	return n
