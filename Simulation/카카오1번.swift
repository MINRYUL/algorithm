//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    var dic = [String : [String]]()
    var resultDic = [String : Int]()
    
    for re in report {
        let split = re.split(separator: " ")
        if dic[String(split[1])] == nil {
            var str = [String]()
            str.append(String(split[0]))
            dic[String(split[1])] = str
        } else {
            var str = dic[String(split[1])]!
            var check = false
            for s in str {
                if s == split[0] {
                    check = true
                    break
                }
            }
            if check { continue }
            str.append(String(split[0]))
            dic[String(split[1])] = str
        }
    }
    
    for id in id_list {
        if dic[id] != nil {
            if dic[id]!.count >= k {
                for name in dic[id]! {
                    if resultDic[name] == nil {
                        resultDic[name] = 1
                    } else {
                        let i = resultDic[name]!
                        resultDic[name]! = i + 1
                    }
                }
            }
        }
    }
    
    var result = [Int]()
    
    for id in id_list {
        if resultDic[id] == nil {
            result.append(0)
        } else {
            result.append(resultDic[id]!)
        }
    }
    
    return result
}

print(solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"], 2))
