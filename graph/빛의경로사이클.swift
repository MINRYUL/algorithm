//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

let dx = [0, -1, 0, 1], dy = [-1, 0, 1, 0]
let l = [3, 0, 1, 2], r = [1, 2, 3, 0]
var maxX = 0, maxY = 0
var visited = [[[Bool]]]()

// 왼: 0, 위: 1, 오른: 2, 아래: 3

func solution(_ grid: [String]) -> [Int] {
    maxX = grid.count
    maxY = grid[0].count
    var answer = [Int]()
    var changeGrid = [[String.Element]]()
    visited = Array(repeating: Array(repeating: Array(repeating: false, count: 4), count: maxY), count: maxX)
    
    for i in 0..<maxX {
        let g = grid[i].map { $0 }
        changeGrid.append(g)
    }
    
    for i in 0..<maxX {
        for j in 0..<maxY {
            var result = bfs(2, changeGrid, i, j)
            if result > 0 { answer.append(result)}
            result = bfs(3, changeGrid, i, j)
            if result > 0 { answer.append(result) }
            result = bfs(0, changeGrid, i, j)
            if result > 0 { answer.append(result) }
            result = bfs(1, changeGrid, i, j)
            if result > 0 { answer.append(result) }
        }
    }
    
    return answer.sorted()
}

func bfs(_ d: Int, _ grid:[[String.Element]], _ startX: Int, _ startY: Int) -> Int {
    var result = 0
    var startDirection = d
    var q = [(Int, Int, Int)]()
    q.append((startX, startY, d))
    
    while !q.isEmpty {
        let node = q.removeFirst()
        var direction = node.2
        var nextNode = (0, 0)

        if grid[node.0][node.1] == "S" {
            let xx = node.0 + dx[node.2], yy = node.1 + dy[node.2]
            nextNode = converter(xx, yy)
        } else if grid[node.0][node.1] == "L" {
            direction = l[node.2]
            let xx = node.0 + dx[direction], yy = node.1 + dy[direction]
            nextNode = converter(xx, yy)
        } else {
            direction = r[node.2]
            let xx = node.0 + dx[direction], yy = node.1 + dy[direction]
            nextNode = converter(xx, yy)
        }
        
        if result == 0 { startDirection = direction }
        
        if visited[node.0][node.1][direction] {
            if node.0 == startX && node.1 == startY && direction == startDirection {
                return result
            }
            return 0
        }
        visited[node.0][node.1][direction] = true
        q.append((nextNode.0, nextNode.1, direction))
        result += 1
    }
    
    return 0
}

func converter(_ xx: Int, _ yy: Int) -> (Int, Int) {
    var position = (xx, yy)
    if xx < 0 { position.0 = maxX - 1 }
    else if xx >= maxX { position.0 = 0 }
    
    if yy < 0 { position.1 = maxY - 1 }
    else if yy >= maxY { position.1 = 0 }
    
    return position
}

print(solution(["R","R"]))
