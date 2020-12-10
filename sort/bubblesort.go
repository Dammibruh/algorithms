package main

import "fmt"

func bubbleSort(arr []int) {
	for i := range arr {
		for j := range arr {
			if arr[i] < arr[j] {
				arr[i], arr[j] = arr[j], arr[i]
			}
		}
	}
}
func main() {
	array := []int{5, 4, 8, 3, 2}
	bubbleSort(array)
	fmt.Println(array)
}
