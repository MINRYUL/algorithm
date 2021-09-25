//
//  main.swift
//  Swift-PS
//
//  Created by 김민창 on 2021/07/24.
//

import Foundation

var feeDic = [Int : Int]()
var feeTime = [Int]()
var recordDic = [String : String]()
var carNumber = [String]()
var resultFee = [String : Int]()
var accumulatedTime = [String : Int]()
var result = [Int]()

func accumulatedTime(_ records: String) {
    let record = records.split(separator: " ")
    
    let inTime = recordDic[String(record[1])]!.split(separator: ":")
    let outTime = String(record[0]).split(separator: ":")
    let clock = Int(String(outTime[0]))! - Int(String(inTime[0]))!
    let minute = Int(String(outTime[1]))! - Int(String(inTime[1]))!
    let time: Int = (clock * 60) + minute
    
    if accumulatedTime[String(record[1])] == nil {
        accumulatedTime[String(record[1])] = time
    } else {
        let num = accumulatedTime[String(record[1])]!
        accumulatedTime[String(record[1])] = time + num
    }
}

func solution(_ fees:[Int], _ records:[String]) -> [Int] {
    var result = [Int]()
    
    records.forEach {
        let record = $0.split(separator: " ")
        if record[2] == "IN" {
            recordDic[String(record[1])] = String(record[0])
            carNumber.append(String(record[1]))
        } else if record[2] == "OUT" {
            accumulatedTime($0)
            recordDic[String(record[1])] = nil
        }
    }
    var calResult = [String: Int]()
    for num in carNumber {
        if recordDic[num] != nil {
            if calResult[num] == nil {
                calResult[num] = 1
                let str = "23:59 \(num) OUT"
                accumulatedTime(str)
            }
        }
    }
    
    carNumber.sort()
    var alredyResult = [String: Int]()
    for num in carNumber {
        if alredyResult[num] == nil {
            alredyResult[num] = 1
            var time = accumulatedTime[num]!
            var fare = 0
            
            fare += fees[1]
            time -= fees[0]
            
            while time >= 0 {
                if time == 0 {
                    fare += 0
                    time -= 1
                } else {
                    fare += fees[3]
                    time -= fees[2]
                }
            }
            result.append(fare)
        }
    }
    
    return result
}

print(solution([1, 461, 1, 10], ["00:00 1234 IN"]))

//[14600, 34400, 5000]
