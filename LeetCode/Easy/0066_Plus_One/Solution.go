package main

//2022-02-19
func plusOne(digits []int) []int {
	carry := 1
	for i := len(digits) - 1; i >= 0 && carry == 1; i-- {
		if digits[i] == 9 {
			digits[i] = 0
		} else {
			digits[i]++
			carry = 0
		}
	}

	if carry == 1 {
		output := make([]int, len(digits)+1)
		output[0] = 1
		for i := 1; i < len(output); i++ {
			output[i] = digits[i-1]
		}
		return output
	}
	return digits
}
