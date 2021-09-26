//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

var locationMap = Array(repeating: [Int](), count: 10001)
var result = [Int]()
var resultNum = 1

func dfs(_ node: Int, _ places: [Int]) {
    if !result.isEmpty { return }
    if places.count == resultNum {
        result = places
        return
    }
    
    for index in 0..<locationMap[node].count {
        if locationMap[node].isEmpty{ return }
        let location = locationMap[node][index]
        locationMap[node].remove(at: index)
        var tempPlaces = places
        tempPlaces.append(location)
        
        dfs(location, tempPlaces)
        
        locationMap[node].append(location)
        locationMap[node].sort()
    }
}

func solution(_ tickets:[[String]]) -> [String] {
    var locationName = [String]()
    var locationCheck = [String: Int]()
    var locationNum = [Int: String]()
    for ticket in tickets {
        if locationCheck[ticket[0]] == nil {
            locationName.append(ticket[0])
            locationCheck[ticket[0]] = 0
        }
        
        if locationCheck[ticket[1]] == nil {
            locationName.append(ticket[1])
            locationCheck[ticket[1]] = 0
        }
    }
    
    var num = 0
    locationName.sort()
    for location in locationName {
        locationCheck[location] = num
        locationNum[num] = location
        num += 1
    }
    let start = locationCheck["ICN"]!
    
    for ticket in tickets {
        resultNum += 1
        let from = locationCheck[ticket[0]]!
        let to = locationCheck[ticket[1]]!
        locationMap[from].append(to)
        locationMap[from].sort()
    }
    dfs(start, [start])
    
    var answer = [String]()
    for i in result {
        answer.append(locationNum[i]!)
    }
    return answer
}

print(solution([["ICN", "BOO"], ["ICN", "COO"], ["COO", "DOO"], ["DOO", "COO"], ["BOO", "DOO"], ["DOO", "BOO"], ["BOO", "ICN"], ["COO", "BOO"]]))
//["ICN", "AOO", "BOO", "COO", "DOO", "EOO", "DOO", "COO", "BOO", "AOO"]
