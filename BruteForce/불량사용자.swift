//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

var map = [String: Bool]()
var resultMap = [[String]: Bool]()

func bannedCheck(_ user: Array<Character>, _ banned: Array<Character>) -> Bool {
    if user.count != banned.count { return false }
    
    for i in 0..<banned.count {
        if banned[i] == "*" { continue }
        else if banned[i] == user[i] { continue }
        else { return false }
    }
    return true
}

func dfs(_ next: Int, _ count: Int, _ sameId: inout [[String]], _ visited: inout [Bool], _ answer: inout Int) {
    if count == sameId.count {
        var strArray = [String]()
        map.forEach{ strArray.append($0.key) }
        strArray.sort()
        if resultMap[strArray] == nil {
            resultMap[strArray] = true
            answer += 1
        }
        return
    }
    
    for i in next..<sameId.count {
        if visited[i] { continue }
        for j in 0..<sameId[i].count {
            if map[sameId[i][j]] == nil {
                visited[i] = true
                map[sameId[i][j]] = true
                dfs(i + 1, count + 1, &sameId, &visited, &answer)
                visited[i] = false
                map[sameId[i][j]] = nil
            }
        }
    }
}

func solution(_ user_id:[String], _ banned_id:[String]) -> Int {
    var userId = [Array<Character>]()
    var bannedId = [Array<Character>]()
    var answer = 0
    
    user_id.forEach{ userId.append(Array($0)) }
    banned_id.forEach{ bannedId.append(Array($0)) }
    
    var sameId: [[String]] = Array(repeating: [String](), count: bannedId.count)
    
    for i in 0..<bannedId.count {
        var strArray = [String]()
        for j in 0..<userId.count {
            if bannedCheck(userId[j], bannedId[i]) {
                strArray.append(String(userId[j]))
            }
        }
        sameId[i] = strArray
    }
    
    var visited: [Bool] = Array(repeating: false, count: sameId.count)
    dfs(0, 0, &sameId, &visited, &answer)
    
    return answer
}

print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["fr*d*", "*rodo", "******", "******"]))
