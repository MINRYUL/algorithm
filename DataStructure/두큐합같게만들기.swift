//
//  main.swift
//  SwiftPS
//
//  Created by 김민창 on 2022/06/14.
//

import Foundation

func solution(_ queue1:[Int], _ queue2:[Int]) -> Int {
    let result = compareQueue(queue1: queue1, queue2: queue2)
    return result
}

func compareQueue(
    queue1: [Int], queue2: [Int]
) -> Int {
    var queue1 = queue1.map { UInt($0) }, queue2 = queue2.map { UInt($0) }
    var queue1Sum: UInt = UInt(queue1.reduce(0) { $0 + $1 })
    var queue2Sum: UInt = UInt(queue2.reduce(0) { $0 + $1 })
    
    let maxCount = queue1.count * 3
    var queue1Index = 0, queue2Index = 0
    var result = 0

    while queue1Sum != queue2Sum {
        if queue1Index >= queue1.count || queue2Index >= queue2.count || result > maxCount {
            return -1
        }
        
        switch queue1Sum < queue2Sum {
        case true:
            queue2Sum -= queue2[queue2Index]
            queue1Sum += queue2[queue2Index]
            queue1.append(queue2[queue2Index])
            queue2Index += 1
        case false:
            queue2Sum += queue1[queue1Index]
            queue1Sum -= queue1[queue1Index]
            queue2.append(queue1[queue1Index])
            queue1Index += 1
        }
        
        result += 1
    }
    
    return result
}


print(solution([1, 1, 1, 1, 1, 1, 1, 1, 1, 10], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]))

//arr1 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 10 }
//arr2 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
