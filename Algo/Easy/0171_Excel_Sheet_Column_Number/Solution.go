package main

const NUM_OF_CHARS = 26

func titleToNumber(columnTitle string) int {
	total := 0
	for i := 0; i < len(columnTitle); i++ {
		total *= NUM_OF_CHARS
		total += (int(columnTitle[i]) - int('A') + 1)
	}
	return total
}
