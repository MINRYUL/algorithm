//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ lines:[String]) -> Int {
    var result = 0
    var splitLines = [Int]()
    var requestTime = [Int]()
    
    for line in lines {
        var enterLine = line.split(separator: " ")
        let splitLine = enterLine[1].split(separator: ":")
        enterLine[2].removeLast()
        let time = Int(Double(enterLine[2])! * 1000)
        
        splitLines.append((Int(splitLine[0])! * 60 * 60 + Int(splitLine[1])! * 60) * 1000 + Int(Double(splitLine[2])! * 1000))
        requestTime.append(time)
    }
    
    for i in 0..<splitLines.count {
        var tempResult = 1
        let time = splitLines[i]
        for j in 0..<splitLines.count {
            if i == j { continue }
            let startTime = splitLines[j] - requestTime[j] + 1
            let endTime = splitLines[j]
            
            if time <= startTime && time + 999 >= startTime {
                tempResult += 1
            } else if time > startTime && endTime >= time {
                tempResult += 1
            }
        }
        if tempResult > result { result = tempResult }
    }
    
    return result
}


solution(["2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"])
