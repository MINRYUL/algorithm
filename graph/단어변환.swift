//
//  main.swift
//  SwiftPS
//
//  Created by 김민창 on 2022/06/14.
//

import Foundation

//두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    let max = 987654321
    var result = 987654321
    var visited = Array(repeating: false, count: words.count)
    
    func workCheck(lhs: String, rhs: String) -> Bool {
        let lhs = Array(lhs)
        let rhs = Array(rhs)
        
        return rhs.enumerated().filter { index, item in
            return lhs[index] != rhs[index]
        }.count == 1 ? true : false
    }
    
    func dfs(cnt: String, count: Int) {
        if count >= result { return }
        if cnt == target {
            result = count
            return
        }
        
        for i in 0..<words.count {
            if workCheck(lhs: cnt, rhs: words[i]) && !visited[i] {
                visited[i] = true
                dfs(cnt: words[i], count: count + 1)
                visited[i] = false
            }
        }
    }
    
    dfs(cnt: begin, count: 0)
    
    return result == max ? 0 : result
}

print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))
