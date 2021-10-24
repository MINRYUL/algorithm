//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func main() {
    let nm = readLine()!.split(separator: " ").map { Int64($0)! }
    var array = [Int64]()
    
    for _ in 0..<nm[0] {
        let x = Int64(readLine()!)!
        array.append(x)
    }
    
    array.sort()
    
    var r: Int64 = array.last! * nm[1]
    var l: Int64 = 1
    var answer = r
    
    while l <= r {
        let mid: Int64 = (l + r)/2
        var sum: Int64 = 0
        
        array.forEach { sum += (mid/$0); }
        
        if sum >= nm[1] {
            answer = min(answer, mid)
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    
    print(answer)
}

main()
