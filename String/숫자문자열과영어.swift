//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ s:String) -> Int {
    
    let dic = ["zero":0, "one":1, "two":2, "three":3, "four":4, "five":5, "six":6, "seven":7, "eight":8, "nine":9]
    var answer = ""
    var str = ""
    
    for ch in s {
        switch String(ch) {
        case "0"..."9":
            answer.append(String(ch))
        default:
            str.append(String(ch))
            if dic[str] != nil {
                answer.append(String(dic[str]!))
                str = ""
            }
        }
    }
    return Int(answer)!
}
