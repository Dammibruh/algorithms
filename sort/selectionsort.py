def selectionsort(n):
	for i in range(len(n)):
		for j in range(len(n)-1, i, -1):
			if n[j] < n[i]:
				n[j], n[i] = n[i], n[j]
	return n
