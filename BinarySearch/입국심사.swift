//
//  main.swift
//  SwiftPS
//
//  Created by 김민창 on 2022/06/14.
//

import Foundation

func solution(_ n:Int, _ times:[Int]) -> Int64 {
    let times = times.sorted()
    
    var l = 1, r = times.last! * n
    var answer: Int64 = 0
    
    while l <= r {
        let mid = (l + r) / 2
        let sum = times.map { mid/$0 }.reduce(0) { $0 + $1 }
        if sum < n {
            l = mid + 1
        } else {
            r = mid - 1
            answer = Int64(mid)
        }
    }
    
    return answer
}
