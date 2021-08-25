//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ dartResult:String) -> Int {
    var score = 0
    var beforeScore = 0
    var currentScore = 0
    for ch in dartResult {
        switch String(ch){
        case "S":
            continue
        case "D":
            currentScore = currentScore * currentScore
        case "T":
            currentScore = currentScore * currentScore * currentScore
        case "*":
            beforeScore = beforeScore * 2
            currentScore = currentScore * 2
        case "#":
            currentScore = -currentScore
        case "0":
            if currentScore == 1 {
                currentScore = 10
            } else {
                score += beforeScore
                beforeScore = currentScore
                currentScore = 0
            }
        default:
            score += beforeScore
            beforeScore = currentScore
            currentScore = Int(String(ch))!
        }
    }
    score += beforeScore
    score += currentScore
    return score
}
