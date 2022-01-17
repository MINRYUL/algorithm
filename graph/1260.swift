//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func main() {
    let nmv = readLine()!.split(separator: " ").map { Int($0)! }
    var graph = Array(repeating: [Int](), count: 1001)
    
    for _ in 0..<nmv[1] {
        let line = readLine()!.split(separator: " ").map { Int($0)! }
        graph[line[0]].append(line[1])
        graph[line[1]].append(line[0])
    }
    
    for i in 1...nmv[0] { graph[i].sort() }
    var visited = Array(repeating: false, count: 1001)
    
    func dfs(node: Int) {
        print(node, terminator: " ")
        
        for i in graph[node] {
            if !visited[i] {
                visited[i] = true
                dfs(node: i)
            }
        }
    }
    visited[nmv[2]] = true
    dfs(node: nmv[2])
    
    visited = Array(repeating: false, count: 1001)
    print()
    
    visited[nmv[2]] = true
    var queue = [Int]()
    queue.append(nmv[2])
    while !queue.isEmpty {
        let node = queue.removeFirst()
        print(node, terminator: " ")
        
        for i in graph[node] {
            if !visited[i] {
                visited[i] = true
                queue.append(i)
            }
        }
    }
}

main()
