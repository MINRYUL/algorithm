//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func main() {
    let k = Int(readLine()!)!
    let n = Int(readLine()!)!
    
    var endSequence = Array(readLine()!)
    var startSequence = endSequence.sorted()

    var str = [[Character]]()

    for _ in 0..<n {
        let x = Array(readLine()!)
        str.append(x)
    }

    for i in 0..<n {
        if str[i][0] == "?" { break }
        for j in 0..<(k - 1) {
            if str[i][j] == "-" {
                let temp = startSequence[j]
                startSequence[j] = startSequence[j + 1]
                startSequence[j + 1] = temp
            }
        }
    }

    str.reverse()
    for i in 0..<n {
        if str[i][0] == "?" { break }
        for j in 0..<(k - 1) {
            if str[i][j] == "-" {
                let temp = endSequence[j]
                endSequence[j] = endSequence[j + 1]
                endSequence[j + 1] = temp
            }
        }
    }

    var answer: [Character] = Array(repeating: "*", count: k - 1)
    for i in 0..<(k - 1) {
        if startSequence[i] == endSequence[i] { continue }
        else if startSequence[i] == endSequence[i + 1] && startSequence[i + 1] == endSequence[i] {
            answer[i] = "-"
            let temp = startSequence[i]
            startSequence[i] = startSequence[i + 1]
            startSequence[i + 1] = temp
        } else {
            print(String(Array(repeating: "x", count: k - 1)))
            return
        }
    }
    print(String(answer))
}

main()
