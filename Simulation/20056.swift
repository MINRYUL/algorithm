//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func main() {
    let nmk = readLine()!.split(separator: " ")
    let N = Int(nmk[0])!, M = Int(nmk[1])!, K = Int(nmk[2])!
    let dx = [0, 1, 1, 1, 0, -1, -1, -1], dy = [-1, -1, 0, 1, 1, 1, 0, -1]
    let di = [[0, 2, 4, 6], [1, 3, 5, 7]]
    
    var board = Array(repeating: Array(repeating: [(Int, Int, Int)](), count: N + 1), count: N + 1)
    
    for _ in 0..<M {
        let rcmsd = readLine()!.split(separator: " ")
        let r = Int(rcmsd[0])!, c = Int(rcmsd[1])!, m = Int(rcmsd[2])!, s = Int(rcmsd[3])!, d = Int(rcmsd[4])!
        board[r][c].append((m, s, d))
    }
    
    for _ in 0..<K {
        var tempBoard = Array(repeating: Array(repeating: [(Int, Int, Int)](), count: N + 1), count: N + 1)
        for i in 1...N {
            for j in 1...N {
                if !board[i][j].isEmpty {
                    for magic in board[i][j] {
                        var x = j
                        var y = i
                        for _ in 0..<magic.1 {
                            x += dx[magic.2]
                            y += dy[magic.2]
                            if x < 1 { x = N }
                            else if x > N { x = 1 }
                            if y < 1 { y = N }
                            else if y > N { y = 1 }
                        }
                        tempBoard[y][x].append((magic.0, magic.1, magic.2))
                    }
                }
            }
        }
        
        for i in 1...N {
            for j in 1...N {
                if tempBoard[i][j].count > 1 {
                    let check = tempBoard[i][j][0].2 % 2
                    var direction = true
                    var mass = 0, speed = 0
                    for magic in tempBoard[i][j] {
                        if check != (magic.2 % 2) {
                            direction = false
                        }
                        mass += magic.0
                        speed += magic.1
                    }
                    if mass/5 == 0 {
                        tempBoard[i][j].removeAll()
                        continue
                    } else {
                        mass /= 5
                        speed /= tempBoard[i][j].count
                    }
                    
                    tempBoard[i][j].removeAll()
                    if direction {
                        for d in di[0] {
                            tempBoard[i][j].append((mass, speed, d))
                        }
                    } else {
                        for d in di[1] {
                            tempBoard[i][j].append((mass, speed, d))
                        }
                    }
                }
            }
        }
        board = tempBoard
    }
    
    var massSum = 0
    for i in 1...N {
        for j in 1...N {
            if !board[i][j].isEmpty {
                for magic in board[i][j] {
                    massSum += magic.0
                }
            }
        }
    }
    
    print(massSum)
}

main()
