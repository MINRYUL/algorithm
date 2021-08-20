//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

let str = readLine()!.split(separator: " ")
let n = Int(str[0])!
let m = Int(str[1])!
let x = Int(str[3])!
let y = Int(str[2])!
let k = Int(str[4])!
let dx = [1, -1, 0, 0], dy = [0, 0, -1, 1]

var dice = Array(repeating: 0, count: 6)
var map = Array(repeating: Array(repeating: 0, count: m), count: n)

for i in 0..<n {
    let num = readLine()!.split(separator: " ")
    for j in 0..<m {
        map[i][j] = Int(num[j])!
    }
}

//102345
let switchDice = [[0, 2, 5, 1, 4, 3], [0, 3, 1, 5, 4, 2], [5, 0, 2, 3, 1, 4], [1, 4, 2, 3, 5, 0]]
//우, 좌, 상, 하

let direction = readLine()!.split(separator: " ")
var currentIndex = (x, y)

func moveDice(_ index: Int) {
    let next = (currentIndex.0 + dx[index], currentIndex.1 + dy[index])
    if next.1 >= n || next.0 >= m || next.1 < 0 || next.0 < 0 {
        return
    }
    dice = [dice[switchDice[index][0]],
            dice[switchDice[index][1]],
            dice[switchDice[index][2]],
            dice[switchDice[index][3]],
            dice[switchDice[index][4]],
            dice[switchDice[index][5]]]
    
    if map[next.1][next.0] != 0 {
        dice[1] = map[next.1][next.0]
        map[next.1][next.0] = 0
    } else {
        map[next.1][next.0] = dice[1]
    }
    currentIndex = next
    print("\(dice[5])")
}

for d in direction {
    moveDice(Int(d)! - 1)
}
