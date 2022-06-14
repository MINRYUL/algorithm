//
//  main.swift
//  SwiftPS
//
//  Created by 김민창 on 2022/06/14.
//

import Foundation

func solution(_ n:Int, _ info:[Int]) -> [Int] {
    var scoreDiff = 1
    var scoreInfo = Array(repeating: 0, count: 11)
    var result: [Int] = [-1]

    func compareScore(lhs: [Int], rhs: [Int]) -> Bool {
        for i in 0...10 {
            if rhs[i] > lhs[i] { return true }
            else if rhs[i] < lhs[i] { return false }
        }
        return false
    }
    
    func dfs(index: Int, arrow: Int) {
        if arrow == 0 || index > n {
            if arrow > 0 { scoreInfo[10] = arrow }
            var tempScore = 0
            scoreInfo.enumerated().forEach { i, s in
                if s > info[i] { tempScore += (10 - i) }
                else if s <= info[i] && info[i] > 0 { tempScore -= (10 - i) }
            }
            if tempScore > scoreDiff ||
                (tempScore == scoreDiff && compareScore(lhs: result.reversed(), rhs: scoreInfo.reversed())) {
                scoreDiff = tempScore
                result = scoreInfo
            }
            scoreInfo[10] = 0
            return
        }

        if info[index] < arrow {
            scoreInfo[index] = info[index] + 1
            dfs(index: index + 1, arrow: arrow - (info[index] + 1))
            scoreInfo[index] = 0
        }
        dfs(index: index + 1, arrow: arrow)
    }

    dfs(index: 0, arrow: n)
    return result
}

solution(5, [2,1,1,1,0,0,0,0,0,0,0])
