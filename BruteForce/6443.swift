//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func main() {
    let n = Int(readLine()!)!
    var str = [String.Element]()
    var alphabet = Array(repeating: 0, count: 26)
    
    func dfs(sum: String) {
        if sum.count == str.count {
            print(sum)
            return
        }
        
        for i in 0..<26 {
            if alphabet[i] > 0 {
                alphabet[i] -= 1
                var sum = sum
                sum.append(Character(UnicodeScalar(i + 97)!))
                dfs(sum: sum)
                alphabet[i] += 1
                sum.removeLast()
            }
        }
    }
    
    for _ in 0..<n {
        str = readLine()!.map { $0 }
        alphabet = Array(repeating: 0, count: 26)
        for s in str {
            alphabet[Int(s.asciiValue!) - 97] += 1
        }
        dfs(sum: "")
    }
}

main()
