//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ n:Int, _ wires:[[Int]]) -> Int {
    var answer = Int.max
    
    for wire in wires {
        var graph = Array(repeating: [Int](), count: n + 1)
        for temp in wires {
            if temp == wire { continue }
            graph[temp[0]].append(temp[1])
            graph[temp[1]].append(temp[0])
        }
        
        var visited = Array(repeating: false, count: n + 1)
        var first = -1, second = -1
        for i in 1...n {
            if visited[i] { continue }
            var queue = [i]
            var result = 1
            visited[i] = true
            while !queue.isEmpty {
                let q = queue.removeFirst()
                for j in graph[q] {
                    if !visited[j] {
                        queue.append(j)
                        result += 1
                        visited[j] = true
                    }
                }
            }
            if first < 0 { first = result }
            else { second = result }
        }
        
        if abs(first - second) < answer {
            answer = abs(first - second)
        }
    }

    return answer
}

print(solution(9, [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]))
