//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ n:Int, _ left:Int64, _ right:Int64) -> [Int] {
    var leftCheck = false
    var result = [Int]()
    let l = left + 1
    let r = right + 1
    
    func appendResult(min: Int, max: Int, i: Int) {
        for j in min...max {
            let startL = j - i
            if startL <= 0 {
                result.append(i)
                continue
            }
            result.append(j)
        }
    }
    
    for i in 1...n {
        if n * (i - 1) < r && n * i >= r {
            var min = 1
            if n * (i - 1) < l && n * i >= l{
                min = Int(l - Int64(n * (i - 1)))
            }
            
            let max = Int(r - Int64(n * (i - 1)))
            appendResult(min: min, max: max, i: i)
            return result
        }
        
        if leftCheck {
            appendResult(min: 1, max: n, i: i)
            continue
        }
        
        if n * (i - 1) < l && n * i >= l{
            leftCheck = true
            let min = Int(l - Int64(n * (i - 1)))
            
            appendResult(min: min, max: n, i: i)
        }
    }
    
    return []
}


print(solution(3, 2, 5))
