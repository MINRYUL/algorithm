//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func main() {
    let nq = readLine()!.split(separator: " ").map { Int($0)! }
    let n = readLine()!.split(separator: " ").map { Int($0)! }
    
    for _ in 0..<nq[1] {
        let xy = readLine()!.split(separator: " ").map { Int($0)! }
        
        var l = xy[1] - 1, r = nq[0] - 1
        
        while l <= r {
            let mid = (l + r)/2
            if xy[0] <= n[mid] { l = mid + 1 }
            else { r = mid - 1 }
        }
        
        let answer = r - xy[1] + 2
        
        if answer == 0 { print(0) }
        else {
            if n[xy[1] - 1] < xy[0] {
                print(answer)
            } else {
                print(answer + n[xy[1] - 1] - xy[0])
            }
        }
    }
}

main()
