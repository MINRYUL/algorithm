//
//  main.swift
//  PS
//
//  Created by 김민창 on 2022/09/23.
//

import Foundation

//MARK: - 1
func solution(_ today:String, _ terms:[String], _ privacies:[String]) -> [Int] {
  var termMap = [String: Int]()
  var result = [Int]()

  let dateFormatter = DateFormatter()
  dateFormatter.dateFormat = "yyyy.MM.dd"
  let compareToday = dateFormatter.date(from: today) ?? Date()

  terms.forEach { term in
    let term = term.components(separatedBy: " ")
    termMap[term[0]] = Int(term[1])!
  }

  privacies.enumerated().forEach { index, privacy in
    let privacy = privacy.components(separatedBy: " ")
    var day = privacy[0].components(separatedBy: ".").map { Int($0)! }
    let term = termMap[privacy[1]]!
    day[1] += term
    while day[1] > 12 {
      day[0] += 1
      day[1] -= 12
    }

    let comparePrivacy = dateFormatter.date(from: "\(day[0]).\(day[1]).\(day[2])") ?? Date()
    if comparePrivacy <= compareToday {
      result.append(index + 1)
    }
  }

  return result
}

print(solution("2022.05.19", ["A 6", "B 12", "C 3"], ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]))

// MARK: - 2
func solution(_ cap:Int, _ n:Int, _ deliveries:[Int], _ pickups:[Int]) -> Int64 {
  var result: Int64 = 0
  let deliveries = deliveries.reversed()
  var beforeDeliverCount = 0
  var beforePickCount = 0

  func drive(main: Int, before: Int) -> (Int, Int) {
    var drive = 0
    var beforeCount = 0

    if (main - before) > cap {
      let rest = (main - before) % cap
      drive = (main - before)/cap
      switch rest == 0 {
        case true:
          beforeCount = 0

        case false:
          beforeCount = cap - rest
          drive += 1
      }

    } else if (main - before) == cap {
      beforeCount = 0
      drive += 1

    } else {
      beforeCount = cap - (main - before)
      if (main - before) == 0 {
        return(0, 0)
      } else if (main - before) < 0 {
        return(before - main, 0)
      }
      drive += 1
    }

    return(beforeCount, drive)
  }

  deliveries.enumerated().forEach { index, delivery in
    let pickup = pickups[pickups.count - (index + 1)]
    if delivery == 0 && pickup == 0 { return }

    let driveNum = drive(main: delivery, before: beforeDeliverCount)
    let pickupNum = drive(main: pickup, before: beforePickCount)

    if driveNum.1 == pickupNum.1 {
      beforeDeliverCount = driveNum.0
      beforePickCount = pickupNum.0
      result += Int64((n - index) * 2 * pickupNum.1)

    } else if driveNum.1 < pickupNum.1 {
      beforePickCount = pickupNum.0
      beforeDeliverCount = driveNum.0 + cap * (pickupNum.1 - driveNum.1)

      result += Int64((n - index) * 2 * pickupNum.1)

    } else {
      beforeDeliverCount = driveNum.0
      beforePickCount = pickupNum.0 + cap * (driveNum.1 - pickupNum.1)

      result += Int64((n - index) * 2 * driveNum.1)
    }
  }

  return result
}

print(solution(2, 4, [2, 2, 0, 20], [0, 10, 0, 0]))

//MARK: - 3
func solution(_ users:[[Int]], _ emoticons:[Int]) -> [Int] {
  var result = [0, 0]
  let discountRate = [10, 20, 30, 40]

  func dfs(_ index: Int, now: [(Int, Int)]) {
    if now.count == emoticons.count {
      var subscription = 0
      var money = 0

      users.forEach { user in
        var sum = 0
        for now in now {
          if user[0] <= now.0 {
            sum += now.1 * (100 - now.0)/100
          }
        }

        if sum >= user[1] {
          subscription += 1
        } else {
          money += sum
        }
      }

      if result[0] < subscription {
        result[0] = subscription
        result[1] = money
      } else if result[0] == subscription && result[1] < money {
        result[1] = money
      }
      return
    }

    for i in index..<emoticons.count {
      for j in 0...3 {
        var now = now
        now.append((discountRate[j], emoticons[i]))
        dfs(i + 1, now: now)
      }
    }
  }

  dfs(0, now: [])
  return result
}
print(solution( [[40, 10000], [25, 10000]], [7000, 9000]))

//MARK: - 4
func solution(_ numbers:[Int64]) -> [Int] {
  func detectBinaryTree(str: String, isZero: Bool) -> Bool {
    var isZero = isZero
    if str.count % 2 == 0 { return false }
    let str = Array(str)
    let mid = str.count / 2
    
    if isZero && str[mid] == "1" { return false }
    
    if str.count == 1 { return true }
    else if str[mid] == "0" { isZero = true }
    
    let left = detectBinaryTree(str: String(str[0..<mid]), isZero: isZero)
    let right = detectBinaryTree(str: String(str[(mid + 1)..<str.count]), isZero: isZero)
    
    return left && right
  }
  
  let numbers = numbers.map { number -> Int in
    let str = String(number, radix: 2)
    
    switch str.count % 2 {
      case 0:
        return detectBinaryTree(str: "0\(str)", isZero: false) ? 1 : 0
        
      default:
        return detectBinaryTree(str: str, isZero: false) ? 1 : 0
    }
  }

  return numbers
}

//print(solution([95, 56]))
//print(solution([63, 111, 95, 2]))

//MARK: - 5
func solution(_ commands:[String]) -> [String] {
    return []
}

//MARK: - 6
func solution(_ n:Int, _ m:Int, _ x:Int, _ y:Int, _ r:Int, _ c:Int, _ k:Int) -> String {
  var board = Array(repeating: Array(repeating: [Int: String](), count: m + 1), count: n + 1)
  let dx = [1, 0, 0, -1], dy = [0, -1, 1, 0]
  let map = ["d", "l", "r", "u"]
  var result: String?
  
  let xDistance = abs(x - r)
  let yDistance = abs(y - c)
  if xDistance + yDistance > k { return "impossible" }
  
  if k > 1000 {
    if k % (xDistance + yDistance + 1) == 0 { return "impossible" }
  }
  func dfs(x: Int, y: Int, str: String, count: Int) {
    if result != nil { return }
    else if count == k {
      if x == r && y == c { result = str }
      return
    } else if let exist = board[x][y][count] {
      if exist > str {
        board[x][y][count] = str
      } else { return }
    } else {
      board[x][y][count] = str
    }

    for i in 0...3 {
      let xx = x + dx[i], yy = y + dy[i]
      if xx < 1 || xx > n || yy < 1 || yy > m { continue }
      dfs(x: xx, y: yy, str: "\(str)\(map[i])", count: count + 1)
    }
  }

  dfs(x: x, y: y, str: "", count: 0)
  return result ?? "impossible"
}

print(solution(3, 3, 1, 2, 3, 3, 4))
