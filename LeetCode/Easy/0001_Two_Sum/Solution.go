package main

func twoSum(nums []int, target int) []int {
	answer := []int{0, 0}
	track := map[int]int{}

	for i := 0; i < len(nums); i++ {
		if val, ok := track[nums[i]]; ok {
			answer[0] = i
			answer[1] = val
		} else {
			track[target-nums[i]] = i
		}
	}

	return answer
}
