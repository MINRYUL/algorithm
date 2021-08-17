//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

var input = readLine()!.split{ $0 == " " }
var graph = [[Int]]()
var chickenIndex = [(Int, Int)]()
var homeIndex = [(Int, Int)]()
var answer = 987654321

let n = Int(input[0])!, m = Int(input[1])!

for _ in 0..<n {
    input = readLine()!.split{ $0 == " " }
    var line = [Int]()
    for element in input {
        line.append(Int(element)!)
    }
    graph.append(line)
}

for i in 0..<n {
    for j in 0..<n {
        if graph[i][j] == 2 { chickenIndex.append((i, j)) }
        if graph[i][j] == 1 { homeIndex.append((i, j)) }
    }
}

var backTracking = [Bool](repeating: false, count: chickenIndex.count)

func chickenDistence(_ store: [(Int, Int)]) -> Int {
    var result = [Int]()
    
    homeIndex.forEach{
        var least = 987654321
        for value in store {
            let distance = abs(value.0 - $0.0) + abs(value.1 - $0.1)
            if least > distance { least = distance }
        }
        result.append(least)
    }
    
    return result.reduce(0){ $0 + $1 }
}


func dfs(_ index: Int, _ count: Int) {
    if count == m {
        var i = 0
        let list = chickenIndex.filter{_ in
            if backTracking[i] {
                i += 1
                return true
            }
            i += 1
            return false
        }
        
        let result = chickenDistence(list)
        if answer > result { answer = result }
        return
    }
    
    for i in index..<chickenIndex.count {
        if backTracking[i] { continue }
        backTracking[i] = true
        dfs(i + 1, count + 1)
        backTracking[i] = false
    }
}

dfs(0, 0)

print(answer)
