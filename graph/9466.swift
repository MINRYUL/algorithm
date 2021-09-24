//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func dfs(_ node: Int, _ graph: inout [Int], _ visited: inout [Bool], _ team: inout [Int]) -> Int{
    if !visited[graph[node]] {
        visited[graph[node]] = true
        team.append(graph[node])
        return dfs(graph[node], &graph, &visited, &team)
    } else {
        for i in 0..<team.count {
            if team[i] == graph[node] {
                return team.count - i
            }
        }
        return 0
    }
}

func main() {
    let testNum = readLine()!

    for _ in 0..<Int(testNum)! {
        let peopleNum = readLine()!
        var people = [0] + readLine()!.split(separator: " ").map{
            Int(String($0))!
        }
        var result = Int(peopleNum)!
        var visited: [Bool] = [false] + Array(repeating: false, count: Int(peopleNum)!)
        for i in 1...Int(peopleNum)! {
            if visited[i] { continue }
            visited[i] = true
            var team = [Int]()
            team.append(i)
            result -= dfs(i, &people, &visited, &team)
        }
        
        print(result)
    }
}

main()
