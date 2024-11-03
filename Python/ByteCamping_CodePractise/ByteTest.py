def solution(n: int, a: list, x: int, y: int) -> bool:
    index_x = a.index(x)
    index_y = a.index(y)

    return abs(index_x - index_y) == 1


if __name__ == "__main__":
    print(solution(4, [1, 4, 2, 3], 2, 4) == True)
    print(solution(5, [3, 4, 5, 1, 2], 3, 2) == False)
    print(solution(6, [6, 1, 5, 2, 4, 3], 5, 2) == True)
