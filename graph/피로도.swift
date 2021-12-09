//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var visited = Array(repeating: false, count: dungeons.count)
    var answer = 0
    
    func dfs(_ fatigue: Int, _ count: Int) {
        if count > answer { answer = count }
        
        for (index, value) in dungeons.enumerated() {
            if fatigue >= value[0] && !visited[index]{
                var tempFatigue = fatigue
                visited[index] = true
                tempFatigue -= value[1]
                dfs(tempFatigue, count + 1)
                visited[index] = false
            }
        }
    }
    
    dfs(k, 0)
    
    return answer
}


print(solution(80, [[80, 20], [50, 40], [30, 10]]))
