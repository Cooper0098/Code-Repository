def solution(t1: str, t2: str, t3: str) -> str:
    # write code here

    def time_to_min(time_str):
        hours, mins = map(int, time_str.split(":"))
        return hours * 60 + mins

    estimated_time = time_to_min(t2)
    estimated_min = time_to_min(t3)

    return "No" if estimated_min <= estimated_time else "Yes"


if __name__ == "__main__":
    print(solution("18:00", "19:05", "19:05") == "No")
    print(solution("23:00", "00:21", "00:23") == "Yes")
    print(solution("23:05", "00:05", "23:58") == "No")
