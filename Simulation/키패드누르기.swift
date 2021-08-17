//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation


func solution(_ numbers:[Int], _ hand:String) -> String {
    var result = ""
    var numberIndex = [(3, 1)]
    for i in 0..<3 {
        for j in 0..<3 {
            numberIndex.append((i, j))
        }
    }
    
    var left = (3, 0), right = (3, 2)
    for number in numbers {
        if (number == 1) || (number == 4) || (number == 7) {
            left = numberIndex[number]
            result.append("L")
        }else if (number == 3) || (number == 6) || (number == 9) {
            right = numberIndex[number]
            result.append("R")
        }else {
            let leftDistance = abs(numberIndex[number].0 - left.0) + abs(numberIndex[number].1 - left.1)
            let rightDistance = abs(numberIndex[number].0 - right.0) + abs(numberIndex[number].1 - right.1)
            if leftDistance < rightDistance {
                left = numberIndex[number]
                result.append("L")
            } else if leftDistance > rightDistance {
                right = numberIndex[number]
                result.append("R")
            } else {
                switch hand {
                case "right":
                    right = numberIndex[number]
                    result.append("R")
                case "left":
                    left = numberIndex[number]
                    result.append("L")
                default:
                    break
                }
            }
        }
    }
    
    return result
}
