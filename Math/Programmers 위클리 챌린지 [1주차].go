func solution(price int, money int, count int) int64 {
    sum := price * count * (count + 1) / 2
    if sum > money {
        return int64(sum - money)
    }
    return 0
}
