//
//  main.swift
//  SwiftPS
//
//  Created by 김민창 on 2022/06/14.
//

import Foundation

func isPrime(n: Int) -> Bool {
    if (n <= 1) { return false }
    for i in 2...Int(sqrt(Double(n))) {
        if n % i == 0 { return false }
    }
    return true
}


func solution(_ n:Int, _ k:Int) -> Int {
    return String(n, radix: k)
        .split(separator: "0")
        .filter { return isPrime(n: Int($0)!) }
        .count
}

print(solution(110011, 10))
