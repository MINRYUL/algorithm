//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func rotate(_ key: [[Int]]) -> [[Int]] {
    var rotateKey: [[Int]] = Array(repeating: Array(repeating: 0, count:  key.count), count:  key.count)
    for i in 0..<key.count {
        for j in 0..<key[i].count {
            rotateKey[j][key.count - 1 - i] = key[i][j]
        }
    }
    return rotateKey
}

func checkLockExpansion(_ key: [[Int]], _ lockExpansion: [[Int]], _ x: Int, _ y: Int) -> Int {
    var zeroCount = 0
    for i in 0..<key.count {
        for j in 0..<key[i].count {
            if lockExpansion[i + y][j + x] == 0 && key[i][j] == 1 {
                zeroCount += 1
            } else if lockExpansion[i + y][j + x] == 1 && key[i][j] == 1 {
                return 0
            }
        }
    }
    
    return zeroCount
}

func findEmptyBlock(_ key:[[Int]], _ lock:[[Int]], _ emptyBlockCount: Int) -> Bool {
    var lockExpansion: [[Int]] = Array(repeating: Array(repeating: -1, count: lock.count + key.count * 2 - 2), count:  lock.count + key.count * 2 - 2)
    
    for i in 0..<lock.count {
        for j in 0..<lock[i].count {
            lockExpansion[i + key.count - 1][j + key.count - 1] = lock[i][j]
        }
    }
    
    for i in 0..<(lockExpansion.count - (key.count - 1)) {
        for j in 0..<(lockExpansion[i].count - (key.count - 1)) {
            let result = checkLockExpansion(key, lockExpansion, j, i)
            if result == emptyBlockCount { return true }
        }
    }
    
    return false
}

func solution(_ key:[[Int]], _ lock:[[Int]]) -> Bool {
    var empty = 0
    
    for i in lock {
        for j in i {
            if j == 0 {
                empty += 1
            }
        }
    }
    var result = findEmptyBlock(key, lock, empty)
    if result { return true }
    var rotateKey = key
    for _ in 0...2 {
        rotateKey = rotate(rotateKey)
        result = findEmptyBlock(rotateKey, lock, empty)
        if result { return true }
    }

    return false
}


solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]])
