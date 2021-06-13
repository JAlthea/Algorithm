func calcRank(count int) int {
    switch count {
        case 6:
            return 1
        case 5:
            return 2
        case 4:
            return 3
        case 3:
            return 4
        case 2:
            return 5
        default:
            return 6
    }
    return -1
}

func solution(lottos []int, win_nums []int) []int {
    m := map[int]bool{}
    countZero := 0
    
    for i := 0; i < len(lottos); i++ {
        if lottos[i] == 0 {
            countZero++
            continue
        }
        m[lottos[i]] = true
    }
    
    minCount := 0
    for i := 0; i < len(win_nums); i++ {
        if _, b := m[win_nums[i]]; b {
            minCount++
        }
    }
    
    return []int{ calcRank(minCount + countZero), calcRank(minCount) }
}
