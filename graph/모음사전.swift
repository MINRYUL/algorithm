//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ word:String) -> Int {
    let words = ["A", "E", "I", "O", "U"]
    var sequence = [String]()
    
    func dfs(_ str: String) {
        if str.count > 5 { return }
        if !str.isEmpty { sequence.append(str) }
        
        for i in 0..<5 {
            var s = str
            s.append(words[i])
            dfs(s)
        }
    }
    
    dfs("")
    
    sequence.sort()
    
    for (index, value) in sequence.enumerated() {
        if value == word {
            return (index + 1)
        }
    }
    
    return 0
}

print(solution("AAAAE"))
