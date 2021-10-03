//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

var num = 0

func check(array: inout [[Int]], k: Int, x: Int, y: Int) -> Bool {
    for i in x..<(x + k) {
        for j in y..<(y + k) {
            if array[i][j] != 0 { return false }
        }
    }
    return true
}

func solution(array: inout [[Int]], k: Int, x: Int, y: Int) {
    let divideK = k/2
    num += 1
    if check(array: &array, k: divideK, x: x, y: y) {
        array[x + divideK - 1][y + divideK - 1] = num
    }
    if check(array: &array, k: divideK, x: x, y: y + divideK) {
        array[x + divideK - 1][y + divideK] = num
    }
    if check(array: &array, k: divideK, x: x + divideK, y: y) {
        array[x + divideK][y + divideK - 1] = num
    }
    if check(array: &array, k: divideK, x: x + divideK, y: y + divideK) {
        array[x + divideK][y + divideK] = num
    }
    
    if k == 2 { return }
    
    solution(array: &array, k: divideK, x: x, y: y)
    solution(array: &array, k: divideK, x: x + divideK, y: y)
    solution(array: &array, k: divideK, x: x, y: y + divideK)
    solution(array: &array, k: divideK, x: x + divideK, y: y + divideK)
}

func main() {
    let k = Int(readLine()!)!
    let xy = readLine()!.split(separator: " ").map{ Int($0)! }
    let num = Int(pow(2.0, Double(k)))
    var array = Array(repeating: Array(repeating: 0, count: num), count: num)

    array[xy[1] - 1][xy[0] - 1] = -1

    solution(array: &array, k: num, x: 0, y: 0)
    
    for i in stride(from: num - 1, to: -1, by: -1) {
        for j in 0..<num {
            print(array[i][j], terminator: " ")
        }
        print("")
    }
}

main()

//func main() {
//    let t = Int(readLine()!)!
//
//    for _ in 0..<t {
//        let n = Int(readLine()!)!
//
//        var preorder = Array(readLine()!.split(separator: " ").map{ Int($0)! })
//        var inorder = Array(readLine()!.split(separator: " ").map{ Int($0)! })
//
//        var leftR
//    }
//
//}
//
//main()
