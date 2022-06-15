//
//  main.swift
//  SwiftPS
//
//  Created by 김민창 on 2022/06/14.
//

import Foundation

func solution(_ fees:[Int], _ records:[String]) -> [Int] {
    var carMap: [String: Int] = [:]
    var carMin: [String: Int] = [:]
    var check: [String: Bool] = [:]
    var result: [String] = []
    let maxMin = 23 * 60 + 59
    
    func calculationCredit(time: Int) -> Int {
        if time <= fees[0] { return fees[1] }
        let unitTime = time - fees[0]
        var fee = (unitTime / fees[2]) * fees[3]
        if unitTime % fees[2] > 0 { fee += fees[3] }
        return fee + fees[1]
    }
    
    records.forEach { record in
        let record = record.components(separatedBy: " ")
        let time = record[0].split(separator: ":")
        let minute = Int(time[0])! * 60 + Int(time[1])!
        guard let exist = carMap[record[1]] else {
            if check[record[1]] == nil {
                result.append(record[1])
                check[record[1]] = true
            }
            carMap[record[1]] = minute
            return
        }
        
        carMap[record[1]] = nil
        guard let min = carMin[record[1]] else {
            carMin[record[1]] = minute - exist
            return
        }
        carMin[record[1]] = min + minute - exist
    }
    
    return result.sorted().map { car -> Int in
        guard let exist = carMap[car] else {
            return calculationCredit(time: carMin[car]!)
        }
        guard let time = carMin[car] else {
            return calculationCredit(time: maxMin - exist)
        }
        return calculationCredit(time: time + maxMin - exist)
    }
}



solution([180, 5000, 10, 600], ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"])
