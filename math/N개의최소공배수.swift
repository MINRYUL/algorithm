//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ arr:[Int]) -> Int {
    let sortedArr = arr.sorted()
    var increasNum = 1
    
    while true {
        let productNum = sortedArr[0] * increasNum
        var checkNum = true
        
        for i in 1..<sortedArr.count {
            if (productNum % sortedArr[i]) > 0 {
                checkNum = false
                break
            }
        }
        
        increasNum += 1
        if checkNum {
            return productNum
        }
    }
    
    return 0
}


