//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

var answer = 0
var count = 0
var nm: [Int]!
var negative = [Int]()
var positive = [Int]()

func main() {
    nm = readLine()!.split(separator: " ").map { Int($0)! }
    let bookLocation = readLine()!.split(separator: " ").map { Int($0)! }
    
    for location in bookLocation {
        if location < 0 {
            negative.append(location)
        } else {
            positive.append(location)
        }
    }
    
    negative.sort(by: { $0 < $1 })
    positive.sort(by: { $0 > $1 })
    
    if positive.isEmpty {
        negativeFunc(before: false)
    } else if negative.isEmpty {
        positiveFunc(before: false)
    } else {
        if (-negative[0]) < positive[0] {
            negativeFunc(before: true)
            positiveFunc(before: false)
        } else {
            positiveFunc(before: true)
            negativeFunc(before: false)
        }
    }
    
    print(answer)
}

func negativeFunc(before: Bool) {
    var check = false
    while !negative.isEmpty {
        var distance = 0
        for _ in 0..<nm[1] {
            if negative.isEmpty { break }
            count += 1
            let num = negative.removeFirst()
            if distance > num { distance = num }
        }
    
        if (count == nm[0] && before) || (!before && !check)  { answer += (-distance) }
        else { answer += ((-distance) * 2) }
        check = true
    }
}

func positiveFunc(before: Bool) {
    var check = false
    while !positive.isEmpty {
        var distance = positive[0]
        for _ in 0..<nm[1] {
            if positive.isEmpty { break }
            count += 1
            let num = positive.removeFirst()
            if distance < num { distance = num }
        }
        
        if (count == nm[0] && before) || (!before && !check) { answer += distance }
        else { answer += (distance * 2) }
        check = true
    }
}

main()
