//
//  main.swift
//  SwiftPS
//
//  Created by 김민창 on 2022/06/14.
//

import Foundation

//[type, r1, c1, r2, c2, degree]

func solution(_ board:[[Int]], _ skill:[[Int]]) -> Int {
    let columnNum = board.count
    let rowNum = board[0].count
    var board = board
    var cumulativeBoard = Array(repeating: Array(repeating: 0, count: rowNum + 1), count: columnNum + 1)

    skill.forEach {
        var degree = $0[5]
        if $0[0] == 1 { degree = -degree }
        cumulativeBoard[$0[1]][$0[2]] += degree
        cumulativeBoard[$0[1]][$0[4] + 1] += -degree
        cumulativeBoard[$0[3] + 1][$0[2]] += -degree
        cumulativeBoard[$0[3] + 1][$0[4] + 1] += degree
    }
    
    for i in 0..<columnNum {
        for j in 0..<rowNum {
            cumulativeBoard[i][j + 1] += cumulativeBoard[i][j]
        }
    }
    
    for j in 0..<rowNum {
        for i in 0..<columnNum {
            cumulativeBoard[i + 1][j] += cumulativeBoard[i][j]
        }
    }
    
    var result = 0
    for i in 0..<columnNum {
        for j in 0..<rowNum {
            board[i][j] += cumulativeBoard[i][j]
            if board[i][j] > 0 { result += 1 }
        }
    }
    
    return result
}


print(solution([[1, 2, 3], [4, 5, 6], [7, 8, 9]], [[1, 1, 1, 2, 2, 4], [1, 0, 0, 1, 1, 2], [2, 2, 0, 2, 0, 100]]))
