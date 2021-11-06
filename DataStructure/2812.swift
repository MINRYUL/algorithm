//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func main() {
    let nk = readLine()!.split(separator: " ").map { Int($0)! }
    let array = readLine()!.map { $0 }
    var stack = [Character]()
    var removeNum = 0

    for i in 0..<array.count {
        while !stack.isEmpty {
            let x = stack.last!

            if array[i] <= x {
                stack.append(array[i])
                break
            }
            else {
                removeNum += 1
                stack.removeLast()
                if removeNum == nk[1] { break }
            }
        }
        if removeNum == nk[1] {
            for j in i..<array.count {
                stack.append(array[j])
            }
            break
        }

        if stack.isEmpty { stack.append(array[i]) }
    }
    
    while removeNum < nk[1] {
        stack.removeLast()
        removeNum += 1
    }
    print(String(stack))
}

main()
