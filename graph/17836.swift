//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func main() {
    let nmt = readLine()!.split(separator: " ").map { Int($0)! }
    let dx = [-1, 0, 1, 0], dy = [0, -1, 0, 1]
    var graph = Array(repeating: Array(repeating: 0, count: nmt[1]), count: nmt[0])
    var visited = Array(repeating: Array(repeating: Array(repeating: false, count: nmt[1]), count: nmt[0]), count: 2)
    var sword = false
    
    for i in 0..<nmt[0] {
        let line = readLine()!.split(separator: " ").map { Int($0)! }
        for j in 0..<nmt[1] {
            graph[i][j] = line[j]
        }
    }
    
    var queue = [(Int, Int, Int, Int)]() //세로 가로 시간 명검
    visited[0][0][0] = true
    queue.append((0, 0, 0, 0))
    
    while !queue.isEmpty {
        let q = queue.removeFirst()
        
        for i in 0..<4 {
            let x = q.0 + dx[i]
            let y = q.1 + dy[i]
            if x < 0 || y < 0 || x >= nmt[0] || y >= nmt[1] { continue }
            if visited[q.3][x][y] { continue }
            if q.2 >= nmt[2] { continue }
            if x == nmt[0] - 1 && y == nmt[1] - 1 {
                print(q.2 + 1)
                return
            }
            
            if !sword && graph[x][y] == 2 {
                queue.append((x, y, q.2 + 1, 1))
                sword = true
                visited[1][x][y] = true
            } else if graph[x][y] == 1 && q.3 == 1 {
                queue.append((x, y, q.2 + 1, q.3))
                visited[q.3][x][y] = true
            } else if graph[x][y] == 0 {
                queue.append((x, y, q.2 + 1, q.3))
                visited[q.3][x][y] = true
            }
        }
    }
    
    print("Fail")
}

main()
