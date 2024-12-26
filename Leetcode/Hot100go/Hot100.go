package main

import (
	"fmt"
	// "math"
	// "sort"
	// "time"
)

func twoSum(nums []int, target int) []int {
	ans := []int{}
	n := len(nums)

	hashmap := make(map[int]int)

	for i := 0; i < n; i++ {
		hashmap[i] = nums[i]
	}

	flag := true

	for i := 0; i < n; i++ {
		x := target - nums[i]
		delete(hashmap, i)

		if flag {
			for idx, val := range hashmap {
				if val == x {
					ans = append(ans, i)
					ans = append(ans, idx)
					flag = false
				}
			}
		}
		hashmap[i] = nums[i]
	}

	return ans
}

func main() {

	fmt.Println("aaaa")

}


