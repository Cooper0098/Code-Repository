package main

import "fmt"

func twoSum(nums []int, target int) []int {

	for i, x := range nums { // 枚举 i

		for j := i + 1; j < len(nums); j++ { // 枚举 i 右边的 j

			if x+nums[j] == target { // 满足要求

				return []int{i, j} // 返回两个数的下标

			}

		}

	}

	return nil // 题目保证一定有解，代码不会执行到这里

}



// --------------------------------------Go-------------------------------------//
//
//
//
//
//
//
//
//
//
//
// --------------------------------------Go------------------------------------//

func main() {

	fmt.Println("Hello, World!")
	///////////////////////////////////////////////////////////////////////
	// 测试用例
	// nums := []int{2, 7, 11, 15}
	// target := 9
	// result := twoSum(nums, target)

	// fmt.Printf("输入数组: %v, 目标值: %d, 结果: %v\n", nums, target, result)



}
