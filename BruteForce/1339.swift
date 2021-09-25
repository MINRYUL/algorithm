//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation
var answer = 0
var strArray = [Array<Character>]()
var alphabet = Array<Character>()
var mapArray = Array(repeating: 0, count: 30)
var allocation = Array(repeating: 0, count: 30)

func calculator() {
    for i in 0..<strArray.count {
        var str = ""
        for j in 0..<strArray[i].count {
            str.append("\(allocation[Int(strArray[i][j].asciiValue! - 65)])")
        }
        answer += Int(str)!
    }
}

func main() {
    let count = Int(readLine()!)!
    var num = 9
    
    for _ in 0..<count {
        strArray.append(Array(readLine()!))
        var alias = 1
        for i in strArray.last!.reversed() {
            mapArray[Int(i.asciiValue! - 65)] += alias
            alias *= 10
        }
    }
    while true {
        var index = 0
        var max = 0
        
        for i in 0..<mapArray.count {
            if mapArray[i] > max {
                max = mapArray[i]
                index = i
            }
        }
        
        if max == 0 { break }
        
        allocation[index] = num
        mapArray[index] = 0
        num -= 1
    }
    calculator()
    print(answer)
}

main()
