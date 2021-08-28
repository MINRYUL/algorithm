//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ str1:String, _ str2:String) -> Int {
    var intersection: Double = 0, union: Double = 0
    var set1 = [String]()
    var dic = [String : Int]()

    let lowerStr1 = str1.lowercased()
    let lowerStr2 = str2.lowercased()
    
    var start = 0, end = 1
    for _ in 1..<lowerStr1.count{
        let startIdx: String.Index = lowerStr1.index(lowerStr1.startIndex, offsetBy: start)
        let endIdx: String.Index = lowerStr1.index(lowerStr1.startIndex, offsetBy: end)
        let str = String(lowerStr1[startIdx...endIdx])
        if "a"..."z" ~= str[0] && "a"..."z" ~= str[1] {
            set1.append(str)
            if dic[str] == nil {
                dic[str] = 1
            } else {
                dic[str] = dic[str]! + 1
            }
        }
        start += 1
        end += 1
    }
    
    start = 0
    end = 1
    for _ in 1..<lowerStr2.count{
        let startIdx: String.Index = lowerStr2.index(lowerStr2.startIndex, offsetBy: start)
        let endIdx: String.Index = lowerStr2.index(lowerStr2.startIndex, offsetBy: end)
        
        let str = String(lowerStr2[startIdx...endIdx])
        if "a"..."z" ~= str[0] && "a"..."z" ~= str[1] {
            if dic[str] != nil {
                if dic[str] != 0 {
                    intersection += 1
                    dic[str] = dic[str]! - 1
                } else {
                    union += 1
                }
            } else {
                union += 1
            }
        }
        start += 1
        end += 1
    }

    union += Double(set1.count)
    if intersection == 0 && union == 0 {
        return 65536
    }
    
    let answer = Int(intersection/union * 65536)
    
    return answer
}

extension String {
    subscript(_ index: Int) -> Character {
        return self[self.index(self.startIndex, offsetBy: index)]
    }
}



print(solution("FRANCE", "french"))
