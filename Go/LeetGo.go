package main

import (
	"fmt"
	"math"
	"sort"
	"time"
)

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

func minimumSubstringsInPartition(s string) int {

	n := len(s)
	f := make([]int, n+1)
	for i := range s {
		f[i+1] = math.MaxInt
		cnt := [26]int{}
		k, maxCnt := 0, 0
		for j := i; j >= 0; j-- {
			b := s[j] - 'a'
			if cnt[b] == 0 {
				k++
			}
			cnt[b]++
			maxCnt = max(maxCnt, cnt[b])
			if i-j+1 == k*maxCnt {
				f[i+1] = min(f[i+1], f[j]+1)
			}
		}
	}
	return f[n]

}

func busyStudent(startTime []int, endTime []int, queryTime int) int {
	ans := 0

	for i, s := range startTime {
		if s <= queryTime && queryTime <= endTime[i] {
			ans++

		}
	}
	return ans
}

func maxConsecutiveAnswers(answerKey string, k int) int {
	ans := 0
	cnt := [2]int{}
	left := 0
	for right, ch := range answerKey {
		cnt[ch>>1&1]++
		for cnt[0] > k && cnt[1] > k {
			cnt[answerKey[left]>>1&1]--
			left++
		}
		ans = max(ans, right-left+1)
	}

	return ans

}

func sortedSquares(nums []int) []int {

	for i := range nums {
		nums[i] = nums[i] * nums[i]
	}
	sort.Ints(nums)

	return nums

}

// ----------------------------------- 链表 --------------------------------//
type ListNode struct {
	Val  int
	Next *ListNode
}

//-------------------------------------------------------------------//

func mergeNodes(head *ListNode) *ListNode {
	tail := head
	for cur := head.Next; cur.Next != nil; cur = cur.Next {
		if cur.Val != 0 {
			tail.Val += cur.Val
		} else {

			tail = tail.Next
			tail.Val = 0
		}
	}
	tail.Next = nil
	return head

}

func edgeScore(edges []int) int {

	ans := 0
	score := make([]int, len(edges))
	for i, to := range edges {
		score[to] += i
		if score[to] > score[ans] || score[to] == score[ans] && to < ans {
			ans = to
		}
	}
	return ans
}

func reportSpam(message []string, bannedWords []string) bool {

	// 将 bannedWords 转换为 set (使用 map 实现)
	banSet := make(map[string]struct{})
	for _, word := range bannedWords { //忽视索引
		banSet[word] = struct{}{}
	}

	// 统计在 message 中出现的禁用词数量
	cnt := 0
	for _, word := range message {
		if _, found := banSet[word]; found {
			cnt++
		}
		if cnt >= 2 {
			return true
		}
	}

	return false
}

func maxScoreSightseeingPair(values []int) int {

	ans := 0
	maxv := values[0]

	for i := 1; i < len(values); i++ {
		ans = max(values[i]-i+maxv, ans)
		maxv = max(maxv, values[i]+i)
	}

	return ans
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
	fmt.Print("---------------------------\n")

	// 测试用例
	// nums := []int{2, 7, 11, 15}
	// target := 9
	// result := twoSum(nums, target)

	// fmt.Printf("输入数组: %v, 目标值: %d, 结果: %v\n", nums, target, result)

	fmt.Print("---------------------------\n")

	currentTime := time.Now()

	fmt.Println("Current time:", currentTime)

	fmt.Print("---------------------------\n")

	// for i := 1; i <= 9; i++ { // i 控制行，以及计算的最大值
	// 	for j := 1; j <= i; j++ { // j 控制每行的计算个数
	// 		fmt.Printf("%d*%d=%d ", j, i, j*i)
	// 	}
	// 	fmt.Println(".")
	// } //乘法表
	fmt.Print("---------------------------\n")

	fmt.Print("---------------------------\n")

	fmt.Print("---------------------------\n")

	fmt.Print("---------------------------\n")

	fmt.Print("---------------------------\n")

	fmt.Print("---------------------------\n")

	fmt.Print("---------------------------\n")

	fmt.Print("---------------------------\n")

	fmt.Print("---------------------------\n")

	// fmt.Print("---------------------------\n")

	// fmt.Print("---------------------------\n")

	// fmt.Print("---------------------------\n")
}
