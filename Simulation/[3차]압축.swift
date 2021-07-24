//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ msg:String) -> [Int] {
    let alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    var dic = [String: Int]()
    var result = [Int]()
    var increseNum = 1
    
    for i in 0..<alphabet.count {
        dic[String(alphabet[i])] = increseNum
        increseNum += 1
    }
    
    var i = 0
    while i < msg.count {
        var addDic = String(msg[i])
        var Index = 0
        while true {
            if dic[addDic] == nil {
                dic[addDic] = increseNum
                result.append(Index)
                increseNum += 1
                break
            } else {
                i += 1
                Index = dic[addDic]!
                if i >= msg.count {
                    result.append(Index)
                    return result
                }
                addDic.append(String(msg[i]))
            }
        }
    }
    
    return result
}

extension String {
    subscript(_ index: Int) -> Character {
        return self[self.index(self.startIndex, offsetBy: index)]
    }
}

print(solution("KAKAO"))
