//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func main() {
    let str = Array(readLine()!)
    var sameStr = true
    
    for i in 0..<str.count/2 {
        if str[i] != str[str.count - i - 1] {
            print(str.count)
            return
        } else if str[i] != str[i + 1]{
            sameStr = false
        }
    }
    
    if sameStr {
        print("-1")
    } else {
        print(str.count - 1)
    }
}
main()
