//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation


func solution(_ places:[[String]]) -> [Int] {
    let dx = [-1, 0, 1, 0], dy = [0, -1, 0, 1]
    var result = [Int]()
    
    places.forEach{
        var visited = Array(repeating: Array(repeating: false, count: 5), count: 5)
        var keepDistance = true
        for i in 0..<$0.count {
            for j in 0..<$0[i].count {
                if $0[i][j] == "P" {
                    var q = [(Int, Int, Int)]()
                    
                    q.append((i, j ,0));
                    visited[i][j] = true
                    
                    while !q.isEmpty {
                        let before = q.removeFirst()
                        if before.2 >= 2 {
                            continue
                        }
                        for i in 0..<4 {
                            let xx = before.0 + dx[i]
                            let yy = before.1 + dy[i]
                            if 0...4 ~= xx && 0...4 ~= yy {
                                if $0[xx][yy] == "X" || visited[xx][yy] {
                                    continue
                                }
                                if $0[xx][yy] == "P" {
                                    keepDistance = false
                                    q.removeAll()
                                    break
                                }
                                
                                q.append((xx, yy, before.2 + 1))
                            }
                        }
                    }
                    if !keepDistance {
                        break
                    }
                }
                if !keepDistance {
                    break
                }
            }
            if !keepDistance {
                break
            }
        }
        if keepDistance {
            result.append(1)
        } else {
            result.append(0)
        }
    }
    
    return result
}

extension String {
    subscript(_ index: Int) -> Character {
        return self[self.index(self.startIndex, offsetBy: index)]
    }
}


print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))
