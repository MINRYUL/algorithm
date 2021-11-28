//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

let n = Int(readLine()!)!
let opcode = ["+", "-", " "]
var answer = [String]()

func findZero(str: String) -> Bool {
    let splitSpace = str.split(separator: " ")
    let stringSum = splitSpace.reduce("") { $0 + $1 }
    
    var opcode = ""
    var before = -1
    var after = ""
    
    for c in stringSum {
        if c == "+" || c == "-" {
            if opcode == "" {
                before = Int(after)!
            } else {
                if opcode == "-" {
                    before = before - Int(after)!
                } else {
                    before = before + Int(after)!
                }
            }
            after = ""
            opcode = String(c)
        } else {
            after = after + "\(c)"
        }
    }
    
    if opcode == "-" {
        before = before - Int(after)!
    } else {
        before = before + Int(after)!
    }
    
    if before == 0 {
        return true
    }
    return false
}

func bfs(str: String, index: Int, end: Int) {
    if str.count == (end + end - 1) {
        if findZero(str: str) {
            answer.append(str)
        }
        return
    }
    
    bfs(str: str + "+\(index)", index: index + 1, end: end)
    bfs(str: str + "-\(index)", index: index + 1, end: end)
    bfs(str: str + " \(index)", index: index + 1, end: end)
}

func main() {
    for _ in 0..<n {
        let x = Int(readLine()!)!
        bfs(str: "\(1)", index: 2, end: x)
        
        for str in answer.sorted() {
            print(str)
        }
        answer.removeAll()
        print("")
    }
}

main()
