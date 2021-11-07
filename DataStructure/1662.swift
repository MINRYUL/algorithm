//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func main() {
    let s = readLine()!.map { $0 }
    var parenthesis = [Character]()
    var stack = [Character]()
    var parenthesisCheck = false
    var depthNum = Array(repeating: 0, count: 100)
    var depth = 0
    
    for char in s {
        if char == "(" {
            parenthesisCheck = true
            parenthesis.append(stack.removeLast())
            depthNum[depth] += stack.count
            depth += 1
            stack.removeAll()
        } else if char == ")" {
            depth -= 1
            let result = parenthesis.last!.wholeNumberValue! * (stack.count + depthNum[depth + 1]) + depthNum[depth]
            depthNum[depth + 1] = 0
            depthNum[depth] = result
            parenthesis.removeLast()
            stack.removeAll()
        } else {
            stack.append(char)
        }
    }
    
    if !stack.isEmpty {
        depthNum[0] += stack.count
    }
    
    if parenthesisCheck {
        print(depthNum[0])
    } else {
        print(stack.count)
    }
    
}

main()
