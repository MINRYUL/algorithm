//
//  main.swift
//  SwiftPS
//
//  Created by 김민창 on 2022/06/14.
//

import Foundation

func solution(_ n: Int) -> Int {
    switch n {
    case 1...3: return n
        
    default:
        var dp = Array(repeating: 0, count: n + 1)
        dp[1] = 1 % 1234567
        dp[2] = 2 % 1234567
        
        for i in 3...n {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567
        }
        
        return dp[n]
    }
}

print(solution(3))
