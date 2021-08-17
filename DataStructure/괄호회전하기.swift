//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func correctParentheses(_ parentheses: String) -> Bool {
    var str = parentheses
    var stack = ""
    stack.append(str.first!)
    str.removeFirst()
    
    while !str.isEmpty {
        var last = ""
        if !stack.isEmpty {
            last.append(stack.last!)
        }
        let add = str.first
        str.removeFirst()
        
        if add == "}" {
            if last.isEmpty { return false }
            if last == "{" { stack.removeLast() }
            else { return false }
        } else if add == ")" {
            if last.isEmpty { return false }
            if last == "(" {  stack.removeLast() }
            else { return false }
        } else if add == "]" {
            if last.isEmpty { return false }
            if last == "[" {  stack.removeLast() }
            else { return false }
        } else {
            stack.append(add!)
        }
    }
    
    if stack.isEmpty { return true }
    return false
}

func solution(_ s:String) -> Int {
    var answer = 0;
    if correctParentheses(s) { answer += 1 }
    
    var str = s
    
    for _ in 0..<(s.count - 1) {
        str.append(str.first!)
        str.removeFirst()
        if correctParentheses(str) { answer += 1 }
    }
    
    return answer
}

