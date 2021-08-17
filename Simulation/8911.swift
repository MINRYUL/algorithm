//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

let count = readLine()
let dx = [-1, 0, 1, 0], dy = [0, -1, 0, 1]
var up = 0, down = 0, left = 0, right = 0

func changeMaxIndex(_ currnet: (Int, Int)){
    if currnet.0 > up { up = currnet.0 }
    if currnet.0 < down { down = currnet.0 }
    if currnet.1 > right { right = currnet.1 }
    if currnet.1 < left { left = currnet.1 }
}

for _ in 0..<Int(count!)! {
    var move = readLine()
    var currentIndex = (0, 0)
    var direction = 0
    up = 0
    down = 0
    left = 0
    right = 0
    while !move!.isEmpty {
        switch move!.first {
        case "F":
            currentIndex = (currentIndex.0 + dx[direction], currentIndex.1 + dy[direction])
            changeMaxIndex(currentIndex)
        case "B":
            var backDirection = 0
            if direction > 1 { backDirection = direction - 2 }
            else { backDirection = direction + 2 }
            currentIndex = (currentIndex.0 + dx[backDirection], currentIndex.1 + dy[backDirection])
            changeMaxIndex(currentIndex)
        case "L":
            direction += 1
            if direction > 3 { direction = 0}
        case "R":
            direction -= 1
            if direction < 0 { direction = 3}
        default:
            break
        }
        move!.removeFirst()
    }
    print((up + abs(down)) * (right + abs(left)))
}
