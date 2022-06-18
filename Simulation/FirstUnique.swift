//
//  main.swift
//  SwiftPS
//
//  Created by 김민창 on 2022/06/14.
//

import Foundation

public func solution(_ a : inout [Int]) -> Int {
    var map: [Int: Int] = [:]
    a.enumerated().forEach { index, item in
        if let exist = map[item] {
            map[item] = exist + 1
        } else {
            map[item] = 1
        }
    }

    var removeItem: [Int] = []
    map.forEach {
        if $0.value != 1 {
            removeItem.append($0.key)
        }
    }

    removeItem.forEach {
        map[$0] = nil
    }

    for item in a {
        if let _ = map[item] {
            return item
        }
    }

    return -1
}
