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

func Factorial(n uint64) (result uint64) {
	if n > 0 {
		result = n * Factorial(n-1)
		return result
	}
	return 1
}

func nthPersonGetsNthSeat(n int) float64 {
	if n == 1 {
		return 1
	}

	return 0.5

}

func say(s string) {
	for i := 0; i < 5; i++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Println(s)
	}
}

func countCompleteDayPairs(hours []int) int {

	ans := 0

	j := 1

	for i := 0; i < len(hours); i++ {
		j = i + 1
		for ; j < len(hours); j++ {
			if (hours[i]+hours[j])%24 == 0 {
				ans++
			}
		}
	}

	return ans

}

func maxEnergyBoost(energyDrinkA []int, energyDrinkB []int) int64 {

	n := len(energyDrinkA)
	f, g := energyDrinkA[0], energyDrinkB[0]
	for i := 1; i < n; i++ {
		f, g = max(f+energyDrinkA[i], g), max(g+energyDrinkB[i], f)

	}

	return int64(max(f, g))
}

func losingPlayer(x int, y int) string {

	a := "Alice"

	b := "Bob"

	flag := 1

	for ; x > 0; x-- {
		y = y - 4
		if y >= 0 {
			flag *= -1

		}
	}

	if flag > 0 {

		return b

	} else {

		return a
	}

}

func countKConstraintSubstrings(s string, k int) (ans int) {

	cnt := [2]int{}

	l := 0

	for r, c := range s {

		cnt[c-'0']++
		for ; cnt[0] > k && cnt[1] > k; l++ {

			cnt[s[l]-'0']--
		}

		ans += r - l + 1
	}

	return
}

func countGoodNodes(edges [][]int) int {
	ans := 0

	n := len(edges) + 1

	g := make([][]int, n)

	for _, e := range edges {
		x, y := e[0], e[1]
		g[x] = append(g[x], y)
		g[y] = append(g[y], x)
	}

	var dfs func(int, int) int

	dfs = func(x, fa int) int {
		size, sz0, ok := 1, 0, true
		for _, y := range g[x] {
			if y == fa {
				continue
			}
			sz := dfs(y, x)
			if sz0 == 0 {
				sz0 = sz
			} else if sz != sz0 {
				ok = false
			}

			size += sz
		}
		if ok {
			ans++
		}

		return size
	}
	dfs(0, -1)
	return ans

}

func minFlips(grid [][]int) int {

	m, n := len(grid), len(grid[0])

	diffRow := 0
	for _, row := range grid {

		for j := 0; j < n/2; j++ {
			if row[j] != row[n-1-j] {

				diffRow++
			}
		}
	}

	diffCol := 0

	for j := 0; j < n; j++ {
		for i, row := range grid[:m/2] {
			if row[j] != grid[m-1-i][j] {
				diffCol++
			}
		}
	}
	return min(diffCol, diffRow)

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

	go say("world")
	say("hello")

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
