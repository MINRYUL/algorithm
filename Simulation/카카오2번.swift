//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func conversion(_ n:Int, _ k:Int) -> String {
    var result = "", num = n
    while num > 0 {
        result.append(String(num % k))
        num /= k
    }
    return String(result.reversed())
}

func isPrime(_ num: String) -> Bool {
    let n = Int(num)!
    
    if n < 4 {
        return n == 1 ? false : true
    }
    for i in 2...Int(sqrt(Double(n))) {
        if(n % i == 0) {
            return false
        }
    }
    return true
}

func solution(_ n:Int, _ k:Int) -> Int {
    let str = conversion(n, k).map { $0 }
    
    var num = "", result = 0
    
    for i in 0..<str.count {
        if !num.isEmpty {
            if str[i] == "0" {
                if isPrime(num) {
                    result += 1
                }
                num = ""
                continue
            }
            num.append(String(str[i]))
            continue
        }
        
        if str[i] != "0" && num.isEmpty {
            num.append(String(str[i]))
        }
    }
    
    if !num.isEmpty {
        if isPrime(num) {
            result += 1
        }
        num = ""
    }
    
    return result
}

print(solution(110011, 10))

