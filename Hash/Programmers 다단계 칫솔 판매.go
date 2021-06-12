type Info struct {
    money int
    parent string
}

func solution(enroll []string, referral []string, seller []string, amount []int) []int {
    var result = []int{}
    var treeMap = map[string]Info{}
    
    treeMap["center"] = Info{ 0, "-" }
    
    for i := 0; i < len(enroll); i++ {
        if referral[i] == "-" {
            treeMap[enroll[i]] = Info{ 0, "center" }
        } else {
            treeMap[enroll[i]] = Info{ 0, referral[i] }
        }
    }
    
    for i := 0; i < len(seller); i++ {
        nowMoney := amount[i] * 100
        nowMember := seller[i]
        
        for nowMoney != 0 && nowMember != "center" {
            t, _ := treeMap[nowMember]
            if nowMoney / 10 == 0 {
                t.money += nowMoney
            } else {
                t.money += nowMoney - nowMoney / 10
            }
            treeMap[nowMember] = t
            
            nowMoney /= 10
            nowMember = t.parent
        }
    }
    
    for i := 0; i < len(enroll); i++ {
        t, _ := treeMap[enroll[i]]
        result = append(result, t.money)
    }
    
    return result
}
