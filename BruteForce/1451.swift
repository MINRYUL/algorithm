//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

let nm = readLine()!.split(separator: " ").map { Int($0)! }
var square = Array(repeating: [Int](), count: nm[0])

for i in 0..<nm[0] {
    let array = readLine()!.map { $0.wholeNumberValue! }
    square[i] = array
}

func sum(_ x: Int, _ y: Int, _ xx: Int, _ yy: Int) -> Int64 {
    var result = Int64()
    
    for i in y...yy {
        for j in x...xx {
            result += Int64(square[i][j])
        }
    }
    return result
}

func main() {
    var answer: Int64 = 0
    
    if 0 < nm[1] - 1 {
        for i in 0..<(nm[1] - 2) {
            for j in (i + 1)..<(nm[1] - 1) {
                let value = (sum(0, 0, i, nm[0] - 1) *
                             sum(i + 1, 0, j, nm[0] - 1) *
                             sum(j + 1, 0, nm[1] - 1, nm[0] - 1))
                
                if answer < value { answer = value }
            }
        }
    }
    
    if 0 < nm[0] - 2 {
        for i in 0..<(nm[0] - 2) {
            for j in (i + 1)..<(nm[0] - 1) {
                let value = (sum(0, 0, nm[1] - 1, i) *
                             sum(0, i + 1, nm[1] - 1, j) *
                             sum(0, j + 1, nm[1] - 1, nm[0] - 1))
                
                if answer < value { answer = value }
            }
        }
    }
    
    for i in 0..<(nm[1] - 1) {
        for j in 0..<(nm[0] - 1) {
            let value = (sum(0, 0, i, nm[0] - 1) *
                         sum(i + 1, 0, nm[1] - 1, j) *
                         sum(i + 1, j + 1, nm[1] - 1, nm[0] - 1))
            
            if answer < value { answer = value }
        }
    }
    
    for i in stride(from: nm[1] - 1, to: 0, by: -1) {
        for j in 0..<(nm[0] - 1) {
            let value = (sum(i, 0, nm[1] - 1, nm[0] - 1) *
                         sum(0, 0, i - 1, j) *
                         sum(0, j + 1, i - 1, nm[0] - 1))
            
            if answer < value { answer = value }
        }
    }
    
    for i in 0..<(nm[0] - 1) {
        for j in 0..<(nm[1] - 1) {
            let value = (sum(0, 0, nm[1] - 1, i) *
                         sum(0, i + 1, j, nm[0] - 1) *
                         sum(j + 1, i + 1, nm[1] - 1, nm[0] - 1))
            
            if answer < value { answer = value }
        }
    }
    
    for i in stride(from: nm[0] - 1, to: 0, by: -1) {
        for j in 0..<(nm[1] - 1) {
            let value = (sum(0, i, nm[1] - 1, nm[0] - 1) *
                         sum(0, 0, j, i - 1) *
                         sum(j + 1, 0, nm[1] - 1, i - 1))
            
            if answer < value { answer = value }
        }
    }
    
    print(answer)
}

main()
